package de.thm.mni.compilerbau.phases._06_codegen;

import de.thm.mni.compilerbau.absyn.*;
import de.thm.mni.compilerbau.absyn.visitor.DoNothingVisitor;
import de.thm.mni.compilerbau.table.*;
import de.thm.mni.compilerbau.types.PrimitiveType;
import de.thm.mni.compilerbau.utils.SplError;
import java.io.PrintWriter;


/**
 * This class is used to generate the assembly code for the compiled program.
 * This code is emitted via the {@link CodePrinter} in the output field of this class.
 */
public class CodeGenerator extends DoNothingVisitor {
    private final CodePrinter output;
    private SymbolTable globalTable;
    private int regNumber = 8;
    private String label;
    private static int labelNumber = 0;
    private ProcedureDeclaration procedureDeclaration;

    public CodeGenerator(PrintWriter output) {
        this.output = new CodePrinter(output);
    }

    /**
     * Emits needed import statements, to allow usage of the predefined functions and sets the correct settings
     * for the assembler.
     */
    private void assemblerProlog() {
        output.emitImport("printi");
        output.emitImport("printc");
        output.emitImport("readi");
        output.emitImport("readc");
        output.emitImport("exit");
        output.emitImport("time");
        output.emitImport("clearAll");
        output.emitImport("setPixel");
        output.emitImport("drawLine");
        output.emitImport("drawCircle");
        output.emitImport("_indexError");
        output.emit("");
        output.emit("\t.code");
        output.emit("\t.align\t4");
    }

    public void generateCode(Program program, SymbolTable table) {
        assemblerProlog();
        this.globalTable = table;
        visit(program);
    }

    @Override
    public void visit(ArrayAccess arrayAccess) {
        arrayAccess.array.accept(this);
        arrayAccess.index.accept(this);

        this.output.emitInstruction("add",getRegister(regNumber),new Register(0), arrayAccess.array.dataType.byteSize /4);

        this.regNumber = this.regNumber -1;

        this.output.emitInstruction("bgeu",getRegister(regNumber),getRegister(regNumber +1), "_indexError");
        this.output.emitInstruction("mul",getRegister(regNumber),getRegister(regNumber), arrayAccess.dataType.byteSize, "calc offset within array");
        this.output.emitInstruction("add",previous(1),previous(1),getRegister(regNumber));
    }

    @Override
    public void visit(AssignStatement assignStatement) {
        assignStatement.target.accept(this);
        assignStatement.value.accept(this);

        this.output.emitInstruction("stw",previous(1),previous(2), 0, "assignment");

        this.regNumber = this.regNumber -2;
    }

    @Override
    public void visit(BinaryExpression binaryExpression) {
        binaryExpression.leftOperand.accept(this);
        binaryExpression.rightOperand.accept(this);

        switch(binaryExpression.operator){
            case ADD:
                this.output.emitInstruction("add",previous(2),previous(2),previous(1));
                this.regNumber = this.regNumber -1;
                break;
            case SUB:
                this.output.emitInstruction("sub",previous(2),previous(2),previous(1));
                this.regNumber = this.regNumber -1;
                break;
            case MUL:
                this.output.emitInstruction("mul",previous(2),previous(2),previous(1));
                this.regNumber = this.regNumber -1;
                break;
            case DIV:
                this.output.emitInstruction("div",previous(2),previous(2),previous(1));
                this.regNumber = this.regNumber -1;
                break;
            case EQU:
                this.output.emitInstruction("bne",previous(2),previous(1), label);
                this.regNumber = this.regNumber -2;
                break;
            case NEQ:
                this.output.emitInstruction("beq",previous(2),previous(1), label);
                this.regNumber = this.regNumber -2;
                break;
            case GRT:
                this.output.emitInstruction("ble",previous(2),previous(1), label);
                this.regNumber = this.regNumber -2;
                break;
            case LST:
                this.output.emitInstruction("bge",previous(2),previous(1), label);
                this.regNumber = this.regNumber -2;
                break;
            case GRE:
                this.output.emitInstruction("blt",previous(2),previous(1), label);
                this.regNumber = this.regNumber -2;
                break;
            case LSE:
                this.output.emitInstruction("bgt",previous(2),previous(1), label);
                this.regNumber = this.regNumber -2;
                break;
        }
    }

    @Override
    public void visit(CallStatement callStatement) {
        ProcedureEntry procedureEntry = (ProcedureEntry) globalTable.lookup(callStatement.procedureName);
        for (int i = 0; i < procedureEntry.parameterTypes.size(); i++) {
            ParameterType param = procedureEntry.parameterTypes.get(i);
            Expression expression = callStatement.argumentList.get(i);

            if(param.isReference){
                ((VariableExpression)expression).variable.accept(this);
            }
            else{
                expression.accept(this);
            }

            this.regNumber = this.regNumber -1;

            this.output.emitInstruction("stw",new Register(regNumber),new Register(29), param.offset, "store arg #" + i);
        }

        this.output.emitInstruction("jal", callStatement.procedureName.toString());


    }

    @Override
    public void visit(CompoundStatement compoundStatement) {
        compoundStatement.statements.forEach(statement -> statement.accept(this));
    }

    @Override
    public void visit(IntLiteral intLiteral) {

        this.output.emitInstruction("add",getRegister(this.regNumber),new Register(0),intLiteral.value);
        this.regNumber = this.regNumber +1;
    }

    @Override
    public void visit(NamedVariable namedVariable){
        ProcedureEntry procedureEntry = (ProcedureEntry) globalTable.lookup(this.procedureDeclaration.name);
        VariableEntry variableEntry = (VariableEntry) procedureEntry.localTable.lookup(namedVariable.name);

        this.output.emitInstruction("add",getRegister(regNumber),new Register(25), variableEntry.offset);

        if (variableEntry.isReference)
            this.output.emitInstruction("ldw",getRegister(regNumber),getRegister(regNumber), 0);

        this.regNumber = this.regNumber +1;
    }

    @Override
    public void visit(ProcedureDeclaration procedureDeclaration) {
        this.procedureDeclaration = procedureDeclaration;

        // symbol table
        ProcedureEntry procedureEntry = (ProcedureEntry) globalTable.lookup(procedureDeclaration.name);

        //get label
        String label = procedureDeclaration.name.toString();
        this.output.emitExport(label);
        this.output.emitLabel(label);

        int frameSize = 0;
        if(procedureEntry.outgoingAreaSize == -1){
            frameSize += procedureEntry.localVarAreaSize + PrimitiveType.intType.byteSize;
        }else{
            frameSize += procedureEntry.localVarAreaSize + (PrimitiveType.intType.byteSize * 2) + procedureEntry.outgoingAreaSize;
        }

        this.output.emitInstruction("sub",new Register(29),new Register(29), frameSize ,"allocate frame");

        //old Fp
        int oldFp = 0;
        if(procedureEntry.outgoingAreaSize != -1){
            oldFp += procedureEntry.outgoingAreaSize + PrimitiveType.intType.byteSize;
        }

        this.output.emitInstruction("stw",new Register(25),new Register(29),oldFp,"save old frame pointer");

        //new FP
        this.output.emitInstruction("add",new Register(25),new Register(29),frameSize,"setup new frame pointer");

        //old return Address check !!
        int oldReturnAdd = procedureEntry.localVarAreaSize + (PrimitiveType.intType.byteSize * 2);
        if(procedureEntry.outgoingAreaSize !=-1){
            this.output.emitInstruction("stw",new Register(31),new Register(25), -oldReturnAdd,"save return register");
        }

        //body
        procedureDeclaration.body.forEach(statement -> statement.accept(this));

        /*epilog (if proc has caller) */
        if (procedureEntry.outgoingAreaSize != -1) {
            this.output.emitInstruction("ldw",new Register(31),new Register(25), -oldReturnAdd,"restore return register");
        }

        this.output.emitInstruction("ldw",new Register(25),new Register(29), oldFp , "restore old frame pointer");
        this.output.emitInstruction("add",new Register(29),new Register(29), frameSize, "release frame");
        this.output.emitInstruction("jr",new Register(31), "return");
    }

    @Override
    public void visit(Program program) {
        program.declarations.forEach(dec -> dec.accept(this));
    }

    @Override
    public void visit(VariableExpression variableExpression){
        variableExpression.variable.accept(this);
        this.output.emitInstruction("ldw",previous(1),previous(1), 0);
    }

    /*
    if (op1 ~operator op2) goto L0
    S1
    goto L1
    l0:
       s2
    l1:
    */
    @Override
    public void visit(IfStatement ifStatement){
        String l0 = getLabel();
        label = l0;
        String l1 = getLabel();

        ifStatement.condition.accept(this);

        ifStatement.thenPart.accept(this);
        this.output.emitInstruction("j",l1);

        this.output.emitLabel(l0);

        if(!(ifStatement.elsePart instanceof EmptyStatement)){
            ifStatement.elsePart.accept(this);
            this.output.emitLabel(l1);
        }
    }

    /*
    l0:
     if(op1 ~operator op2) goto l1
     s
     goto l0
    l1:
     */
    @Override
    public void visit(WhileStatement whileStatement) {
        String l0 = getLabel();
        String l1 = getLabel();

        this.output.emitLabel(l0);
        label = l1;
        whileStatement.condition.accept(this);

        whileStatement.body.accept(this);

        this.output.emitInstruction("j",l0);
        this.output.emitLabel(l1);
    }

    private Register previous(int offset) {
        return getRegister(this.regNumber - offset);
    }

    private String getLabel(){
        return "L" + CodeGenerator.labelNumber++;

    }

    private Register getRegister(int number){
        Register register = new Register(number);
        if(!(register.isFreeUse())){
            throw SplError.RegisterOverflow();
        }
        return register;
    }
}
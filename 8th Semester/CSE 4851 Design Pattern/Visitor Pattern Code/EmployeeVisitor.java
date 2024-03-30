// Visitor Interface
interface EmployeeVisitor {
    void visit(Manager manager);
    void visit(Programmer programmer);
    void visit(Intern intern);
}

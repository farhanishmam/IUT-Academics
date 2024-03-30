// Programmer class
class Programmer extends Employee {
    private int numberOfProjects;

    public Programmer(String name, double salary, int numberOfProjects) {
        super(name, salary);
        this.numberOfProjects = numberOfProjects;
    }

    public int getNumberOfProjects() {
        return numberOfProjects;
    }

    // Accept method implementation for Programmer
    @Override
    public void accept(EmployeeVisitor visitor) {
        visitor.visit(this);
    }
}
class Manager extends Employee {
    private int numberOfSubordinates;

    public Manager(String name, double salary, int numberOfSubordinates) {
        super(name, salary);
        this.numberOfSubordinates = numberOfSubordinates;
    }

    public int getNumberOfSubordinates() {
        return numberOfSubordinates;
    }

    // Accept method implementation for Manager
    @Override
    public void accept(EmployeeVisitor visitor) {
        visitor.visit(this);
    }
}
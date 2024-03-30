class Intern extends Employee {
    private int durationInMonths;

    public Intern(String name, double salary, int durationInMonths) {
        super(name, salary);
        this.durationInMonths = durationInMonths;
    }

    public int getDurationInMonths() {
        return durationInMonths;
    }

    // Accept method implementation for Intern
    @Override
    public void accept(EmployeeVisitor visitor) {
        visitor.visit(this);
    }
}
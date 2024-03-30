// Salary calculation visitor
class SalaryCalculator implements EmployeeVisitor {
    private double totalSalary = 0;

    @Override
    public void visit(Manager manager) {
        totalSalary += manager.getSalary() + manager.getNumberOfSubordinates() * 1000;
    }

    @Override
    public void visit(Programmer programmer) {
        totalSalary += programmer.getSalary() + programmer.getNumberOfProjects() * 500;
    }

    @Override
    public void visit(Intern intern) {
        totalSalary += intern.getSalary() + intern.getDurationInMonths() * 100;
    }

    public double getTotalSalary() {
        return totalSalary;
    }
}
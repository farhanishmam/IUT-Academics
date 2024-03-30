// Main class
public class Client {
    public static void main(String[] args) {
        // Creating employees
        Manager manager = new Manager("John Doe", 5000, 5);
        Programmer programmer = new Programmer("Jane Smith", 3000, 3);
        Intern intern = new Intern("Bob Williams", 1000, 6);

        // Creating visitor object
        SalaryCalculator calculator = new SalaryCalculator();
		    // Accepting visitor for each employee
		manager.accept(calculator);
		programmer.accept(calculator);
		intern.accept(calculator);

		// Printing total salary
		System.out.println("Total Salary: " + calculator.getTotalSalary());
    }
}
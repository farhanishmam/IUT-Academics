// Define the concrete classes for QuackBehavior interface in the strategy pattern
class Quack implements QuackBehavior {
    public void quack() {
        System.out.println("Quack");
    }
}
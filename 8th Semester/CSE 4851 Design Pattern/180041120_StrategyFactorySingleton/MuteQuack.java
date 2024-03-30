// Define the concrete classes for QuackBehavior interface in the strategy pattern
class MuteQuack implements QuackBehavior {
    public void quack() {
        System.out.println("<< Silence >>");
    }
}
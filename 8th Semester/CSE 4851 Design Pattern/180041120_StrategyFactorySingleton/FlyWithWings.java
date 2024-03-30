// Define the concrete classes for FlyBehavor interface in the strategy pattern
class FlyWithWings implements FlyBehavior {
    public void fly() {
        System.out.println("I'm flying with wings");
    }
}
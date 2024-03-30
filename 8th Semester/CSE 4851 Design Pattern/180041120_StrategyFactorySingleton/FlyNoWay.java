// Define the concrete classes for FlyBehavor interface in the strategy pattern
class FlyNoWay implements FlyBehavior {
    public void fly() {
        System.out.println("I can't fly");
    }
}
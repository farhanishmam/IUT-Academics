// Uses the strategy, factory, and singleton patterns together
public class ClientCode {
    public static void main(String[] args) {
        DuckFactory duckFactory = DuckFactory.getInstance();

        Duck mallardDuck = duckFactory.create("mallard");
        mallardDuck.display();
        mallardDuck.performQuack();
        mallardDuck.performFly();

        Duck rubberDuck = duckFactory.create("rubber");
        rubberDuck.display();
        rubberDuck.performQuack();
        rubberDuck.performFly();

        rubberDuck.setFlyBehavior(new FlyWithWings());
        rubberDuck.performFly();
    }
}
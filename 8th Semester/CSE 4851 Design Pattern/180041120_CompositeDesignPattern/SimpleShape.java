// Leaf class
public class SimpleShape implements VillageObject {
    private String name;

    public SimpleShape(String name) {
        this.name = name;
    }

    @Override
    public void draw() {
        System.out.println("Drawing " + name);
    }
}

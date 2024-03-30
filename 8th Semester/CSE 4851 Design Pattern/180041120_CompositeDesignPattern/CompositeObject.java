import java.util.*;

public class CompositeObject implements VillageObject {
    private List<VillageObject> children = new ArrayList<>();
    private String name;

    public CompositeObject(String name) {
        this.name = name;
    }

    public void add(VillageObject obj) {
        children.add(obj);
    }

    public void remove(VillageObject obj) {
        children.remove(obj);
    }

    @Override
    public void draw() {
        System.out.println("Drawing " + name);
        for (VillageObject obj : children) {
            obj.draw();
        }
    }
}

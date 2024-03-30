//Client Code
public class VillageBuilder {
    public static void main(String[] args) {
        // Creating the Simple Shapes
        VillageObject roof = new SimpleShape("Roof");
        VillageObject building = new SimpleShape("Building");
        VillageObject branch = new SimpleShape("Branch");
        VillageObject leaf = new SimpleShape("Leaf");
        VillageObject stem = new SimpleShape("Stem");
        VillageObject water = new SimpleShape("Water");

        // Creating composite objects of House, Tree, and Water Source
        CompositeObject house = new CompositeObject("House");
        house.add(roof);
        house.add(building);

        CompositeObject tree1 = new CompositeObject("Tree");
        tree1.add(branch);
        tree1.add(leaf);
        tree1.add(stem);

        CompositeObject tree2 = new CompositeObject("Tree");
        tree2.add(branch);
        tree2.add(leaf);
        tree2.add(stem);

        CompositeObject waterSource = new CompositeObject("Water Source");
        waterSource.add(water);

        // Creating a composite object for forest with 2 trees
        CompositeObject forest = new CompositeObject("Forest");
        forest.add(tree1);
        forest.add(tree2);

        // Creating a composite object for village
        CompositeObject village = new CompositeObject("Village");
        village.add(forest);
        village.add(house);
        village.add(waterSource);

        // Drawing the village
        village.draw();
    }
}
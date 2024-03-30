// Define the factory for the factory pattern
// The factory also has a single instance following the singleton pattern

class DuckFactory {
    private static DuckFactory instance =  new DuckFactory();;

    private DuckFactory() {}

    public static DuckFactory getInstance() {
        return instance;
    }

    public Duck create(String type) {
        if (type.equals("mallard")) {
            return new MallardDuck();
        } else if (type.equals("rubber")) {
            return new RubberDuck();
        } else {
            throw new IllegalArgumentException("Invalid duck type: " + type);
        }
    }
}

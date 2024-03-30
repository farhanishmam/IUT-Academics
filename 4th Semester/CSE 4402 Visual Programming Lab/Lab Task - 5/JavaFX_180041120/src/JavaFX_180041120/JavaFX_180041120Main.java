package JavaFX_180041120;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class JavaFX_180041120Main extends Application
{
    @Override
    public void start(Stage primaryStage) throws Exception
    {
        Parent root = FXMLLoader.load(getClass().getResource("JavaFX_180041120_HomePage.fxml"));
        primaryStage.setTitle("Home Page");
        primaryStage.setScene(new Scene(root, 704, 480));
        primaryStage.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
}

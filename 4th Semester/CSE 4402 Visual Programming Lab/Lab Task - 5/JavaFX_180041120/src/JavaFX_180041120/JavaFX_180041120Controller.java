package JavaFX_180041120;

import javafx.stage.Stage;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import java.net.URL;
import java.util.ResourceBundle;

public class JavaFX_180041120Controller
{
    public void initialize(URL url, ResourceBundle rb)
    {
    }

    @FXML
    private AnchorPane exitPane;

    @FXML
    private void handleYes(ActionEvent event)
    {
        System.exit(0);
    }
    @FXML
    private void handleNo(ActionEvent event)
    {
        Stage stage = (Stage) exitPane.getScene().getWindow();
        stage.close();
    }

    @FXML
    private void handleNextButton(ActionEvent event) throws Exception
    {
        Parent page02Parent = FXMLLoader.load(getClass().getResource("JavaFX_180041120_Page2.fxml"));
        Scene page02Scene = new Scene(page02Parent,704,480);
        Stage window = (Stage)((Node)event.getSource()).getScene().getWindow();
        window.setScene(page02Scene);
        window.setTitle("Page 2");
        window.show();
    }

    @FXML
    private void handleExitButton(ActionEvent event) throws Exception
    {
        Parent exitPageParent = FXMLLoader.load(getClass().getResource("JavaFX_180041120_ExitPage.fxml"));
        Scene exitPageScene = new Scene(exitPageParent);
        Stage window = new Stage();
        window.setScene(exitPageScene);
        window.setTitle("Exit Page");
        window.show();
    }

    @FXML
    private void returnHomePage(ActionEvent event) throws Exception
    {
        Parent homeParent = FXMLLoader.load(getClass().getResource("JavaFX_180041120_HomePage.fxml"));
        Scene homeScene = new Scene(homeParent,704,480);
        Stage window = (Stage)((Node)event.getSource()).getScene().getWindow();
        window.setScene(homeScene);
        window.setTitle("Home Page");
        window.show();
    }
}

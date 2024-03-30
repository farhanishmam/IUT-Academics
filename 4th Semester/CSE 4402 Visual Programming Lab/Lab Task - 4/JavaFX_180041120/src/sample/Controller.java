package sample;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;

/** Adds functionality to Java FX GUI
 *
 */
public class Controller implements Initializable

{
    @FXML
    private Button exitButton;
    @FXML
    private Label output;
    @FXML
    private TextField input;
    @Override
    /**Initializes the JavaFX instance
     * Left as empty
     */
    public void initialize(URL url, ResourceBundle resourceBundle) {

    }

    /** Takes a username as input and displays it
     *
     * @param keyEvent keyboard key pressed
     */
    @FXML
    public void keyPressed(KeyEvent keyEvent)
    {
        if (keyEvent.getCode() == KeyCode.ENTER)
        {
            String username;
            username = input.getText();
            output.setText(username);
        }
    }
    /** Exits the program when exit button is pressed
     *
     */
    @FXML
    public void exitAction()
    {
        System.exit(1);
    }
}

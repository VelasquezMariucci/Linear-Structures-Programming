package com.example.ecometrics;

import com.example.ecometrics.model.*;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.Vector;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource
                ("/com/example/ecometrics/view/Window_ProductionAnalysis.fxml")); 

        Parent root = fxmlLoader.load();

        stage.setScene(new Scene(root));
        stage.setResizable(false);
        stage.show();
    }

    public static Vector<User> users;

    public static void main(String[] args) {

        UserManager userManager = new UserManager();
        users = userManager.loadUsers();

        launch();
    }
}
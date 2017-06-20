//package projectserver;

import java.sql.*;
import java.util.*;

public class SQL {
    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
    static final String DB_URL = "jdbc:mysql://localhost/library";

    // Database credentials set to defaults
    static final String USER = "root";
    static final String PASS = ""; 

// Called by the server to run queries 
public void run(String data){
    Connection connection = null;
    Statement statement = null;

    try {
        // Register JDBC driver
        Class.forName("com.mysql.jdbc.Driver");

        // Opening a connectionection
        System.out.print("\n Connecting to database...");
        connection = DriverManager.getConnection(DB_URL, USER, PASS);
        System.out.println("Successfully donnected to Database! \n");

        // Excuting queries
        System.out.print("\n Inserting records into table...");
        statement = connection.createStatement();
        
        String inputs[] = data.split(",");
        String sql;
        ResultSet response;
        
        switch (inputs[0]) {
            
            case "login_login" :
                sql = " SELECT * FROM users WHERE UName = "+inputs[1]+" AND Password = "+inputs[2]+" ";
                statement.executeQuery(sql);
                break;
            case "id_proceed" : 
                sql = " SELECT * FROM users WHERE SSID = "+inputs[1]+" ";
                response = statement.executeQuery(sql);
                // ------------------------------------ send response to server
                break;
            case "search_scan" : 
                sql = " SELECT ShelfID FROM books WHERE BSN = "+inputs[1]+" ";
                response = statement.executeQuery(sql);
                break;
            case "search_proceed" : 
                sql = " SELECT * FROM books WHERE BName = "+inputs[1]+" AND Author = "+inputs[2]+" ";
                response = statement.executeQuery(sql);
                break;
            case "look_id" : 
                sql = " SELECT * FROM customers WHERE CustomerID = "+inputs[1]+" ";
                response = statement.executeQuery(sql);
                break;
            case "look_book" : 
                sql = " SELECT * FROM books WHERE BSN = "+inputs[1]+" ";
                response = statement.executeQuery(sql); 
                break;
            case "lend_proceed" : 
                sql = " UPDATE books SET IsReserved = true AND CustomerID = "+inputs[2]+" WHERE BSN = "+inputs[1]+" ";
                break;
            case "return_proceed" : 
                sql = " UPDATE books SET IsReserved = false AND CustomerID = null WHERE BSN = "+inputs[1]+" ";
                break;
            default : break;    
        }
        
        
        System.out.println(" Query successful! \n");

    } catch(SQLException se) {
        se.printStackTrace();
    } catch(Exception e) {
        e.printStackTrace();
    } finally {
        try {
            if(statement != null)
                connection.close();
        } catch(SQLException se) {
        }
        try {
            if(connection != null)
                connection.close();
        } catch(SQLException se) {
            se.printStackTrace();
        }
    }
    System.out.println("Thank you for your patronage!");
  }

}




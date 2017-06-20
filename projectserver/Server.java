//package projectserver;
import java.sql.*;
import java.io.*;
import java.util.*;
import java.net.ServerSocket;
import java.net.Socket;
import javax.swing.*;
import java.awt.*;

public class Server{
static final int port = 1234;
public static void main(String[] args)throws IOException{
      
    SQL sql = new SQL();
    
      ServerSocket serverSocket = new ServerSocket(port);
      String data = null;
      System.out.println("running");
      while(true){  //input from RFID
      Socket socket = serverSocket.accept();
      System.out.println("started");
      BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));

     	if((data = br.readLine())!= null){
        System.out.println(data);
        sql.run(data);
      }
        
      socket.close();
    }
  }
}
	



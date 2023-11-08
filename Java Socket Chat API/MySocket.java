import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;


public class MySocket {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(50051);

            Socket userSocket1 = serverSocket.accept();
            System.out.println("Cliente 1 Entrou!");

            Socket userSocket2 = serverSocket.accept();
            System.out.println("Cliente 2 Entrou!");

            BufferedReader in1 = new BufferedReader(new InputStreamReader(userSocket1.getInputStream()));
            PrintWriter out1 = new PrintWriter(userSocket1.getOutputStream(), true);

            BufferedReader in2 = new BufferedReader(new InputStreamReader(userSocket2.getInputStream()));
            PrintWriter out2 = new PrintWriter(userSocket2.getOutputStream(), true);

            Thread user1ToUser2 = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        String msg; //msg
                        out1.println("Usuario 1 Diga seu nome: ");
                        String name1 = in1.readLine();
                        while ((msg = in1.readLine()) != null) {
                            System.out.println(name1+": " + msg);
                            out2.println(name1+": "+msg);
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            });

            Thread user2ToUser1 = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        String msg;//msg
                        out2.println("Usuario 1 Diga seu nome: ");
                        String name2 = in2.readLine();
                        while ((msg = in2.readLine()) != null) {
                            System.out.println(name2+": " + msg);
                            out1.println(name2+": "+msg);
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            });

            user1ToUser2.start();
            user2ToUser1.start();


            user1ToUser2.join();
            user2ToUser1.join();



            in1.close();
            out1.close();
            in2.close();
            out2.close();
            userSocket1.close();
            userSocket2.close();
            serverSocket.close();

        } catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}


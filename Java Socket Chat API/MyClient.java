import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class MyClient {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 50051);
            System.out.println("Conexão Estabelecida!");

            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            BufferedReader console = new BufferedReader(new InputStreamReader(System.in));

            Thread msgThread = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        String serverMsg;
                        while ((serverMsg = in.readLine()) != null) {
                            System.out.println(serverMsg+"\n");
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            });

            msgThread.start();

            while (true) {
                System.out.print("Msg: ");
                String myMsg = console.readLine();
                out.println(myMsg);

                if (myMsg == "" || myMsg == null){
                    break;
                } 
            }
            
            msgThread.join();

            in.close();
            out.close();
            console.close();
            socket.close();

        } catch (UnknownHostException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}

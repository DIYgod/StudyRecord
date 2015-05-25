import java.net.*;
import java.io.*;

public class ChatClient {
	public static void main(String[] args) {
		try {
			Socket client = new Socket("127.0.0.1",1207);
			
			BufferedReader serverin = new BufferedReader(new InputStreamReader(client.getInputStream()));
			PrintWriter clientout = new  PrintWriter(client.getOutputStream());
			BufferedReader standin = new BufferedReader(new InputStreamReader(System.in));
			String s = "nothing";
			
			while(!s.equals("q"))
			{
				System.out.print("Client: ");
				s = standin.readLine();
				clientout.println(s);
				clientout.flush();
				System.out.println("Server: " + serverin.readLine());
			}
			
			serverin.close();
			clientout.close();
			standin.close();
			client.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

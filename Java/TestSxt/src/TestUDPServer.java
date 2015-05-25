import java.net.*;
import java.io.*;

public class TestUDPServer {
	public static void main(String[] args)
	{
		byte[] b = new byte[1024];
		ByteArrayInputStream bais = new ByteArrayInputStream(b);
		DataInputStream dis = new DataInputStream(bais);
		
		try {
			DatagramPacket dp = new DatagramPacket(b, b.length);
			@SuppressWarnings("resource")
			DatagramSocket ds = new DatagramSocket(1207);
			while(true)
			{
				ds.receive(dp);
				System.out.println(dis.readInt());
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
}

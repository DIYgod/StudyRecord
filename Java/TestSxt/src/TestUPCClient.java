import java.io.*;
import java.net.*;

public class TestUPCClient {
	public static void main(String[] args) {
		int level = 99;
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(baos);
		try {
			dos.writeInt(level);
			byte[] b = baos.toByteArray();
		
			DatagramPacket dp = new DatagramPacket(b, b.length, new InetSocketAddress("127.0.0.1", 1207));
			DatagramSocket ds = new DatagramSocket(1208);
			ds.send(dp);
			
			baos.close();
			dos.close();
			ds.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}

import java.io.*;
public class TestPrintStream_ReadFIle {

	public static void main(String[] args) {

		try {
		BufferedReader br = new BufferedReader(new FileReader("/home/diygod/Code/Java/test.txt"));
		String st = null;
		while((st = br.readLine()) != null)
		{
			System.out.println(st);
		}
		br.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
		
	}

}

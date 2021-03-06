import java.io.*;
import java.util.*;

public class TestPrintStream {
	public static void main(String[] args) {
		FileOutputStream fos = null;
		
		try {
			fos = new FileOutputStream("/home/diygod/Code/Java/test.txt", true);
		} catch(IOException e) {
			e.printStackTrace();
		}
		
		PrintStream ps = new PrintStream(fos);
		System.setOut(ps);
		BufferedReader buf = new BufferedReader(new InputStreamReader(System.in)); 
		String st = null;
		
		try {
			System.out.println(new Date());
			while((st = buf.readLine()) != null)
			{
				if(st.equals("q")) break;
				System.out.println(st);
			}
			fos.close();
		} catch(IOException e) {
			e.printStackTrace();
			
		}
	}
}

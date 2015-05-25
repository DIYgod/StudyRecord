import java.util.*;
public class CompareInts {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Random rand1 = new Random();
		Random rand2 = new Random();
		while(true) {
			int x = rand1.nextInt(10);
			int y = rand2.nextInt(10);
			if(x > y)
				System.out.println(x + " > " + y);
			else if(x == y)
				System.out.println(x + " = " + y);
			else
			    System.out.println(x + " < " + y);
			
		}

	}

}

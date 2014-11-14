
public class Binary {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int i = 0xAA;
		int j = 0x55;
		System.out.println("i = " + Integer.toBinaryString(i));
		System.out.println("j = 0" + Integer.toBinaryString(j));
		System.out.println("i & j = " + Integer.toBinaryString(i & j));
		System.out.println("i | j = " + Integer.toBinaryString(i | j));
		System.out.println("i ^ j = " + Integer.toBinaryString(i ^ j));
		System.out.println("~i = " + Integer.toBinaryString(~i));
		System.out.println("~j = " + Integer.toBinaryString(~j));

	}

}

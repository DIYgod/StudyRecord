class ST {
	static String s1 = "Anotherhome";
	static String s2;
	static {
		s2 = ".net";
	}
	static void Print() {
		System.out.println(s1 + s2);
	}
}
public class StaticTest1 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		ST.Print();
		

	}
    static ST test = new ST();
}

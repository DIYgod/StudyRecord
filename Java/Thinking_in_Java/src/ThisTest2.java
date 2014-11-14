class Th {
	Th(int i) {
		this(i, "Anotherhome");
	}
	Th(int j, String s) {
		for(int count = 0; count < j; count++) {
			System.out.println(s);
		}
		}
}


public class ThisTest2 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		new Th(30);

	}

}

class Tankoo {
	String i;
	Tankoo(String s) {
		i = s;
		if(s == "full")
			System.out.println("The tank is full.");
		else if(s == "empty")
			System.out.println("The tank is empty.");
		else
			System.out.println("Error!");
	}
	protected void finalize() {
		if(i == "empty") {
			System.out.println("Clear.");
		}
	}
}

public class FinalizeTest {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		new Tankoo("empty");
        System.gc();
	}
}

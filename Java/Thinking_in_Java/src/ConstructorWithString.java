class CWS {
	CWS(String s) {
		System.out.println(s);
	}
}
public class ConstructorWithString {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		CWS test = new CWS("home");
		CWS[] a = {
			new CWS("another"),
			test,
		};

	}

}

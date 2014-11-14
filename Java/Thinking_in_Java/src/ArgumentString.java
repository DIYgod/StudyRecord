class Arg {
	Arg(Object... args) {
		for(Object obj : args)
			System.out.print(obj + " ");
		System.out.println( );
	}
}
public class ArgumentString {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		new Arg("another", "home");

	}

}

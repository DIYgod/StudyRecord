class Arg {
	Arg(Object... args) {
		for(Object obj : args)
			System.out.print(obj + " ");
		System.out.println( );
	}
}
public class ArgumentString {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		new Arg("another", "home");

	}

}

class Default {
	Default() {
		System.out.println("Anotherhome");
	}
	Default(String s) {
		System.out.println(s + "Anotherhome");
	}
}
public class DefaultConstructorTest {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		Default test = new Default();
		Default test1 = new Default("I love ");

	}

}

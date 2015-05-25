class StringTest1 {
	String test = "Anotherhome";
}
class StringTest2 {
	String test;
	StringTest2() {
		test = "Anotherhome";
	}
}
public class Initialization1 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		StringTest1 Test1 = new StringTest1();
		System.out.println(Test1.test);
		StringTest2 Test2 = new StringTest2();
		System.out.println(Test2.test);

	}

}

class InA {
	InA() {
		System.out.println("A");
	}
}
class InB {
	InB() {
		System.out.println("B");
	}
}
class InC extends InA {
	InB ib = new InB();
}
public class InheritC {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		InC inc = new InC();

	}

}

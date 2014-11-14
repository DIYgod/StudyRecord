class InhA {
	InhA(int i) {
		System.out.println(i + "A");
	}
}
class InhB {
	InhB(int j) {
		System.out.println(j + "B");
	}
}
class InhC extends InhA {
	InhC() {
		super(47);
	}
	InhB ib = new InhB(99);
}
public class ArgInherit {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		InhC inhc = new InhC();

	}

}


public class InheritDetergent extends Detergent {
	public void scrub() {
		System.out.println("Another");

	}
	public void sterilize() {
		System.out.println("home");
	}

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		InheritDetergent s = new InheritDetergent();
		s.dilute();
		System.out.println(s);
		s.scrub();
		s.sterilize();
	}

}

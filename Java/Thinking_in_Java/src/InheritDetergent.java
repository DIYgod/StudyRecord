
public class InheritDetergent extends Detergent {
	public void scrub() {
		System.out.println("Another");

	}
	public void sterilize() {
		System.out.println("home");
	}

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		InheritDetergent s = new InheritDetergent();
		s.dilute();
		System.out.println(s);
		s.scrub();
		s.sterilize();
	}

}

class Tank {
	float level;
}
public class BieMing {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Tank t1 = new Tank();
		Tank t2 = new Tank();
		t1.level = 9;
		t2.level = 47;
		System.out.println("t1 = " + t1.level + " t2 = " + t2.level);
		t1 = t2;
		System.out.println("t1 = " + t1.level + " t2 = " + t2.level);
		t1.level = 99;
		System.out.println("t1 = " + t1.level + " t2 = " + t2.level);
	}

}

class Talk {
	Talk(int b, double h) {
		System.out.println("Barking.");
	}
	Talk(double h, int b) {
		System.out.println("Howling.");
	}
}

public class DogTalk {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		int i = 0;
		double j = 0;
		Talk t1 = new Talk(i, j);
		Talk t2 = new Talk(j, i);

	}

}

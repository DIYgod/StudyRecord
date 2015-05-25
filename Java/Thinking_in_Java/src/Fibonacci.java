
public class Fibonacci {

	public static void main(String[] args) {
		int i, j, k;
		i = j = 1;
		System.out.println(i);
		System.out.println(j);
		for(int count = 0; count < 10; count ++) {
			k = i + j;
			i = j;
			j = k;
			System.out.println(j);
		}

	}

}

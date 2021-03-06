
public class TestPriority {
	public static void main(String[] args)
	{
		PrintThousand pt1 = new PrintThousand("py1");
		PrintThousand pt2 = new PrintThousand("pt2");
		Thread t1 = new Thread(pt1);
		Thread t2 = new Thread(pt2);
		t1.setPriority(Thread.NORM_PRIORITY + 3);
		t1.start();
		t2.start();
	}
}

class PrintThousand implements Runnable
{
	PrintThousand(String name)
	{
		this.name = name;
	}
	String name;
	public void run()
	{
		for(int i = 0; i < 1000; i++)
		{
			System.out.println(name + ": " + i);
		}
	}
}
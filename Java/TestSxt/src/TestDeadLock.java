
public class TestDeadLock implements Runnable {
	private int flag = 0;
	static Object o1 = new Object(), o2 = new Object();
	
	TestDeadLock(int flag)
	{
		this.flag = flag;
	}
	
	public void run()
	{
		System.out.println("flag : " + flag);
		
		if(flag == 0)
		{
			synchronized(o1)
			{
				System.out.println("flag " + flag + " lock 1");
				try {
					Thread.sleep(500);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				synchronized(o2)
				{
					System.out.println("flag " + flag + " lock 2");
				}
			}
		}
		
		if(flag == 1)
		{
			synchronized(o2)
			{
				System.out.println("flag " + flag + " lock 2");
				try {
					Thread.sleep(500);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				synchronized(o1)
				{
					System.out.println("flag " + flag + " lock 1");
				}
			}
		}
	}
	
	public static void main(String[] args) {
		TestDeadLock tdl1 = new TestDeadLock(0);
		TestDeadLock tdl2 = new TestDeadLock(1);
		Thread t1 = new Thread(tdl1);
		Thread t2 = new Thread(tdl2);
		t1.start();
		t2.start();
	}

}

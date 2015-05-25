import java.util.*;

public class TestThread {
	public static void main(String[] args)
	{
		iThread it = new iThread();
		Thread t = new Thread(it);
		t.start();
		try {
			Thread.sleep(10000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		it.shutDown();
	}
}

class iThread implements Runnable
{
	private boolean flag = true;
	
	public void run() 
	{
		while(flag)
		{
			System.out.println("===" + new Date() + "===");
			try {
				Thread.sleep(1000);
			} catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	
	public void shutDown()
	{
		flag = false;
	}
}
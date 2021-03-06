public class ProducerConsumer {
	public static void main(String[] args) {
		Space s = new Space();
		Producer p = new Producer(s);
		Consumer c = new Consumer(s);
		new Thread(p).start();
		new Thread(c).start();
	}
}


class Product
{
	int id;
	Product(int id)
	{
		this.id = id;
	}
}


class Space
{
	int top = -1;
	Product[] arrProduct = new Product[6];
	
	public synchronized void push(Product p)
	{
		while(top >= arrProduct.length - 1)
		{
			try {
				this.wait();
			} catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
		this.notifyAll();
		top++;
		arrProduct[top] = p;
	}
	
	public synchronized Product pop()
	{
		while(top <= -1)
		{
			try {
				this.wait();
			} catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
		this.notifyAll();
		Product p = arrProduct[top];
		top--;
		
		return p;
	}
}


class Producer implements Runnable
{
	Space s = null;
	Producer(Space s)
	{
		this.s = s;
	}
	
	public void run()
	{
		for(int i = 0; i < 20; i++)
		{
			Product p = new Product(i);
			s.push(p);
			System.out.println("Producer push Product  id:" + p.id);
			
			try {
				Thread.sleep((int)(Math.random() * 1000));
			} catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}


class Consumer implements Runnable
{
	Space s = null;
	Consumer(Space s)
	{
		this.s = s;
	}
	
	public void run()
	{
		for(int i = 0; i < 20; i++)
		{
			Product p = s.pop();
			System.out.println("Consumer pop Product  id:" + p.id);
			
			try {
				Thread.sleep((int)(Math.random() * 1000));
			} catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
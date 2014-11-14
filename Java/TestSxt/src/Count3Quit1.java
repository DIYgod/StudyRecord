/*
 * Êý3ÍË1
 */
public class Count3Quit1 {
	public static void main(String[] args)
	{
		KidCircle kc = new KidCircle(500);
		int countNum = 0;
		Kid k = kc.first;
		while(kc.count > 1)
		{
			countNum++;
			if(countNum == 3)
			{
				countNum = 0;
				kc.delete(k);
			}
			k = k.right;
		}
		System.out.println(kc.first.id);
	}
}

class Kid
{
	int id;
	Kid left;
	Kid right;
}

class KidCircle
{
	int count = 0;
	Kid first;
	Kid last;
	
	KidCircle(int n)
	{
		int i;
		for(i = 0; i < n; i++)
		{
			add();
		}
	}
	
	void add()
	{
		Kid k = new Kid();
		k.id = count;
		if(count <= 0)
		{
			first = k;
			last = k;
			k.left = k;
			k.right = k;
		}
		else
		{
			last.right = k;
			k.left = last;
			first.left = k;
			k.right = first;
			last = k;
		}
		count++;
	}
	
	void delete(Kid k)
	{
		if(count <= 0)
		{
			System.out.println("Fuck! No kid!");
			return;
		}
		else if(count == 1)
		{
			first = null;
			last = null;
			count --;
		}
		else
		{
			k.left.right = k.right;
			k.right.left = k.left;
			count --;
			if(k == first)
			{
				first = k.right;
			}
			else if(k == last)
			{
				last = k.left;
			}
		}
	}
	
}
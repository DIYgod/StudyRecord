import java.io.File;

public class ShowDir
{
	public static void main(String[] args)
	{
		String separator = File.separator;
		String directory = "D:" + separator + "A";
		File f = new File(directory);
		show(f);
	}
	
	public static void show(File f)
	{
		System.out.print(f.getName());
		if(f.isDirectory())
		{
			File[] childs = f.listFiles();
			int i;
			System.out.print("(");
			for(i = 0; i <childs.length; i++)
			{
				System.out.print(" ");
				show(childs[i]);
				System.out.print(" ");
			}
			System.out.print(")");
		}
	}
}
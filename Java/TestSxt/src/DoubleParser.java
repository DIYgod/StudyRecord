public class DoubleParser {
	public static void main (String[] args)
	{
		String st = "1,2;3,4,5;6,7,8";
		String[] s1 = st.split(";");
		int i, j;
		double[][] doubleAr = new double[s1.length][];
		
		for(i = 0; i < s1.length; i++)
		{
			String[] s2 = s1[i].split(",");
			doubleAr[i] = new double[s2.length];
			for(j = 0; j < s2.length; j++)
			{
				doubleAr[i][j] = Double.parseDouble(s2[j]);
			}
		}
		
		for(i = 0; i < doubleAr.length; i++)
		{
			for(j = 0; j < doubleAr[i].length; j++)
				System.out.print(doubleAr[i][j] + " ");
			System.out.println();
		}
	}
}
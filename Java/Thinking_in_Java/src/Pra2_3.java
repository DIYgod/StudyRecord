
public class Pra2_3 {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
      class ATypeName {
    	  int a;
    	  double b;
    	  boolean c;
    	  void show() {
    		  System.out.println(a);
    		  System.out.println(b);
    		  System.out.print(c);
    	  }
      }
      ATypeName test = new ATypeName();
      test.a = 9;
      test.b = 9.9;
      test.c = true;
      test.show();
	}

}

public class StorageTest {
	public static void main(String[] args) {
	  class Store {
        int storage(String s) {
    	  return s.length() * 2;
        }
      }
      Store Test = new Store();
      System.out.println(Test.storage("Anotherhome"));
    }
}

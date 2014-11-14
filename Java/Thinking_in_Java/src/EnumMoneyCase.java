
public class EnumMoneyCase {
	public enum Emoney {
		ONE, FIVE, TEN, TWENTY, FIFTY, HUNDRED
	}
	Emoney value;
	public EnumMoneyCase(Emoney value) {this.value = value;}
	public void describe() {
		System.out.print("The value is ");
		switch(value) {
		case ONE:     System.out.println("1");
		              break;
		case FIVE:    System.out.println("5");
		              break;
		case TEN:     System.out.println("10");
		              break;
		case TWENTY:  System.out.println("20");
		              break;
		case FIFTY:   System.out.println("50");
		              break;
		case HUNDRED: System.out.println("100");
		              break;
		}
	}
	
	public static void main(String[] args) {
		EnumMoneyCase mine = new EnumMoneyCase(Emoney.TEN);
		mine.describe();
	}
}

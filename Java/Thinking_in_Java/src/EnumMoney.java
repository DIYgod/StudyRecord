
public class EnumMoney {
	public enum Emoney {
		ONE, FIVE, TEN, TWENTY, FIFTY, HUNDRED
	}
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		for(Emoney money : Emoney.values())
			System.out.println(money + ".ordinary" + money.ordinal());
	}

}

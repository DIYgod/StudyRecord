class Dog {
	String name;
	String says;
}
public class DogTest {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Dog d1 = new Dog();
		Dog d2 = new Dog();
		d1.name = "spot";
		d1.says = "Ruff!";
		d2.name = "scruffy";
		d2.says = "Wurf!";
		System.out.println(d1.name + ":" + d1.says +";" + d2.name + ":" + d2.says);
		Dog d3 = new Dog();
		d3.name = "spot";
		d3.says = "Ruff!";
		System.out.println(d3 == d1);
		System.out.println(d3.equals(d1));

	}

}

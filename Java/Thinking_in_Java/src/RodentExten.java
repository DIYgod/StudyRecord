class Rodent {
	void eat() {
		System.out.println("Rodent eat");
	}
}
class Mouse extends Rodent {
	void eat() {
		System.out.println("Mouse eat");
	}
}
class Gerbil extends Rodent {
	void eat() {
		System.out.println("Gerbil eat");
	}
}
class Hamster extends Gerbil {
	void eat() {
		System.out.println("Hamster eat");
	}
}

public class RodentExten {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Rodent [] Rodents = {
				new Mouse(),
				new Gerbil(),
				new Hamster(),
		};
		for(Rodent i : Rodents) {
			i.eat();
		}

	}

}

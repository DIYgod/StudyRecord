import another.Animal;

class Pig implements Animal {
	public void eat(String food) {
		System.out.println("pig eat " + food);
	}
	public void move() {
		System.out.println("pig move");
	}
	public void say() {
		System.out.println("Hehe!");
	}
}

class Doge implements Animal {
	public void eat(String food) {
		System.out.println("dog eat " + food);
	}
	public void move() {
		System.out.println("dog move");
	}
	public void say() {
		System.out.println("Wowo!");
	}
}

public class Animals {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Pig Tom = new Pig();
		Doge Marry = new Doge();
		Tom.eat("grass");
		Tom.move();
		Tom.say();
		Marry.eat("Shit");
		Marry.move();
		Marry.say();

	}

}

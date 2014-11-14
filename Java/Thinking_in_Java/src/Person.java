public class Person {
	int id;
	int age = 20;
	
	Person(int _id, int _age) {
		id = _id;
		age = _age;
	}
	
	public static void main(String[] args) {
		Person tom = new Person(1, 19);
		System.out.println("tom.id: " + tom.id + ", tom.age: "+ tom.age);
	}
}
//: reusing/Detergent.java
// Inheritance syntax & properties.

class Cleanse {
  private String s = "Cleanser";
  public void append(String a) { s += a; }
  public void dilute() { append(" dilute()"); }
  public void apply() { append(" apply()"); }
  public void scrub() { append(" scrub()"); }
  public String toString() { return s; }
  public static void main(String[] args) {
    Cleanse x = new Cleanse();
    x.dilute(); x.apply(); x.scrub();
    System.out.println(x);
  }
}	

public class DelegationDetergent {
  // Change a method:
	Cleanse c = new Cleanse();
	private String s = "Cleanser";
	public void append(String a) {
		c.append(a);
	}
	public void dilute() {
		c.dilute();
	}
	public void apply() {
		c.apply();
	}
	public String toString() {
		return c.toString();
	}

  public void scrub() {
    append(" Detergent.scrub()");
    c.scrub(); // Call base-class version
  }
  // Add methods to the interface:
  public void foam() { append(" foam()"); }
  // Test the new class:
  public static void main(String[] args) {
    Detergent x = new Detergent();
    x.dilute();
    x.apply();
    x.scrub();
    x.foam();
    System.out.println(x);
    System.out.println("Testing base class:");
    Cleanser.main(args);
  }	
} /* Output:
Cleanser dilute() apply() Detergent.scrub() scrub() foam()
Testing base class:
Cleanser dilute() apply() scrub()
*///:~

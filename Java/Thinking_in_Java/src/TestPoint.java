class Point {
	double x, y, z;
	
	Point(double _x, double _y, double _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	
	void setX(double _x) {
		x = _x;
	}
	
	void setY(double _y) {
		y = _y;
	}
	
	void setZ(double _z) {
		z = _z;
	}
	
	double getDistance() {
		return ((x * x) + (y * y) + (z * z));
	}
}

public class TestPoint {
	
	public static void main(String[] args){
		Point p = new Point(1.0, 2.0, 3.0);
		p.setX(2.0);
		System.out.println(p.getDistance());
	}
}
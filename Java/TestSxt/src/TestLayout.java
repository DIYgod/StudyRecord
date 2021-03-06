import java.awt.*;

public class TestLayout {
	public static void main(String[] args)
	{
		Frame f = new Frame("TestLayout");
		f.setLayout(new GridLayout(2, 1));
		
		Panel p1 = new Panel(new BorderLayout());
		p1.add(new Button("B11"), BorderLayout.WEST);
		p1.add(new Button("B13"), BorderLayout.EAST);
		Panel p12 = new Panel(new GridLayout(2, 1));
		p12.add(new Button("B121"));
		p12.add(new Button("B122"));
		p1.add(p12, BorderLayout.CENTER);
		
		Panel p2 = new Panel(new BorderLayout());
		p2.add(new Button("B21"), BorderLayout.WEST);
		p2.add(new Button("B23"), BorderLayout.EAST);
		Panel p22 = new Panel(new GridLayout(2, 2));
		p22.add(new Button("B2211"));
		p22.add(new Button("B2212"));
		p22.add(new Button("B2221"));
		p22.add(new Button("B2222"));
		p2.add(p22, BorderLayout.CENTER);
		
		f.add(p1);
		f.add(p2);
		f.pack();
		f.setVisible(true);
	}
}

import java.awt.*;

public class TestFrame {
	@SuppressWarnings("unused")
	public static void main(String[] args)
	{
		iFrame f1 = new iFrame(100, 100, 100, 100, Color.orange, "L");
		iFrame f2 = new iFrame(200, 100, 100, 100, Color.blue, "o");
		iFrame f3 = new iFrame(100, 200, 100, 100, Color.gray, "k");
		iFrame f4 = new iFrame(200, 200, 100, 100, Color.red, "i");
	}
}

@SuppressWarnings("serial")
class iFrame extends Frame
{
	iFrame(int x, int y, int w, int h, Color c, String name)
	{
		super(name);
		setBounds(x, y, w, h);
		setBackground(c);
		setLayout(new FlowLayout());
		add(new Button("Another"));
		add(new Button("home"));
		setVisible(true);
	}
}
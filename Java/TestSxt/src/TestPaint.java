import java.awt.*;

public class TestPaint {
	public static void main(String[] args)
	{
		new PaintLollipops().launchFrame();
	}
}

@SuppressWarnings("serial")
class PaintLollipops extends Frame
{
	public void launchFrame()
	{
		setBounds(400, 200, 400, 300);
		setVisible(true);
	}
	
	public void paint(Graphics g)
	{
		Color c = g.getColor();
		g.setColor(new Color(217, 92, 92));
		g.fillOval(150, 50, 100, 100);
		g.drawLine(200, 150, 200, 250);
		g.setColor(c);
	}
}
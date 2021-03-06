import java.awt.*;

public class TestPanel {
	public static void main(String[] args)
	{
		new PanelCenter("Anotherhome", 400, 300, 400, 300, Color.orange, Color.gray);
	}
}


@SuppressWarnings("serial")
class PanelCenter extends Frame
{
	private Panel p = new Panel();
	PanelCenter(String name, int x, int y, int w, int h, Color framecolor, Color panelcolor)
	{
		super(name);
		setLayout(null);
		p.setBounds(3 * w / 8, 3 * h / 8, w / 4, h / 4);
		p.setBackground(panelcolor);
		add(p);
		setBounds(x, y, w, h);
		setBackground(framecolor);
		setVisible(true);
	}
}
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class PaintPoint {
	public static void main(String[] args)
	{
		new PaintPointFrame("Anotherhome");
	}
}

@SuppressWarnings("serial")
class PaintPointFrame extends Frame
{
	ArrayList<Point> points = new ArrayList<Point>();
	PaintPointFrame(String s)
	{
		super(s);
		addMouseListener(new PaintPointMouseMonitor());
		addWindowListener(new PaintPointWindowMonitor());
		/*addWindowListener(											//匿名类
				new WindowAdapter()
				{
					public void windowClosing(WindowEvent e)
					{
						System.exit(0);
					}
				}
		);
		*/
		
		setBackground(new Color(217, 92, 92));
		setBounds(400, 200, 400, 300);
		setVisible(true);
	}
	
	public void paint(Graphics g)
	{
		Iterator<Point> i = points.iterator();
		while(i.hasNext()	)
		{
			Point p = i.next();
			g.setColor(Color.black);
			g.fillOval(p.x, p.y, 5, 5);
		}
	}
	
	class PaintPointMouseMonitor extends MouseAdapter
	{
		public void mousePressed(MouseEvent e)
		{
			points.add(new Point(e.getX(), e.getY()));
			repaint();
		}
	}
	
	class PaintPointWindowMonitor extends WindowAdapter
	{
		public void windowClosing(WindowEvent e)
		{
			System.exit(0);
		}
	}
}
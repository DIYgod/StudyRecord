import java.awt.*;
import java.awt.event.*;

public class TextFieldCalculator {
	public static void main(String[] args)
	{
		new Calculator().LaunchFrame();
	}
}

@SuppressWarnings("serial")
class Calculator extends Frame
{
	TextField tf1;
	TextField tf2;
	TextField tf3;
	public void LaunchFrame()
	{
		tf1 = new TextField(10);
		tf2 = new TextField(10);
		tf3 = new TextField(15);
		Label l = new Label("+");
		Button b = new Button("=");
		b.addActionListener(new CalculatorMonitor());
		setLayout(new FlowLayout());
		add(tf1);
		add(l);
		add(tf2);
		add(b);
		add(tf3);
		pack();
		setVisible(true);
	}
	
	class CalculatorMonitor implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			int num1 = Integer.parseInt(tf1.getText());
			int num2 = Integer.parseInt(tf2.getText());
			tf3.setText(" " + (num1 + num2));
		}
	}
}
/*
class CalculatorMonitor implements ActionListener
{
	Calculator c = null;
	public CalculatorMonitor(Calculator c)
	{
		this.c = c;
	}
	
	public void actionPerformed(ActionEvent e)
	{
		int num1 = Integer.parseInt(c.tf1.getText());
		int num2 = Integer.parseInt(c.tf2.getText());
		c.tf3.setText(" " + (num1 + num2));
	}
}
*/
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Calculator extends JFrame implements ActionListener {
	JPanel[] row = new JPanel[5];
	JButton[] button = new JButton[19];
	String[] buttonString = {"7","8","9","+",
							 "4","5","6","-",
							 "1","2","3","*",
							 ".","/","C","√",
							 "+/-","=","0"};
	int[] dimW = {300,45,100,90};
	int[] dimH = {35,40};
	Dimension displayDimension = new Dimension(dimW[0], dimH[0]);
	Dimension regularDimension = new Dimension(dimW[1], dimH[1]);
	Dimension rColumnDimension = new Dimension(dimW[2], dimH[1]);
	Dimension zeroButDimension = new Dimension(dimW[3], dimH[1]);
	boolean[] function = new boolean [4];
	double[] temporary = {0,0};
	JTextArea display = new JTextArea(1,20);
	Font font = new Font("Times New Roman", Font.BOLD,14);
	
	Calculator(){
		super("Calcs");
		setDesign();
		setSize(380, 250);
		setResizable(false);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		GridLayout grid = new GridLayout(5,5);
		setLayout(grid);
		for(int i=0; i < 4;i++){
			function[i]=false;
		}
		FlowLayout f1 = new FlowLayout(FlowLayout.CENTER);
		FlowLayout f2 = new FlowLayout(FlowLayout.CENTER, 1, 1);
		
		for (int i = 0; i < 5; i++){
			row[i] = new JPanel();
		}
		
		row[0].setLayout(f1);

		for (int i = 1; i < 5; i++){
			row[i].setLayout(f2);
		}

		for (int i =0; i < 19; i++){
			button[i] = new JButton();
			button[i].setText(buttonString[i]);
			button[i].setFont(font);
			button[i].addActionListener(this);
		}

		display.setFont(font);
		display.setEditable(false);
		display.setComponentOrientation(ComponentOrientation.RIGHT_TO_LEFT);

		display.setPreferredSize(displayDimension);

		for(int i = 0; i < 14; i++){
    		button[i].setPreferredSize(regularDimension);
    	}
		for(int i = 14; i < 18; i++){
    		button[i].setPreferredSize(rColumnDimension);
		}
		button[18].setPreferredSize(zeroButDimension);

		row[0].add(display);
		add(row[0]);

		for(int i=0; i < 4; i++){
			row[1].add(button[i]);
		}
		row[1].add(button[14]);
		add(row[1]);
		for(int i=0; i < 8; i++){
			row[2].add(button[i]);
		}
		row[2].add(button[14]);
		add(row[2]);
		for(int i=0; i < 12; i++){
			row[3].add(button[i]);
		}
		row[3].add(button[14]);
		add(row[3]);
		for(int i=0; i < 18; i++){
			row[4].add(button[i]);
		}
		row[4].add(button[14]);
		add(row[4]);

		setVisible(true);

	}

	public final void setDesign(){
		try{
			UIManager.setLookAndFeel(
				"com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
		} catch(Exception e){

		}
	}

	public void actionPerformed(ActionEvent ae){

	}
	

	public static void main(String[] arguments){
		Calculator c = new Calculator();
	}
	
}
/* Text editor. And java learn stuff */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

    public class frame extends Frame implements WindowListener{
        private JTextField text;
        private JTextArea boxes;
        private Label saveTitle;
        private JButton b;
        private JButton op;
        private JButton obj;
        private File file;
        private int numClicks = 0;

        public frame(String title) {
                super(title);
		        setDesign();



                JTextField text = new JTextField(20);
                text.setBounds(110,760,100,25);

                JTextArea boxes = new JTextArea("", 40, 75);
                boxes.setBounds(10,50,780,700);

                saveTitle = new Label("File Name");
                saveTitle.setBounds(10,760,100,18);

                JButton b = new JButton("Save");
                b.setBounds(210,760,60,18);
                
                JButton op = new JButton("Open");
                op.setBounds(310,760,60,18);

                JButton obj = new JButton("Button");
                obj.setBounds(410,760,100,18);

                addWindowListener(this);
                add(saveTitle);
                add(text);
                add(b);
                add(op);
                add(obj);
                add(boxes);
                b.addActionListener(new ActionListener(){
                   public void actionPerformed(ActionEvent event){
                       String content = boxes.getText();
                       String filename = text.getText();
                       save(content,filename);
                   }
                });
                op.addActionListener(new ActionListener(){
                   public void actionPerformed(ActionEvent event){
                       open();
                   }
                });
                obj.addActionListener(new ActionListener(){
                   public void actionPerformed(ActionEvent event){
                       herro();
                   }
                });
        }

        public static void setGUI(){
            frame myWindow = new frame("Dat Text Edit");
            myWindow.setSize(800,800);
            myWindow.setLayout(null);
            myWindow.setVisible(true);
            
        }
        public final void setDesign(){
            try{
                UIManager.setLookAndFeel(
                    "com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
            } catch(Exception e){

            }
	    }


        public static void main(String[] args) throws FileNotFoundException{
        	setGUI();
        }

        
        /*
            Writing to File. Make it do more

        */

        public void save(String content, String filename){
        	//File file = new File (text.getText()+".txt");
        	File file = new File (filename + ".txt");
           try
    		{
        		PrintWriter printWriter = new PrintWriter(file);
                //printWriter.println (text.getText());
        		printWriter.print(content);
                printWriter.close(); 
        		System.out.print("Written");      
    		}
    			catch (FileNotFoundException ex){
                    System.out.println("Failed to Save");
			}
		}
		

        public void windowClosing(WindowEvent e) {
                dispose();
                System.exit(0);
        }
        public void write(){

        }

        public void windowOpened(WindowEvent e) {}
        public void windowActivated(WindowEvent e) {}
        public void windowIconified(WindowEvent e) {}
        public void windowDeiconified(WindowEvent e) {}
        public void windowDeactivated(WindowEvent e) {}
        public void windowClosed(WindowEvent e) {} 

    /* Button needs ActionListener Object to do certain things.*/ 
        public void herro(){
            System.out.println("Hello World");
        }

    /* This is the "Open" button actions. Find out how to make it into another file. Seem to be having trouble. */
        public void open(){
            System.out.println("Opened");
        }

}


// import javax.swing.*;
// import javax.swing.JFrame;
// import java.util.*;
// import java.awt.*;
// import java.awt.event.*;

	 
// public class frame {
	
// 	public static void main(String args[]){
// 		JFrame wframe = new JFrame("Bitch");
// 		wframe.setBounds(50,50,300,200);
// 		wframe.setLayout(null);
// 		wframe.setBackground(Color.white);
// 		wframe.setVisible(true);
// 		JLabel label = new JLabel("Text-Only Label");
// 		wframe.add(label);
		
// 		wframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
// 		JButton fooBtn = new JButton("Do Foo");
//       	fooBtn.addActionListener(new ActionListener() {
//         	public void actionPerformed(ActionEvent e) {
//             	System.out.println("Herro Wourd!");
//          	}
//       });
//       wframe.add(fooBtn);
// 	}
// }

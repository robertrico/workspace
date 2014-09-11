import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class MyAction implements ActionListener{

       
        public MyAction{
            testImport test = new testImport();
        }
        public actionPerformed(ActionEvent ae){
            
            testImport test = new testImport();
            System.out.println(test.add(4,5));
        }


    }

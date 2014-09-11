/* Class ID: 1286; CSC-15; Project 3 */
/* This project uses an input file */
/* and computes statistics using the numbers */
/* found in the file.*/

package proj3;                                                                   
import java.util.*;
import java.io.*;
public class fileCalc {

	public static void main(String[] args)
				throws FileNotFoundException {
		boolean quest = true; // boolean to prevent incorrect input in text vs screen
		Scanner console = new Scanner(System.in);
		System.out.print("Excluding the file type, ");
		System.out.println("Enter the name of the file to be read: ");
		String fileName = console.next();
		Scanner fileIn = new Scanner(new File(fileName + ".txt"));
		System.out.println("File Name: "+fileName+".txt");
		InputCalc calc = new InputCalc(); // New Calculator Object
		double[] inNum = new double[(int)fileIn.nextDouble()]; //Creates array
		System.out.println("There are "+inNum.length+ " numbers in the file");
		for (int i=0;i<inNum.length;i++){ //creates an array from data file       
			inNum[i]=fileIn.nextDouble();
		}	
		while (quest == true){
			System.out.println("Do you want to print to file, or screen?");
			String choice=console.next();
			if (choice.equalsIgnoreCase("screen")){
				System.out.println("Input File Statistics");                         
				System.out.println("The Mean is: "+ calc.getMean(inNum));
				System.out.println("The Median is: "+ calc.getMedian(inNum));
				System.out.println("The Maximum is: "+ calc.getMax(inNum));
				System.out.println("The Minimum is: " + calc.getMin(inNum));
				System.out.println("The Mode is: " + calc.getMode(inNum));
				System.out.println("The Standard Deviation is: " 
				                                     + calc.getStDev(inNum));
				quest = false;
			}
			else if (choice.equalsIgnoreCase("file")){
				System.out.println("Name the output file. (Exclude File Type)");
				String outFi = console.next();
				PrintStream fileOut = new PrintStream (new File(outFi+".txt"));
				fileOut.println("The input statistics are:");
				fileOut.println("The Mean is: "+ calc.getMean(inNum));
				fileOut.println("The Median is: "+ calc.getMedian(inNum));
				fileOut.println("The Maximum is: " + calc.getMax(inNum));
				fileOut.println("The Minimum is: " + calc.getMin(inNum));
				fileOut.println("The Mode is: " + calc.getMode(inNum));
				fileOut.println("The Standard Deviation is: " 
                                                 + calc.getStDev(inNum));
				System.out.println("Data Written to \""+outFi+".txt\".");
				quest = false;
				fileOut.close();
			}
			else {
				System.out.println("Invalid Input");
			}
		}
		fileIn.close();
		console.close();
	}

}

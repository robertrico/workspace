import java.util.*;
import java.io.*;
public class testObjs {

	public static void main(String[] args){
        Scanner console = new Scanner(System.in);
	    testImport test = new testImport();
        test.print("Say what you have to say");
        test.print(console.nextLine());
        System.out.print("Enter two numbers to be added\n");
        System.out.print(test.add(console.nextInt(),console.nextInt()));



    }

}

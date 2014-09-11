import java.util.*;
import java.io.*;

public class Dictionary{
    public static void main(String[] args)throws FileNotFoundException{
        Scanner input = new Scanner(System.in);
        DiscreteDefinitions definitions = new DiscreteDefinitions(input);
        greeting();
        String ans = "";
        while (!ans.equalsIgnoreCase("quit")){
            System.out.println("\n");
            System.out.println("Enter a word to be defined: ");
            ans = input.nextLine();
            if (ans.equalsIgnoreCase("quit") || ans.equalsIgnoreCase("q")){
               definitions.quit();
            } 
            definitions.define(ans,input);
        }
    }

    public static void greeting(){
        System.out.println("\n");
        System.out.println("*++----------------------------------------++*");
        System.out.println("Welcome to the Discrete Structures dictionary.");
        System.out.println("\n");
        System.out.println("Enter a word for it's definition");
        System.out.println("\n");
        System.out.println("To quit type \"quit\" or \"q\" at anytime.");
        /*System.out.println("");
        System.out.println("");
        System.out.println("");*/
        System.out.println("*++----------------------------------------++*");
    }
    
    public void quit(){
        System.out.println("\n");
        System.out.println("**************");
        System.out.println("Program Closed");
        System.out.println("**************");
        System.exit(0);
    }

}

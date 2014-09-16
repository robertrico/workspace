import java.util.*;
import java.io.*;

public class Dictionary{
    public static void main(String[] args)throws FileNotFoundException{
        Scanner input = new Scanner(System.in);
        DiscreteDefinitions definitions = new DiscreteDefinitions(input);
        greeting();
        definitions.define(input);
    }

    public static void greeting(){
        System.out.println("\n");
        System.out.println("************************************************");
        System.out.println("************************************************");
        System.out.println("**************--Welcome to the--****************");
        System.out.println("*******--Discrete Structures Dictionary--*******");
        System.out.println("************************************************");
        System.out.println("*****--Enter a word for it's definition--*******");
        System.out.println("*****--To see the wordbank enter \"/bank\"--******");
        System.out.println("************************************************");
        System.out.println("***--To quit type /quit or /q at anytime.--*****");
        System.out.println("****--For the help menu, type /help or /?--*****");
        System.out.println("************************************************");
        System.out.println("*********************************--Written By--*");
        System.out.println("********************************--Robert Rico--*");
        System.out.println("************************************************");
    }
    
    public void quit(){
        System.out.println("\n");
        System.out.println("**************");
        System.out.println("Program Closed");
        System.out.println("**************");
        System.exit(0);
        //Update Comment
    }

}

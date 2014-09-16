import java.util.*;
import java.io.*;
public class CompArc{
    public static void main(String[] args){
        /*Create the Conversion object*/
        //TODO fix binary converter and eliminate reduncancies
        Scanner input = new Scanner(System.in);
        System.out.println("What would you like to convert? (Hex, Decimal)");
        String choice = input.nextLine();
        if (choice.equals("quit")  || choice.equals("q")){
            quit();
        }
        while (choice.equalsIgnoreCase("decimal") || choice.equalsIgnoreCase("hex")){
            if (choice.equalsIgnoreCase("decimal")){
                convertBin(input);
            }
            else{
                convertHex(input);
            }
        }
    }  
    public static void convertBin(Scanner input){
        BinaryToDecimal convert = new BinaryToDecimal();
        /* Calls the converter with the passed string*/
        System.out.println("Enter a 16-bit Binary Integer to be converted.");
        String binary = (input.nextLine());
        if (binary.equals("quit")  || binary.equals("q")){
            quit();
        }
        while (binary.length() > 16 || binary.length() < 16 ){
            System.out.println("Binary Integer is larger than 16-bits, re-enter a Binary Integer to be converted.");
            binary = (input.nextLine());
            convert.convertFromBinary(binary);
        }
        convert.convertFromBinary(binary);
    }
    public static void convertHex(Scanner input){
        HexToDecimal hexconvert = new HexToDecimal();
        /* Calls the converter with the passed string*/
        System.out.println("Enter a 32-bit Hexdecimal Integer to be converted.");

        String hex = (input.nextLine());
        if (hex.equals("quit")  || hex.equals("q")){
            quit();
        }

        /*while (binary.length() > 16 || binary.length() < 16 ){
            System.out.println("Binary Integer is larger than 16-bits, re-enter a Binary Integer to be converted.");
            binary = (input.nextLine());
            convert.convertFromBinary(binary);
        }*/
        //convert.convertFromBinary(binary);
        hexconvert.convertFromHex(hex);
    }
    
    public static void quit(){
        System.out.println("\n");
        System.out.println("**************");
        System.out.println("Program Closed");
        System.out.println("**************");
        System.exit(0);
        //Update Comment
    }





}

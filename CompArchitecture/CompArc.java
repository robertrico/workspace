import java.util.*;
import java.io.*;
public class CompArc{
    public static void main(String[] args){
        /*Create the Conversion object*/
        BinaryToDecimal convert = new BinaryToDecimal();
        HexToDecimal hexconvert = new HexToDecimal();
        Scanner input = new Scanner(System.in);
        /* Calls the converter with the passed string*/
        System.out.println("Enter a 16-bit Binary Integer to be converted.");

        String binary = (input.nextLine());
        while (binary.length() > 16 || binary.length() < 16 ){
            System.out.println("Binary Integer is larger than 16-bits, re-enter a Binary Integer to be converted.");
            binary = (input.nextLine());
            convert.convertFromBinary(binary);
        }
        convert.convertFromBinary(binary);
        //hexconvert.convertFromHex("A");



    }




}

import java.io.*;
import java.util.*;
import java.util.Arrays;

public class DiscreteDefinitions extends Dictionary{
    private String word;
    private String definitions[];
    private String bank[];
    private Scanner input;
    public DiscreteDefinitions(Scanner input) throws FileNotFoundException{
        //bank = new String[] {"sets","sequence"};
        Scanner fileIn = new Scanner(new File("wordbank.ref"));
        this.bank = new String[fileIn.nextInt()];
        fileIn.nextLine();
        definitions = new String[bank.length];
        for (int i=0;i<bank.length;i++){ //creates an array from data file       
			bank[i]=fileIn.nextLine().toLowerCase();
            System.out.println(bank[i]);
			definitions[i]=fileIn.nextLine();
		}
    }
    
    public void define(String word, Scanner input){
        if (word.equalsIgnoreCase("quit")){
            quit();
        }
        String symbol = "";
        //System.out.println(word);
        //word = word.replaceAll("\\s","");
        //System.out.println(word);
        int indice = Arrays.asList(this.bank).indexOf(word.toLowerCase());
        if (indice == -1){
            System.out.println("Not found, please check your spelling or add word to bank.");
            System.out.println("Enter a word to be defined: ");
            define(input.nextLine(),input);
            return;
        }

        /* Need a gracefull fail system 
         * Also, apply more symbols*/
        if (word.equals("intersection")){
            symbol = "Denoted with \"\u2229";
        }
        System.out.println("\n");
        System.out.println(bank[indice]);
        System.out.println("----------------------");
        System.out.println(symbol+definitions[indice]);
        
        
    }

       
    
    




}

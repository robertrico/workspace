import java.io.*;
import java.util.*;
import java.util.Arrays;

public class Definitions extends Dictionary{
    private String word;
    private String definitions[];
    private String helpDef[];
    private String bank[];
    private String help[];
    private Scanner input;
    private String wordbank;

    public Definitions(Scanner input,String filename) throws FileNotFoundException{

        wordbank = filename;
        /* The Help has to be first in order for it to 
         * properly assign the actual wordbank.
         * Need to test with new word bank
         */
        String [][] helpArrs = buildDefinitionsArray("help");
        this.help = helpArrs[0];
        this.helpDef = helpArrs[1];
        /* Possible reduncancy reduction */
        String [][] defArr = buildDefinitionsArray(filename);
        this.bank = defArr[0];
        this.definitions = defArr[1]; 
    }

    public String[][] buildDefinitionsArray(String filename) throws FileNotFoundException{
        Scanner fileIn = new Scanner(new File(filename+".ref"));
        this.bank = new String[fileIn.nextInt()];
        definitions = new String[bank.length];
        fileIn.nextLine();
        for (int i=0;i<bank.length;i++){ //creates an array from data file       
			bank[i]=fileIn.nextLine().toLowerCase();
            //System.out.println(bank[i]);
			definitions[i]=fileIn.nextLine();
		}
        // Create an array of arrays for assignments
        String[][] bigArr = new String[][] {bank,definitions};
        return bigArr;
    } 

    public void define(Scanner input){
        System.out.println("\n");
        System.out.println("Enter a word from the wordbank "+wordbank+" to be defined: ");
        String word = input.nextLine();
        this.action(word,input);
        int indice = Arrays.asList(this.bank).indexOf(word.toLowerCase());
        if (indice == -1){
            System.out.println("\n");
            System.out.println("Not found, please check your spelling or add word to bank.");
            define(input);
        }

        System.out.println("\n");
        System.out.println(bank[indice]);
        System.out.println("----------------------");
        System.out.println(definitions[indice]);
        define(input);
        
        
    }

    public  void getBank(){
        System.out.println("\n");
        System.out.println("----------------------");
        System.out.println("------WORD BANK------");
        System.out.println("----------------------");
        for (int i=0;i<bank.length;i++){        
            System.out.println(bank[i]);
		}
    }

    public void getHelp(){
        System.out.println("\n");
        System.out.println("----------------------");
        System.out.println("---------HELP---------");
        System.out.println("----------------------");

        for (int i=0;i<help.length;i++){        
            System.out.println(help[i]);
		}
    }
    public void helpDefine(String word, Scanner input){
        action(word, input);
        int indice = Arrays.asList(this.help).indexOf(word.toLowerCase());
        if (indice == -1){
            System.out.println("\n");
            System.out.println("Not found, please check your spelling or add word to bank.");
            System.out.println("Enter a help function to be defined: ");
            helpDefine(input.nextLine(),input);
        }

        System.out.println("\n");
        System.out.println(help[indice]);
        System.out.println("----------------------");
        System.out.println(helpDef[indice]);
    }

    public void action(String word,Scanner input){
        if (word.equalsIgnoreCase("/switch") || word.equalsIgnoreCase("/s")){
            try
            {
                super.chooseBank();
            }
            catch (FileNotFoundException e)
           {
            // Handle the exception
           }
        }
        if (word.equalsIgnoreCase("/quit") || word.equalsIgnoreCase("/q")){
            quit();
        }
        if (word.equalsIgnoreCase("/bank")){
            getBank();
            define(input);
        }
        if (word.equalsIgnoreCase("/help") || word.equalsIgnoreCase("/?")){
            getHelp();
            System.out.println("\n");
            System.out.println("Enter a help function to be defined: ");
            helpDefine(input.nextLine(),input);
            define(input);
            //Update Comment
        }
       
    } 
    

}

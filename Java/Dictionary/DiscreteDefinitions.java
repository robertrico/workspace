import java.io.*;
import java.util.*;
import java.util.Arrays;

public class DiscreteDefinitions extends Dictionary{
    private String word;
    private String definitions[];
    private String helpDef[];
    private String bank[];
    private String help[];
    private Scanner input;

    public DiscreteDefinitions(Scanner input) throws FileNotFoundException{
        this.help = new String[] {"/quit","/help","/bank"};
        Scanner fileIn = new Scanner(new File("wordbank.ref"));
        Scanner helpFile = new Scanner(new File("help.ref"));
        this.bank = new String[fileIn.nextInt()];
        fileIn.nextLine();
        definitions = new String[bank.length];
        helpDef = new String[help.length];
        for (int i=0;i<bank.length;i++){ //creates an array from data file       
			bank[i]=fileIn.nextLine().toLowerCase();
            //System.out.println(bank[i]);
			definitions[i]=fileIn.nextLine();
		}
        this.help = new String[helpFile.nextInt()];
        helpFile.nextLine();
        for (int i=0;i<help.length;i++){ //creates an array from data file       
			help[i]=helpFile.nextLine().toLowerCase();
            //System.out.println(help[i]);
			helpDef[i]=helpFile.nextLine();
		}
    }
    
    public void define(String word, Scanner input){
        if (word.equalsIgnoreCase("/quit") || word.equalsIgnoreCase("/q")){
            //quit();
        }
        if (word.equalsIgnoreCase("/bank")){
            getBank();
            System.out.println("\n");
            System.out.println("Enter a word to be defined: ");
            define(input.nextLine(),input);
        }
        if (word.equalsIgnoreCase("/help") || word.equalsIgnoreCase("/?")){
            getHelp();
            System.out.println("\n");
            System.out.println("Enter a help function to be defined: ");
            helpDefine(input.nextLine(),input);
            return;
        }

        String symbol = "";
        //System.out.println(word);
        //word = word.replaceAll("\\s","");
        //System.out.println(word);
        int indice = Arrays.asList(this.bank).indexOf(word.toLowerCase());
        if (indice == -1){
            System.out.println("\n");
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
        if (word.equalsIgnoreCase("/quit")){
            //quit();
        }

        String symbol = "";
        int indice = Arrays.asList(this.help).indexOf(word.toLowerCase());
        if (indice == -1){
            System.out.println("\n");
            System.out.println("Not found, please check your spelling or add word to bank.");
            System.out.println("Enter a word to be defined: ");
            define(input.nextLine(),input);
            return;
        }

        System.out.println("\n");
        System.out.println(help[indice]);
        System.out.println("----------------------");
        System.out.println(helpDef[indice]);
        
        
    }

}

import java.util.*;
import java.io.*;

public class Dictionary{
    private String[] wordbanks;
    private Scanner input;
    public Dictionary(){
        wordbanks = new String[] {"","DiscreteMath","test"};
        input = new Scanner(System.in);
    }
    
    public void chooseBank()throws FileNotFoundException{
        System.out.println("\n");
        System.out.println("Choose a word bank");
        for (int i=1; i < wordbanks.length; i++){
            System.out.println( i + ":" + wordbanks[i]);
        }

        //User bank choice. See ReadMe.MD for wordbank format
        int choice = input.nextInt();
        while (choice <= 0 || choice > wordbanks.length-1){
            System.out.println("Not a choice");
            choice = input.nextInt();
        }

        
        // The following is to clear inputs line, so it isn't used
        // in the definitions class
        input.nextLine();
        Definitions discrete = new Definitions(input,wordbanks[choice]);
        discrete.define(input);

    }

    public void greeting(){
        System.out.println("\n");
        System.out.println("************************************************");
        System.out.println("************************************************");
        System.out.println("***************--Welcome to--*******************");
        System.out.println("*********--Robert's CSC Dictionay--*************");
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
       try
        {
            chooseBank();
        }
       catch (FileNotFoundException e)
       {
        // Handle the exception
       } 
    }
    
    public String[] getBanks(){
        return wordbanks;
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

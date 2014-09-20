/*#####Programming Project 2#######CSC15#####Spring#####2014#########3/26/2014#
#############################Written by: Class ID 1286#########################
#This program guesses a number and adjusts its guesses according to user input*/
import java.util.*;
public class proj2{
   public static final int RANGE=10; // number boundary
	public static void main(String[] args){
		Scanner console=new Scanner (System.in);
		Random f = new Random();
		int guess = f.nextInt(RANGE); //initial guess of half of range
		int gHi = RANGE; //upper bound
		int gLo = 0; //lower bound	
		int gCount=0; //Guess Counter
		boolean guessBool=false; //number guess boolean
		boolean boundBool=false; //boundary setting boolean
		boolean resBool=false; //reset boolean
		System.out.println("Think of a number between 0 and "+RANGE);
		while (guessBool != true ){
			if (resBool==true){ //Boolean if statement used to reset
				gHi=RANGE;
				gLo=0;
				gCount=0;
				guess=f.nextInt(RANGE);
				resBool=false;
			}
			guessBool = promptYN(console,false,"Is your number " + guess);
			boundBool = false;
			if (guessBool !=true){
				gCount++;
				System.out.println("Your number is " + guess + "!");
				System.out.println("It took me " + gCount + " guess[es]!");
				guessBool = reset(console,guessBool); //game reset
            resBool=true;           		 		
			}else if (guessBool ==true){
				gCount++;
				while (boundBool != true){
					boundBool=promptYN(console,false,"Is your number lower");
					if (boundBool==false){  
						gHi=guess-1;
						guessBool=lieCheck(console,guessBool,gLo,gHi);
						resBool=!guessBool;
						if (guessBool!=true){//breaks while loop in case of lie
							break;
						}
						guess=f.nextInt((gHi-gLo+1))+(gLo);
						guessBool = false;
						boundBool = true;             
					}else if (boundBool==true){ 
						gLo=guess+1;
						guessBool=lieCheck(console,guessBool,gLo,gHi);
						resBool=!guessBool;
						if (guessBool!=true){//breaks while loop in case of lie
							break; 
						}
						guess=f.nextInt((gHi-gLo+1))+(gLo);
						guessBool = false;
					} 				
				}
			}
		}		
	}
   public static boolean lieCheck(Scanner console,boolean c,int Lo, int Hi){
	   if (Lo>Hi){//if they are equal the player has lied
		   System.out.println("Your deceit is not welcome here!");
           c = reset(console,c); //game reset
       }
       return c;
   }

   public static boolean reset(Scanner console,boolean c){ //Game reset method
      c = promptYN(console,false,"Do you want to play again");
      if (c!=true){	
    	  System.out.println("Resetting Game...");
     }else if (c==true){System.exit(0);
     }
     return c;
   }
   public static boolean promptYN(Scanner console,boolean k,String q){
		boolean t = false;
		while (t != true){
			System.out.println(q+"?(Y/N)");
			String r = console.next();
			console.nextLine(); //clears buffer for more than one token
			if (r.equalsIgnoreCase("Y")||r.equalsIgnoreCase("yes")){
				k = false;
				t = true;
			}else if (r.equalsIgnoreCase("N")||r.equalsIgnoreCase("no")){
				k = true;
				t = true;
			}else {
				System.out.println("Please enter \"y\" ,\"yes\", \"n\" or \"no\""
										   + ".Capitalization does not matter."); 
				                   //robust else to defend against improper input  
			}			
		}
		return k;
	}	
}

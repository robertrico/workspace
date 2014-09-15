import java.util.Arrays;
public class HexToDecimal{
    /* Initiate Variables */
    /*hex[] stores the actual values i.i 16^0, 16^1,16^2..etc*/
    private String hex[];
    private int base_sixteen[];
    /*The String integer passed in to be converted*/
    private String integer;
    /*Constructor goodness*/
    public HexToDecimal(){
       hex = new String[] {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
       base_sixteen = new int[32];
       base_sixteen = buildHex();
       //letters = 
    }
    
    /*32-bit Base 16 values*/
    private int[] buildHex(){
        for (int i = 0; i <= 7; i++){
            this.base_sixteen[i] = power(16,i);
            System.out.println(base_sixteen[i]);
        }
        return base_sixteen;
    }
  
    /*Simple Value retrievers for testing.*/    
    public String getHex(int x){
        return this.hex[x];
    }
    public String getInt(){
        return this.integer;
    }

    /*TODO Make this work better. 32-bit = 0x0000000 not some 
     * crazy long number*/
    public void convertFromHex(String x){
        integer = x;
        String[] convert = this.integer.split("");
        convert = stringPop(convert);
        int converted = 0;
        for(int i = 0; i < x.length(); i++){
            
            //System.out.println(convert[i]);
            converted += (base_sixteen[Arrays.asList(hex).indexOf(convert[i])]);
            //System.out.println(base_sixteen[i]);
            //System.out.print(hex[i]);
        }
        System.out.println("\n");
        System.out.println("The Conversion for "+x+" is");
        System.out.println(converted);   
    } 
    public String[] stringPop(String[] array){
        String [] freshArray = new String [array.length];
        for (int i = 1; i < array.length; i++){
            freshArray[i-1]= array[i];
        }
        return freshArray;
    }









    /* Exponentential method*/
    private int power(int x, int y){
        if (y == 0){
            return 1;
        }
        int orig = x;
        for (int i = 1; i < y; i++){
            x *= orig;
        }
        return x;
    }

}

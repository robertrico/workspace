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
       // The Hex characters. With the index being its value
       hex = new String[] {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
       base_sixteen = new int[8];
       base_sixteen = buildHex();
    }
    
    /*32-bit Base 16 values*/
    private int[] buildHex(){
        for (int i = 0; i <= 7; i++){
            this.base_sixteen[i] = power(16,i);
            //System.out.println(base_sixteen[i]);
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

    public void convertFromHex(String x){
        if (x.length() > base_sixteen.length){
            System.out.println("This number is too large");
            return;
        }
        String[] convert = x.split("");
        // Takes off the first element
        // split adds an extra index at the beginning
        convert = stringPop(convert);
        //Flips the array.
        //i.e first element is last, and last is first
        convert = stringFlip(convert);
        int converted = 0;
        for(int i = 0; i < x.length(); i++){
            //System.out.println(convert[i]);
            //System.out.println(base_sixteen[i]);
            int index = Arrays.asList(hex).indexOf(convert[i]);
            if (index == -1){
                System.out.println("Hexdecimal character not found");
                return;
            }
            converted += (index * base_sixteen[i]);
            //System.out.print(hex[i]);
        }
        System.out.println("\n");
        System.out.println("The Conversion for "+x+" is");
        System.out.println(converted);   
    } 
    public String[] stringPop(String[] array){
        String [] freshArray = new String [array.length-1];
        for (int i = 1; i < array.length; i++){
            freshArray[i-1]= array[i];
        }
        return freshArray;
    }

    public String[] stringFlip(String[] array){
        String [] freshArray = new String [array.length];
        //System.out.println("Array Flip:");
        //System.out.println("Array length: "+array.length);
        //System.out.println("Arr:"+array[7]);
        /*This was a pain to write. Logic: Assign the 
         * first index of the new array the value of the 
         * length of the old array - 1, because of length
         * minus the iterator value*/
        for (int i = 0; i < array.length; i++){
            freshArray[i] = array[((array.length-1)-i)];
            //System.out.println(freshArray[i]);
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

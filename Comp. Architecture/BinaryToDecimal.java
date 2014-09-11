public class BinaryToDecimal{
    /* Initiate Variables */
    /*binary[] stores the actual values i.i 2^0, 2^1,2^2..etc*/
    private int binary[];
    /*The String integer passed in to be converted*/
    private String integer;
    /*Constructor goodness*/
    public BinaryToDecimal(){
       binary = new int[16];
       binary = buildBin(); 
    }
    
    /*Assign each index of binary[] to the appropriate value of base 2.*/
    private int[] buildBin(){
        for (int i = 0; i < 16; i++){
            binary[i] = power(2,i);
        }
        return binary;
    }
    
    /*Simple Value retrievers for testing.*/    
    public int getBin(int x){
        return this.binary[x];
    }
    public String getInt(){
        return this.integer;
    }
    /*The Conversion method
     * Reads in the string and breaks it apart into an array
     * traverses the array and looks for a "1", if it is flagged
     * it adds the value from the binary array to the conversion
     * variable */
    public void convertFromBinary(String x){
        integer = x;
        String[] convert = this.integer.split("");
        int converted = 0;
        for(int i = 15; i >= 0; i--){
           if(convert[i].equals("1")){
              converted += binary[15-i];
           } 
        }
        System.out.println("\n");
        System.out.println("The Conversion for "+x+" is");
        System.out.println(converted);   
    }
    
    /*Custom built power method. Instructions said to avoid Library functions such
     * as Math.pow(), etc.*/
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

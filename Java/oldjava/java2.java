public class java2 {
    public static void main(String[] args){
        Object hello = new Object("Hello World!");
        Object bye = new Object("Goodbye World!");
        hello.concatString(bye.getGreet());
        System.out.print(hello);
        //System.out.print(hello);
        //System.out.print(bye);
    
    }
}

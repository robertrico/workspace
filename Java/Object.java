public class Object{
    private String greeting;
    public Object(String greet){
        this.greeting = greet; 
    }
    public String toString(){
        return this.greeting+"\n";
    }
    public String getGreet(){
        return this.greeting;
    }
    public String concatString(String con){
        return this.greeting += " "+con;
    }



}

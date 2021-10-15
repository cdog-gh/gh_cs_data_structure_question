import java.util.*;
class myObj{
    private int x;
    public myObj(int x){
        this.x = x;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        myObj myObj = (myObj) o;
        return x == myObj.x;
    }

    @Override
    public int hashCode() {
        return 0;
    }
}
public class Main {
    public static void main(String []args){
        Map <myObj, String> hm = new HashMap<>();
        for(int i=0; i<50000; i++)
            hm.put(new myObj(i), "");
    }
}

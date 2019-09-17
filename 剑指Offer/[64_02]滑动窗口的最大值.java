import java.util.*;
public class Solution {
    public ArrayList<Integer> maxInWindows(int [] num, int size)
    {
        ArrayList<Integer>list=new ArrayList<>();
        if(num.length<size||size==0)
            return list;
        ArrayDeque<Integer>window=new ArrayDeque<>();
        for(int i=0;i<size;i++){
            if(window.isEmpty()){
                window.addLast(i);
            }   
            else if(num[window.peek()]<=num[i])
            {
                window.poll();
                window.addLast(i);
            }else{
                window.addLast(i);
            }
        }
        for(int i=size,len=num.length;i<len;i++){
           list.add(num[window.peekFirst()]);
            while(!window.isEmpty()&&num[window.peekLast()]<=num[i]){
                window.pollLast();
            }   
            window.addLast(i);
            if(window.peekFirst()<(i-size+1)){
                window.pollFirst();
            }
            
        }
        list.add(num[window.peekFirst()]);
        return list;
    }
}

------------------------------------------------------------------------------------------------------------------------




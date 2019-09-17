 import java.util.ArrayList;
public class Solution {
    public void reOrderArray(int [] array) {
        ArrayList lista = new ArrayList(); //创建空列表-存放偶数
        ArrayList listb = new ArrayList();
        for(int a=0;a<array.length;a++){
            if((array[a]%2)==1){
                lista.add(array[a]);
            }else if((array[a]%2==0)){
                listb.add(array[a]);
            }
        }
        int m=0;
        for(int i=0;i<lista.size();i++){
            array[m] = (int)lista.get(i);
            m++;
        }
        for(int j=0;j<listb.size();j++){
            array[m] = (int)listb.get(j);
            m++;
        } 
    }
	
}

优化方法一
public class Solution {
    public void reOrderArray(int [] array) {
        int len = array.length;
        int[] arr = new int[len]; // 创建一个新的数组
        int start=0;
        int end = len -1;
        for(int i=0;i<len;i++){
            if((array[i]&1)==1){ // 奇数
                arr[start++] = array[i];
                
            }
            if((array[len-1-i]&1)==0){
                arr[end--] = array[len-1-i];
            }
        }
        for(int i=0;i<len;++i){
            array[i] =arr[i];
        }
        
        
    }
}
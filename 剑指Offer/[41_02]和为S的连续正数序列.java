import java.util.ArrayList;
public class Solution {
    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>(); // 创建返回对象
        if(sum<3){
            return res;
        }
        for(int n=(int)Math.sqrt(2*sum);n>=2;n--){
            if(n%2==1 && sum%n==0 || n%2==0 && sum%n*2==n){
                ArrayList<Integer> arrayList = new ArrayList<>();
                for(int j=0,k=sum/n-(n-1)/2;j<n;j++,k++){
                    arrayList.add(k);
                }
                res.add(arrayList);
            }
        }
        return res;
       
    }
}
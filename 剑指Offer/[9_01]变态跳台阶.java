public class Solution {
    public int JumpFloorII(int target) {
        /*if(target==0){
            return 0;
        }
        return target==1?1:2*JumpFloorII(target-1);*/
        // 方式二
        if(target==1)
            return 1;
        else if(target==2)
            return 2;
        else
            return JumpFloorII(target-1)*2;
        
    }
}
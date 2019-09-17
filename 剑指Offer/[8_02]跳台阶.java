public class Solution {
    public int JumpFloor(int target) {
        if(target<=0){
            return 0;
        }else if(target<=2){
            return target; // 跳1个台阶就是1种跳发，跳2个台阶就是2种跳发
        }else{
            int tem1 = 1; // 跳1个或者2个台阶
            int tem2 = 2;
            int result = 0;
            for(int i=3;i<=target;i++){
                result = tem1 + tem2; // 起初当i=3 时，就调3词
                tem1 = tem2;
                tem2 = result;
            }
            return result;
        }

    }
}
public class Solution {
    public int JumpFloor(int target) {
        /**if(target<=0){
            return 0;
        }else if(target<=2){
            return target; // 跳1个台阶就是1种跳发，跳2个台阶就是2种跳发
        }else{
            int tem1 = 1; // 跳1个或者2个台阶
            int tem2 = 2;
            int result = 0;
            for(int i=3;i<=target;i++){
                result = tem1 + tem2; // 起初当i=3 时，就调3词
                tem1 = tem2;
                tem2 = result;
            }
            return result;
        }*/
        if(target<0){
            return -1;
        }
        if(target<=2){
            return target;
        }
        return JumpFloor(target-1) + JumpFloor(target-2);

    }
}
 
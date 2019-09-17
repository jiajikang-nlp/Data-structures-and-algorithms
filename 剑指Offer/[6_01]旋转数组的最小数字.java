import java.util.ArrayList;
public class Solution {
    public int minNumberInRotateArray(int [] array) {
        if(array==null || array.length ==0){ /*如果数组为空*/
            return 0;
        }
        int p1 =0;/*从前往后走*/
        int p2 = array.length - 1;/*因为含有结束标识符，所以-1*/
        int min = array[p1]; /*如果没有发生旋转，直接将array[0]的值返回：min标识符先指向p1所指向的位置，*/ 
        int mid = 0; /*中间位置标识符*/
        /*当数组发旋转*/
        while(array[p1]>=array[p2]){
            // 当两个指针走到相邻的位置时，p2所指向的数字就是最小的
            if(p2-p1==1){
                min = array[p2];
                break;
            }
            mid = (p1+p2)/2; /*折中，采用二分查找的思想*/
            /*1、如果中间位置的数既等于p1位置的数有又等于p2位置的数*/
            if(array[p1] == array[mid] && array[p2]==array[mid]){
                min = minInorder(array,p1,p2);
            }
            /*2、若中间位置的数位于前半部分数组，让p1走到mid的位置*/
            if(array[p1]<=array[mid]){
                p1 = mid;
            }else if(array[p2]>=array[mid]){/*若中间位置的数位于数组2，让p2走到mid的位置*/
                p2= mid;
            }
        }
        return min;
    
    }
    private int minInorder(int[] array,int p1,int p2){
        int min = array[p1];
        for(int i=p1+1;i<=p2;i++){
            if(min>array[i]){
                min = array[i];
            }
        }
        return min;
    }
}
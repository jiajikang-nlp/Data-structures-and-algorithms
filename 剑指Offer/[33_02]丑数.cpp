class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        // 求第N个丑数
        if(index<=0){
            return 0;
        }
        // 开辟index辅助空间
        int *pUglyNumber = (int *)malloc(sizeof(int)*index); 
        pUglyNumber[0] = 1; // 第一个丑数1
        int nextIndex = 1; // 下一个丑数的下标
        // 记录上次求丑数时动车那个丑数的位置
        int *pMutiply2 = pUglyNumber;
        int *pMutiply3 = pUglyNumber;
        int *pMutiply5 = pUglyNumber;
        
        while(nextIndex<index){
            // 下一个丑数是3个乘积中最小值
            int minvalue = Min(*pMutiply2*2,*pMutiply3*3,*pMutiply5*5);
            pUglyNumber[nextIndex] = minvalue;
            //找到小于等于有序数组中最后一个丑数的位置(避免计算比上一个丑数小的值)
            while(*pMutiply2*2<=pUglyNumber[nextIndex]){
                pMutiply2++;
            }
            while(*pMutiply3*3<=pUglyNumber[nextIndex]){
                pMutiply3++;
            }
            while(*pMutiply5*5<=pUglyNumber[nextIndex]){
                pMutiply5++;
            }
            nextIndex++;
        }
        int nUglyNum = pUglyNumber[nextIndex-1];
        free(pUglyNumber);
        pUglyNumber = NULL;
        return nUglyNum;
 
    }
    // 求三个值中的最小值
    int Min(int n1,int n2,int n3){
        int min = n1>n2 ? n2 : n1; // 大于就min=n2
        return min > n3 ? n3 : min;
    }
};
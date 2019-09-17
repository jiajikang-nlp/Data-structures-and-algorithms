class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        // 非法输入
        if(numbers==NULL || length<=0){
            return false;
        }
        // 非法输入
        for(int i=0;i<length;i++){
            if(numbers[i]<0||numbers[i]>length-1){
                return false;
            }
        }
        // 遍历查找第一个重复的数
        for(int i=0;i<length;i++){
            while(numbers[i]!=i){ // 当下标和对应的元素不相等
                if(numbers[i]==numbers[numbers[i]]){ // 将当前位置i上的元素和numbre[i]作为位置，对应的元素进行判断
                    *duplication = numbers[i];
                    return true;
                }
                swap(numbers[i],numbers[numbers[i]]);// 交换
            }
        }
        return false;
    }
};
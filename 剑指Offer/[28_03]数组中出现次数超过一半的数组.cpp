class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    if(numbers.empty()){
        return 0;
    }
        sort(numbers.begin(),numbers.end()); // 排序，取数组中的那个数,对给定区间所有元素进行排序
        int middle = numbers[numbers.size()/2]; // 数组元素的个数/2
        int counts = 0; // 出现的次数
        for(int i=0;i<numbers.size();++i){
            if(numbers[i]==middle){
                ++counts;
            }
        }
        return (counts>numbers.size()/2)?middle:0;
    }
};
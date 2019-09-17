class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> list; // 用于返回结果
        // 特殊处理
        if(array.size()==0||array.empty()){
            return list; // 返回一个空列表
        }
        // 获取数组长度
        int leng = array.size();
        // 创建首尾指针
        int start = 0;
        int end = leng-1;
        while(start<end && end>0){
            if(array[start]+array[end]==sum){
                list.push_back(array[start]);
                list.push_back(array[end]);
                return list;
            }
            if(array[start]+array[end]>sum){
                end--;
            }
            if(array[start]+array[end]<sum){
                start++;
            }
            
        }
        return list;
    }
};
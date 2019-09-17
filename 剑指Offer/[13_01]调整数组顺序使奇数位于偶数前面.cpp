class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> arr;
        for(int i=0;i<array.size();i++){
            if(array[i]%2==1){
                arr.push_back(array[i]); // 添加到arr数组的尾部
            }
        }
        for(int i=0;i<array.size();i++){
            if(array[i]%2==0){
                arr.push_back(array[i]);
            }
        }
        for(int i=0;i<array.size();i++){
            array[i] = arr[i];
        }
        
    }
};
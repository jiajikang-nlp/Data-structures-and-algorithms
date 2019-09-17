class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int len = data.size();// 获取数组的长度
        if(len==0){
            return 0;
        }
        // 二分查找
        int low = 0;
        int high = len-1;
        int mid = 0;
        while(low<=high){
            mid = (low+high)>>1; // 求中间
            if(data[mid]==k){
                break;
            }else if(data[mid]<k){ // 右侧
                low = mid + 1;
            }else{
                high = high -1;
            }
        }
         //若存在，在左右拓展找相同
        if(data[mid]==k){
            int count = 1;
            low = high = mid;
            while(--low>=0 && data[low]==k){
                count++;
            }
            while(++high<len && data[high] ==k){
                count++;
            }
            return count;
        }
        return 0;
        
    }
};
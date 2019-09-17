class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int leng = data.size();// 数组的长度
        if(leng<2){
            return;
        }
        // 对原始数组求异或
        int resultExclusiveOR = 0;
        for(int i=0;i<leng;++i){
            resultExclusiveOR ^=data[i];// a^0=a
        }
        unsigned int indexof1 = FindFirstBitIS1(resultExclusiveOR);
        *num1 = *num2 = 0;
        for(int j=0;j<leng;j++){
            if(ISBit1(data[j],indexof1)){
                *num1 ^= data[j];
            }else{
                *num2 ^= data[j];
            }
        }
        
    }
private:
    // 找到二进制数num第一个为1的位数，比如0010，第一个位1的位数是2
    unsigned int FindFirstBitIS1(int num){
        unsigned int indexBIT = 0;
        while((num & 1)==0 && (indexBIT<8*sizeof(unsigned int))){
            num = num>>1;
            indexBIT++;
        }
        return indexBIT;
    }
    // 判断第indexBIT是否为1
    bool ISBit1(int num,unsigned int indexBit){
        num = num >> indexBit;
        return (num & 1);
    }
    
};
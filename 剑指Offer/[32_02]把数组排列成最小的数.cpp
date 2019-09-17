
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int length = numbers.size(); // 元素个数
        if(length==0){
            return ""; // 返回空
        }
        sort(numbers.begin(),numbers.end(),cmp);
        string res; // 定义一个字符串
        for(int i=0;i<length;i++){
            res +=to_string(numbers[i]);
        }
        return res;
        
    }
// 注意在C++中，cmp函数要是使用static进行声明，声明是静态成员函数，这样才能正确调用。
private:
    // 升序排序
    static bool cmp(int a,int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
};
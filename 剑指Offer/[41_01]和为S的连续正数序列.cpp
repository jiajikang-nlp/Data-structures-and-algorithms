class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> allRes;
        for(int n=sqrt(2*sum);n>=2;--n){
            // S = （a0 + a0 +n-1）*  n / 2，等差序列公式自然是不必说的。
            // 对其进行放缩，就有S > n平方 / 2；即n < 根号2S（这一点在解法4中也有涉及）。
            // (a1+an)*n = s 可知：n<sqrt(2s)
            // 这样做的话可以减少遍历次数。 在for循环中就有体现。
            if((n&1)==1 &&sum%n==0 || (sum%n*2==n)){
                vector<int> res;
                // 
                for(int j=0,k=sum/n -(n-1)/2;j<n;j++,k++){
                    res.push_back(k);
                }
                allRes.push_back(res);
            }
        }
        return allRes;
    }
};
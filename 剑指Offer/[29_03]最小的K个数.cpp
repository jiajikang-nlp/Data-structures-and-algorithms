class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result; // 创建一个返回结果的对象
        if(k<=0||k>input.size()||input.size()==0){
            return result;
        }
       
        sort(input.begin(),input.end()); // 排序，取数组中的那个数,对给定区间所有元素进行排序
        for(int j=0;j<k;j++){
            result.push_back(input[j]);// vecotr容器中添加：push_back()
        }
        return result;
        
        
    }
};


	解题思路三：O（nlogk）
	    分析一：
	    本方法使用于海量数据处理。大致思想是：建立一个k个数的大堆，每次拿一个数和堆顶元素比较，
		1：如果这个数比堆顶元素大，则必然不是最小的K个数，
		2：如果这个数比堆顶元素小，则与堆顶元素进行交换，
		3：然后在向下调整一次建成新的大堆
		4：然后遍历所有的数，直到最小的K个数都进入堆里。
		
			a：最大的K个数----建小堆
			b：最小的K个数----建大堆
	
	    步骤：
        1、先创建一个大小为k的数据容器来存储最小的k个数字，接下来我们每次从输入的n个整数中读入一个数．
	    2、如果容器中已有的数字少于k个，则直接把这次读入的整数放入容器之中：
	    3、如果容器中己有k数字了，也就是容器己满，此时我们不能再插入新的数字而只能替换已有的数字。
	    4、找出这己有的k个数中的最大值，然后在这次待插入的整数和最大值进行比较。
	       a：如果待插入的值比当前己有的最大值小，则用这个数替换当前已有的最大值：
		   b：如果待插入的值比当前已有的最大值还要大，那么这个数不可能是最小的k个整数之一，于是我们可以抛弃这个整数。

        因此当容器满了之后我们要做3 件事情： 
		     a：一是在k个整数中找到最大数
			 b：二是有可能在这个容器中删除最大数： 
			 c：三是有可能要插入一个新的数字。我们可以使用一个大顶堆在O(logk）时间内实现这三步操作
 
	    分析二：
            这是典型的Top-K问题，即从n个数中找出最小的k个数或者最大的k个数问题。我们通常的做法用一个容量为k的容器来存放这k个最小的值。我们只需遍历一遍原数组，就能得到最小的k个数。
 
			1：起初容器是空，当已遍历的数的个数小于容器的容量k时，直接向容器中添加该值。
			2：当容器的容量已满，则判断该容器中最大值是否大于待插入的点：
			   a：若大于，则从容器中删除该最大值，添加待插入的点
			   b：若小于或者等于，则不做任何操作，继续遍历下一个值
            
			问题转化为如何高效率得到容器中的最大值。一个优雅的数据结构完美的解决此题，即堆结构，分为大根堆或者小根堆。
			显然这里应该选择大根堆。在大根堆中，根节点大于左子树和右子树中所有点，所以我们只需访问根节点即可得到k容量的最大值，且数据结构可以对插入的值进行动态调整堆结构，使得满足大根堆。
			在Java中，没有专门的堆数据结果，不过有基于堆结构的优先队列，所以这里采用优先队列并自定义比较器，来满足大根堆的需求。


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        /*vector<int> result; // 创建一个返回结果的对象
        if(k<=0||k>input.size()||input.size()==0){
            return result;
        }
        
        sort(input.begin(),input.end()); // 排序，取数组中的那个数,对给定区间所有元素进行排序
        for(int j=0;j<k;j++){
            result.push_back(input[j]);// vecotr容器中添加：push_back()
        }
        return result;*/
        vector<int> result;
        if(input.empty()||k<=0||k>input.size()){
            return result;     
        }
        priority_queue<int> q;
        for(int i=0; i<input.size();i++){
            if(q.size()<k){
                q.push(input[i]);// 添加
            }else{
                if(q.top()>input[i]){
                    q.pop(); // 弹出
                    q.push(input[i]);
                }
            }
        }
        for(int i=0;i<k;i++){
            result.push_back(q.top());
            q.pop();
        }
        return result;
        
    }
};






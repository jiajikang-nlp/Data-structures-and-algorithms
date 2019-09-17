class Solution {
public:
	//基于二分查找算法的快速解法
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty())
			return 0;
		else
		{
			int index1 = 0;
			int index2 = rotateArray.size() - 1;
			int indexMid = index1; //当把数组前面0个元素搬到后面时，即排序数组本身，第一个数字就是最小数字，可以直接返回
			while (rotateArray[index1] > rotateArray[index2])
			{
				if (index2 - index1 == 1)
				{
					return rotateArray[index2];
					break;
				}
				indexMid = (index1 + index2) / 2;
				if (rotateArray[indexMid] >= rotateArray[index1])
					index1 = indexMid;
				if (rotateArray[indexMid] <= rotateArray[index2])
					index2 = indexMid;
 
				//当index1、index2和indexMid位置的值相等时，无法判断indexMid属于前半部分还是后半部分，需要遍历查找
				if (rotateArray[index1] == rotateArray[index2] && rotateArray[index1] == rotateArray[indexMid])
					return minInorder(rotateArray, index1, index2);
			}
			return rotateArray[indexMid];
		}
	}
 
	/*实现顺序查找*/
	int minInorder(vector<int> Array, int index1, int index2)
	{
		int result = Array[index1];
		for (int i = index1+1;i <= index2;i++)
		{
			if (Array[i] < result)
				result = Array[i];
		}
		return result;
	}
};
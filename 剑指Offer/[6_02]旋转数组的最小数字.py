# -*- coding: utf-8 -*-
"""
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
    输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
    例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
    NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
    思路：首先所给的旋转数组书局部有序的，这完全可以想到使用二分查找来解决会优化线性查找的性能。这道题的解法和二分查找类似，设置三个指针，left,right,mid。当mid>=left时说明最小数在右边，当mid<=right时说明在左边。但是在left==right==mid时就不能判断了，只能顺序查找。边界情况需要特殊处理。
"""
def minNumberInRotateArray(rotateArray):
    left = 0 #左侧的指针
    right = len(rotateArray) - 1 #右侧的指针
    mid = 0 #中间的指针
    while rotateArray[left] >= rotateArray[right]:
        #当两个指针走到挨着的位置时，即right - left == 1,right就是最小数了 
        if right - left == 1:
            mid = right
            break
        mid = left + (int)((right-left)/2)
        #如果中间位置的数既等于left位置的数又等于right位置的数  
        if rotateArray[left] == rotateArray[mid] and rotateArray[right]==rotateArray[mid]:
            return minInorder(rotateArray,left,right) 
        #若中间位置的数大于左边位置的数，说明最小的数在mid位置的右边中，让left走到mid的位置  
        if rotateArray[mid] >= rotateArray[left]:
            left = mid
        #若中间位置的数小于右边指针位置的数，说明最小的数在mid位置的左边，让right走到mid的位置  
        elif rotateArray[mid] < rotateArray[right]:
            right = mid
    return rotateArray[mid]
#顺序查找数组里的最小值
def minInorder(rotateArray,left,right):
    minNum = rotateArray[left]
    length = right - left
    for i in range(length):
        if rotateArray[left+i] < minNum:
            minNum = rotateArray[left+i]
    return minNum
 
if __name__ == "__main__":
    array = [5,6,7,8,3,4]
    print(minNumberInRotateArray(array))
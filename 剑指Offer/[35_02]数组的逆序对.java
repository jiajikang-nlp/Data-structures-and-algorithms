# -*- coding:utf-8 -*-
class Solution:
    def InversePairs(self, data):
        # write code here
        return self.sort(data[:],0,len(data)-1,data[:]) % 1000000007 
    def sort(self,temp,left,right,data):
        if right-left<1:
            return 0
        if right-left==1:
            if data[left]<data[right]:
                return 0
            else:
                temp[left],temp[right] = data[right],data[left] # 左右交换
                return 1
        mid = (left+right)//2
        res = self.sort(data,left,mid,temp) + self.sort(data,mid+1,right,temp)
        # 和
        i = left
        j = mid + 1
        index = left
        while i<=mid and j<=right:
            if data[i] <= data[j]:
                temp[index] = data[i]
                i += 1
            else:
                temp[index] = data[j]
                res += mid -i + 1
                j += 1
            index += 1
        while i<=mid:
            temp[index] = data[i]
            i += 1
            index += 1
        while j<=right:
            temp[index] = data[j]
            j += 1
            index += 1
        return res
        
        
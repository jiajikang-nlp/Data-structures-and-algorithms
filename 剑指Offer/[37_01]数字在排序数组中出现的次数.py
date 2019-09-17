# -*- coding:utf-8 -*-
class Solution:
    def GetNumberOfK(self, data, k):
        # write code here
        if len(data) ==0:
            return 0
        else:
            return data.count(k)
			
			
			
# -*- coding:utf-8 -*-
class Solution:
    def GetNumberOfK(self, data, k):
        # write code here
        if len(data) <=0:
            return 0
        else:
            count = 0
            mid = len(data)//2
            if k > data[mid]: # 如果需要统计的K大于中间位置的数, 则右侧
                for i in range(mid+1,len(data)):
                    if data[i] == k:
                        count += 1
                return count
            elif k<data[mid]:
                for i in range(mid-1,-1,-1): # 左侧
                    if data[i] == k:
                        count += 1
                return count
            else:
                count += 1 
                for i in range(mid-1,-1,-1):
                    if data[i] ==k:
                        count += 1
                    else:
                        break
                for i in range(mid+1,len(data)):
                    if data[i] == k:
                        count += 1
                    else:
                        break
                return count
            
            
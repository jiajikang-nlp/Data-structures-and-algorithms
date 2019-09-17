# -*- coding:utf-8 -*-
"""
第一种方法：
	思路：
	     数组排序后，如果符合条件的数存在，则一定是数组中间那个数。（比如：1，2，2，2，3；或2，2，2，3，4；或2，3，4，4，4等等）
		 这种方法虽然容易理解，但由于涉及到快排sort，其时间复杂度为O(NlogN)并非最优。
"""
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        # 时间复杂度：O(NlogN)由于涉及到sort排序，并非最优
        if len(numbers) == 0:
            return 0
        numbers.sort() # 升序排序
        middle = numbers[len(numbers)//2] # 排序后的中位数，整除：//
        # 判断出现的次数是否大于数组长度的一半
        counts = 0
        for j in range(len(numbers)):# 遍历数组的长度
            if numbers[j] == middle:
                counts+=1 # 出现重复的个数
        if counts>len(numbers)//2: # 如果出现的个数>数组长度的一半
            return middle
        else:
            return 0
			
			
# -*- coding:utf-8 -*-
import collections
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        # 时间复杂度：O(NlogN)由于涉及到sort排序，并非最优
        tmp = collections.Counter(numbers)# 统计列表元素出现的次数，返回一个字典：键值
        middle = len(numbers)/2 # 求整，获取列表的中位数
        for x,y in tmp.items(): # 列表返回可遍历的(键,值)元组数组
            if y > middle:
                return x
        return 0
		
		
第二种方法：
	
	    思路：
		1、在遍历数组时保存两个值：一是数组中一个数字，一是次数。
		2、遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；
		3、若次数为0，则保存下一个数字，并将次数置为1。
		4、遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
		
		
		
# -*- coding:utf-8 -*-
import collections
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        """
        tmp = collections.Counter(numbers)# 统计列表元素出现的次数，返回一个字典：键值
        middle = len(numbers)/2 # 求整，获取列表的中位数
        for x,y in tmp.items(): # 列表返回可遍历的(键,值)元组数组
            if y > middle:
                return x
        return 0
        """
        len1 = len(numbers) # 获取数组的长度
        if len1 == 0:
            return 0
        elif len1>=1:
            # 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
            res = numbers[0]# 初始值
            count = 1# 次数
            for i in range(1,len1):
                if count ==0:
                    # 更新result的值为当前值，并置次数为1
                    res = numbers[i]
                    count = 1
                elif numbers[i] ==res:
                    count += 1 # 相同则加1
                elif numbers[i] !=res:
                    count -= 1 # 不同则减1
            # 判断res是否符合条件，即出现的次数是否大于数组长度的一半
            counts = 0
            for j in range(len1):
                if numbers[j] == res:
                    counts += 1
            if counts>len1//2: # python3整除为// ,python2整除/
                return res
            else:
                return 0
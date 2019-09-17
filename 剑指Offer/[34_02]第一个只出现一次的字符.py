# -*- coding:utf-8 -*-
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        if not s or len(s)>10000:
            return -1
        else:
            for i in s:
                if s.count(i) == 1:
                    return s.index(i)
        
		
# -*- coding:utf-8 -*-
from collections import Counter
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        if not s or len(s)>10000:
            return -1
        # 先对每个字符出现的次数统计
        # 然后在对原字符串进行遍历，找出第一个出现次数为1的字符，返回即可
        count = Counter(s)
        for i,c in enumerate(s):# 以字典形式遍历
            if count[c] ==1:
                return i
				

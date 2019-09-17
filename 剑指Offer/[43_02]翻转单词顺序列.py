# -*- coding:utf-8 -*-
class Solution:
    def ReverseSentence(self, s):
        # write code here
        wors = s.split(' ') # 以空格切割
        return ' '.join(wors[::-1])# 逆向翻转
		
		
		
# -*- coding:utf-8 -*-
# -*- coding:utf-8 -*-
class Solution:
    def ReverseSentence(self, s):
        # write code here
        #wors = s.split(' ') # 以空格切割-将空格切分成数组，反转数组，然后在使用空格连接
        #return ' '.join(wors[::-1])# 逆向翻转
        if s is None or len(s)==0:
            return s
        stack = [] # 创建一个栈
        for i in s.split(' '):
            stack.append(i) # 依次添加
        ans = ""
        while len(stack)>0:
            ans += stack.pop() + " "
        ans = ans[:-1]# 逆序
        return ans





# -*- coding:utf-8 -*-
class Solution:
    def ReverseSentence(self, s):
        # write code here
        #wors = s.split(' ') # 以空格切割-将空格切分成数组，反转数组，然后在使用空格连接
        #return ' '.join(wors[::-1])# 逆向翻转
        """
        if s is None or len(s)==0:
            return s
        stack = [] # 创建一个栈
        for i in s.split(' '):
            stack.append(i) # 依次添加
        ans = ""
        while len(stack)>0:
            ans += stack.pop() + " "
        ans = ans[:-1]# 从位置0到位置-1之前的数
        return ans
        """
        if s is None or len(s) ==0 or " " not in s:
            return s
        # 两次翻转，先将字符串全部原地翻转。使用双指针，分别对应前后两个空格的位置，翻转两指针之间的子字符串，即单词。
        # 第一次翻转
        s = s[::-1] # 字符串全部原地翻转
        l = 0
        r = s.index(" ") # 返回空格所在的位置
        ans = ""
        while r<len(s):
            #第二次翻转
            ans += s[l:r][::-1] + " " # 从1到r全部反转+空格符
            l = r + 1
            r += 1
            while r<len(s) and s[r] != " ":
                r+=1
        ans += s[l:r][::-1] # 结果返回，各自独立的单词翻转
        return ans
    



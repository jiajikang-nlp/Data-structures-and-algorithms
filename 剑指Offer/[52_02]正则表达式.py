# -*- coding:utf-8 -*-
class Solution:
    # s, pattern都是字符串
    def match(self, s, pattern):
        # write code here
        if s == pattern:
            return True
        if not pattern:
            return False
        if len(pattern)>1 and pattern[1] == '*': # 而当模式中的第二个字符是*时： 
            if (s and s[0]==pattern[0] or (s and pattern[0]=='.')):#如果字符串第一个字符跟模式第一个字符匹配
                return self.match(s,pattern[2:]) or self.match(s[1:],pattern[2:]) or self.match(s[1:],pattern)
            else:# 而当模式中的第二个字符是*时：
                return self.match(s,pattern[2:]) # 模式后移两位，继续匹配
        elif s and (s[0] == pattern[0] or pattern[0] == '.'):
            return self.match(s[1:],pattern[1:])# 如果字符串第一个字符和模式中的第一个字符相匹配，那么字符串和模式都后移一个字符，然后匹配剩余的。
        return False
                
                
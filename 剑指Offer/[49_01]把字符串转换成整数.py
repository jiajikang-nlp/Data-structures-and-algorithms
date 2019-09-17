# -*- coding:utf-8 -*-
class Solution:
    def StrToInt(self, s):
        # write code here
        if s=='':
            return 0
        ret = 0 # 结果
        num = 0
        flag = 1
        for i in s[::-1]: # 倒序
            if i<'0' or i>'9': # 如果不在此范围直接返回0
                if i=='-':
                    flag = -1
                    continue
                elif i=='+':
                    continue
                else:
                    return 0
            ret += int(i) * pow(10,num)# 10的num次方
            num += 1
        return ret*flag
        
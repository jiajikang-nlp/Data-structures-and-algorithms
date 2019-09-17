# -*- coding:utf-8 -*-
class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        if not s:
            return False
        if s[0] =='+' or s[0] == '-':
            if s[1] !='+' and s[1]!='-':
                try:
                    if float(s[1:]):
                        return True
                except:
                    return False
            else:
                return False
        else:
            try:
                if float(s):
                    return True
            except:
                return False
                    
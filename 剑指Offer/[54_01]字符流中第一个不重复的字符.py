# -*- coding:utf-8 -*-
class Solution:
    # 返回对应char
    # 用字典（Java中的HashMap结构）来做。字典中的键值对中，键key存储字符；值value存储字符出现的次数。
    charDict = {} # 创建一个字典
    #lis = [] 
    # 疼字符串来存储字符流的顺序，适用于python2，但不适用于python3
    lis = ""
    def FirstAppearingOnce(self):
        # write code here
        for key in self.lis:
            if self.charDict[key] == 1:
                return key
        return '#'
    def Insert(self, char):
        # write code here
        self.charDict[char] = 1 if char not in self.charDict else self.charDict[char] + 1 # 如果字典中不存在就是1，如果存在就是+1
        #self.lis.append[char]
        self.lis += char
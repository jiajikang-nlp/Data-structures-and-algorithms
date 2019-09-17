# -*- coding:utf-8 -*-
class Solution:
    def cutRope(self, number):
        # write code here
        if number<2:
            return 0
        elif number==2:
            return 1
        max_list = [0,1,2]
        for i in range(3,number+1):
            if i<number:
                max1 = i
            else:
                max1 = 0
            for j in range(1,i//2+1):
                tmp = max_list[j]*max_list[i-j]
                if tmp>max1:
                    max1 =tmp
            max_list.append(max1)
        return max_list[number]
                
---------------------------------
# -*- coding:utf-8 -*-
class Solution:
    def cutRope(self, number):
        # write code here
        # 贪心算法
        if number <2:
            return 0
        elif number==2:
            return 1
        elif number==3:
            return 2
        multi_3 = 0
        # 当n<=3时如果再剪一刀那么结果肯定小于未剪时的值
        # 而当n>3时继续剪肯定会存在大于等于未剪时的
        # 即我们将长为number的数一直剪下去直到碰到剩下的小于4时结束
        while number>4:
            multi_3 += 1
            number -=3
        return 3**multi_3*number# 3的multi_3的平方，再乘number
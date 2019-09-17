class Solution:
    def reOrderArray(self, array):
        # write code here
        even, odd = [], []
        for i in array:
            if i % 2 == 0:
                odd.append(i)
            else:
                even.append(i)
        return even + odd
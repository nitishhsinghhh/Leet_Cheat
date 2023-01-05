class Solution(object):
    def twoSum(self, nums, target):
        res = []
        for i, x in enumerate(nums):
            res.append([x, i])
        res.sort()
        
        left, right = 0, len(res) - 1
        while left < right:
            sum2 = res[left][0] + res[right][0]
            if sum2 == target:
                return [res[left][1], res[right][1]]
            elif sum2 > target:
                right -= 1
            else:
                left += 1

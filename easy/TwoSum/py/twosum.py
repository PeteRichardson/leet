#!/usr/bin/env python3

class Solution:
    # def twoSum(self, nums, target):
    #     for i in range(0,len(nums)):
    #         for j in range(i+1, len(nums)):
    #             if nums[i] + nums[j] == target:
    #                 return [i,j]

    def twoSum(self, nums, target):
        seen = {}
        for i in range(0, len(nums)):
            value = nums[i]
            needed = target - value
            if seen.get(needed) != None:
                return sorted([i, seen[needed]])
            seen[value] = i
        # assert(False, "Shouldn't have gotten here.  There is always an answer!")
        return None

sol = Solution()

assert(sol.twoSum([2,7,11,15], 9) == [0,1])
assert(sol.twoSum([3,2,4],6) == [1,2])
assert(sol.twoSum([3,3],6) == [0,1])
assert(sol.twoSum([3,3],7) == None)
assert(sol.twoSum([-35, 1, 7, 500, 36, 892], 1) == [0,4])
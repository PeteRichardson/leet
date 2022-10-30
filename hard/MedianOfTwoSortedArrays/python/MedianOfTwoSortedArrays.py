
from typing import List
from xml.dom import IndexSizeErr

def isOdd(n: int) -> bool:
    return n % 2

class Solution:

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        print("nums1 = ", nums1)
        print("nums2 = ", nums2)

        m = len(nums1)
        n = len(nums2)
        print(f"nums1 length: {m}, nums2 length: {n}")

        merged_len = m + n
        print(f"merged length = {merged_len}")

        # if merged_len == 0:
        #     throw IndexError()          # no need for this check.  1 <= m + n

        high_median_index = int(merged_len/2)
        low_median_index = high_median_index - 1

        is_odd = isOdd(merged_len)
        if is_odd:
            print("merged_len is odd")
            print(f"median value is at index {high_median_index}")
        else:
            print("merged_len is even")
            print(f"median value is mean of values at indices {low_median_index} and {high_median_index}")
 
        i1 : int = 0
        i2 : int = 0
        value : int = 0
        for i in range(high_median_index+1):    # don't need to go any farther than this

            # see if nums1 list has any remaining values
            nums1_candidate = None
            if m != 0 and i1 < m:
                nums1_candidate = nums1[i1]
                print(f"nums1_candidate = {nums1_candidate}")

            # see if nums2 list has any remaining values
            nums2_candidate = None
            if n != 0 and i2 < n:
                nums2_candidate = nums2[i2]
                print(f"nums2_candidate = {nums2_candidate}")

            # Now walk through the possibilities (neither has a value, one has a value, both have values)
            # if nums1_candidate == None and nums2_candidate == None:
            #     throw IndexError("Impossible!  Depleted both lists!?")
                # This shouldn't happen because we only go so far as high_median_index

            if (nums1_candidate != None and nums2_candidate == None):
                # Pick the value from nums1
                value = nums1[i1]
                print(f"{i}. {value} from nums1[{i1}]")
                i1 += 1
            elif (nums1_candidate != None and nums2_candidate != None) and (nums1_candidate <= nums2_candidate):
                value = nums1[i1]
                print(f"{i}. {value} from nums1[{i1}]")
                i1 += 1               
            elif (nums1_candidate != None and nums2_candidate != None) and (nums1_candidate > nums2_candidate):
                value = nums2[i2]
                print(f"{i}. {value} from nums2[{i2}]")
                i2 += 1                
            elif (nums1_candidate == None and nums2_candidate != None) or (nums1_candidate > nums2_candidate):
                value = nums2[i2]
                print(f"{i}. {value} from nums2[{i2}]")
                i2 += 1

            if i == low_median_index:
                low_median = value
                print(f"low_median is at index {i}: {value}")
        high_median = value
        print(f"high_median is at index {high_median_index}: {value}")

        if is_odd:
            return high_median
        else:
            return (low_median + high_median)/2


sol = Solution()
median = sol.findMedianSortedArrays([1,4,5,6], [2,3])
print(f"median is {median}")
print("---------------------------")
median = sol.findMedianSortedArrays([0], [0])
print(f"median is {median}")
print("---------------------------")
median = sol.findMedianSortedArrays([-1], [0])
print(f"median is {median}")
print("---------------------------")
median = sol.findMedianSortedArrays([1,2,3,4,5,6], [])
print(f"median is {median}")
print("---------------------------")
median = sol.findMedianSortedArrays([1], [])
print(f"median is {median}")







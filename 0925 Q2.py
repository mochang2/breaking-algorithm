"""
Given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum
and maximum element on it is less or equal than target.

Since the answer may be too large, return it modulo 10^9 + 7.
"""

class Solution(object):
    def numSubseq(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        #revised version with two pointers
        n = len(nums)
        nums.sort()
        mod = pow(10, 9) + 7
        left = 0
        right = n - 1
        result = 0

        while (left <= right):
            if nums[left] + nums[right] > target:
                right -= 1
            else:
                result += pow(2, right - left, mod)   #right를 초과하는 숫자와
                                                                #left미만 숫자는 제외, left를 반드시 포함하는
                                                                #부분집합의 개수
                result %= mod
                left += 1

        return result




        #my original version n^2 time complexity with two for loops
        """n=len(nums)
        nums.sort()
        
        num_of_cases = 0
        
        for i in range(n):   #nums[0]~nums[n-1]
            for j in range(i, n):  #nums[i]~nums[n-1]
                if nums[i] + nums[j] > target or j == n - 1:
                    if nums[i] + nums[j] >target:
                        a = j - i - 1        
                    else:
                        a = j - i

                    if a < 0:
                        pass
                    else:
                        num_of_cases += 2**a
                    break
                        
        
        return num_of_cases"""


#main.py
ex1 = Solution()
result = ex1.numSubseq([1,2,3,4,5,6], 6)

print(result)

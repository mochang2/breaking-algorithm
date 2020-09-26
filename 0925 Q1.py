"""
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
"""



class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """

        #my original code with n^2 time complexity
        """
        n = len(intervals)
        intervals.sort()
        li = []
        if n < 2:
            pass
                
        else:
            for i in range(n-1):
                for j in range(i+1, n):
                    if intervals[i][1] >= intervals[j][0]:
                        intervals[i][0] = min(intervals[i][0], intervals[j][0])
                        intervals[i][1] = max(intervals[i][1], intervals[j][1])
                        if (j not in li) :
                            li.append(j)
                        
            li.reverse()
            for k in li:
                intervals.remove(intervals[k])

        return intervals
        """

        #revised code with nlogn time complexity (but in leet code, error happens, even though
        #there is no error in compilers
        n = len(intervals)
        intervals.sort()
        li = []
        
        li.append(intervals[0])
        
        for i in range(1, n):
            if li[-1][1] >= intervals[i][0]:
                li[-1][1] = max(li[-1][1], intervals[i][1])
            else:
                li.append(intervals[i])
        
        return li


#main.py    
example1 = Solution()
example1 = example1.merge([[1,5], [0,4], [2,7], [5,8], [4,6], [9,13]])
for i in example1:
    print(i)
example2 = Solution()
example2 = example2.merge([[1,4],[0,2],[3,5]])
for i in example2:
    print(i)


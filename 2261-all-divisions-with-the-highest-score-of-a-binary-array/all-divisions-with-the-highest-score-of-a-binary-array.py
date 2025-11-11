class Solution:
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        prefix_zeros = [0] * (n + 1)
        for i in range(1, n + 1):
            prefix_zeros[i] = prefix_zeros[i - 1] + (1 if nums[i - 1] == 0 else 0)

        suffix_ones = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix_ones[i] = suffix_ones[i + 1] + (1 if nums[i] == 1 else 0)

        max_score = -1
        res = []

        for i in range(n + 1):
            score = prefix_zeros[i] + suffix_ones[i]
            if score > max_score:
                max_score = score
                res = [i]
            elif score == max_score:
                res.append(i)
        return res
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        removed_list = list(set(nums))
        removed_list.sort()

        for i in range(len(nums)):
            if(i > len(removed_list) - 1):
                nums[i] = '_'
            else:
                nums[i] = removed_list[i]

        return len(removed_list)

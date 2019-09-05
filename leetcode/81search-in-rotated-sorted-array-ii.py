
List = []
class Solution:
    def search(self, nums, target):
        n = len(nums)
        if n == 0:
            return False
        l, r = 0, n-1
        while l < r:
            mid = int((l + r) / 2)
            if target == nums[l] or target == nums[r] or target == nums[mid]:
                return True
            if nums[mid] == nums[l] and nums[mid] == nums[r]:
                l += 1
                r -= 1
            if nums[mid] >= nums[l]:
                if target >= nums[l] and target <= nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if target >= nums[mid] and target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
        return target == nums[l]


if __name__ == "__main__":
    sol = Solution()
    nums = [1,3,1,1,1]
    t = 3
    print(sol.search(nums, t))
List = list
class Solution:
    def merge(self, nums1, m: int, nums2, n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i, j = 0, 0
        while j < n and i < m:
            if nums2[j] < nums1[i]:
                for id in range(m, i, -1):
                    nums1[id] = nums1[id - 1]
                nums1[i] = nums2[j]
                j += 1
                m += 1
            i += 1
        while j < n:
            nums1[m] = nums2[j]
            m += 1
            j += 1


if __name__ == "__main__":
    solu = Solution()

    nums1 = [1, 2, 3, 0, 0, 0]
    nums2 = [2, 5, 6]
    solu.merge(nums1, 3, nums2, 3)
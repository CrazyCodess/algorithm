List = []
class Solution:
    def generate(self, numRows):
        if numRows == 0:
            return []
        ans = [[1]]
        for i in range(1, numRows):
            tmp = []
            for j in range(i+1):
                if j == 0:
                    tmp.append(1)
                elif j >= len(ans[i - 1]):
                    tmp.append(1)
                else:
                    tmp.append(ans[i-1][j] + ans[i-1][j-1])
            ans.append(tmp)
        return ans
if __name__ == "__main__":
    solu = Solution()
    solu.generate(10)
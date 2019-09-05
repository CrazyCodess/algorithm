List = []
class Solution:
    def intersection(self, A: List[int], B: List[int]) -> List[int]:
        ans = List[int]
        if (A[0] >= B[0] and A[0] <= B[1]) or (B[0] >= A[0] and B[0] <= A[1]):
            ans.append(min(A[0], B[0]))
            ans.append(min(A[1], B[1]))
        return ans
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        m, n = len(A), len(B)
        ans = []
        i, j = 0, 0
        while i < m and j < n:
            l, r = max(A[i][0], B[j][0]) , min(A[i][1], B[j][1])
            if l <= r:
                ans.append([l, r])
            if A[i][1] < B[j][1]:
                i += 1
            else:
                j += 1
        return ans




if __name__ == "__main__":
    pass

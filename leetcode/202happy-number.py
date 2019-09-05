class Solution:
    def isHappy(self, n: int) -> bool:
        st = set()
        n = str(n)
        while True:
            n = str(sum(int(i) ** 2 for i in n))
            if n == "1":
                return True
            if n in st:
                return False
            st.add(n)
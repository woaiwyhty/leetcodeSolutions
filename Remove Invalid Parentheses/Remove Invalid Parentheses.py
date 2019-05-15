class Solution(object):
    ansList = set()
    def dfs(self, cur, s, openNums, closeNums, ans, removeChance):
        if cur == len(s):
            if openNums != closeNums or removeChance != 0:
                return
            self.ansList.add(ans)
            return
        if s[cur] == '(':
            self.dfs(cur + 1, s, openNums + 1, closeNums, ans + '(', removeChance)
            self.dfs(cur + 1, s, openNums, closeNums, ans, removeChance - 1)
        elif s[cur] == ')':
            if closeNums < openNums:
                self.dfs(cur + 1, s, openNums, closeNums + 1, ans + ')', removeChance)
            self.dfs(cur + 1, s, openNums, closeNums, ans, removeChance - 1)
        else:
            self.dfs(cur + 1, s, openNums, closeNums, ans + s[cur], removeChance)

    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        openNums = 0
        closeNums = 0
        removeChance = 0
        self.ansList = set()
        for c in s:
            if c == '(':
                openNums = openNums + 1
            elif c == ')':
                closeNums = closeNums + 1
                if closeNums > openNums:
                    closeNums = closeNums - 1
                    removeChance = removeChance + 1

        if openNums > closeNums:
            removeChance = removeChance + openNums - closeNums
        self.dfs(0, s, 0, 0, "", removeChance)
        a = {x for x in self.ansList}
        if len(a) == 0:
            return [""]
        return a


if __name__ == '__main__':
    sol = Solution();
    ans = sol.removeInvalidParentheses(")(f")
    print(ans)
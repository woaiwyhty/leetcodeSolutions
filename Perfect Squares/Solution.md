we can use dynamic programming to solve this problem.
Creating an array called dp. And dp[i] is the least number of perfect square numbers which sums to i.
Then, we can consider how to get dp[i] if we have already had all the value between the range dp[0] to d[i - 1].
dp[i] can be equals to dp[j] + 1 if i - j is a perfect square number, right?
Therefore, we can use a loop to iterate all the numbers started at 1. And the condition for this loop is i - loop variable^2 should be greater or equals to 0.
The fomula can be written as:
dp[i] = min(dp[j] + 1) when i - j is perfect square number.
the final answer would be dp[n].
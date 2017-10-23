对于一个可以放置bomb的点，可以被消灭的enemy的数量就是他上下左右四个方向的敌人数量之和
对于一个可以点(i,j),我们可以维护四个数组,left, right, up, down 分别代表这个点左右上下四个方向的敌人数量
那么如果要求出left数组,可以使用递推的方式,
left[i][j] = left[i][j - 1] + 1 如果 点(i,j)是enemy
left[i][j] = left[i][j - 1] 如果点(i, j)是empty
left[i][j] = 0 如果 i,j 是墙

其他三个数组同理维护。

然后对于一个可以放置bomb的点，答案就是 left[i][j] + right[i][j] + up[i][j] + down[i][j]
枚举所有可以放bomb的点，求最大的答案
注意边界条件即可
假设一个人首先在(0,0)，他首先得往右走，走到一个点超出矩阵范围，或者这个点已经已经被走过，就更换方向
如果现在是右边走，那么更换方向就是向下
如果现在是向下走，那么更换方向就向左
按照题目规则类推一下就好了
O(n*m)
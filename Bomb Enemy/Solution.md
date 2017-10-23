Assuming we put the bomb in the point (i, j).
The number of enemies that can be killed is from four direction, up, down, left and right.
For the up direction, the number of enemies that can be killed is the number of those elements in the grid array with 'E' letter and in the j column and up by ith row. To be specific, it is the number of the elements on the upper side of point(i,j) and on the same column with the point(i, j) and with letter 'E'.

For the left direction, the number is the elements on the left side of the point(i, j) in the grid and on the same row and with letter 'E'.

down and right sides are the same as up and left directions.
So, we can use four arrays, called left, right, down, up, to store the number of elements that can be killed in the four different direction.
left[i][j] = left[i][j - 1] + 1 if grid[i][j] is 'E'.
left[i][j] = left[i][j - 1] if grid[i][j] is '0'.
left[i][j] = 0 if grid[i][j] is 'W'.

The other 3 arrays are kind like left array.

the answer will be max(left[i][j] + right[i][j] + up[i][j] + down[i][j]) when point(i, j) is empty.




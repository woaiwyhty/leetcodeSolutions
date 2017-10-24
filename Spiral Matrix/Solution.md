Firstly, I defined two arrays which refer to four different moving direction in the matrix.
dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}
it is easy to implement if I want to move to up, down, left or right.
For example, if I want to move to right, I just need to add dx[1] to the x position and add dy[1] to the y position.

Creating a variable called 'direction' and initializing with the value 1 which means going right.
Assuming I am in (0, 0)
The new point I will move to will be (0 + dx[direction], 0 + dy[direction]).
If the new point is out of the matrix or the new point have already been visited, we need to change the direction and continue to move until we visit all points in the matrix.


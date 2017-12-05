the concave part in the graph showed in the question description can contain water.
if we have a descending sub array, and then the sub array become ascending when the program continue to iterate the whole array.
we can use a stack to maintain a descending sub array by using the follow rules:
1. iterate the whole array.
2. if the new element is higher than the top of the current stack, pop the top until the new top of the current stack is higher than the new element.
3. during the pop process, two elements (index x and y, x < y) in the stack and one new element (index i, i > y > x) which we iterate now can be comprised of a container, the area is (height[x] - height[y]) * (i - x  - 1)
4. then push the new element to the stack

the time complexity is O(n) because all the elements will only be accessed twice.
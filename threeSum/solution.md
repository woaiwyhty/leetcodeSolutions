this question is similar to the question called two sum.
Firstly, sort this array in ascending order.
Because this question requires to find three numbers, we can iterate the first number, and then use the method in two sum to get the second and third numbers when the first number is fixed.

when the program iterate the first number nums[l], we can maintain two pointers called m and r.
Firstly, m will be the index of the first number plus one, r will be the last element in the sorted array.
Obviously, l < m < r
there are three different situations.
Assuming the sum of the triplet equals to a variable called sum.
if sum == 0, the triple will be added to the answer array, then move m to right by one (m++) and move r to left by one (r--)
if sum < 0, just move m to right by one (m++) because we need a larger m to make the sum be 0
if sum > 0, just move r to left by one (r--) because we need a smaller r to make the sum be 0
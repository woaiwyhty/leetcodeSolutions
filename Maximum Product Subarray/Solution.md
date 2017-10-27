its like another question called maximum sum subarray..
But there is a little bit difference.
because there will be some negative values, if we have a new element which has negative value when we iterate all the array, the new element can be selected when there exists a subarray with negative product in the left side of the new element in the array.

For example, assuming we iterate at ith element.
if ith element is positive, we need to find a subarray started at any index as long as the index is smaller than i-1 and ended at i-1. The subarray we find should have the maximum product. And the local maximum product will be the product in the subarray multiply the value of ith element.
if ith element is negative, we need to find a subarray have the minimum product (might be negative). The local maximum product will be the product in the subarray multiply the value of ith element.

So, we need to maintain two array to store the local minimum product and maximum product.
max[i] = max(max(max[i - 1] * nums[i], nums[i]), min[i - 1] * nums[i])
min[i] = min(min(min[i - 1] * nums[i], nums[i]), max[i - 1] * nums[i])

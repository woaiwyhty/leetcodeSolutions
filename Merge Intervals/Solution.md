its easy to get that for a pair [x, y] will be ignored if there exists another pair [a, b] which a equals to x and b is greater than y.

Firstly, we need to sort the given vector by ascending start value.
If there are two pairs [a, b] and [x, y] which a equals to x, then we use sort by descending the end value.
In the sorted vector, for each different start value, we just need to consider the first existed element with the start value.
Also, it is clear that if the ith interval cannot be merged with previous intervals, those intervals after the ith intervals also cannot be merged with previous intervals.
Then, iterate all the intervals, if the current interval that the loop iterate cannot intersect with the interval [nowL, nowR], we add previous intervals to the answer vector, and create a new interval be[currentStart, currentEnd].
If the current interval can intersect, just update the value of nowR.
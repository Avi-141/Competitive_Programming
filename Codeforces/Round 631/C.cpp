You are given m segments of different colors and you can slide these segments in a row of size n.
The maximum length we can get by spreading these segments is equal to the lengths of all the segments(i.e without any overlapping), let denote it by sum.
So if sum is less than n, it is not possible to cover the whole row.
Now if sum >= n we have to compress it to fit in the row size of n. We have to overlap some units of the cells(possibly zero) such that all the colors are visible.
The number of units cells to be overlapped is simply sum-n.
So start placing the segments from start of the row and after leaving sufficient units of cell place next segment(trying to overlap as much as possible but less than required length), and keep doing this for all the segments maintaining the required number of cells to be overlapped.
And if at any iteration the end of segment goes out of the window of size n, in that case answer is not possible.
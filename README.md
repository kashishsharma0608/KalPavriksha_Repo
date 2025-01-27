The Painter's Partition Problem is a classic problem where we are tasked with finding the optimal way to partition a set of boards (or segments of wood, for example) for painters to minimize the time required to paint them. The boards are assigned to multiple painters, and each painter can paint a contiguous set of boards. Each painter paints at a constant speed, and the goal is to minimize the maximum time any one painter spends painting.

Problem Statement:
You are given n boards of different lengths and k painters. Each painter can paint one or more boards in a contiguous manner. The task is to assign the boards to the painters in such a way that the maximum amount of time spent by any one painter is minimized.

For example:

You have 4 boards with lengths [12, 34, 67, 90], and you have 2 painters.
The objective is to assign these boards to the two painters so that the maximum time any one painter spends painting is minimized.

Constraints:
The time taken by each painter to paint a board is proportional to the length of the board.
A painter can paint multiple contiguous boards, but each painter should paint at least one board.

Input:
n: The number of boards.
k: The number of painters.
A list of integers representing the lengths of the n boards.

Output:
The minimum possible time that the painter who paints the longest set of boards will take. This is the time we aim to minimize.

Example:
You are given 4 boards with lengths [12, 34, 67, 90], and you have 2 painters. The objective is to assign these boards to the two painters in such a way that the maximum time spent by any painter is minimized.

Time complexity
getSum()-o(n) 
getMaxElement()-o(n)
numberOfPainters() -o(n)
freeMemory()-o(n)
minimumTimeToPaint()-o(log(sum))
total - o(n*log(sum))- for each numberof painters n sum caluclation is done.

Space complexity
To store the nodes it takes N spaces.

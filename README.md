Problem Statement: Sorting Heroes by Power Levels
A secret organization maintains a list of superheroes, each with a unique Hero ID and a Power Level. This data is stored in a singly linked list, where each node contains:

Hero ID (generated automatically as a sequential integer starting from 1).
Power Level (an integer representing the hero's strength).
Your task is to help the organization sort the heroes in descending order of their Power Levels using the Bubble Sort algorithm. Once sorted, display the sorted list of heroes, showing their Hero ID and Power Level.

Input Format:
The first line contains an integer 
𝑁
N, the number of heroes in the list.
The next 
𝑁
N lines each contain one integer:
Power Level

Note: The Hero ID will be generated sequentially starting from 1 and does not need to be provided in the input.

Output Format:
Print the sorted list in descending order of Power Levels, with each line displaying:
HeroID -> PowerLevel

Constraints:
1≤N≤10^4
1≤Power Level≤10^6

Example:
Input:
450  
300  
600  
200  
500  

Output:
3 -> 600  
5 -> 500  
1 -> 450  
2 -> 300  
4 -> 200  

Time Complexity:
createLinkedList - O(n)
display - O(n)
getLength - O(n)
sortThePowerNonIncreasing - O(n^2)
freeMemory - O(n)
Total : O(n^2)

Space Complexity:
createLinkedList - O(1)
display - O(1)
getLength - O(1)
sortThePowerNonIncreasing - O(1)
freeMemory - O(1)
Total- O(N) for storing N spaces.
All function consumes - O(1) and N nodes take O(N) spaces.
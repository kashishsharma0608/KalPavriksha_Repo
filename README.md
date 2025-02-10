Stack implementation using queue

isEmpty(int front): Checks if the stack is empty by verifying if front is -1. Returns 1 if empty, 0 otherwise.

push(int capacity, int queue[], int *front, int *rear, int value): Adds an element to the stack. If full, shows an overflow message. Shifts elements and updates front and rear to maintain the stack structure in a circular queue.

pop(int capacity, int queue[], int *front, int *rear): Removes the top element from the stack. If empty, shows an underflow message. Updates front and rear accordingly.

top(int front, int queue[]): Returns the top element of the stack without removing it. If empty, shows a message and returns -1.

size(int front, int rear, int capacity): Returns the number of elements in the stack. Uses the circular queue formula to calculate size based on front and rear.

display(int queue[], int front, int rear, int capacity): Displays all elements in the stack. Iterates from front to rear and prints each element, considering circular wraparound.

Time complexity
push: O(n) (due to shifting elements)
pop: O(1)
top: O(1)
size: O(1)
display: O(n)

space complexity
O(1) for all operations since the stack is implemented using a fixed-size array and no additional dynamic memory allocation occurs except for the array.
Queue Implementation Using Circular Array


This C program implements a Circular Queue using a fixed-size array. It provides basic queue operations such as enqueue, dequeue, peek, size calculation, and displaying the elements. The queue operates on the First-In-First-Out (FIFO) principle, with efficient circular array management to overcome the problem of wasted space in traditional queue implementations.

Functionality includes:
isEmpty(int front): Checks if the queue is empty by verifying if the front pointer is -1.

enqueue(int capacity, int queue[], int *front, int *rear, int value): Adds an element to the rear of the queue.
If the queue is full, it prints "Queue is full".
If the queue is empty, both front and rear are set to 0.
Updates the rear pointer circularly using modulo operation to prevent overflow.

dequeue(int capacity, int queue[], int *front, int *rear): Removes the front element of the queue.
If the queue is empty, it prints "Queue is empty".
If there is only one element, both front and rear are reset to -1.
Otherwise, it updates the front pointer in a circular manner.

peekOfQueue(int front, int queue[]): Retrieves the front element without removing it.
If the queue is empty, returns -1.

sizeOfQueue(int front, int rear): Calculates the number of elements in the queue.
If the queue is empty, returns 0.
Uses abs(front - rear + 1) to calculate the size, though it’s an approximation for a circular queue.

display(int queue[], int front, int rear, int capacity): Displays all elements in the queue from front to rear.

Time Complexity

Enqueue: O(1) - The enqueue operation inserts an element at the rear, which is done in constant time.
Dequeue: O(1) - The dequeue operation removes the element from the front in constant time.
Peek: O(1) - Retrieving the front element is done in constant time.
Size: O(n) - This function requires traversing the queue to count the number of elements.
Display: O(n) - The display function requires traversing all the elements in the queue to print them.

Space Complexity

O(n): The space complexity is O(n) because the queue stores n elements in a fixed-size array.
O(1): The space used by pointers (front, rear) and function call variables is constant.

Edge Cases Handled

Empty Queue: The program checks if the queue is empty before performing operations like peek and dequeue. If the queue is empty, appropriate messages are printed, and operations are skipped.

Full Queue: The program checks if the queue is full before performing the enqueue operation. If the queue is full, it prints "Queue is full" and prevents the insertion.

Single Element Queue: Proper handling of the case when there is only one element in the queue. When the last element is dequeued, both front and rear pointers are reset to -1 to indicate the queue is empty.

Circular Nature: The program ensures the queue behaves circularly, allowing the front and rear to "wrap around" when necessary.
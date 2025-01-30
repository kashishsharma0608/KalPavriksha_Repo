Stack Implementation Using Linked List in C

This C program implements a stack using a linked list and provides various stack operations through a menu-driven approach.

-> Features of the Program

Push an element onto the stack

Pop an element from the stack

Peek at the top element

Check the size of the stack

Display all elements in the stack

The stack structure represents each node in the stack, containing the data field and a pointer next to the next node. The program dynamically allocates memory for new nodes and manages stack operations efficiently.

-> Functions Used in the Program

1. isEmpty(stack *top)

Checks if the stack is empty.

Returns 1 if top == NULL, otherwise returns 0.

2. createNode(int value)

Dynamically allocates a new stack node.

Returns the new node if successful, otherwise prints an allocation error.

3. push(stack *top, int value)

Creates a new node and pushes it onto the stack.

If the stack is empty, the new node becomes the top.

Otherwise, the new node’s next pointer is set to the current top, and top is updated.

4. pop(stack *top)

Removes and returns the top element of the stack.

Checks for underflow before popping.

Updates top to the next node and frees the popped node’s memory.

5. peek(stack *top)

Returns the top element without removing it.

If the stack is empty, returns -1.

6. sizeOfStack(stack *top)

Iterates through the stack to count the number of elements.

Returns the count or -1 if the stack is empty.

7. display(stack *top)

Recursively prints the stack elements in order.

Handles the empty stack case by printing a new line.

-> Edge Cases Handled by the Program

1. Stack Overflow (Handled Implicitly)

Unlike arrays, a linked list-based stack does not have a fixed maximum size.

However, if memory allocation fails (heap memory is full), the program prints "Allocation failed" and does not push the element.

2. Stack Underflow (Pop or Peek on Empty Stack)

If pop() is called on an empty stack, the program prints "List is empty" and does nothing.

If peek() is called on an empty stack, it returns -1 to indicate no element is available.

3. Invalid Menu Choice Handling

If the user enters an invalid option, the program prints:"Choose between 1 to 5 or 0 to exit" and prompts again.

4. Handling an Empty Stack in Display Operation

If display() is called on an empty stack, it prints a new line instead of accessing NULL pointers.



Time Complexity

isEmpty()-O(1)
createNode()-O(1)
push()-O(1)
pop()-O(1)
peek()-O(1)
sizeOfStack()-O(n)
display()-O(n)
main() (Overall)-O(n)

Space Complexity Analysis

Each node takes O(1) space, and the total space is O(n) for n nodes.
Recursion in display() may increase memory usage due to function call stack space.
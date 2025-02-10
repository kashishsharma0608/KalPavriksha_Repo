The attcahed C progrfam implements the stack datastructure using the functionality of array. 

The program provides functionalities to:

->Push an element onto the stack
->Pop an element from the stack
->Peek at the top element
->Check the size of the stack
->Display the stack elements

The stacks structure holds the stack array and top index. Helper functions handle stack operations, including checking for overflow and underflow conditions. The program interacts with users via a menu-driven approach, allowing multiple operations based on user input.

**Functions Used in the Program**

*initialize_stack(stacks *stack)*

Initializes the stack by setting top = -1, indicating an empty stack.

*is_empty(stacks *stack)*

Returns 1 if the stack is empty (top == -1), otherwise returns 0.

*is_full(stacks *stack)*

Returns 1 if the stack is full (top == MAX_LENGTH - 1), otherwise returns 0.

*push_stack(stacks *stack, int value)*

Adds value to the stack.
Checks for overflow before pushing.
Increments top and stores value in stack_array[top].

*pop_stack(stacks *stack)*

Removes and returns the top element of the stack.
Checks for underflow before popping.
Decrements top after returning the value.
peek_of_stack(stacks *stack)

Returns the top element without removing it.
Checks for underflow before accessing the top.

*size_of_stack(stacks *stack)*

Returns the current number of elements in the stack (top + 1).
display(stacks *stack)

Prints all elements in the stack from bottom to top.
Handles the empty stack case by displaying "Stack is empty".

**Edge Cases Handled by the Program**

->Stack Overflow (Push on Full Stack)

The stack has a fixed maximum size (MAX_LENGTH = 1000).
If the user tries to push an element when the stack is full, the program prints "Overflow! Stack is full" and prevents the operation.

->Stack Underflow (Pop or Peek on Empty Stack)

If the user tries to pop an element or peek at the top of the stack when it is empty, the program prints "Underflow! Stack is empty" and returns -1.

->Invalid Menu Choice Handling

If the user enters an option outside the range 0-5, the program prints "Invalid choice! Choose between 1 to 5" and prompts again.

->Handling an Empty Stack in Display Operation

If the user tries to display the stack when it is empty, the program prints "Stack is empty" instead of iterating through an empty array.

Time complexity
initiliaze stack - o(1)
is_empty -o(1)
is_full -o(1)
push() -o(1)
pop()  -o(1)
peek() -o(1)
size() -o(1)
display - O(n)
main() -O(n)

Space complexity 
All function takes o(1) spaces except main() taking o(n) due to stack size defined.
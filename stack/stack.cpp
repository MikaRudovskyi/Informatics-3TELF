#include <iostream>

#define N 10

using namespace std;

typedef struct stack 
{
    int list[N];
    int tos; // Top Of Stack
} stack_t;

void initialize(stack_t *s) 
{
    s->tos = -1;
}

void push(int newItem, stack_t *myStack) 
{
    if (myStack->tos == N - 1) 
	{
        cout << "The stack is full. Cannot add elements." << endl;
        return;
    }
    
    myStack->tos = myStack->tos + 1;
    myStack->list[myStack->tos] = newItem;
}

int pop(stack_t *myStack) 
{
    if (myStack->tos == -1) 
	{
        cout << "The stack is empty. Cannot remove elements." << endl;
        return -1;
    }
    
    int remove = myStack->list[myStack->tos];
    myStack->tos = myStack->tos - 1;
    
    return remove;
}

bool isEmpty(stack_t *myStack) 
{
    return myStack->tos == -1;
}

bool isFull(stack_t *myStack) 
{
    return myStack->tos == N - 1;
}

void printStack(stack_t *myStack) 
{
    if (isEmpty(myStack)) 
	{
        cout << "The stack is empty." << endl;
        return;
    }
    
    cout << "Stack: ";
    for (int i = myStack->tos; i >= 0; i--) 
	{
        cout << myStack->list[i] << " ";
    }
    
    cout << endl;
}

int main() 
{
    stack_t myStack;
    initialize(&myStack);

    int choice;
    int newItem;
    
    while (true) 
	{
        cout << "===============================" << endl;
        cout << "Welcome!" << endl;
        cout << "Choose what you want to do:" << endl;
        cout << "1. View the stack" << endl;
        cout << "2. Add an element (push)" << endl;
        cout << "3. Remove an element (pop)" << endl;
        cout << "4. Is it full?" << endl;
        cout << "5. Is it empty?" << endl;
        cout << "6. How many elements are there?" << endl;
        cout << "7. Exit" << endl;
        cout << "===============================" << endl;
        cin >> choice;

        switch (choice) 
		{
            case 1:
                printStack(&myStack);
                break;
            case 2:
                cout << "Insert an element into the stack: ";
                cin >> newItem;
                push(newItem, &myStack);
                break;
            case 3:
                cout << "You removed " << pop(&myStack) << endl;
                break;
            case 4:
                if (isFull(&myStack))
                    cout << "The stack is full." << endl;
                else
                    cout << "The stack is not full." << endl;
                break;
            case 5:
                if (isEmpty(&myStack))
                    cout << "The stack is empty." << endl;
                else
                    cout << "The stack is not empty." << endl;
                break;
            case 6:
                cout << "The number of elements in the stack is: " << myStack.tos + 1 << endl;
                break;
            case 7:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid number!" << endl;
        }
    }
    
    return 0;
}

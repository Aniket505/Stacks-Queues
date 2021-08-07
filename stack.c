/**
 * Program to implement stack in c language.
 *
 * Compilation: gcc -o ques_1 ques_1.c
 * Execution:./ques_1
 *
 * @Aniket , (1910990836) , 05/07/2021
 * Day_2_Coding_Assignment
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

//intializing stack
int stack[MAXSIZE];
//variable to store index of topmost element in stack
int top = -1;

/**
 * Function to push an element at top of the stack
 */
void push() { 
    int x;
    if(top >= MAXSIZE - 1 )
    {
        printf("Stack Overflow");
	return;
    }
    else
    {
	printf("Enter Element To Be Inserted : ");
	scanf("%d",&x);
        top++;
	stack[top] = x;
    }
}

/**
 * Function to check that stack is empty or not
 *
 * returns 1 : When stack is empty
 * returns 0 : When stack is not empty
 */
int is_empty()
{
    if( top < 0 )
	return 1;
    else
	return 0;
}

/**
 * Function to delete element from top of the stack.
 *
 * returns Poped out element
 */
int pop()
{
    int item;
    if( is_empty() )
    {
	printf("Stack Underflow\n");
    }
    else
    {
        item = stack[top];
	top--;
	printf("Element Deleted : %d\n", item);
	return item;
    }
}

/**
 * Function to print the topmost element of the stack.
 *
 */
void peek()
{
    printf("Element At Top Of The Stack : %d",stack[top]);
}

/**
 * Function to print elements in stack
 */
void print() {
    for(int i = 0 ; i <= top ; i++ )
    {
        printf("%d\n",stack[i]);
    }
}

int main()
{
    int op;
    printf("\nStack Operations");
    printf("\n1. Push \n2. Pop \n3. Peek \n4. Print Stack \n5. Exit");
    while(1)
    {
	printf("\nEnter Operation : ");
	scanf("%d",&op);

	switch(op)
	{
	    case 1: push();
		    break;
            case 2: pop();
		    break;
	    case 3: peek();
		    break;
	    case 4: print();
		    break;
	    case 5: exit(0);

	    default: printf("Enter Valid Operation\n");
		     break;
	}
    }
    
}

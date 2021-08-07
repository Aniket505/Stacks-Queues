/**
 * Program to implement queue in c language.
 *
 * Compilation: gcc -o queue queue.c
 * Execution:./queue_1
 *
 * @Aniket , (1910990836) , 05/07/2021
 * Day_2_Coding_Assignment
 */
#include<stdio.h>
#include<stdlib.h>
#define N 100

//intializing queue
int queue[N];
//variable to store index of head of the queue.
int head = -1;
//variable to store index of tail of the queue.
int tail = -1;

/**
 * Function to enqueue an element at tail of the queue
 */

void enqueue()
{
    int x;
    if((tail + 1) % N == head)
    {
        printf("Queue OverFlow");
    }
    else
    {	
	printf("Enter Element To Enqueue : ");
	scanf("%d", &x);

        if(tail == -1)   //Empty Queue
	{
            tail = head = 0;
	    queue[tail] = x;
	}
	else
	{   
	    tail = (tail + 1) % N ;     // condition for circular queue
	    queue[tail] = x;
	}
    }
}

int is_empty()
{
    if(head == -1)
        return 1;
    else
	return 0;
}

/**
 * Function to delete element from head of the queue.
 */
int dequeue()
{
    int y;
    if(is_empty())
    {
        printf("Queue UnderFlow");
    }
    else
    {
        y = queue[head];
	if(head == tail)   //Only One Element
	{
	    head = tail = -1;
	    printf("\nElement Deleted : %d",y);
	    return y; 
	}
	else
	{
            head = (head + 1) % N ;     // condition for circular queue
	    printf("\nElement Deleted : %d",y);
	    return y;
	}
    }
}

/**
 * Function to print the element at the tail of the queue
 */

void peek()
{
    printf("%d", queue[tail]);
}

/**
 * Function to print elements in the queue.
 */
void print()
{
    if( head == -1 )
    {
        printf("\nQueue is Empty!!!");
	return ;
    }
    if( tail >= head )
    {
    for(int i = head ; i <= tail ; i++ )
        printf("%d\n",queue[i]);
    }
    else
    {
        for( int i = head; i < N ; i++ )
	{
	    printf("%d ", queue[i]);
	}
	for( int i = 0; i <= tail ; i++ )
	{
            printf("%d ", queue[i]);
	}
    }
}

int main()
{
    int op;
    printf("\nQueue Operations");
    printf("\n1. Enqueue \n2. Dequeue \n3. Peek \n4. Print Queue \n5. Exit");
    while(1)
    {
        printf("\nEnter Operation : ");
        scanf("%d",&op);

        switch(op)
        {
            case 1: enqueue();
                    break;
	    case 2: dequeue();
                    break;
            case 3: peek();
                    break;
            case 4: print();
                    break;
            case 5: exit(0);

            default: printf("Enter Valid Operation");
                     break;
        }
    }

}

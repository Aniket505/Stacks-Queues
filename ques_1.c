#include<stdio.h>
#define MAXSIZE 100
#define N 100
//intializing stack
int stack[MAXSIZE];
//variable to store index of topmost element in stack
int top = -1;

/**
 * Function to push an element at top of the stack
 */
void push(int item) {
    
    if(top >= MAXSIZE - 1 )
    {
        printf("Stack Overflow");
        return;
    }
    else
    {
        top++;
        stack[top] = item;
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
        return item;
    }
}
/** 
 * Function to print the topmost element of the stack.
 *
 */
int peek()
{
    return stack[top];
}
    
int bracket_balanced(char *s)
{
    char x;
    for( int i = 0; i < N ; i++ )
    {
        if( s[i] == '{' || s[i] == '(' || s[i] == '[' )
	{
	    push(s[i]);
	    continue;
	}

	if( is_empty())
	    return 1;

	switch (s[i]) {
            case ']' : x = peek();
		       pop();
		       if( x == '{' || x == '(' )
			   return 0;
		       break;
            case '}' : x = peek();
                       pop();
                       if( x == '[' || x == '(' )
                           return 0;
                       break;
            case ')' : x = peek();
                       pop();
                       if( x == '{' || x == '[' )
                           return 0;
                       break;

	}
    }
    return (is_empty());
}

int main() 
{
    char str[100];
    printf("Enter String : ");   
    gets(str);
    int x = bracket_balanced(str);
    printf("%d\n",x);
    if(x == 1)
	printf("Balanced");
    else
	printf("Not Balanced");
}

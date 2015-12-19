#include <stdio.h>
#include <stdlib.h>

int TOP = -1, STACK[50];

int push(int value)
{
    if (TOP == 50)
    {
        printf ("Stack Overflow\n");
        return -1;
    }
    TOP++;
    STACK[TOP] = value;

    return 0;
}

int pop()
{
    if (TOP == -1)
    {
        printf ("Stack Underflow\n");
        return -1;
    }
    printf ("Popping %d from the stack\n", STACK[TOP]);
    STACK[TOP] = '\0';
    TOP--;

    return 0;
}

int traverse()
{
    if (TOP == -1)
    {
        printf ("Stack doesn't contain any value\n");
        return -1;
    }

    int i;

    printf ("The elements in the stack are: ");
    for (i = TOP; i >= 0; i--)
        printf ("%d\t", STACK[i]);
    printf ("\nTop Of Stack = %d\n", STACK[TOP]);

    return 0;
}

int main()
{
    int ch, val;

    printf ("STACK (LIFO) Algorithm\n");
    while(1)
    {
        printf ("1.Push in stack\n2.Pop from stack\n3.Traverse\n4.Exit\nEnter your choice: ");
        scanf ("%d", &ch);
        if (!ch)
            exit(-1);

        switch(ch)
        {
            case 1:
                printf ("Enter the value you want to insert: ");
                scanf ("%d", &val);
                printf ("Pushing %d into stack\n", val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf ("Invalid choice\n");
                break;
        }
    }
    return 0;
}

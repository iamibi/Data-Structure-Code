#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;
int queue[10];

int insert(int value)
{
    if (rear == 10)
    {
        printf ("Queue Overflow\n");
        return 0;
    }

    printf ("Inserting the value %d in the queue\n", value);
    if (rear == -1)
        front = rear = 0;
    else
        rear++;
    queue[rear] = value;

    return 0;
}

int delete()
{   
    if (front == -1)
    {
        printf ("Queue Underflow\n");
        return 0;
    }
    printf ("Value to be deleted from the queue is %d\n", queue[front]);
    queue[front] = '\0';
    front++;
    if (front == rear + 1)
    {
        front = rear = -1;
        return 0;
    }

    return 0;
}

int traverse()
{
    int i;

    if (front == -1)
    {
        printf ("No data in the queue\n");
        return 0;
    }
    printf ("The values in the queue are: ");
    for (i = front; i <= rear; i++)
        printf ("%d -> ", queue[i]);
    printf ("\n");
    return 0;
}

int main()
{
    printf ("Program to implement queue(FIFO)\n");

    int ch, val;

    while(1)
    {
        printf ("1.Insert\n2.Delete\n3.Traverse\n4.Exit\nEnter your choice: ");
        scanf ("%d", &ch);
        if (!ch)
            return -1;

        switch(ch)
        {
            case 1:
                printf ("Enter the value you want to insert in the queue: ");
                scanf ("%d", &val);
                insert(val);
                break;
            case 2:
                delete();
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf ("Invalid Choice\n");
                break;
        }
    }
    return 0;
}

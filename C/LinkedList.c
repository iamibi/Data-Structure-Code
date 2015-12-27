/*
 *
 * Linked List Program
 * 
*/

#include <stdio.h>
#include <stdlib.h>

long int count = 0;

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *start = NULL;

void insert_at_beg()
{
    Node *ptr;

    ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf ("Insufficient Memory, Please delete some nodes from the list\n");
        return;
    }
    printf ("Enter the value you want to insert at the beginning: ");
    scanf ("%d", &(ptr -> data));
    ptr -> next = start;
    start = ptr;
    count++;
}

void insert_at_end()
{
    Node *ptr;

    ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf ("Insufficient Memory, Please delete some nodes from the list\n");
        return;
    }
    printf ("Enter the value you want to insert at the end: ");
    scanf ("%d", &(ptr -> data));
    if (start == NULL)
    {
        ptr -> next = start;
        start = ptr;
        printf ("No node in the list. This is the first node\n");
    }
    else
    {
        Node *loc;

        loc = start;
        while (loc != NULL)
            loc = loc -> next;
        loc -> next = ptr;
        ptr -> next = NULL;
    }
    count++;
}

void insert_in_between()
{
    Node *ptr;

    ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf ("Insufficient Memory, Please delete some nodes from the list\n");
        return;
    }
    int loc, temp = 0;

    printf ("Enter the value you want to insert in between: ");
    scanf ("%d", &(ptr -> data));
    if (start == NULL)
    {
        ptr -> next = start;
        start = ptr;
        printf ("No Node present in the list. This is the first node\n");
        count++;
        return;
    }

    while (1)
    {
        printf ("Enter the location where you want to insert the node: ");
        scanf ("%d", &loc);
        if (loc < count && loc >= 0)
            break;
        else
            printf ("The location is not valid\n");
    }
    Node *locA;

    locA = start;
    while (temp < loc)
    {
        locA = locA -> next;
        temp++;
    }

    ptr -> next = locA -> next;
    locA -> next = ptr;
}

void delete()
{
    Node *curr, *prev;

    curr = start;
    if (curr == NULL)
    {
        printf ("No data to delete from the list\n");
        return;
    }
    int ch, val, temp = 0, i;

    printf ("How do you want to delete the data?\n1.By Value\n2.By Location\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
        case 1:
        {
            printf ("Enter the value you want to delete: ");
            scanf ("%d", &val);
            prev = curr;
            while (curr -> data != val)
            {
                temp++;
                prev = curr;
                curr = curr -> next;
                if (curr == NULL)
                {
                    printf ("The value doesn't exist\n");
                    return;
                }
            }
            prev -> next = curr -> next;
            curr -> data = '\0';
            free(curr);
            curr = NULL;
            break;
        }
        case 2:
        {
            while (1)
            {
                printf ("Enter the location of the node you want to delete: ");
                scanf ("%d", &val);
                if (val >= count || val < 0)
                    printf ("The location doesn't exist\n");
                else
                    break;
            }
            prev = curr;
            for (i = 0; i < val; i++)
            {
                prev = curr;
                curr = curr -> next;
            }
            prev -> next = curr -> next;
            curr -> data = '\0';
            free(curr);
            curr = NULL;
            break;
        }
        default:
            printf ("Invalid Choice\n");
            break;
    }
    count--;
}

void traverse()
{
    if (start == NULL)
    {
        printf ("No node to traverse\n");
        return;
    }
    Node *ptr;

    ptr = start;
    while (ptr != NULL)
    {
        printf (" -> %d", ptr -> data);
        ptr = ptr -> next;
    }
    printf ("\nNumber of nodes present = %ld\n", count);
}

int main()
{
    int ch;

    while (1)
    {
        printf ("Single Linked List Program\n1.Insert a node at beginning\n2.Insert a node at the end\n3.Insert a node in between\n4.Delete a node\n5.Traverse\n6.Exit\nEnter your choice: ");
        scanf ("%d", &ch);
        switch (ch)
        {
            case 1:
                insert_at_beg();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                insert_in_between();
                break;
            case 4:
                delete();
                break;
            case 5:
                traverse();
                break;
            case 6:
                exit(0);
            default:
                printf ("Wrong Choice\n");
                break;
        }
    }
    return 0;
}

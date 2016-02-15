/*
 *
 * Linked List Program
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head = NULL;

//function prototypes
int ListLength(void);
void insert(int, int);
void delete(int);
void traverse(void);
void free_list(void);

int main(void)
{
    int choice, val, pos;

    while (1)
    {
        printf ("Linked List Program\n");
        printf ("1.Insert at beginning\n2.Insert at end\n3.Insert in between\n4.Delete from beginning\n5.Delete from end\n6.Delete from between\n7.Traverse\n8.Exit\nEnter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1:
                printf ("Enter the value to be inserted: ");
                scanf ("%d", &val);
                insert(1, val);
                break;
            case 2:
                printf ("Enter the value to be inserted: ");
                scanf ("%d", &val);
                insert(ListLength() + 1, val);
                break;
            case 3:
                printf ("Enter the value to be inserted: ");
                scanf ("%d", &val);
                printf ("Enter the position of insertion of this node: ");
                scanf ("%d", &pos);
                insert(pos, val);
                break;
            case 4:
                printf ("Deleting the node from the beginning...\n");
                delete(1);
                break;
            case 5:
                printf ("Deleting the node from the end...\n");
                delete(ListLength());
                break;
            case 6:
                printf ("Enter the position from where you want the node to be deleted: ");
                scanf ("%d", &pos);
                delete(pos);
                break;
            case 7:
                traverse();
                break;
            case 8:
                free_list();
                exit(0);
            default:
                printf ("...Invalid Choice, Enter again...\n");
        }
    }
    return 0;
}

void free_list(void)
{
    if (head == NULL)
        return;

    node *aux, *iter;

    iter = head;
    while (iter)
    {
        aux = iter -> next;
        free(iter);
        iter = NULL;
        iter = aux;
    }
    head = NULL;
}

int ListLength(void)
{
    node *ptr = head;
    int count = 0;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr -> next;
    }

    return count;
}

void insert(int position, int value)
{
    node *newNode;

    newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf ("Memory Unavailable\n");
        return;
    }

    newNode -> data = value;

    if (position == 1)
    {
        newNode -> next = head;
        head = newNode;
    }
    else
    {
        int k = 1;
        node *p, *q;

        p = head;
        while (p != NULL && k < position)
        {
            k++;
            q = p;
            p = p -> next;
        }
        q -> next = newNode;
        newNode -> next = p;
    }
}

void delete(int position)
{
    if (head == NULL)
    {
        printf ("List is Empty.\n");
        return;
    }

    node *p;

    p = head;
    if (position == 1)
    {
        head = head -> next;
        free (p);
        p = NULL;
        printf ("Deletion successfull\n");
    }
    else
    {
        int k = 1;
        node *q;

        while (p != NULL && k < position)
        {
            k++;
            q = p;
            p = p -> next;
        }
        if (p == NULL)
            printf ("Position doesn't exist.\n");
        else
        {
            q -> next = p -> next;
            free(p);
            p = NULL;
            printf ("Deletion Successfull\n");
        }
    }
}

void traverse(void)
{
    if (head == NULL)
    {
        printf ("List is empty\n");
        return;
    }
    node *ptr;

    ptr = head;
    while (ptr != NULL)
    {
        printf ("-> %d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf ("\n");
}

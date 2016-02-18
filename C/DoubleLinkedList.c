/*
 *
 * Double Linked List
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct dll
{
    int data;
    struct dll *next;
    struct dll *prev;
}dll;

dll *head = NULL;

int ListCount(void);
void insert(int, int);
void delete(int);
void traverse_beg(void);
void traverse_end(void);
void free_list(void);

int main()
{
    int ch, val, pos;

    while (1)
    {
        printf ("Double Linked List\n");
        printf ("1.Insert at beginning\n2.Insert at end\n3.Insert in between\n4.Delete from beginning\n5.Delete from end\n6.Delete from in between\n7.Traverse from start\n8.Traverse from end\n9.Exit\n");
        printf ("Enter your choice: ");
        scanf ("%d", &ch);
        switch(ch)
        {
            case 1:
                printf ("Enter the value to insert: ");
                scanf ("%d", &val);
                insert(1, val);
                break;
            case 2:
                printf ("Enter the value to insert: ");
                scanf ("%d", &val);
                insert(ListCount(), val);
                break;
            case 3:
                printf ("Enter the value to insert: ");
                scanf ("%d", &val);
                printf ("Enter the position of insertion: ");
                scanf ("%d", &pos);
                insert(pos, val);
                break;
            case 4:
                delete(1);
                break;
            case 5:
                delete(ListCount());
                break;
            case 6:
                printf ("Enter the position you want to delete the node from: ");
                scanf ("%d", &pos);
                delete(pos);
                break;
            case 7:
                traverse_beg();
                break;
            case 8:
                traverse_end();
                break;
            case 9:
                free_list();
                exit(0);
            default:
                printf ("Invalide Choice\n");
        }
    }
    return 0;
}

void traverse_beg(void)
{
    if (head == NULL)
    {
        printf ("Nothing to traverse.\n");
        return;
    }

    dll *ptr;

    ptr = head;

    while (ptr != NULL)
    {
        printf ("-> %d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf ("\n");
}

void traverse_end(void)
{
    if (head == NULL)
    {
        printf ("Nothing to traverse.\n");
        return;
    }

    dll *ptr;

    ptr = head;

    while (ptr -> next != NULL)
        ptr = ptr -> next;

    while (ptr != NULL)
    {
        printf ("-> %d ", ptr -> data);
        ptr = ptr -> prev;
    }
    printf ("\n");
}

int ListCount(void)
{
    if (head == NULL)
        return 0;

    dll *ptr;
    int count = 0;

    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr -> next;
    }

    return count;
}

void free_list(void)
{
    if (head == NULL)
        return;
    dll *iter, *aux;
    
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

void insert(int position, int value)
{
    dll *newNode;

    newNode = (dll *)malloc(sizeof(dll));
    if (newNode == NULL)
    {
        printf ("Memory Error.\n");
        return;
    }
    newNode -> data = value;
    if (position == 1)
    {
        newNode -> next = head;
        newNode -> prev = NULL;

        if (head)
            head -> prev = newNode;

        head = newNode;
        return;
    }
    dll *temp;

    temp = head;
    int k = 1;

    while (k < position - 1 && temp -> next != NULL)
    {
        temp = temp -> next;
        k++;
    }
    if (k != position - 1)
        printf ("The desired position doesn't exist. Inserting at the previous position known.\n");
    newNode -> next = temp -> next;
    newNode -> prev = temp;

    if (temp -> next)
        (temp -> next) -> prev = newNode;

    temp -> next = newNode;
    return;
}

void delete(int position)
{
    if (head == NULL)
    {
        printf ("Empty List\n");
        return;
    }

    dll *temp;

    temp = head;

    if (position == 1)
    {
        head = head -> next;

        if (head != NULL)
            head -> prev = NULL;
        free(temp);
        temp = NULL;
        return;
    }

    dll *ptr;
    int k = 1;

    while (k < position && temp -> next != NULL)
    {
        temp = temp -> next;
        k++;
    }

    if (k != position)
        printf ("Desired position doesn't exist\n");

    ptr = temp -> prev;
    ptr -> next = temp -> next;

    if (temp -> next)
        (temp -> next) -> prev = ptr;

    free (temp);
    temp = NULL;
}

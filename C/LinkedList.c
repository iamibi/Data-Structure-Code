/*
*This program is of linked list for insertion at different positions i.e,
*either at starting, after end or in between.
*Then traversing the whole list.
*Made by Ibrahim. 16/9/2014.
*/

#include<stdio.h>
#include<stdlib.h>

int traverse();
int insert_at_beg();
int insert_at_end();
int insert_in_between();

struct node
{
	int data;
	struct node *link;
};
struct node *start;

main()
{
	int choice;
	
	while(1)
	{
		printf("Linked List Operations are\n");
		printf("1.Insert element at beginning\n2.Insert element at End\n3.Insert element in between\n4.Traverse Linked List\n5.Delete\n6.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
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
					traverse();
					break;
			case 5:
					delete();
					break;
			case 6:
					exit(0);
			default:
					printf("Wrong Choice\n");
		}
	}
	return 0;
}

int traverse()
{
	struct node *p;
	p=start;
	if(p == NULL)
	{
		printf("No Node\n");
	}
	while(p != NULL)
	{
		printf("%d \t",p->data);
		p = p -> link;
	}
	printf("\n");
	return 0;
}

int insert_at_beg()
{
	struct node *ptr;
	int value;
	ptr = (struct node *)malloc(sizeof(struct node));
	printf("Enter a value to insert in the beginning: ");
	scanf("%d",&value);
	ptr -> data = value;
	if(start == NULL)
	{
		ptr -> link = NULL;
		printf("The very first node inserted\n");
	}
	else
	{
		ptr -> link = start;
		printf("Insertion Successfull\n");
	}
	start = ptr;
	return 0;
}

int insert_at_end()
{
	struct node *ptr, *loc;
	int val;
	ptr = (struct node *)malloc(sizeof(struct node));
	printf("Enter a value to insert in the end: ");
	scanf("%d",&val);
	ptr -> data = val;
	ptr -> link = NULL;
	if(start == NULL)
	{
		start = ptr;
		printf("The very first node inserted\n");
	}
	else
	{
		loc = start;
		while(loc -> link != NULL)
		{
			loc = loc -> link;
		}
		loc -> link = ptr;
		printf("Insertion Successful at the end\n");
	}
	return 0;
}

int insert_in_between()
{
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node));
	int loca, value1,i;
	if(ptr==NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		printf("Enter a value to insert in between: ");
		scanf("%d",&value1);
		ptr->data=value1;
		if(start == NULL)
		{
			ptr->link=NULL;
			start=ptr;
			printf("The very first node inserted successfully\n");
		}
		else
		{
			printf("Enter a location: ");
			scanf("%d",&loca);
			temp=start;
			for(i=0;i < loca-1;i++)
			{
				temp = temp -> link;
			}
			ptr->link = temp->link;
			temp->link = ptr;
		}
	}
	return 0;
}
int delete()
{
	struct node *temp, *prev;
	float value;
	if(start == NULL)
	{
		printf("UNDERFLOW\n");
	}
	else
	{
		printf("Enter the value to be deleted: ");
		scanf("%f",&value);
    		temp = start;
    		while(temp != NULL)
    		{
    			if(temp -> data == value)
    			{
    	  	  		if(temp == start)
    	    			{
    	    				start = temp -> link;
        				free(temp);
        				return 1;
        			}
        			else
        			{
        				prev -> link = temp -> link;
        				free(temp);
       					return 1;
        			}
    			}
    			else
    			{
        			prev = temp;
        			temp = temp -> link;
    			}
    		}
	}
	return 0;
}

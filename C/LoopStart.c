struct node *FindTheStartOfLoop(struct node* head)
{
    struct node *slow, *fast;
    int flag = 0;

    slow = fast = head;

    while (slow && fast && fast -> next)
    {
        slow = slow -> next;
        fast = (fast -> next) -> next;
        if (slow == fast)
        {
            flag = 1;
            break;
        }
    }

    //loop exist
    if (flag)
    {
        slow = head;

        while (slow != fast)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }
    return NULL;
}

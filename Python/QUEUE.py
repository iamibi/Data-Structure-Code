import sys

queue = []
front = -1
rear = -1

def traverse():
    global queue, front, rear
    if rear == -1:
        print ("No Value in the queue")
        return 0
    
    for i in queue:
        print (" -> %s"%(i), end = '')
    print ()

    return 0

def delete():
    global queue, front, rear
    if front == -1 or len(queue) == 0:
        print ("Queue Underflow")
        return 0

    print ("Popping the value %s from the queue"%(queue.pop(front)))
    front = 0
    
    if front == rear + 1:
        front = rear = -1
        
    return 0

def insert(value):
    global queue, front, rear
    if rear == 10:
        print ("Queue Overflow")
        return 0
    
    print ("Inserting %s in the queue"%(value))
    if rear == -1:
        front = rear = 0
    else:
        rear = rear + 1
    queue.insert(rear, value)

    return 0

def main():
    while True:
        print ("Queue Program\n1.Insert\n2.Delete\n3.Traverse\n4.Exit\nEnter your choice: ", end = '')
        ch = int(input())
        if ch == 1:
            val = int(input("Enter the value you want to insert: "))
            insert(val)
        elif ch == 2:
            delete()
        elif ch == 3:
            traverse()
        elif ch == 4:
            sys.exit("Exiting...")
        else:
            print ("Invalid Choice")

    return 0

if __name__ == '__main__':
    main()

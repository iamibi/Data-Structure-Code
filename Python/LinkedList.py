import sys;

count = 0;

class Node:
    def __init__(self, value):
        self.data = value;
        self.next = None;
    def getData(self):
        return self.data;
    def getNext(self):
        return self.next;
    def setData(self, val):
        self.data = val;
    def setNext(self, nxt):
        self.next = nxt;

class List:
    def __init__(self):
        self.head = None;
        
    def isEmpty(self):
        return self.head == None;
    
    def Insert(self, item):
        global count;

        count = count + 1
        temp = Node(item);
        temp.setNext(self.head);
        self.head = temp;
        
        
    def Size(self):
        global count;
        return count;

    def Traverse(self):
        global count
        temp = self.head;

        while temp != None:
            print ("%d -> "%(temp.getData()), end = '');
            temp = temp.getNext();
        print ("Number of nodes = %d"%(count))
        
    def Search(self, val):
        ptr = self.head;
        found = False;

        while ptr != None and not found:
            if ptr.getData() == val:
                found = True;
            else:
                ptr = ptr.getNext();

        return found;

    def Delete(self, item):
        current = self.head;
        prev = None;
        found = False;
        while not found:
            if current.getData() == item:
                found = True;
            else:
                prev = current;
                current = current.getNext();

        if prev == None:
            self.head = current.getNext();
        else:
            prev.setNext(current.getNext());
        count = count - 1;
            
def main():
    try:
        print ("Linked List Program in Python");
        LinkedList = List();
        
        while True:
            ch = int(input("1.Insert\n2.Delete\n3.Traverse\n4.Exit\nEnter your choice: "));
            if ch == 1:
                val = int(input("Enter the value to insert: "));
                if LinkedList.isEmpty():
                    print ("First Node Inserted");
                LinkedList.Insert(val);
            elif ch == 2:
                if LinkedList.isEmpty():
                    print ("---Underflow---");
                else:
                    val = int(input("Enter the value to be deleted: "));
                
                    if LinkedList.Search(val):
                        LinkedList.Delete(val);
                    else:
                        print ("The value doesn't exist in the list");
            elif ch == 3:
                if LinkedList.isEmpty():
                    print ("Nothing to traverse");
                else:
                    LinkedList.Traverse();
            elif ch == 4:
                sys.exit("Exiting...");
            else:
                print ("Invalid Choice")
                
    except Exception as er:
        print ("Something has gone wrong: " + str(er));

if __name__ == '__main__':
    main();

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
    
    def add(self, item):
        temp = Node(item);
        temp.setNext(self.head);
        self.head = temp;
        
    def size(self):
        current = self.head;
        count = 0;

        while current != None:
            count = count + 1;
            current = current.getNext()

        return count;

    def Traverse(self):
        temp = self.head;

        while temp != None:
            print ("%d -> "%(temp.getData()), end = '');
            temp = temp.getNext();
        print ()

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
            prev.setNext(current.getNext())
def main():
    print ("Linked List Program in Python")

if __name__ == '__main__':
    main()

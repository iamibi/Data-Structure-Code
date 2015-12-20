import sys

TOP = -1
STACK = []

def traverse():
    global TOP
    global STACK

    for i in STACK:
        print ("%s "%(i), end = '')
    print ("\nTop of Stack %s"%(STACK[TOP]))
    return 0
def pop():
    global TOP
    global STACK

    if TOP == -1:
        print("Stack Underflow")
        return 0

    print ("Popping the value %s"%(STACK[TOP]))
    STACK.pop(TOP)
    TOP = TOP - 1

    return 0

def push(val):
    global TOP
    global STACK

    if (TOP == 10):
        print ("Stack Overflow")
        return 0
    TOP = TOP + 1
    STACK.insert(TOP, val)

    return 0

def main():
    while True:
        ch = int(input("1.Push\n2.Pop\n3.Traverse\n4.Exit\nEnter what you want to do: "))
        if ch == 1:
            val = int(input("Enter the value to push into stack: "))
            push(val)
        elif ch == 2:
            pop()
        elif ch == 3:
            traverse()
        elif ch == 4:
            sys.exit("Exiting")
        else:
            print("-----------------Invalid Choice--------------------")

if __name__ == '__main__':
    main()

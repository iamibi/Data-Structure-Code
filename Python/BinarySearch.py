'''
    Binary Search Function definition
'''

def BinarySearch(L, n):
    #if the list is empty
    if len(L) == 0:
        return False

    lower = 0
    upper = len(L) - 1

    mid = int((lower + upper) / 2)

    while lower <= upper:
        if L[mid] == n:
            return True
        elif n > L[mid]:
            lower = mid + 1
        elif n < L[mid]:
            upper = mid - 1
        mid = int((lower + upper) / 2)

    #the number n doesn't exist in the list
    if lower > upper:
        return False

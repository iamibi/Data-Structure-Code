/*
 * Insertion Sort
 * 
 * function definition
 * Complexity: O(n^2)
*/
int InsertionSort(int a[], int s)
{
    int i, temp, j;
    
    for(i = 1; i < s; i++)
    {
        temp = a[i];
        j = i - 1;
        while(temp < a[j] && j >= 0)
        {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = temp;
    }
    return 0;
}

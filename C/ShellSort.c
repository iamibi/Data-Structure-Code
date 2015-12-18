int ShellSort (int ar[], int n)
{
    int i, j, key;
    int h = 0;

    while (h < n)
        h = h * 3 + 1;
                
    while (h > 0)
    {
        for ( j = h; j <= n; j++ )
        {
            key = ar[j];
            i = j - h;

            while (i >= h && ar[i] > key)
            {
                ar[i+h] = ar[i];
                i -= h;
            }
            ar[i+h] = key;
        }
        h /= 3;
    }
    return 0;
}

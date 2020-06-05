void puzzle (int* data, int n, bool* extra, int k)
{
    // data contains n distinct numbers from 1 to n + k, extra provides
    // space for k extra bits.

    // Rearrange the array so there are (even) even numbers at the start
    // and (odd) odd numbers at the end.
    int even = 0, odd = 0;
    while (even + odd < n)
    {
        if (data [even] % 2 == 0) ++even;
        else if (data [n - 1 - odd] % 2 == 1) ++odd;
        else { int tmp = data [even]; data [even] = data [n - 1 - odd];
               data [n - 1 - odd] = tmp; ++even; ++odd; }
    }

    // Erase the lowest bits of all numbers and set the extra bits to 0.
    for (int i = even; i < n; ++i) data [i] -= 1;
    for (int i = 0; i < k; ++i) extra [i] = false;

    // Set a bit for every number that is present
    for (int i = 0; i < n; ++i)
    {
        int tmp = data [i];
        tmp -= (tmp % 2);
        if (i >= odd) ++tmp;
        if (tmp <= n) data [tmp - 1] += 1; else extra [tmp - n - 1] = true;
    }

    // Print out the missing ones
    for (int i = 1; i <= n; ++i)
        if (data [i - 1] % 2 == 0) printf ("Number %d is missing\n", i);
    for (int i = n + 1; i <= n + k; ++i)
        if (! extra [i - n - 1]) printf ("Number %d is missing\n", i);

    // Restore the lowest bits again.
    for (int i = even; i < n; ++i) data [i] += 1;
}

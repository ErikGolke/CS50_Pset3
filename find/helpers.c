/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
#include <cs50.h>



#include "helpers.h"
// This program conducts a binary search on 
// a sorted array of numbers.
bool bSearch(int value, int values[], int min, int max)
{
    // if min is more than max, number is not in the array.
    if (min > max)
    {
        return false;
    }
    else
    {
        // divides the array by 2
        int mid = (min + max) / 2;
        
        // if mid is less than value, change mid to the right
        if (values[mid] < value)
        {
            return bSearch(value, values, mid + 1, max);
        }
        // if mid is more than value, change mid to the left
        else if (values[mid] > value)
        {
            return bSearch(value, values, min, mid - 1);
        }
        // if mid is the value, returns found
        else if (values[mid] == value)
        {
            return true;
        }
    }
    return false;

}
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    return bSearch(value, values, 0, n - 1);
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int i, j, temp;
    
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {   
            if (values[i] > values[j])
            {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
    return;
}
/* Write a program that asks the user to enter a series of integers (which it stores 
 * in an array), then sorts the integers by calling the function selection_sort.
 * When given an array with n elements, selection_sort must do the following:
 * 1. Search the array to find the largest element, then move it to the last position in the array
 * 2. Call itself recursively to sort the first n-1 elements of the array
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXLEN 100
#define neg_inf -1000000

/* incorrect version 
void selection_sort(int n, int arr[n]) {
   long largest = neg_inf;
    int tmp, idx_largest, i;
    bool sorted = true;

    for (i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
            idx_largest = i;
        }
    }
    // perform swap
    tmp = arr[n];
    arr[n] = largest;
    arr[i] = tmp;

    if (n <= 1)
        selection_sort(n-1, arr);

}
*
* The above version presented some issues:
* 1. wrong array indexing (should go up until n-1 not n)
* 2. incorrect swap logic: should be swapping the largest element with the last element
* of the unsorted part of the array.
* 3. Recursive base case was wrong: should stop when n<=1, not when n==0.
*/

void selection_sort(int n, int arr[]) {
    if (n <= 1) return;

    int largest_idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[largest_idx]) {
            largest_idx = i;
        }
    }

    int temp = arr[n - 1];
    arr[n - 1] = arr[largest_idx];
    arr[largest_idx] = temp;

    selection_sort(n - 1, arr);
}

int main(void) {
    char c, arr[MAXLEN];
    int i = 0, idx = 0, nums[MAXLEN], n = 0;
    printf("Enter numbers (max %d): ", MAXLEN);
    while ((c = getchar()) != '\n') {
        // adds characters to the array of chars
        arr[i++] = c;
        // assumes that each number is separated by a blank space
        if (c == ' ') {
            // adds string terminator to make it a variable length string
            arr[i] = '\0';
            // compute the length of the array of chars storing the number as a string
            int len = strlen(arr);
            // adds to the nums array the integer representation of the string
            nums[idx++] = atoi(arr);
            // this is to clean the array
            for (int x = 0; x < len; x++) 
                arr[x] = 0;
            // resets to zero so that the new numbers can be written starting from the beginning
            i = 0;
            // keeps track of actual length of the array as new elements are added to it
            n++;
        }
    }
    
    // Add null terminator to last part since it is not necessarily followed by a ' ' blank space character
        arr[i] = '\0';
        nums[idx++] = atoi(arr);
        n++;

    selection_sort(n, nums);

    printf("Sorted numbers: ");
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);
    putchar('\n');
    
    return 0;
}

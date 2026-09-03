#include <iostream>
using namespace std;

// Function to remove duplicate elements from the array
void removeDuplicates(int *arr, int n)
{
    // 'a' represents the current/remaining size of the array.
    // It decreases whenever a duplicate element is removed.
    int a = n;

    // Select each element one by one
    for (int i = 0; i < a; i++)
    {
        // Compare the current element with all elements
        // that come after it.
        for (int j = i + 1; j < a; j++)
        {
            // *(arr + i) means arr[i]
            // *(arr + j) means arr[j]
            //
            // If both elements are equal, a duplicate is found.
            if (*(arr + i) == *(arr + j))
            {
                // A duplicate has been found at position j.
                // Shift every element after j one position to the left.
                //
                // Example:
                // Before:  2  4  9  2  9  3
                //                 ↑
                //              duplicate
                //
                // After shifting:
                //         2  4  9  9  3
                for (int k = j; k < a - 1; k++)
                {
                    // Move the next element into the current position.
                    // *(arr + k)     = arr[k]
                    // *(arr + k + 1) = arr[k + 1]
                    *(arr + k) = *(arr + k + 1);
                }

                // The array now has one less valid element
                // because the duplicate was removed.
                a--;

                // Since the elements were shifted left,
                // check the current position again.
                j--;
            }
        }
    }

    // Print the array after removing duplicates.
    for (int i = 0; i < a; i++)
    {
        cout << *(arr + i) << " ";
    }
}

int main()
{
    // Create an array containing some duplicate values.
    int arr[] = {2, 4, 9, 2, 9, 3, 9, 6};

    // Call the function.
    // arr = address of the first element
    // 8   = number of elements in the array
    removeDuplicates(arr, 8);

    return 0;
}
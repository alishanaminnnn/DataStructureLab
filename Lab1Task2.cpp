#include <iostream>
using namespace std;

int main()
{
    // Create an array
    int arr[] = {3, 4, 7, 10, 9, 1};

    // Assume the first element is the smallest
    int smallest = *(arr + 0);

    // Store the index of the smallest number
    // Initially, index 0 is assumed to be the smallest
    int a = 0;

    // Find the smallest number and its index
    for (int i = 0; i < 6; i++)
    {
        // Compare the current element with the smallest
        if (*(arr + i) < smallest)
        {
            // Update the smallest number
            smallest = *(arr + i);

            // Store the index of the new smallest number
            a = i;
        }
    }

    // Display the smallest number
    cout << "Smallest: " << smallest << endl;

    // Reset smallest to the first element
    // because we now want to find the second smallest
    smallest = *(arr + 0);

    // Go through the array again
    for (int i = 1; i < 6; i++)
    {
        // Check two conditions:
        // 1. Current element must be smaller than 'smallest'
        // 2. Current index must not be the index of the actual smallest
        if (*(arr + i) < smallest && i != a)
        {
            // Update smallest
            // This will actually become the second smallest
            smallest = *(arr + i);
        }
    }

    // Display the second smallest number
    cout << "Second Smallest: " << smallest << endl;

    return 0;
}
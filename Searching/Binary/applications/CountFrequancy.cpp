#include <iostream>
using namespace std;

// count freq = upperbound - lowerbound
int lowerBound(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    int ans = size; // def value if target is greater than all elements in the array
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int upperBound(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    int ans = size; // def value if target is greater than all elements in the array
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
        {
            ans = mid; // may be the answer but we need to check if there is a smaller index with the same condition
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int countFrequency(int arr[], int size, int target)
{
    int lb = lowerBound(arr, size, target);
    int ub = upperBound(arr, size, target);
    return (ub - lb);
}

int main()
{
    return 0;
}
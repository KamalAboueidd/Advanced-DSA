#include <iostream>

using namespace std;

int lowerBound(int arr[], int size, int target)
{
    int low = 0;
    int hight = size - 1;
    int ans = size; // def value if target is greater than all elements in the array
    while (low <= hight)
    {
        int mid = low + (hight - low) / 2;
        if (arr[mid] >= mid)
        {
            ans = mid;
            hight = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int upperBound(const int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    int ans = size;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
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

int main()
{
   int arr[] = {10, 20, 20, 20, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 20;

    int lb = lowerBound(arr, size, target);
    int ub = upperBound(arr, size, target);

    cout << "Lower Bound index of " << target << ": " << lb << "\n";
    cout << "Upper Bound index of " << target << ": " << ub << "\n";
    cout << "Frequency of " << target << ": " << (ub - lb) << "\n";

    return 0;
}
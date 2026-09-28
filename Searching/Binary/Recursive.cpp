#include <iostream>
using namespace std;
int binarySearchrecursive(int arr[], int low, int hight, int target)
{
    if (low > hight) // base case
    {
        return -1;
    }
    int mid = low + (low - hight) / 2;
    if (arr[mid] == target) // alse base case
    {
        return mid;
    }
    if (arr[mid] < target)
    {
        return binarySearchrecursive(arr, mid + 1, hight, target);
    }

    return binarySearchrecursive(arr, low, hight - 1, target);
}
int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearchrecursive(arr, 0, size - 1, target);

    if (result != -1)
    {
        cout << "Element found at index: " << result << "\n";
    }
    else
    {
        cout << "Element not found.\n";
    }

    return 0;
}
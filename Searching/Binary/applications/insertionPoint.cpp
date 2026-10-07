#include <iostream>
#include <vector>
using namespace std;

int FindInsertionPoint(const vector<int> &vec, int target)
{
    int low = 0;
    int high = vec.size() - 1;
    int ans = vec.size(); // Default value if target is greater than all elements in the vector

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (vec[mid] >= target)
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
    vector<int> vec = {1, 3, 5, 7, 9};
    int newElement = 6;
    int insertionPoint = FindInsertionPoint(vec, newElement);
    cout << "Optimal insertion index for " << newElement << " is: " << insertionPoint << "\n";
    vec.insert(vec.begin() + insertionPoint, newElement);
    cout << "Vector after insertion: ";
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << "\n";
    return 0;
}
  //vector works not with index but with iterators so we use vec.begin() + insertionPoint to get the correct position for insertion.
  // vec.begin() refere to the iterator of the first element of the vector 
  // insert method takes an iterator as the first argument, which specifies where to insert the new element. By adding insertionPoint to vec.begin(), we get the correct position in the vector for the new element.
  // after arrived at the correct position we can insert the new element into the vector using the insert method , and shift the subsequent elements to the right to make space for the new element.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
void BucketSorting(vector<float>& arr)
{
   int n = arr.size();
    if(n<=0)return;
        
     // 1 
    vector <vector<float>> buckets(n);
    // 2 
        for(int i = 0 ; i < n ; i++)
        {
             int BucketIndex = n * arr[i]; 
             buckets[BucketIndex].push_back(arr[i]); 
        }
        // 3
        for(int i = 0 ; i < n ; i++)
        {
             sort(buckets[i].begin() , buckets[i].end());
        }
         int index = 0 ;
          for(int i = 0 ;i < buckets.size() ; i++)
        {
             for(int j = 0 ; j < buckets[i].size() ; j++)
             {
                arr[index] = buckets[i][j];
                index++;
             }
        }
}





int main()
{
    vector <float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12};
    cout << "Before sorting:\n";
    for(float x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << "After Sorting: " << "\n";
    BucketSorting(arr);
    for(float y : arr)
    {
        cout << y << " ";
    }
    

    return 0;
}
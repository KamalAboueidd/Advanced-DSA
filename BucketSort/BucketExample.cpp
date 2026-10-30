#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

void BucketSort(vector<float>& arr )
{
        int n = arr.size();
         
        if(n < 0) return ;
        vector<vector<float>> buckets(n);
         for(int i = 0 ; i < n ; i++)
         {
             int BucketIndex = n * arr[i];
             buckets[BucketIndex].push_back(arr[i]);
         }
            for(int i = 0 ; i < n ; i++){
                sort(buckets[i].begin() , buckets[i].end());
            }
             // now All Buckets Are Sorted .
             int index = 0 ;
               for(int i = 0 ; i < n ; i++)
               {
                 for(int j=0 ; j < buckets[i].size() ; j++)
                 {
                    arr[index] = buckets[i][j];
                    index++;  
                 }
               }
}







int main()
{
vector<float>ar ={0.78, 0.17, 0.39, 0.99, 0.72, 0.94, 0.21, 0.12};

   cout<< "before sorting " << "\n";
   for(float x : ar ){
        cout << x << " "; 
   }
       cout << "\n";
       BucketSort(ar); 
          cout<< "after sorting " << "\n";
   for(float x : ar ){
        cout << x << " "; 
   }
    return 0;
}

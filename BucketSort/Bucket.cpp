#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 


void BucketSort(vector<float>& arr )
{
   int n = arr.size();
  if    (n <= 0)  return;
  
     // 1. Create n empty Buckets. (Note : these buckets are vector of float)
   vector<vector<float>> buckets(n) ;       // bucket here means : how many buckets we want . 
   //  bucket() is a function that return a vector  <vector<float>> means vector of vector of float (means vector of buckets)      
            // 2 put array elemets into diffrents buckets
              for(int i = 0 ; i < n ; i ++)
              {
                  int BucketIndex = n * arr[i];   
                  buckets[BucketIndex].push_back(arr[i]);  
              }              
              
              //  3 Sort individual buckets (
                for(int i = 0  ; i < n ; i++){ 
                     sort(buckets[i].begin() , buckets[i].end());    
                }    // now every bucket is sorted 
            
        // 4 concatenate all backkets back ito the original array.
           int index = 0 ;
            for(int i = 0 ; i < buckets.size() ; i++ )
               {
                 for(int j = 0 ; j < buckets[i].size() ; j++)
                 {
                      arr[index] = buckets[i][j];
                      index++;
                 }
               }                                                                                    
}

 int main (){
      vector<float> arr ={0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12};
      cout << "Before Sorting" << "\n";
     for(float x : arr)a;;;pkk
     {
          cout << x << " "; 
     }
      cout << "\n";
         BucketSort(arr);

    cout << "After sorting:  ";
    for (float x : arr) cout << x << " ";
    cout << "\n";
    
    return 0 ;
 }

#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;
 

   void CountingSort(vector<int>& arr){
       // 1  find max value in array 
          int maxValue = *max_element(arr.begin() , arr.end());
          // 2 create count 
         vector<int> count(maxValue + 1 , 0);
         // 3  count hw many times each number appers in original array 
            for(int i = 0 ; i < arr.size() ; i++)
            {
               count[arr[i]]++; 
             }   
   }    // now count array : [0 , 1 , 2 , 2 , 1 , 0 , 0 , 0 , 1]  ( Note that index 0 had 0 times so it will be 0)
                                                               // index of count array :  0  1  2  3  4  5  6  7  8          
    // 4 Rebuild the original array in sorted order 
       int index = 0 ;
        for(int i = 0 ; i <= maxValue ; i++)
        {
            while(count[i] > 0)
            {
                arr[index] = i;
                index++;
                count[i]--;  // IMPORATNT todecrease the count so that we dont palce the same number again .
            }
        }
int main(){
     vector<int> arr = {4,2,2,8,3,3,1};
     cout << "Before Sorting : ";
     for(int x : arr) cout << x << " "; 
     cout << "\n";
     
   cout << "Counting Sort" << "\n";
    return 0 ;
}
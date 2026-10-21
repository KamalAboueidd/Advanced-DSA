#include <iostream>
#include <vector>
#include <algorithm> // needed for maxLenght function 
using namespace std;


// counting sort 3 steps 

// 1) find MaxValue.
// 2) cout Frequencies.
// 3) Rebuild the Array.

 void CountingSort(vector<int>& arr )
 {
      // step 1  : find the max value in the array
       int maxValue = *max_element(arr.begin() , arr.end());
       
       // step 2 : Create Count (Frequency) array of Size (MaxValue + 1) intialized with zeros.
         vector<int> count(maxValue + 1 , 0);   
         //  step 3 : Count how many Times each Number appers in the original array .
         for(int i = 0 ; i < arr.size() ; i++ )
         {
             count[arr[i]]++;    // means if arr[i] = 4 then count[4] = 1 , and if again arrr[i] = 4 then count[4] = 2 , etc.  ,
              // in that example after count work and complete will be : [0 , 1 , 2 , 2 , 1 , 0 , 0 , 0 , 1]  ( Note that index 0 had 0 times so it will be 0)
              // index of count array :  0  1  2  3  4  5  6  7  8         
         }
         // step 4 : Rebuild  the original Array in Sorted Order using count array.
           int index = 0 ;  // track the current position in the main array 
             for(int i  = 0 ; i <= maxValue ; i++)
             {
                 while(count[i] > 0 )
                 {
                      arr[index] = i ; // palce the nu,ber back into the array  
                      index++;    // Move to next Position 
                      count[i]--;  // Decrease the count .
                 }
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
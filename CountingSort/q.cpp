#include <iostream>
#include <vector>   
#include <algorithm> 
#include <algorithm> using namespace std ;
 
   void CountingSort(vector<int>&arr)
   {
      int maxElement = *max_element(arr.begin() , arr.end());
      
        // 2 create count array 
          vector<int> count(maxElement +1 ,0);

          // 3  count hw many times each element appers in original array 
            for(int i = 0 ; i < arr.size() ; i++)
            {
                count[arr[i]]++; 
            }     

            // 4: rebuilding the array
            int index = 0 ;
             for(int i = 0 ; i <= maxElement ; i++ )
             {
                while(count[i] > 0)
                {
                    arr[index] = i ; 
                    index++;
                    count[i]--;    
                }
             }  
   }


int  main()
{
     vector <int> arr = {12 , 8 ,4 ,5 ,3, 11 ,3, 4}
              
     return 0 ;
}
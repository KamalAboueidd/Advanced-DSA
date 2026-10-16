#include <iostream>
#include <vector>
#include <cstdlib > // rand () 
#include <ctime>
using namespace std ;

 int partition(vector<int>& arr , int low , int hight )
 {
        int pivot = arr[hight];
        int i = low -1 ;
        for(int j = low ; j < hight ; j++)
        {
             if(arr[j] <= pivot)
             {
                 i++ ;
                 swap(arr[i] , arr[j]);
             }
        }
        swap(arr[i+1] , arr[hight]);
        return (i + 1);
 }

 int rondomizedPartition(vector<int>& arr , int low , int hight)
 {
        int RomndomIndex = low + rand() % (hight - low + 1);
        swap(arr[RomndomIndex] , arr[hight]);
        return partition(arr , low , hight);
 }
   
 void QuickSort(vector<int>& arr  , int low ,int hight) 
 {
      if (low < hight)
      {
         int pi =  rondomizedPartition(arr , low ,hight);
         
         QuickSort(arr , low , pi-1);
         QuickSort(arr , pi + 1 , hight);
      }
 }
int main()
{
    vector<int> arr = {12 , 1 , 13 , 5 , 6 , 7};
    int n = arr.size();
      cout << "Array Before Sorting" << endl ;
      for(int i = 0 ; i < n ; i++){
         cout << arr[i] << " " ;
      }
      cout << endl ;
      QuickSort(arr , 0 , n-1);
        cout << "Array After Sorting" << endl ;
      for(int i = 0 ; i < n ; i++){
         cout << arr[i] << " " ;
      }
      cout << endl ;
    return 0 ;
} 
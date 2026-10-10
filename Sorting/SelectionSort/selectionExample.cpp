#include <iostream>
using namespace std ;

void SelectionSort(int arr[] , int n)
{
   for(int i = 0 ; i< n ; i++){
      int mainIndex = i ;
        for(int j =  i+1 ; j < n ;j++)
        {
              if(arr[j] < arr[mainIndex]){
                  mainIndex = j;
              }
        }
          if(mainIndex != i){
            int tmp = arr[i];
            arr[i] = arr[mainIndex];
            arr[mainIndex] = tmp;

          }
   }
}

int main(){
   int arr[] = {66 , 88 ,12 , 34 , 9 , 77 , 5};
   int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Array in Unsorted order " << endl;
   for(int i = 0 ; i < n ; i++){
    cout << arr[i] << " ";
   }
   cout << endl;
   SelectionSort(arr , n);  
   cout << "Array in Sorted order " << endl;
   for(int i = 0 ; i < n ; i++){
    cout << arr[i] << " ";
   }
   cout << endl;
    return 0;
}
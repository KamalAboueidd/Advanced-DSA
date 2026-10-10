#include <iostream>
using namespace std ;

void InsertionSort(int arr[] , int n)
{
   for(int i = 1 ; i< n ; i++){
      int current = arr[i];
      int j = i-1;
        while(j>=0 && arr[j]>current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
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
   InsertionSort(arr , n);  
   cout << "Array in Sorted order " << endl;
   for(int i = 0 ; i < n ; i++){
    cout << arr[i] << " ";
   }
   cout << endl;
    return 0;
}
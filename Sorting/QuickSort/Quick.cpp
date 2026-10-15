#include <iostream> 
#include <vector>
using namespace std ;



int partition(vector<int>&arr , int low , int hight){
      int pivot = arr[hight] ;
      int i = low -1;
      for(int j = low ; j < hight ; j++){
             if(arr[j] <= pivot){
                i++;
                swap(arr[i] , arr[j]);
             }
      } 
      swap(arr[i+1] , arr[hight]);
      return (i+1);
}

void QuickSort(vector<int> &arr , int low , int hight)
{
     if(low < hight){
        int pi = partition(arr , low , hight);
        QuickSort(arr , low , pi - 1);
        QuickSort(arr , pi + 1 , hight);
     }
}
int main(){
   vector<int> arr = {1 , 12, 5 , 3 , 64 , 12 , 23 };
   int n = arr.size();
    cout<< "array Before Sorting : " << "\n";
    for(int i = 0 ; i < n ; i++){
          cout << arr[i] << " " ;
   }
   cout << "\n";
   QuickSort(arr , 0 , n-1);

     cout << "array After Sorting : " << "\n";
    for(int i = 0 ; i < n ; i++){
           cout << arr[i] << " " ;
    }
    return 0 ;
}
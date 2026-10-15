#include <iostream>
using namespace std ;

 void Merge(vector<int>& arr  , int left , int mid , int right){
    int  n1 = mid - left + 1 ; // len for every side 
    int n2 = right - mid;
         // creating a 2 tmp Two vectors
            vector<int> L(n1) , R(n2) ;  
               // copy element(data) to temp vectors
                 for(int i = 0 ; i < n1 ; i++){
                      L[i] = arr[left + i];
                 }
                 for(int j = 0 ; i < n2 ; j++){
                      L[j] = arr[mid + 1 + j];
                 }
             int   i , j = 0 ;
             int k = left;
               // merging the two tmp vectors
               // arr  [left .. left]
                 while(i < n1 && j < n2){
                    if(L[i] <=R[i]){
                        arr[k] = L[i];
                        i++
                    }else {
                         arr[k] = R[j];
                         j++;
                    }
                    k++;
                 }
                 while(i < n1){
                        arr[k] = L[i];
                        i++;
                        j++;
                 }
                 while(j < n2){
                      arr[k] =R[j];
                       j++;
                       k++;
                 }
        }
 // begin is for left index and end is right index
 // of the sub array of arr to be sorted.
void mergeSort(vector<int>& arr , left , right){
   if(left >= right ){
    return ;
   }
    int mid = left  + (right - left ) / 2 ;
    mergeSort(arr , left , mid);
    mergeSort(arr , mid + 1, right);
    Merge(arr , left , mid , right);
     
}

int mian(){ 
      vector <int> arr = {38 , 27 , 43 , 10}
       int n = arr.size();
       mergeSort(arr , 0 , n- 1);

    return 0;
}
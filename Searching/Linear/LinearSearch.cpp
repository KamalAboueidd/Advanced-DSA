#include <iostream>
#include <string>
using namespace std;
   int LinearSearch(int arr[] , int size , int target){
              for(int i = 0 ; i < size ; i++){
                  if(arr[i] == target){
                       return i ;
                  }
              }
                  return -1 ;
   }

int main() {
    int arr [] = {1 ,2 ,3, 4,5 ,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 4 ;
    int result = LinearSearch(arr, size, target);

    if (result != -1) {
        cout << "Element found at index: " << result << "\n";
    } else {
        cout << "Element not found in the array.\n";
    }
    return 0;
}

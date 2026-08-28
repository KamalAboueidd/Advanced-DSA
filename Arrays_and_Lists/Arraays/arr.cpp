#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // static array .
    int score[5] = {10, 11, 13, 14, 10};
    score[2] = 55;
    cout << score[2] << "\n";           // [10,11,55,14,10]
    const int address = 1000 + (2 * 4); // address = base address + (index , size Dt)
    cout << "address " << address << "\n";

    // dynamic array
    vector<int> vec;
    for (int i = 1; i <= 5; i++)
    {
         vec.push_back(i * 10);
         cout << "Pushed" << i * 10 << "\n";
         cout << "Size " << vec.size() << "\n";
         cout << "Capacity " << vec.capacity() << "\n";
         cout << "Memory address of Fist Element : " << vec.data() << "\n"; 
    }
 // ex 
 // i want Assign value to specific place in the arraybut this place is not empty 
    
     vector <int> vecc = {10,20,30};
      cout << "SIZE : " << vecc.size() << " CAPACITY " << vecc.capacity() << "\n";
       vecc.insert(vecc.begin()+2,40); // re-allocation
       cout << "Display the new Dynamic array " << "\n";
       for(int x :vecc)
       {
          cout << x << "\n";
       }
             cout << "SIZE : " << vecc.size() << " CAPACITY " << vecc.capacity() << "\n";
       
      return 0;
}
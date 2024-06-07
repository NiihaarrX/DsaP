#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//Find the element which only appear once in a sorted array
// (even,odd) -> Left Side 
// (odd,even) -> Right Side

int SingleElement(vector<int> &arr,int size) {
  if(size == 1) return arr[0];
  if(arr[0] != arr[1]) return arr[0];
  if(arr[size -1] != arr[size - 2]) return arr[size - 1];
  int low = 1,high = size - 2;
  while(low <= high) {
    int mid = low + (high - low)/2;
    if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
    if((mid % 2 == 1) && arr[mid] == arr[mid-1] || (mid % 2 == 0) && arr[mid] == arr[mid + 1]) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
} 
int main() {
  vector<int> arr = {1,1,2,2,3,4,4,5,5,6,6};
  int n = arr.size();
  int Index = SingleElement(arr,n);
  cout << Index << endl;
}

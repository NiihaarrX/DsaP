#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch(vector<int> &arr,int size,int target) {
  int start = 0,end = size - 1;
  while(start <= end) {
    int mid = (start + end)/2;
    if(arr[mid] == target) return mid;
    else if(arr[mid] > target) end = mid - 1;
    else start = mid + 1;
  }
  return -1;
} 
int main() {
  vector<int> arr = {1,3,4,6,8,12,15};
  int search = 11;
  int n = arr.size();
  int Index = BinarySearch(arr,n,search);
  cout << Index << endl;
}

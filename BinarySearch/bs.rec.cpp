#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch(vector<int> &arr,int start,int end,int target) {
  if(start > end) return -1;
  int mid = start + (end - start)/2;
  if(arr[mid] == target) return mid;
  else if(arr[mid] > target) return BinarySearch(arr,start,mid - 1,target);
  else return BinarySearch(arr,mid + 1,end,target);
} 
int main() {
  vector<int> arr = {1,3,4,6,8,12,15};
  int search = 3,n = arr.size();
  int Index = BinarySearch(arr,0,n-1,search);
  cout << Index << endl;
}

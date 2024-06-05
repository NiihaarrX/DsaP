#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int UpperBound(vector<int> &arr,int size,int target) {
  int answer = size;
  int start = 0,end = size - 1;
  while(start <= end) {
    int mid = start + (end- start)/2;
    if(arr[mid] <= target) {
      start = mid + 1;
    }
    else {
      answer = mid;
      end = mid - 1;
    }

  }
  return answer;
} 
int main() {
  vector<int> arr = {3,5,8,15,19};
  int search = 19,n = arr.size();
  int Index = UpperBound(arr,n,search);
  cout << Index << endl;
}

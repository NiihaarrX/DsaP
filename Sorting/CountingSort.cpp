#include <bits/stdc++.h>
using namespace std;

void CountingSort(vector<int> &v) {
  int maxi = INT_MIN;
  for(int i = 0; i < v.size(); i++)  maxi = max(maxi, v[i]);
  vector<int> cnt_arr(maxi + 1, 0);
  for(int i = 0; i < v.size(); i++) cnt_arr[v[i]]++;
  int index = 0;
  for(int i = 0; i <= maxi; i++) {
    while(cnt_arr[i] > 0) {
      v[index] = i;
      index++;
      cnt_arr[i]--;
    }
  }
}

int main() {
  vector<int> arr = {23, 12, 19, 15, 8, 9};
  CountingSort(arr);
  for(auto i : arr)
    cout << i << " ";
  
  return 0;
}

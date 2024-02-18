#include <bits/stdc++.h>

using namespace std;


void BubbleSort(vector<int> &arr,int n) {
  for(int i = 0; i < n - 1;i++) {
    bool change = false;
    for(int j = 0; j < n - i -1;j++) {
      if(arr[j] > arr[j+1]) {
        swap(arr[j],arr[j+1]);
        change = true;
      }
    }
    if(!change) break;
    }
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int &a : arr) cin >> a;
  BubbleSort(arr,n);
  for(int &a : arr) cout << a << " ";
  cout << endl;
}

#include <bits/stdc++.h>

using namespace std;


void InsertionSort(vector<int> &arr,int n) {
    int j;
    for(int i = 1; i < n;i++) {
        int temp = arr[i];
        for(j = i - 1;j >= 0;j--) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            }
            else break;
        }
        arr[j+1] = temp;
    }
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int &a : arr) cin >> a;
  InsertionSort(arr,n);
  for(int &a : arr) cout << a << " ";
  cout << endl;
}

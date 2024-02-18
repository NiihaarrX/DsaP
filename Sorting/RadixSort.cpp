#include <bits/stdc++.h>

using namespace std;

const int base = 10;

void Sort(vector<int> &v,int exp) {
  vector<int> output(v.size());
  vector<int> freq(base,0);

  for(int i = 0;i < v.size() ; i++) freq[(v[i] / exp) % 10]++;
  for(int i = 1; i < base ;i++) freq[i] += freq[i-1];
  
  for(int i = v.size() - 1; i >= 0; i--) {
        output[freq[(v[i] / exp) % base] - 1] = v[i];
        freq[(v[i] / exp) % base]--;
    }
  for(int i = 0 ;i < v.size() ;i++) v[i] = output[i];
} 

void CountingSort(vector<int> &v) {
  int max_num = INT_MIN;
  for(auto &i : v) max_num = max(max_num,i);

  for(int exp = 1; max_num/exp > 0 ; exp *= 10) Sort(v,exp);
}

int main() {
  vector<int> v = {23,12,45,34,46,40};
  CountingSort(v);

  for(auto i : v)
    cout << i << " ";
}

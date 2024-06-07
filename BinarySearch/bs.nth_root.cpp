#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int a,int b) {
  int answer = 1;
  for(int i = 0;i < b;i++) answer *= a;
  return answer;
}

int n(int a,int b) {
  int low = 1,high = a;
  while(low <= high) {
    int mid = low + (high - low)/2;
    int answer = f(mid,b);
    if(answer == a) return mid;
    else if(answer > a) high = mid - 1;
    else low = mid + 1;
  }
  return -1;
} 
int main() {
  int a = 27,b = 4;
  cout << n(a,b);
}

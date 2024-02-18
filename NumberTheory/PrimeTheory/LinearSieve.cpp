#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prime;
    vector<int> temp(n+1,0);
    for(int i = 2; i <= n;i++) {
        if(temp[i] == 0) {
            temp[i] = i;
            prime.push_back(i);
        }
        for(int j = 0; i * prime[j] <= n;j++) {
            temp[i * prime[j]] = prime[j];
            if(prime[j] == temp[i]) break;
        }
    }
    for(int i = 0; i < prime.size();i++) cout << prime[i] << " ";
}

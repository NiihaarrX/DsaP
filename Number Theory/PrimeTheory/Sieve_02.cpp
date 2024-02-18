#include <bits/stdc++.h>

using namespace std;

// Time Complexity = O(n log(log root n))
// Space Complexity = O(n)
// Sieving Till roots (Following prime rule inside prime rule)

vector<int> Sieve(int n) {
    vector<bool> prime(n+1,true);
    prime[0] = false;prime[1] = false;
    for(int i = 2; i * i <= n;i++) {
        if(prime[i]) for(int j = i * i;j <= n; j += i) prime[j] = false;
    }
    vector<int> ans;
    for(int i = 0; i < prime.size();i++) {
        if(prime[i] == true) ans.push_back(i);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> primes = Sieve(n);
    for(int i = 0; i < primes.size();i++) {
        cout << primes[i] << " ";
    }cout << endl;
    return 0;
}

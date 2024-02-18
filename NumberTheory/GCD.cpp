#include <bits/stdc++.h>

using namespace std;

int f(int a,int b) {
    if(a % b == 0) return b;
    else return f(b,a % b);
}


int main() {
    int a,b;
    cin >> a >> b;
    cout << f(a,b) << endl;
}

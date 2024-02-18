#include <vector>
#include <iostream>

using namespace std;

void print_subset(vector<int>& arr, vector<int>& ans) {
    for (int i = 0; i < arr.size(); ++i) {
        if (ans[i] == 1) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void Solve(int curr_index, int n, vector<int>& arr, vector<int>& ans, int curr_sum, int target) {
    if (curr_index == n) {
        if (curr_sum == target) {
            print_subset(arr, ans);
        }
        return;
    }

    ans[curr_index] = 1;
    Solve(curr_index + 1, n, arr, ans, curr_sum + arr[curr_index], target);

    ans[curr_index] = 0;
    Solve(curr_index + 1, n, arr, ans, curr_sum, target);
}

int main() {
    int n, target, sum = 0;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    vector<int> ans(n, 0);
    Solve(0, n, arr, ans, 0, target);
    return 0;
}

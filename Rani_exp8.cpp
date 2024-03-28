#include <iostream>
#include <vector>

using namespace std;

int unboundedKnapsack(int k, vector<int>& arr) {
    vector<int> dp(k + 1, 0);

    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            if (arr[j] <= i) {
                dp[i] = max(dp[i], dp[i - arr[j]] + arr[j]);
            }
        }
    }

    return dp[k];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int result = unboundedKnapsack(k, arr);
        cout << result << endl;
    }

    return 0;
}

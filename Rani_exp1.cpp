#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    vector<int> A(N);

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    reverse(A.begin(), A.end());

    cout << "Reversed array:" << endl;
    for (const auto& element : A) {
        cout << element << " ";
    }

    return 0;
}
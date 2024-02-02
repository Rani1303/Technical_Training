#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> leftRotate(const vector<int>& arr, int d) {
    vector<int> result(arr.size());
    rotate_copy(arr.begin(), arr.begin() + d, arr.end(), result.begin());

    return result;
}
int main() {
    int n, d;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array:" <<endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the number of left rotations: ";
    cin >> d;
    vector<int> rotatedArray = leftRotate(arr, d);

    cout << "Array after " << d << " left rotations:" << endl;
    for (const auto& element : rotatedArray) {
        cout << element << " ";
    }

    return 0;
}

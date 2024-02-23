#include <iostream>
#include <vector>
using namespace std;

int maxEqualHeight(vector<int>& stack1, vector<int>& stack2, vector<int>& stack3) {
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int height : stack1) sum1 += height;
    for (int height : stack2) sum2 += height;
    for (int height : stack3) sum3 += height;

    int top1 = 0, top2 = 0, top3 = 0;

    while (true) {
        if (top1 == stack1.size() || top2 == stack2.size() || top3 == stack3.size()) {
            return 0;
        }

        if (sum1 == sum2 && sum2 == sum3) {
            return sum1;
        }

        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= stack1[top1++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= stack2[top2++];
        } else {
            sum3 -= stack3[top3++];
        }
    }
}

int main() {
    vector<int> stack1 = {3, 2, 1, 1, 1};
    vector<int> stack2 = {4, 3, 2};
    vector<int> stack3 = {1, 1, 4, 1};

    int result = maxEqualHeight(stack1, stack2, stack3);

    cout << "Maximum possible equal height: " << result << endl;

    return 0;
}

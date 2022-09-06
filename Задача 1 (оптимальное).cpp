#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySum(vector<int> &array, int &startIndex, int &finalIndex) {

    int maxValue = INT_MIN;
    int maxCheck = 0;

    for (int i = 0, s = 0; i < array.size(); i++) {
        maxCheck += array[i];
        if (maxValue < maxCheck) {
            maxValue = maxCheck;
            startIndex = s;
            finalIndex = i;
        }
        if (maxCheck < 0) {
            maxCheck = 0;
            s = i + 1;
        }
    }
    return maxValue;
}

int main() {

    vector<int> array {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int startIndex = 0;
    int finalIndex = 0;

    int max_sum = maxSubArraySum(array, startIndex, finalIndex);
    cout << " = " << max_sum << " (" << startIndex << "," << finalIndex << ")\n";

    return 0;
}
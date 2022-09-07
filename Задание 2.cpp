#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> array {-2,1,-3,4,-1,2,1,-5,4};
    int resultSummary = -4;

    int startIndex, sum;
    int finalIndex = -1;
    int size = (int) array.size();
    for (int i = 0; i < (size - 1) && finalIndex < 0; i++) {
        for (int j = i + 1; j < size; j++) {
            sum = array[i] + array[j];
            if (sum == resultSummary) {
                startIndex = i;
                finalIndex = j;
                break;
            }
        }
    }
    if (finalIndex > 0) {
        cout << array[startIndex] << " + " <<array[finalIndex];
        cout << " = " << resultSummary << endl;
    } else {
        cerr << "Не найдено\n";
    }

    return 0;
}

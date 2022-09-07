#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> array {-100,-77, -50, -24, -17, -13, -9, -5, -2, -1, 1, 7, 9, 10, 15};
    //vector<int> array {-100,-88, -63, -50, -15, -11, -10, -5};
    //vector<int> array { 10, 15, 25, 40, 50, 55, 61, 72, 100};
    vector<int> result;

    int indexMin = 0;
    int size = (int) array.size();

    for (int i = 1; i < size; i++)
        if (abs(array[i]) < abs(array[indexMin])) indexMin = i;
    result.push_back(array[indexMin]);

    int indexL = indexMin - 1;
    int indexR = indexMin + 1;
    while (indexL >= 0 && indexR < size) {
        if (abs(array[indexL]) < abs(array[indexR])) {
            result.push_back(array[indexL--]);
            result.push_back(array[indexR++]);
        } else {
            result.push_back(array[indexR++]);
            result.push_back(array[indexL--]);
        }
    }
    while (indexL >= 0)
        result.push_back(array[indexL--]);
    while (indexR < size)
        result.push_back(array[indexR++]);

    cout << "{ ";
    for (int i: result) cout << i << " ";
    cout << "}\n";

    return 0;
}

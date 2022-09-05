#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> array {-100,-50, -5, 1, 10, 15};

    int indexMin;
    int size = (int) array.size();

    for (int i = 0; i < size; i++) {
        indexMin = i;
        for (int j = i + 1; j < size; j++) {
            if (abs(array[j]) < abs(array[indexMin])) indexMin = j;
        }
        swap(array[i],array[indexMin]);
    }

    cout << "[ ";
    for (int i: array) cout << i << " ";
    cout << "]\n";


    return 0;
}

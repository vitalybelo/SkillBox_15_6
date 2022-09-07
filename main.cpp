#include <iostream>
#include <vector>
using namespace std;

void printArray (vector<int>& array);
bool entryDataArray (vector<int>& array);
bool entryDataArray (vector<int>& array, vector<int>& buffer, int size);

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");
    vector<int> array;
    vector<int> buffer;

    while (entryDataArray(array, buffer, 5)) {

        if (array.size() < 5) {
            cout << "Нет 5-го элемента :: ";
        } else {
            cout << "Пятый элемент = " << buffer[4] << " :: ";
        }
        printArray(buffer);
        printArray(array);
    };
    return 0;
}

void printArray (vector<int>& array) {
    cout << "{";
    for (int i: array) cout << i << ",";
    cout << "}\n";
}

void LRUcache (int value, vector<int>& buffer, int sizeBuffer) {

    if (buffer.empty() || buffer[buffer.size() - 1] <= value)
        buffer.push_back(value);
    else {
        for (auto iter = buffer.begin(); iter < buffer.end(); iter++) {
            if (value <= *iter) {
                buffer.insert(iter,value);
                break;
            }
        }
    }
    if (buffer.size() > sizeBuffer) buffer.resize(sizeBuffer);
}

bool entryDataArray (vector<int>& array, vector<int>& buffer, int size) {
    int inputValue;
    cout << "Ввод: ";
    do {
        cin >> inputValue;
        if (inputValue >= 0) {
            array.push_back(inputValue);
            LRUcache(inputValue, buffer, size);
        }
    } while (inputValue >= 0);
    return (inputValue != -2);
}

bool entryDataArray (vector<int>& array) {
    int inputValue;
    cout << "Ввод: ";
    do {
        cin >> inputValue;
        if (inputValue >= 0) {
            if (array.empty() || array[array.size() - 1] <= inputValue) {
                array.push_back(inputValue);
            } else {
                for (auto iter = array.begin(); iter < array.end(); iter++)
                    if (inputValue <= *iter) {
                        array.insert(iter,1,inputValue);
                        break;
                    }
            }
        }
    } while (inputValue >= 0);
    return (inputValue != -2);
}

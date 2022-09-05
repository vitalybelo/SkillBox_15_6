#include <iostream>
#include <vector>
using namespace std;

void printArray (vector<int>& array);
bool entryDataArray (vector<int>& array);
vector<int> shiftArrayMinToMax (vector<int> array);
void sortArrayMinToMax (vector<int>& array);

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    vector<int> array;
    while (entryDataArray(array)) {

        // ��� ������� �� ������� ������ ���� � ����
        // 1-�� ���������� ����� ������������� ������
        // 2-�� ����������� ������ ������ ���� ������
        vector<int>sortedArray = shiftArrayMinToMax(array);
        sortArrayMinToMax(array);

        if (sortedArray.size() >= 5) {
            cout << "����� ������� = " << array[4] << " ";
        } else {
            cerr << "��� 5-�� �������� ";
        }
        printArray(sortedArray);
    };
    cout << "���������� ���������\n";
    return 0;
}

/**
 * ������� � ������ �������� �������
 * @param array - ������ �������� ��� �����������
 */
void printArray (vector<int>& array) {
    cout << "[ ";
    for (int i: array) cout << i << " ";
    cout << "]\n";
}

/**
 * ��������� ������ ����� ������ � ������
 * @param array - ����������� �� ������ ����������
 * @return - ������ ��� ���� ���������� ���������
 */
bool entryDataArray (vector<int>& array) {
    int inputValue;
    cout << "����: ";
    do {
        cin >> inputValue;
        if (inputValue >= 0) array.push_back(inputValue);
    } while (inputValue >= 0);

    return (inputValue != -2);
}

/**
 * ������������� ������� )), ������������� �������� ������� �
 * ����� ������ � ������� �����������. � ���������� ������
 * �������� ������ ����������, �������� ������ ��������� ���
 * �������� ��������� ������� �� � ������������� �������.
 * @param array - ������ ��������� �������
 * @return - ������ ���������������� �������
 */
vector<int> shiftArrayMinToMax (vector<int> array) {
    vector<int> result;
    vector<int>::iterator iter, iterMin;
    int size = (int) array.size();

    for (int i = 0; i < size; i++) {
        iterMin = array.begin();
        for (iter = iterMin + 1; iter < array.end(); iter++) {
            if (*iter < *iterMin) iterMin = iter;
        }
        result.push_back(*iterMin);
        array.erase(iterMin);
    }
    return result;
}

/**
 * ������� ��������� �������� ������� � ������� �����������
 * ������ ������ ���� ��� ������ �������������� ������.
 * @param array - ��������� �� ������ ������� ��� ����������
 */
void sortArrayMinToMax (vector<int>& array) {

    int indexMin;
    int size = (int) array.size();

    for (int i = 0; i < size; i++) {
        indexMin = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[indexMin]) indexMin = j;
        }
        swap(array[i],array[indexMin]);
    }
}

#include <iostream>
#include <vector>
using namespace std;

void printArray (vector<int>& array);
bool entryDataArray (vector<int>& array);

int main() {
    vector<int> array;
    while (entryDataArray(array)) {

        if (array.size() < 5) {
            cout << "Нет 5-го элемента :: ";
        } else {
            cout << "Пятый элемент = " << array[4] << " :: ";
        }
        printArray(array);
    };
    cout << "Завершение программы\n";
    return 0;
}

/**
 * Выводит в строку элементы массива
 * @param array - массив значений для отображения
 */
void printArray (vector<int>& array) {
    cout << "{";
    for (int i: array) cout << i << ",";
    cout << "}\n";
}

/**
 * Ввод данных в массив. Каждое введенное значение ставится
 * на нужное место в массиве сдвигая вправо значения которые
 * больше введенного, в итоге массив сортируется по возрастанию
 * @param array - указательно на массив заполнения
 * @return - истину как флаг завершения программы
 */
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

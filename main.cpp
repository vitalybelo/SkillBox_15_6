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

        // две функции по разному делают одно и тоже
        // 1-ая возвращает новый сортированный массив
        // 2-ая сортируется массив внутри себя самого
        vector<int>sortedArray = shiftArrayMinToMax(array);
        sortArrayMinToMax(array);

        if (sortedArray.size() >= 5) {
            cout << "Пятый элемент = " << array[4] << " ";
        } else {
            cerr << "Нет 5-го элемента ";
        }
        printArray(sortedArray);
    };
    cout << "Завершение программы\n";
    return 0;
}

/**
 * Выводит в строку элементы массива
 * @param array - массив значений для отображения
 */
void printArray (vector<int>& array) {
    cout << "[ ";
    for (int i: array) cout << i << " ";
    cout << "]\n";
}

/**
 * Локальная задача ввода данных в массив
 * @param array - указательно на массив заполнения
 * @return - истину как флаг завершения программы
 */
bool entryDataArray (vector<int>& array) {
    int inputValue;
    cout << "Ввод: ";
    do {
        cin >> inputValue;
        if (inputValue >= 0) array.push_back(inputValue);
    } while (inputValue >= 0);

    return (inputValue != -2);
}

/**
 * Инновационная функция )), перекладывает значения массива в
 * новый вектор в порядке возрастания. В результате работы
 * исходный массив обнуляется, итоговый массив принимает все
 * значения исходного массива но в сортированном порядке.
 * @param array - вектор исходного массива
 * @return - вектор отсортированного массива
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
 * Функция сортирует значения массива в порядке возрастания
 * внутри самого себя без затрат дополнительной памяти.
 * @param array - указатель на вектор массива для сортировки
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

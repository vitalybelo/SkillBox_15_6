#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> array {-2,1,-3,4,-1,2,1,-5,4};

    // инициализируем максимум
    int maxValue = INT32_MIN;
    // но этот способ более надежный
    // устанавливаем максимальное значение = минимальному числу в массиве
    // int maxValue = array[0];
    // for (int i = 1; i < array.size(); i++)
    //    if (array[i] < maxValue) maxValue = array[i];

    // определяем индексы между которыми сумма чисел максимальная
    int startIndex, finalIndex, sum;
    for (int i = 0; i < array.size() - 1; i++) {
        sum = array[i];
        for (int j = i + 1; j < array.size(); j++) {
            sum += array[j];
            if (sum > maxValue) {
                startIndex = i;
                finalIndex = j;
                maxValue = sum;
            }
        }
    }
    cout << startIndex << " " << finalIndex << endl;

    return 0;
}

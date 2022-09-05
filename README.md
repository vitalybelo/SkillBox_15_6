15.6 Практическая работа

Задача
Цели практической работы
Попробовать на практике алгоритмы поиска в массиве.
Изучить основные алгоритмы сортировки массивов.


Задача 1
Что нужно сделать
Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в этом массиве, что сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.

a = {-2,1,-3,4,-1,2,1,-5,4}

Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1}, сумма = 6. Необходимо вывести 3 и 6.


Задача 2
Что нужно сделать
Вам даётся массив целых чисел и одно число — результат. Необходимо найти в массиве два числа, сумма которых будет давать результат, и вывести их на экран. Гарантируется, что только одна пара чисел в массиве даёт в сумме результат.

Пример:

a = {2, 7, 11, 15}. Результат = 9

2 + 7 = 9, так что надо вывести числа 2 и 7

Советы и рекомендации
Как только найдена первая удовлетворяющая условиям пара, можно заканчивать поиск.



Задача 3
Что нужно сделать
С клавиатуры вводятся числа. Когда пользователь вводит «-1»,  необходимо выводить на экран пятое по возрастанию число среди введённых. Когда пользователь вводит «-2», программа завершает работу.

Пример:

ввод: 7 5 3 1 2 4 6 -1
вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
ввод: 1 1 1 -1
вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
ввод -2
завершение программы

Советы и рекомендации
Нужно удостовериться, что можно вывести требуемое число (может быть меньше пяти чисел).



Задача 4
Что нужно сделать
Вам даётся массив целых чисел, отсортированных по возрастанию. Необходимо вывести его на экран отсортированным в порядке возрастания модуля чисел.

Пример:

Массив {-100,-50, -5, 1, 10, 15}

Вывод: 1, -5, 10, 15, -50, -100

Советы и рекомендации
Положительные числа уже отсортированы в порядке возрастания модулей.



Критерии оценки
В циклах нет выхода за границы массивов.
Вывод ошибок должен производиться в поток вывода ошибок std::cerr.
Действия должны быть вынесены в функции.
Программы запускаются и корректно работают, нет синтаксических ошибок.
Имена переменных корректные, отражают суть хранимых данных.
Создан текстовый интерфейс для всех программ.
Для всех задач обеспечен контроль ввода.
Использован оптимальный алгоритм поиска или сортировки.
Выполнены все четыре задания.


Как отправить работу на проверку
В форме ниже прикрепите ссылки на ваши проекты в repl.it — по одной на каждое задание.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функція для створення динамічного масиву
int* createArray(int n) {
    int* arr = new int[n];
    cout << "Введіть елементи масиву:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    return arr;
}

// Функція для виведення масиву
void printArray(int* arr, int n, const string& label) {
    cout << label << ": ";
    for (int i = 0; i < n; ++i) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

// Функція для обчислення мінімального за модулем елемента
int findMinAbsElement(int* arr, int n) {
    int minAbs = abs(arr[0]);
    for (int i = 1; i < n; ++i) {
        if (abs(arr[i]) < minAbs) {
            minAbs = abs(arr[i]);
        }
    }
    return minAbs;
}

// Функція для обчислення суми модулів елементів після першого нульового елемента
int sumAfterFirstZero(int* arr, int n) {
    int sum = 0;
    bool zeroFound = false;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) {
            zeroFound = true;
        }
        else if (zeroFound) {
            sum += abs(arr[i]);
        }
    }
    return sum;
}

// Функція для перестановки елементів масиву
void transformArray(int* arr, int n) {
    int* temp = new int[n];
    int evenIndex = 0, oddIndex = (n + 1) / 2;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            temp[evenIndex++] = arr[i];
        }
        else {
            temp[oddIndex++] = arr[i];
        }
    }
    // Копіювання модифікованого масиву
    for (int i = 0; i < n; ++i) {
        arr[i] = temp[i];
    }
    delete[] temp;
}

int main() {
    int n;
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    if (n <= 0) {
        cout << "Невірний розмір масиву." << endl;
        return 1;
    }

    int* arr = createArray(n);
    printArray(arr, n, "Початковий масив");

    int minAbsElement = findMinAbsElement(arr, n);
    cout << "Мінімальний за модулем елемент: " << minAbsElement << endl;

    int sumModules = sumAfterFirstZero(arr, n);
    cout << "Сума модулів елементів після першого нульового елемента: " << sumModules << endl;

    transformArray(arr, n);
    printArray(arr, n, "Перетворений масив");

    delete[] arr;
    return 0;
}

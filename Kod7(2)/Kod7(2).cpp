#include <iostream>

// Функція для сортування методом Шелла
void shellSort(int arr[], int n) {
    // Починаємо з великого проміжку і поступово зменшуємо його
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Застосовуємо сортування вставками зі зміщенням на величину проміжку
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {

    setlocale(LC_ALL, "Ukrainian");


    int n;
    std::cout << "Введіть кількість елементів у масиві (непарне число): ";
    std::cin >> n;

    if (n % 2 == 0) {
        std::cout << "Масив повинен містити непарну кількість елементів." << std::endl;
        return 1;
    }

    int* arr = new int[n]; // Виділення пам'яті для масиву

    std::cout << "Введіть " << n << " елементів масиву:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Сортуємо масив за спаданням
    shellSort(arr, n);

    // Виводимо відсортований масив
    std::cout << "Відсортований масив за спаданням: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr; // Звільнення пам'яті, виділеної для масиву

    return 0;
}

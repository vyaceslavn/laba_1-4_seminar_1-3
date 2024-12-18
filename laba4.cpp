#include <iostream>
#include <cstring> // Добавляем подключение cstring.h
#include <ctime>
#include <locale.h>

using namespace std;

// Функция для обмена двух элементов местами
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Сортировка пузырьком
void bubbleSort(int arr[], const int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// Шейкерная сортировка
void shakerSort(int arr[], const int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        // Проход слева направо
        for (int i = left; i < right; ++i)
            if (arr[i] > arr[i + 1])
                swap(&arr[i], &arr[i + 1]);
        right--;

        // Проход справа налево
        for (int i = right; i > left; --i)
            if (arr[i - 1] > arr[i])
                swap(&arr[i - 1], &arr[i]);
        left++;
    }
}

// Сортировка расчёской
void combSort(int arr[], const int n)
{
    float shrinkFactor = 1.247330950103979;
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped)
    {
        if (gap > 1)
            gap /= shrinkFactor;

        swapped = false;
        for (int i = 0; gap + i < n; ++i)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(&arr[i], &arr[i + gap]);
                swapped = true;
            }
        }
    }
}

// Сортировка вставками
void insertionSort(int arr[], const int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

// Слияние двух отсортированных частей массива
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Создаем временные массивы
    int L[100], R[100];

    // Копируем данные в временные массивы
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Объединяем временные массивы обратно в исходный
    i = 0; // Индекс первого подмассива
    j = 0; // Индекс второго подмассива
    k = l; // Индекс объединенного подмассива
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы L[], если они есть
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы R[], если они есть
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Сортировка слиянием
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Сортируем первую и вторую половины
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Сортировка выбором
void selectionSort(int arr[], const int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

// Сортировка подсчётом
void countingSort(int arr[], const int n, int maxValue)
{
    int count[100]; // Массив для хранения количества каждого числа
    memset(count, 0, sizeof(count));

    // Подсчитываем количество каждого числа
    for (int i = 0; i < n; ++i)
        count[arr[i]]++;

    // Преобразуем массив count так, чтобы он содержал позиции
    for (int i = 1; i <= maxValue; ++i)
        count[i] += count[i - 1];

    // Создаём новый отсортированный массив
    int output[100];
    for (int i = n - 1; i >= 0; --i)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Копируем отсортированные элементы обратно в исходный массив
    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

// Разделение массива и вызов быстрой сортировки
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Быстрая сортировка
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Построение кучи (используется в пирамидальной сортировке)
void heapify(int arr[], const int n, int i)
{
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // Левый дочерний элемент
    int right = 2 * i + 2; // Правый дочерний элемент

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Рекурсивно преобразовываем затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Пирамидальная сортировка
void heapSort(int arr[], const int n)
{
    // Построить кучу (перегруппировываем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(&arr[0], &arr[i]);

        // Вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

// Бинарный поиск (работает только на отсортированном массиве)
int binarySearch(int arr[], const int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Элемент не найден
}

// Поиск в ширину (BFS)
bool BFS(int arr[], const int n, int x)
{
    for (int i = 0; i < n; ++i)
        if (arr[i] == x)
            return true;
    return false;
}

// Поиск в глубину (DFS) для линейной структуры (массива)
bool DFS(int arr[], const int n, int x)
{
    for (int i = 0; i < n; ++i)
        if (arr[i] == x)
            return true;
    return false;
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL)); // Инициализация генератора случайных чисел

    const int N = 10; // Размер массива
    int arr[N];

    printf("massiv:\n");
    for (int i = 0; i < N; ++i)
    {
        arr[i] = rand() % 100; // Генерация случайных чисел от 0 до 99
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Сортируем массив разными способами
    bubbleSort(arr, N);       // Сортировка пузырьком
    printf("Отсортирован пузырьковой сортировкой: ");
    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    shakerSort(arr, N);       // Шейкерная сортировка
    printf("Отсортирован шейкерной сортировкой: ");
    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    combSort(arr, N);         // Сортировка расчёской
    printf("Отсортирован сортировкой расчёской: ");
    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    insertionSort(arr, N);    // Сортировка вставками
    printf("Отсортирован сортировкой вставками: ");
    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, N - 1); // Сортировка слиянием
    printf("Отсортирован сортировкой слияния: ");
    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    selectionSort(arr, N);    // Сортировка выбором
    printf("Отсортирован сортировкой выбором: ");
    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    countingSort(arr, N, 99); // Сортировка подсчётами
    printf("Отсортирован сортировкой подсчётами: ");
    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, 0, N - 1); // Быстрая сортировка
    printf("Отсортирован быстрой сортировкой: ");
    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    heapSort(arr, N);         // Пирамидальная сортировка
    printf("Отсортирован пирамидальной сортировкой: ");
    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    // Выполняем поиск различных элементов
    int searchElement = 50; // Элемент для поиска
    int index = binarySearch(arr, N, searchElement);
    if (index != -1)
        printf("Бинарным поиском элемент %d найден на позиции %d.\n", searchElement, index);
    else
        printf("Элемент %d не найден бинарным поиском.\n", searchElement);

    if (BFS(arr, N, searchElement))
        printf("Поиск в ширину нашёл элемент %d.\n", searchElement);
    else
        printf("Поиск в ширину не нашёл элемент %d.\n", searchElement);

    if (DFS(arr, N, searchElement))
        printf("Поиск в глубину нашёл элемент %d.\n", searchElement);
    else
        printf("Поиск в глубину не нашёл элемент %d.\n", searchElement);

    return 0;
}
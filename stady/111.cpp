#include <iostream>
#include <vector>
#include <algorithm>  // // для std::lower_bound

// // Вспомогательная функция для вывода содержимого вектора на экран.
// // label - это необязательный текст, который будет выводиться перед самим вектором.
static void printVector(const std::vector<int> &vec, const std::string &label = "") {
    if (!label.empty()) {
        std::cout << label << " ";
    }
    std::cout << "[ ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i + 1 < vec.size()) std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

class PmergeMe {
public:
    // // Вызов пользовательского метода: сортируем вектор m_vector
    void mergeSortVector();

    // // Метод, куда можно передать любой вектор для сортировки с печатью процесса
    void insertionSortVector(std::vector<int> &vec);

private:
    // // Реализация алгоритма вставок в диапазоне [left, right]
    void insertionSortRangeVector(std::vector<int> &arr, int left, int right);

    // // Двоичный поиск и вставка
    void binaryInsertVector(std::vector<int> &arr, int x);

    // // Внутренний вектор, который будем сортировать
    std::vector<int> m_vector;

public:
    // // Конструктор, чтобы удобнее заполнить "m_vector" для демонстрации
    PmergeMe(const std::vector<int> &init) : m_vector(init) {}
    
    // // Метод для печати финального результата или состояния
    void printInternalVector() const {
        printVector(m_vector, "Current internal vector:");
    }
};

// // =======================================================================
// //                   РЕАЛИЗАЦИЯ МЕТОДОВ
// // =======================================================================

// // Запуск сортировки основного вектора
void PmergeMe::mergeSortVector() {
    std::cout << "\n=== Начинаю сортировку mergeSortVector() ===" << std::endl;
    printVector(m_vector, "Стартовое содержимое m_vector:");

    // // Если меньше двух элементов, сортировать нечего
    if (m_vector.size() < 2) {
        std::cout << "Вектор содержит 0 или 1 элемент, сортировка не требуется." << std::endl;
        return;
    }

    // // Передаём управление «умному» методу insertionSortVector
    insertionSortVector(m_vector);

    std::cout << "=== Завершена сортировка mergeSortVector() ===" << std::endl;
    printVector(m_vector, "Результирующий m_vector:");
}

// // Основная «умная» функция Ford-Johnson (pair + insert) для вектора
void PmergeMe::insertionSortVector(std::vector<int> &vec) {
    // // Если вектор совсем маленький, используем обычную сортировку вставками в диапазоне.
    const int INSERTION_THRESHOLD = 5;
    size_t n = vec.size();

    std::cout << "\n--> Вызов insertionSortVector() для вектора из " 
              << n << " элементов\n";
    printVector(vec, "Текущий вектор:");

    if (n <= INSERTION_THRESHOLD) {
        std::cout << "Размер <= " << INSERTION_THRESHOLD 
                  << ", используем простой insertionSortRangeVector\n";
        insertionSortRangeVector(vec, 0, static_cast<int>(n) - 1);

        // // Выведем результат после классической сортировки
        printVector(vec, "Вектор после insertionSortRangeVector:");
        return;
    }

    // // Разбиваем элементы на пары (ведущий / ведомый)
    std::vector<int> leaders;
    std::vector<int> followers;
    leaders.reserve(n / 2 + 1);
    followers.reserve(n / 2 + 1);

    for (size_t i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            // // Есть пара
            std::cout << "Формируем пару: (" << vec[i] << ", " << vec[i + 1] << ") -> ";
            if (vec[i] <= vec[i + 1]) {
                // // Если первый <= второго, тогда первый лидер, второй ведомый
                leaders.push_back(vec[i]);
                followers.push_back(vec[i + 1]);
                std::cout << "лидер = " << vec[i] 
                          << ", ведомый = " << vec[i + 1] << std::endl;
            } else {
                // // Иначе наоборот
                leaders.push_back(vec[i + 1]);
                followers.push_back(vec[i]);
                std::cout << "лидер = " << vec[i + 1] 
                          << ", ведомый = " << vec[i] << std::endl;
            }
        } else {
            // // Нечётное число элементов — последний будет без пары
            leaders.push_back(vec[i]);
            std::cout << "Остался одиночный элемент без пары: " 
                      << vec[i] << " (считаем лидером)" << std::endl;
        }
    }

    // // Теперь leaders и followers получили данные
    printVector(leaders, "Сформированный leaders:");
    printVector(followers, "Сформированный followers:");

    // // Рекурсивно сортируем leaders
    std::cout << "Рекурсивная сортировка массива leaders..." << std::endl;
    insertionSortVector(leaders);

    // // По одному вставляем элементы followers в уже отсортированный leaders
    std::cout << "\nНачинаем вставку элементов followers в leaders...\n";
    for (size_t i = 0; i < followers.size(); i++) {
        std::cout << "Вставляем followers[" << i << "] = " << followers[i] 
                  << " в leaders" << std::endl;
        binaryInsertVector(leaders, followers[i]);
        printVector(leaders, "leaders после вставки:");
    }

    // // Обновляем исходный вектор: теперь он — это полностью отсортированные leaders
    vec = leaders;
    std::cout << "\n-- Завершена insertionSortVector() для текущего подмножества --" << std::endl;
    printVector(vec, "Итоговый vec после слияния:");
}

// // Классическая сортировка вставкой (Insertion Sort) по индексам [left, right]
void PmergeMe::insertionSortRangeVector(std::vector<int> &arr, int left, int right) {
    std::cout << "  -> Начинаем insertionSortRangeVector() в диапазоне ["
              << left << ", " << right << "]" << std::endl;

    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    // // Для наглядности покажем, как выглядит массив после классической сортировки
    printVector(arr, "  -> Результат внутри insertionSortRangeVector:");
}

// // Вставка элемента x в отсортированный массив arr с помощью двоичного поиска
void PmergeMe::binaryInsertVector(std::vector<int> &arr, int x) {
    // // Найдём позицию, куда надо вставлять x
    std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), x);

    // // Для отладочных целей выведем индекс:
    size_t index = it - arr.begin();
    std::cout << "  -- binaryInsertVector: вставляем " << x << " в позицию " 
              << index << std::endl;

    arr.insert(it, x);
}

// // ============================
// // Пример использования
// // ============================
int main() {
    // // Создадим тестовый вектор
    std::vector<int> data = {8, 3, 7, 1, 9, 2, 5, 4, 10, 6};

    // // Инициализируем наш класс
    PmergeMe sorter(data);

    // // Посмотрим, что было "до"
    std::cout << "----- Исходный набор данных -----" << std::endl;
    sorter.printInternalVector();

    // // Запустим сортировку
    sorter.mergeSortVector();

    // // Посмотрим, что стало "после"
    std::cout << "\n----- Финальный результат -----" << std::endl;
    sorter.printInternalVector();

    return 0;
}

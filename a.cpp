#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>

struct MyStruct
{
    int id;
    std::string name;

    bool operator<(const MyStruct &other) const
    {
        return id < other.id;
    }
    bool operator>(const MyStruct &other) const
    {
        return id > other.id;
    }

    bool operator==(const MyStruct &other) const
    {
        return id == other.id && name == other.name;
    }

    friend std::ostream &operator<<(std::ostream &os, const MyStruct &s)
    {
        os << "(" << s.id << ", " << s.name << ")";
        return os;
    }
};

int main()
{
    // Задание 1: создание и заполнение контейнера
    std::deque<MyStruct> myDeque = {
        {5, "Женя"},
        {3, "Жанара"},
        {7, "Таисия"},
        {2, "Анна"},
        {9, "Михаил"}};

    // Задание 2: замена максимального элемента минимальным
    auto minIt = std::min_element(myDeque.begin(), myDeque.end());
    auto maxIt = std::max_element(myDeque.begin(), myDeque.end());

    if (minIt != myDeque.end() && maxIt != myDeque.end())
    {
        std::swap(*minIt, *maxIt);
    }

    std::cout << "После замены мин на макс: ";
    for (const auto &elem : myDeque)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Задание 3: удаление элементов меньше среднего
    double sum = std::accumulate(myDeque.begin(), myDeque.end(), 0.0,
                                 [](double acc, const MyStruct &s)
                                 { return acc + s.id; });
    double average = sum / myDeque.size();

    auto removeIt = std::remove_if(myDeque.begin(), myDeque.end(),
                                   [&](const MyStruct &s)
                                   { return s.id < average; });

    myDeque.erase(removeIt, myDeque.end());

    std::cout << "После удаления числа меньше: ";
    for (const auto &elem : myDeque)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Задание 4: сортировка по убыванию
    std::sort(myDeque.begin(), myDeque.end(), std::greater<MyStruct>());

    std::cout << "После сортировки в порядке убывания: ";
    for (const auto &elem : myDeque)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Задание 5: нахождение медианы
    if (!myDeque.empty())
    {
        std::size_t medianIndex = myDeque.size() / 2;
        std::nth_element(myDeque.begin(), myDeque.begin() + medianIndex, myDeque.end());
        std::cout << "Median: " << myDeque[medianIndex] << std::endl;
    }

    // Задание 6: Изменить знак каждого элемента в контейнере.
    std::deque<int> d = {10, -20, 30, -40, 50};

    std::cout << "Исходный контейнер: ";
    for (auto i : d)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::transform(d.begin(), d.end(), d.begin(), std::negate<int>());

    std::cout << "Контейнер после изменения знака: ";
    for (auto i : d)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

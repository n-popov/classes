#include <iostream>
#include <exception>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>


// Функция, которая, по нашему мнению,
// не должна бросать исключения
int increase(int x) noexcept {
    return x + 1;
}

// Ситуация, требующая выбрасывания исключения
template <typename N>
N divide(N lhs, N rhs) {
    if (rhs == static_cast<N>(0)) {
        throw std::invalid_argument("Can't divide by zero");
    }
    return lhs / rhs;
}

int main() {
    // Применение std::equal_range
    std::multiset set{1, 5, 6, 4, 7, 4};
    std::copy(std::begin(set), std::end(set),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    auto [lower, upper] = std::equal_range(std::begin(set),
                                   std::end(set), 4);
    std::copy(lower, upper,
              std::ostream_iterator<int>(std::cout, " "));

    // Метод splice
    std::list<int> list{1, 3};
    std::list<int> other_list{54, 6, 42};

    list.splice(std::next(list.begin()),
                other_list, std::begin(other_list),
                std::next(std::begin(other_list), 2));
    std::copy(std::begin(list), std::end(list),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::copy(std::begin(other_list), std::end(other_list),
              std::ostream_iterator<int>(std::cout, " "));

    // Очередь с приоритетами
    std::priority_queue<int> queue;
    queue.push(1);
    queue.push(54);
    queue.push(42);

    std::cout << queue.top() << std::endl;
    queue.pop();
    std::cout << queue.top() << std::endl;

    // Ловим конкретное исключение
    std::vector<int> v{34, 42, 53, 3};
    std::cout << v.at(0) << ' ' << v.at(3) << std::endl;
    try {
        std::cout << v.at(54) << std::endl;
    } catch (std::bad_alloc& ex) {
        std::cout << ex.what() << std::endl;
    }

    // Ловим все исключения (в т.ч. наше)
    try {
        std::cout << divide<double>(5., 0) << std::endl;
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
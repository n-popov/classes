//
// Created by Nikita on 12.02.2021.
//
#include <memory>
#include <iostream>

int main() {
    int* num = new int(5);
    std::shared_ptr<int> ptr(num);
    std::cout << *ptr << ' ' << ptr << std::endl;
    auto another_ptr = std::make_shared<int>(5);

    {
        std::shared_ptr<int> another_unique_ptr = ptr;
        std::cout << *another_unique_ptr << ' ' << another_unique_ptr << std::endl;
    }

    std::cout << *another_ptr << ' ' << another_ptr << std::endl;
//    int* num = new int(5);
//    std::unique_ptr<int> ptr(num);
//    std::cout << *ptr << std::endl;
//    auto another_ptr = std::make_unique<int>(5);
//    std::cout << *another_ptr << std::endl;
//
//    std::unique_ptr<int> another_unique_ptr = ptr;
}

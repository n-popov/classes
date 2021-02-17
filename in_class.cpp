#include <string>
#include <iostream>

class Student {
public:
    Student(const std::string &name, unsigned int age) :
    name(name), age(age) {}

    explicit Student(const std::string &name) :
    name(name), age(unsigned()) {}

    Student(const Student& student) = delete;
//    Student(const Student& student) :
//    name(student.name), age(student.age) {
//        std::cout << "Student copied" << std::endl;
//    }

    Student& operator=(const Student&) = delete;

    virtual ~Student() {

    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Student::name = name;
    }

    void setAge(unsigned int age) {
        Student::age = age;
    }

    unsigned int getAge() const {
        return age;
    }

private:
    std::string name;
    unsigned age;
};

class StringPtr {
public:
    StringPtr() : ptr(nullptr) {}
    StringPtr(std::string *ptr) : ptr(ptr) {}
    StringPtr(const StringPtr& anotherptr) {
        ptr = new std::string;
        *ptr = *(anotherptr.getPtr());
    }

    ~StringPtr() {
        delete ptr;
    }

    StringPtr& operator=(const StringPtr&) = delete;

    [[nodiscard]] std::string* getPtr() const {
        return ptr;
    }

    std::string& operator*() {
        return *ptr;
    }

private:
    std::string* ptr;

};

std::ostream& operator<<(std::ostream& ostr, const StringPtr& ptr) {
    ostr << ptr.getPtr();
    return ostr;
}
std::istream& operator>>(std::istream& istr, StringPtr& ptr) {
    istr >> *ptr;
    return istr;
}

void someFunc(Student s) {
    std::cout << s.getName() << std::endl;
}

int main() {
//    Student arkadiy("Arkadiy", 15);
//    Student another_arkadiy = arkadiy;

//    std::string niki = "Niki";
//    someFunc(another_arkadiy);
//    StringPtr* array_of_ptrs = new StringPtr[15];
    std::string* some_string = new std::string("Niki");
    StringPtr smart_ptr(some_string);
    StringPtr another_ptr(smart_ptr);
    std::cout << *another_ptr << ' ' << *smart_ptr << std::endl;
//    std::cout << smart_ptr.operator*() << std::endl;
//    std::cin >> smart_ptr;
//    std::cout << smart_ptr << ' ' << *smart_ptr << std::endl;


//    int* intptr = new int;
//    *intptr = 5;
//    std::cout << intptr << ' ' << *intptr << std::endl;

    auto x = 5;
}
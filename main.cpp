#include <iostream>

#include "array.hpp"
#include "list.hpp"

template <typename T>
void ArrayTest() {
    std::cout << "=============ARRAY=============" << std::endl;
    MyArray<T> arr(5);
    std::cout << "=============PushBack=============" << std::endl;
    arr.PushBack(0);
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    arr.PushBack(4);
    arr.PushBack(5);
    arr.PushBack(6);
    arr.PushBack(7);
    arr.PushBack(8);
    arr.PushBack(9);
    arr.Print();
    for (size_t i = 0; i < arr.Size(); i++) {
        std::cout << "arr [" << i << "] = " << arr[i] << std::endl;
    }

    std::cout << "=============Erase=============" << std::endl;
    arr.Erase(2);
    arr.Print();
    arr.Erase(3);
    arr.Print();
    arr.Erase(4);
    arr.Print();

    std::cout << "=============Insert=============" << std::endl;
    arr.Insert(10, 0);
    arr.Print();
    std::cout << "=============Insert=============" << std::endl;
    arr.Insert(20, 4);
    arr.Print();

    std::cout << "=============Copy ctor=============" << std::endl;
    MyArray<T> arr2(arr);
    arr2.Print();

    std::cout << "=============Copy assignment operator============="
              << std::endl;
    MyArray<T> arr3(0);
    arr3 = arr2;
    arr3.Print();

    std::cout << "=============Move ctor=============" << std::endl;
    MyArray<T> arr4{std::move(arr3)};
    arr4.Print();
    arr3.Print();

    std::cout << "=============Move assignment operator============="
              << std::endl;
    MyArray<T> arr5(0);
    arr5 = std::move(arr2);
    arr5.Print();
    arr2.Print();
}

template <typename T>
void ContainerTest() {
    std::cout << "=============CONTAINER=============" << std::endl;
    MySingneIist<T> arr;
    std::cout << "=============PushBack=============" << std::endl;
    arr.PushBack(0);
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    arr.PushBack(4);
    arr.PushBack(5);
    arr.PushBack(6);
    arr.PushBack(7);
    arr.PushBack(8);
    arr.PushBack(9);
    arr.Print();
    for (size_t i = 0; i < arr.Size(); i++) {
        std::cout << "arr [" << i << "] = " << arr[i] << std::endl;
    }

    std::cout << "=============Erase=============" << std::endl;
    arr.Erase(2);
    arr.Print();
    arr.Erase(3);
    arr.Print();
    arr.Erase(4);
    arr.Print();

    std::cout << "==============Insert==============" << std::endl;
    arr.Insert(10, 0);
    arr.Print();
    std::cout << "==============Insert==============" << std::endl;
    arr.Insert(20, 4);
    arr.Print();

    std::cout << "============Copy ctor=============" << std::endl;
    MySingneIist<T> arr2(arr);
    arr2.Print();

    std::cout << "=====Copy assignment operator=====" << std::endl;
    MySingneIist<T> arr3;
    arr3 = arr2;
    arr3.Print();

    std::cout << "============Move ctor=============" << std::endl;
    MySingneIist<T> arr4{std::move(arr3)};
    arr4.Print();
    arr3.Print();

    std::cout << "=====Move assignment operator=====" << std::endl;
    MySingneIist<T> arr5;
    arr5 = std::move(arr2);
    arr5.Print();
    arr2.Print();
}

int main() {
    std::cout << "ArrayTest fot int!" << std::endl;
    ArrayTest<int>();

    std::cout << "ArrayTest fot double!" << std::endl;
    ArrayTest<double>();

    std::cout << "ArrayTest fot short!" << std::endl;
    ArrayTest<short>();

    std::cout << "MySingneIist fot int!" << std::endl;
    ContainerTest<int>();

    std::cout << "MySingneIist fot double!" << std::endl;
    ContainerTest<double>();

    std::cout << "MySingneIist fot short!" << std::endl;
    ContainerTest<short>();

    return 0;
}
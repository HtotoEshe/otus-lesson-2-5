#pragma once

#include <cstddef>
#include <cstring>
#include <iostream>

template <typename T>
class MyArray {
public:
    virtual ~MyArray() {
        if (value_) {
            delete value_;
            value_ = nullptr;
        }
    }

    explicit MyArray(size_t n)
            : value_{nullptr}
            , size_{n}
            , tail_{0} {
        if (size_ > 0) {
            value_ = new T[size_];
        }
    }

    // Copy ctor
    MyArray(const MyArray& other)
            : MyArray{other.Size()} {
        memcpy(value_, other.value_, size_ * sizeof(T));
        tail_ = other.tail_;
    }

    // Move ctor
    MyArray(MyArray&& other) {  // r-value reference
        value_ = other.value_;
        size_ = other.size_;
        tail_ = other.tail_;
        other.value_ = nullptr;
        other.size_ = 0;
        other.tail_ = 0;
    }

    // Copy assignment operator
    MyArray& operator=(const MyArray& rhs) {
        delete value_;
        size_ = 0;
        Resize(rhs.size_);
        memcpy(value_, rhs.value_, rhs.size_ * sizeof(T));
        size_ = rhs.size_;
        tail_ = rhs.tail_;
        return *this;
    }

    // Move assignment operator
    MyArray& operator=(MyArray&& rhs) {
        MyArray tmp{std::move(rhs)};
        return *this = tmp;
    }

    void PushBack(const T& v) {
        if (tail_ >= size_) {
            Resize(size_ + 1);
        }

        value_[tail_] = v;
        tail_++;
    }

    bool Insert(const T& v, size_t pos) {
        if (pos >= size_) {
            return false;
        }

        for (size_t i = size_ - 1; i > pos; i--) {
            value_[i] = value_[i - 1];
        }

        value_[pos] = v;
        tail_++;

        return true;
    }

    bool Erase(size_t pos) {
        if (pos >= tail_) {
            return false;
        }
        for (size_t i = pos; i < tail_ - 1; i++) {
            value_[i] = value_[i + 1];
        }
        tail_--;

        return true;
    }

    void Print() const {
        std::cout << "Size = " << Size() << " tail_ = " << tail_ << std::endl;
        for (size_t i = 0; i < tail_; i++) {
            std::cout << " " << value_[i];
        }
        std::cout << std::endl;
    }

    size_t Size() const { return size_; }

    T operator[](size_t i) { return value_[i]; }

private:
    void Resize(size_t n) {
        T* new_val = new T[n];
        memcpy(new_val, value_, size_ * sizeof(T));
        size_ = n;
        if (value_) {
            delete value_;
        }
        value_ = new_val;
    }
    T* value_;
    size_t size_;
    size_t tail_;
};
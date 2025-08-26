#pragma once

#include <cstddef>
#include <cstring>
#include <iostream>

template <typename T>
class MySingneIist {
public:
    struct Entry {
        T data;
        Entry* next;
        explicit Entry()
                : data{}
                , next{nullptr} {}
        explicit Entry(const T& val)
                : data{val}
                , next{nullptr} {}
    };
    virtual ~MySingneIist() {
        auto curr = head_;
        while (curr) {
            auto tmp = curr->next;
            delete curr;
            curr = tmp;
        }
    }

    explicit MySingneIist()
            : head_{nullptr}
            , size_{0} {}

    // Copy ctor
    MySingneIist(const MySingneIist& other)
            : head_{nullptr}
            , size_{other.size_} {
        Copy(other);
    }

    // Move ctor
    MySingneIist(MySingneIist&& other)  // r-value reference
            : head_{other.head_}
            , size_{other.size_} {
        other.head_ = nullptr;
        other.size_ = 0;
    }

    // Copy assignment operator
    MySingneIist& operator=(const MySingneIist& rhs) {
        Clear();
        Copy(rhs);
        return *this;
    }

    // Move assignment operator
    MySingneIist& operator=(MySingneIist&& rhs) {
        MySingneIist tmp{std::move(rhs)};
        return *this = tmp;
    }

    void Clear() {
        auto curr = head_;
        while (curr) {
            auto tmp = curr;
            delete curr;
            curr = curr->next;
        }
    }

    void Copy(const MySingneIist& other) {
        if (other.head_) {
            head_ = new Entry{other.head_->data};
            auto tail = head_;
            auto other_it = other.head_->next;

            while (other_it) {
                Entry* entry = new Entry{other_it->data};
                tail->next = entry;
                tail = entry;
                other_it = other_it->next;
            }
        }
        size_ = other.size_;
    }

    size_t Size() { return size_; }

    void PushBack(const T& v) {
        Entry* entry = new Entry{v};
        if (!head_) {
            head_ = entry;
        } else {
            Entry* tail = head_;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = entry;
        }
        size_++;
    }

    bool Insert(const T& v, size_t pos) {
        if (pos >= size_) {
            return false;
        }
        Entry* entry = new Entry{v};
        if (pos == 0) {
            entry->next = head_;
            head_ = entry;
        } else {
            Entry* last = GetElement(pos - 1);
            if (last) {
                auto tmp = last->next;
                last->next = entry;
                entry->next = tmp;
            }
        }
        size_++;

        return true;
    }

    bool Erase(size_t pos) {
        if (pos >= size_) {
            return false;
        }
        if (pos == 0) {  // rm head
            Entry* tmp = head_->next;
            delete head_;
            head_ = tmp;
        } else {  // rm tail
            Entry* last = GetElement(pos - 1);
            Entry* point = last->next;
            Entry* tmp = point->next;
            delete point;
            last->next = tmp;
        }

        size_--;
        return true;
    }

    Entry* GetElement(size_t index) {
        if (index >= size_) {
            return nullptr;
        }

        Entry* last = head_;
        if (index > 0) {
            for (size_t i = 1; i <= index && last; i++) {
                last = last->next;
            }
        }

        return last;
    }

    void Print() const {
        std::cout << "Size = " << size_ << std::endl;
        Entry* tmp = head_;
        while (tmp) {
            std::cout << " " << tmp->data;
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

    T operator[](size_t index) {
        Entry* point = GetElement(index);
        if (point) {
            return point->data;
        } else {
            return T{};
        }
    }

private:
    Entry* head_;
    size_t size_;
};
#pragma once

#include <cassert>
#include <new>         
#include <utility>     

template<typename T>
class Vector
{
public:
    using ValueType = T;
    using Iterator = T*;

public:
    Vector(size_t cap = 5)
        : size_(0), capacity_(cap)
    {
        data = static_cast<T*>(::operator new(sizeof(T) * capacity_)); // raw memory만 확보(T 생성자 호출 x)
    }

    ~Vector()
    {
        clear();
        ::operator delete(data);
    }

    void push_back(const T& value)
    {
        if (size_ >= capacity_)
            reallocate(capacity_ + capacity_ / 2 + 1);

        new (data + size_) T(value);  // placement new
        ++size_;
    }

    void push_back(T&& value)
    {
        if (size_ >= capacity_)
            reallocate(capacity_ + capacity_ / 2 + 1);

        new (data + size_) T(std::move(value));
        ++size_;
    }

    void pop_back()
    {
        assert(size_ > 0);

        --size_;
        data[size_].~T();  // 직접 소멸
    }

    Iterator erase(Iterator it)
    {
        assert(size_ > 0);

        size_t index = it - data;

        data[index].~T();  // 제거 대상 소멸

        for (size_t i = index; i < size_ - 1; ++i)
        {
            new (data + i) T(std::move(data[i + 1]));
            data[i + 1].~T();
        }

        --size_;
        return data + index;
    }

    T& operator[](size_t index)
    {
        assert(index < size_);
        return data[index];
    }

    const T& operator[](size_t index) const
    {
        assert(index < size_);
        return data[index];
    }

    Iterator begin() { return data; }
    Iterator end() { return data + size_; }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }

private:

    void reallocate(size_t newCap)
    {
        T* newData = static_cast<T*>(::operator new(sizeof(T) * newCap));

        for (size_t i = 0; i < size_; ++i)
        {
            new (newData + i) T(std::move(data[i]));
            data[i].~T();
        }

        ::operator delete(data);
        data = newData;
        capacity_ = newCap;
    }

    void clear()
    {
        for (size_t i = 0; i < size_; ++i)
            data[i].~T();

        size_ = 0;
    }

private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T* data = nullptr;
};
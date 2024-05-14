#pragma once
#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"
template <typename T> class Vector
{
  private:
    DynamicArray<T> *elements;

  public:
    Vector()
    {
        this->elements = new DynamicArray<T>();
    }

    Vector(T *items, int count)
    {
        this->elements = new DynamicArray<T>(items, count);
    }

    Vector(const Sequence<T> &seq)
    {
        this->elements = new DynamicArray<T>(seq.GetLength());
        for (int i = 0; i < seq.GetLength(); i++)
        {
            this->elements->Set(seq.Get(i), i);
        }
    }

    Vector(const Vector<T> &vec)
    {
        this->elements = new DynamicArray<T>(vec.GetLength());
        for (int i = 0; i < vec.GetLength(); i++)
        {
            this->elements->Set(vec.Get(i), i);
        }
    }

    T GetFirst()
    {
        return this->elements->Get(0);
    }
    T GetLast()
    {
        return this->elements->Get(this->elements->GetSize() - 1);
    }
    T Get(int index) const
    {
        return this->elements->Get(index);
    }

    int GetLength() const
    {
        return this->elements->GetSize();
    }

    Vector<T> *vectorSum(const Vector<T> &vec2)
    {
        if (this->GetLength() != vec2.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        T *intermediate = new T[this->GetLength()];

        for (int i = 0; i < this->GetLength(); i++)
        {
            intermediate[i] = this->Get(i) + vec2.Get(i);
        }
        Vector<T> *vecRes = new Vector(intermediate, this->GetLength());
        return vecRes;
    }

    Vector<T> *vectorMultiOnScalar(const int elem)
    {
        T *intermediate = new T[this->GetLength()];

        for (int i = 0; i < this->GetLength(); i++)
        {
            intermediate[i] = this->Get(i) * elem;
        }
        Vector<T> *vecRes = new Vector(intermediate, this->GetLength());
        return vecRes;
    }

    Vector<T> *vectorMulti(const Vector<T> &vec2)
    {
        if (this->GetLength() != vec2.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        T *intermediate = new T[this->GetLength()];

        for (int i = 0; i < this->GetLength(); i++)
        {
            intermediate[i] = this->Get(i) * vec2.Get(i);
        }
        Vector<T> *vecRes = new Vector(intermediate, this->GetLength());
        return vecRes;
    }

    virtual ~Vector()
    {
        delete elements;
    }

    Vector<T> *operator+(Vector<T> &vec)
    {
        Vector<T> *vecRes = this->vectorSum(vec);
        return vecRes;
    }

    Vector<T> *operator*(Vector<T> &vec)
    {
        Vector<T> *vecRes = this->vectorMulti(vec);
        return vecRes;
    }

    Vector<T> *operator*(const T item)
    {
        Vector<T> *vecRes = this->vectorMultiOnScalar(item);
        return vecRes;
    }

    T operator[](int index)
    {
        return this->Get(index);
    }
};

template <typename T> void VectorShow(Vector<T> &vec)
{
    for (int i = 0; i < vec.GetLength(); i++)
    {
        std::cout << vec.Get(i) << " ";
    }
    std::cout << std::endl;
}

template <typename T> void VectorShow(Vector<T> *vec)
{
    for (int i = 0; i < vec->GetLength(); i++)
    {
        std::cout << vec->Get(i) << " ";
    }
    std::cout << std::endl;
}

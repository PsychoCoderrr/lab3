#pragma once
#include "DynamicArray.h"
#include "Sequence.h"
#include "LinkedList.h"
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

    Vector(Sequence<T> &seq)
    {
        this->elements = new DynamicArray<T>(seq.GetLength());
        for (int i = 0; i < seq.GetLength(); i++)
        {
            this->elements->Set(seq.Get(i), i);
            this->elements->Resize(this->GetLength() - 1);
        }
    }

    Vector(Vector<T> &vec)
    {
        this->elements = new DynamicArray<T>(vec.GetLength());
        for (int i = 0; i < vec.GetLength(); i++)
        {
            this->elements->Set(vec.Get(i), i);
            this->elements->Resize(this->GetLength() - 1);
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
};


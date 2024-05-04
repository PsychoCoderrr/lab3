#include <iostream>
#include "assert.h"
template <typename T> class Sequence
{
public:
  virtual ~Sequence () {}
  virtual T GetFirst () = 0;
  virtual T GetLast () = 0;
  virtual T Get (int index) const = 0;
  virtual int GetLength () const = 0;

  virtual Sequence<T> *GetSubSequence (int startIndex, int endIndex) = 0;
  virtual Sequence<T> *Append (const T &item) = 0;
  virtual Sequence<T> *Prepend (const T &item) = 0;
  virtual Sequence<T> *InsertAt (const T &item, int index) = 0;
  virtual Sequence<T> *Concat (Sequence<T> &list) = 0;
  virtual T &operator[] (int index) = 0;
};

template <typename T> class DynamicArray
{
private:
  T *elements = nullptr;
  int capacity;
  int size;

  void
  Reserve (int newCapacity)
  {
    if (newCapacity <= capacity)
      {
        capacity = newCapacity;
        return;
      }

    T *newElements = new T[newCapacity];
    for (int i = 0; i < size; i++)
      {
        newElements[i] = elements[i];
      }
    delete elements;
    elements = newElements;
    capacity = newCapacity;
  }

public:
  DynamicArray () : size (0), capacity (0), elements (nullptr) {}

  DynamicArray (int size)
      : size (size), capacity (size + 1), elements (nullptr)
  {
    if (size <= 0)
      {
        throw std::out_of_range ("invalid argument for size");
      }
    else
      {
        elements = new T[capacity];
      }
  }

  DynamicArray (T *items, int count) : DynamicArray (count)
  {
    if (items == nullptr)
      {
        throw std::out_of_range ("invalid argument in elems for constructor");
      }
    else
      {
        for (int i = 0; i < count; i++)
          {
            elements[i] = items[i];
          }
      }
  }

  DynamicArray (const DynamicArray<T> &dynamicArray)
      : DynamicArray<T> (dynamicArray.elements, dynamicArray.size)
  {
  }

  ~DynamicArray () { delete[] elements; }

  T
  Get (int index)
  {
    if (index < 0 || index > size)
      {
        throw std::out_of_range ("invalid argument");
      }
    return elements[index];
  }

  int
  GetSize () const
  {
    return size;
  }

  void
  Set (const T &value, int index)
  {
    if (index < 0 || index > size)
      {
        throw std::out_of_range ("invalid argument");
      }
    Resize (size + 1);
    for (int i = size; i > index; i--)
      {
        elements[i] = elements[i - 1];
      }
    elements[index] = value;
  }

  void
  Resize (int newSize)
  {
    if (newSize < 0)
      {
        throw std::invalid_argument ("invalid argument");
      }
    if (newSize == 0)
      {
        delete[] elements;
        elements = nullptr;
      }
    if (newSize > capacity)
      {
        Reserve (newSize * 2);
      }
    size = newSize;
  }

  T &
  operator[] (int index)
  {
    if (size <= index)
      {
        throw std::out_of_range ("Invalid argument");
      }
    return elements[index];
  }

  bool
  operator== (const DynamicArray<T> &array)
  {
    if (array.size != size)
      {
        return false;
      }
    for (int i = 0; i < size; i++)
      {
        if (array[i] != elements[i])
          {
            return false;
          }
      }
    return true;
  }
};

template <typename T> class Vector
{
private:
    DynamicArray<T>* elements;
public:
    Vector (){this->elements = new DynamicArray<T>();}
    
    Vector (int count) {this->elements = new DynamicArray<T>(count);}
    
    Vector (T *items, int count)
    {
      this->elements = new DynamicArray<T> (items, count);
    }
    
    Vector (Sequence<T> &seq)
    {
      this->elements = new DynamicArray<T> (seq.GetLength ());
      for (int i = 0; i < seq.GetLength (); i++)
        {
          this->elements->Set (seq.Get (i), i);
            this->elements->Resize (this->GetLength () - 1);
        }
    }
    
    Vector (Vector<T> &vec)
    {
      this->elements = new DynamicArray<T> (vec.GetLength ());
      for (int i = 0; i < vec.GetLength (); i++)
        {
          this->elements->Set (vec.Get (i), i);
          this->elements->Resize (this->GetLength () - 1);
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
    
    Vector<T>* Append(const T& item)
    {
        this->elements->Set(item, elements->GetSize());
        return this;
    }
    
    Vector<T>* Prepend(const T& item)
    {
        this->elements->Set(item, 0);
        return this;
    }
    
    Vector<T>* InsertAt(const T &item, int index)
    {
        this->elements->Set(item, index);
        return this;
    }
    
    Vector<T>* vectorSum( const Vector<T> &vec2)
    {
        if (this->GetLength() != vec2.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        Vector<T>* vecRes = new Vector();
        for (int i = 0; i < this->GetLength(); i ++)
        {
            vecRes->Append(this->Get(i) + vec2.Get(i));
        }
        return vecRes;
    }
    
    Vector<T>* vectorMultiOnScalar( const int elem)
    {
        Vector<T>* vecRes = new Vector();
        for (int i = 0; i < this->GetLength(); i ++)
        {
            vecRes->Append(this->Get(i) * elem);
        }
        return vecRes;
    }
    
    Vector<T>* vectorMulti( const Vector<T> &vec2)
    {
        if (this->GetLength() != vec2.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        Vector<T>* vecRes = new Vector();
        for (int i = 0; i < this->GetLength(); i ++)
        {
            vecRes->Append(this->Get(i) * vec2.Get(i));
        }
        return vecRes;
    }
    
    virtual ~Vector () { delete elements; }
};

void TestVectorSum()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};
    int c[] = {2, 4, 6, 8, 10};
    Vector<int> test1 (a, 5);
    Vector<int> test2 (b, 5);
    Vector<int>* res = test1.vectorSum(test2);
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i) == c[i]);
    }
}

void TestVectorMultiOnScalar()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 6, 8, 10};
    Vector<int> vec (a, 5);
    Vector<int>* res = vec.vectorMultiOnScalar(2);
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i) == b[i]);
    }
}

void TestVectorMulti()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 6, 8, 10};
    int c[] = {2, 8, 18, 32, 50};
    Vector<int> vec1 (a, 5);
    Vector<int> vec2 (b, 5);
    Vector<int>* res = vec1.vectorMulti(vec2);
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i) == c[i]);
    }
}

int main(int argc, const char * argv[]) {
    TestVectorSum();
    TestVectorMultiOnScalar();
    TestVectorMulti();
    return 0;
}

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

template <typename T> struct TheNode
{
  TheNode (T value) : data (value), next (nullptr) {}
  T data;
  TheNode<T> *next = nullptr;
};

template <typename T> class LinkedList
{
private:
  int size;
  TheNode<T> *head;

public:
  LinkedList (T *items, int count) : size (0), head (nullptr)
  {
    if (count < 0)
      {
        throw std::invalid_argument ("invalid argument");
      }
    for (int i = 0; i < count; i++)
      {
        Append (items[i]);
      }
  }

  LinkedList () : size (0), head (nullptr) {}

  LinkedList (const LinkedList<T> &list) : LinkedList ()
  {
    TheNode<T> *intermediate = list.head;
    for (int i = 0; i < list.size; i++)
      {
        Append (intermediate->data);
        intermediate = intermediate->next;
      }
    this->size = list.size;
  }

  virtual ~LinkedList ()
  {
    if (head != nullptr)
      {
        TheNode<T> *current = head;
        TheNode<T> *buf;
        for (int i = 0; i < this->size; i++)
          {
            buf = current->next;
            delete current;
            current = buf;
          }
        delete current;
      }
  }

  T
  GetFirst ()
  {
    if (head == nullptr)
      {
        throw std::invalid_argument ("index out of range");
      }
    return head->data;
  }

  T
  GetLast ()
  {
    if (head == nullptr)
      {
        throw std::invalid_argument ("index out of range");
      }
    TheNode<T> *intermediate = head;
    for (int i = 0; i < this->size - 1; i++)
      {
        intermediate = intermediate->next;
      }
    return intermediate->data;
  }

  T
  Get (int index)
  {
    if (index < 0 || index >= this->size)
      {
        throw std::invalid_argument ("index out of range");
      }
    TheNode<T> *intermediate = head;
    for (int i = 0; i < index; i++)
      {
        intermediate = intermediate->next;
      }
    return intermediate->data;
  }

  LinkedList<T> *
  GetSubList (int startIndex, int endIndex)
  {
    if (startIndex < 0 || endIndex < 0 || startIndex > endIndex
        || endIndex >= size)
      {
        throw std::invalid_argument ("index out of range");
      }
    LinkedList<T> *ResultList = new LinkedList ();
    TheNode<T> *intermediate = head;
    for (int i = 0; i < startIndex; i++)
      {
        intermediate = intermediate->next;
      }
    for (int i = startIndex; i < endIndex; i++)
      {
        ResultList->Append (intermediate->data);
        intermediate = intermediate->next;
      }
    return ResultList;
  }

  int
  GetLength ()
  {
    return this->size;
  }

  void
  Append (const T &item)
  {
    if (head == nullptr)
      {
        TheNode<T> *buf = new TheNode<T> (item);
        this->head = buf;
        size++;
      }
    else
      {
        TheNode<T> *buf = new TheNode<T> (item);
        TheNode<T> *intermediate = head;
        for (int i = 0; i < this->size - 1; i++)
          {
            intermediate = intermediate->next;
          }
        intermediate->next = buf;
        this->size++;
      }
  }

  void
  Prepend (const T &item)
  {
    TheNode<T> *buf = new TheNode<T> (item);
    buf->next = head;
    head = buf;
    this->size++;
  }

  void
  InsertAt (T item, int index)
  {
    if (index < 0 || index >= this->size)
      {
        throw std::invalid_argument ("index out of range");
      }
    TheNode<T> *newElem = new TheNode<T> (item);
    TheNode<T> *intermediate = head;
    for (int i = 0; i < index - 1; i++)
      {
        intermediate = intermediate->next;
      }
    newElem->next = intermediate->next;
    intermediate->next = newElem;
    this->size++;
  }

  LinkedList<T> *
  Concat (LinkedList<T> &list)
  {
    LinkedList<T> *resultList = new LinkedList<T> ();
    for (int i = 0; i < this->size; i++)
      {
        resultList->Append (this->Get (i));
      }
    TheNode<T> *intermediate = list.head;
    for (int i = 0; i < list.size; i++)
      {
        resultList->Append (intermediate->data);
        intermediate = intermediate->next;
      }
    return resultList;
  }

  T &
  operator[] (int index)
  {
    if (index > this->size || index < 0)
      {
        throw std::invalid_argument ("index out of range");
      }
    TheNode<T> *intermediate = head;
    for (int i = 0; i < index; i++)
      {
        intermediate = intermediate->next;
      }
    return intermediate->data;
  }
};

template <typename T> class ListSequence : public Sequence<T>
{
protected:
  virtual ListSequence<T> *Instance () = 0;
  LinkedList<T> *list;

  ListSequence<T> *
  appendWithoutInstance (const T &item)
  {
    ListSequence<T> *result = this;
    result->list->Append (item);
    return result;
  }

public:
  ListSequence () { this->list = new LinkedList<T> (); }
  ListSequence (T *items, int count)
  {
    this->list = new LinkedList<T> (items, count);
  }
  ListSequence (const Sequence<T> &seq)
  {
    this->list = new LinkedList<T> ();
    for (int i = 0; i < seq.GetLength (); i++)
      {
        appendWithoutInstance (seq.Get (i));
      }
  }

  ListSequence (const ListSequence<T> &seq)
  {
    this->list = new LinkedList<T> ();
    for (int i = 0; i < seq.GetLength (); i++)
      {
        appendWithoutInstance (seq.Get (i));
      }
  }

  T
  GetFirst () override
  {
    return this->list->GetFirst ();
  }

  T
  GetLast () override
  {
    return this->list->GetLast ();
  }

  T
  Get (int index) const override
  {
    return this->list->Get (index);
  }

  int
  GetLength () const override
  {
    return this->list->GetLength ();
  }

  ListSequence<T> *
  Append (const T &item) override
  {
    ListSequence<T> *result = Instance ();
    result->list->Append (item);
    return result;
  }

  ListSequence<T> *
  Prepend (const T &item) override
  {
    ListSequence<T> *result = Instance ();
    result->list->Prepend (item);
    return result;
  }

  ListSequence<T> *
  InsertAt (const T &item, int index) override
  {
    ListSequence<T> *result = Instance ();
    result->list->InsertAt (item, index);
    return result;
  }

  T &
  operator[] (int index) override
  {
    return (*(this->list))[index];
  }

  ~ListSequence () { delete list; }
};

template <typename T> class MutableListSequence : public ListSequence<T>
{
private:
  ListSequence<T> *
  Instance () override
  {
    return static_cast<ListSequence<T> *> (this);
  }

public:
  using ListSequence<T>::ListSequence;

  MutableListSequence<T> *
  Concat (Sequence<T> &elements) override
  {
    MutableListSequence<T> *result
        = new MutableListSequence<T> (static_cast<Sequence<T> &> (*this));
    for (int i = 0; i < elements.GetLength (); i++)
      {
        result->Append (elements.Get (i));
      }
    return result;
  }
  MutableListSequence<T> *
  GetSubSequence (int startIndex, int endIndex) override
  {
    if (startIndex < 0 || endIndex < startIndex
        || endIndex >= this->GetLength ())
      {
        throw std::invalid_argument ("invalid argument");
      }
    T *intermediate = new T[endIndex - startIndex + 1];
    for (int i = 0; i < endIndex - startIndex + 1; i++)
      {
        intermediate[i] = this->Get (startIndex + i - 1);
      }
    MutableListSequence<T> *result
        = new MutableListSequence<T> (intermediate, endIndex - startIndex + 1);
    delete[] intermediate;
    return result;
  }
};

template <typename T> class Vector
{
private:
    DynamicArray<T>* elements;
public:
    Vector (){this->elements = new DynamicArray<T>();}
    
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
    
    Vector<T>* vectorSum( const Vector<T> &vec2)
    {
        if (this->GetLength() != vec2.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        T* intermediate = new T[this->GetLength()];
        
        for (int i = 0; i < this->GetLength(); i ++)
        {
            intermediate[i] = this->Get(i) + vec2.Get(i);
        }
        Vector<T>* vecRes = new Vector(intermediate, this->GetLength());
        return vecRes;
    }
    
    Vector<T>* vectorMultiOnScalar( const int elem)
    {
        T* intermediate = new T[this->GetLength()];
        
        for (int i = 0; i < this->GetLength(); i ++)
        {
            intermediate[i] = this->Get(i) * elem;
        }
        Vector<T>* vecRes = new Vector(intermediate, this->GetLength());
        return vecRes;
    }
    
    Vector<T>* vectorMulti( const Vector<T> &vec2)
    {
        if (this->GetLength() != vec2.GetLength())
        {
            throw std::invalid_argument("different sizes");
        }
        T* intermediate = new T[this->GetLength()];
        
        for (int i = 0; i < this->GetLength(); i ++)
        {
            intermediate[i] = this->Get(i) * vec2.Get(i);
        }
        Vector<T>* vecRes = new Vector(intermediate, this->GetLength());
        return vecRes;
    }
    
    virtual ~Vector () { delete elements; }
};

template <typename T>
class Stack
{
private:
    MutableListSequence<T>* elements;
public:
    Stack()
    {
        elements = new MutableListSequence<T>();
    }
    
    Stack(T* array, int count)
    {
        elements = new MutableListSequence<T>(array, count);
    }
    
    Stack(Stack<T>& StackForCopy)
    {
        elements = new MutableListSequence<T>();
        for (int i = 0; i < StackForCopy.elements->GetLength(); i++)
        {
            elements->Append(StackForCopy.elements->Get(i));
        }
    }
    
    ~Stack()
    {
        delete elements;
    }
    
    void push(const T& item)
    {
        this->elements->Prepend(item);
    }
    
    T pop() // удаление элемента из стека с его получением
    {
        T result = elements->GetFirst();
        elements = elements->GetSubSequence(1, elements->GetLength());
    }
    
    T ShowElement (int index)
    {
        return elements->Get(index);
    }
    
    void StackShow()
    {
        for (int i = 0; i < this->GetSize(); i++)
        {
            std::cout << this->ShowElement(i) << std::endl;
        }
    }
    
    T GetSize()
    {
        return elements->GetLength();
    }
    
    Stack<T>* Concat (Stack<T>& stack)
    {
        for (int i = 0; i < stack.GetSize(); i++)
        {
            elements->Append(stack.ShowElement(i));
        }
        return this;
    }
    
    Stack<T>* GetSubStack (int startIndex, int endIndex)
    {
        Stack<T>* resultStack = new Stack<T>();
        resultStack->elements = elements->GetSubSequence(startIndex, endIndex);
        return resultStack;
    }
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

void TestStackConstructors()
{
    int a[] = {1, 2, 3, 4};
    Stack<int> test1 (a, 4);
    assert(test1.GetSize() == 4);
    for (int i = 0; i < test1.GetSize(); i++)
    {
        assert(test1.ShowElement(i) == a[i]);
    }
    
    Stack<int> test2 (test1);
    for (int i = 0; i < test1.GetSize(); i++)
    {
        assert(test1.ShowElement(i) == test2.ShowElement(i));
    }
}

void TestStackPush()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 1, 2, 3, 4};
    Stack<int>* test = new Stack<int>(a, 4);
    assert(test->GetSize() == 4);
    test->push(5);
    assert(test->GetSize() == 5);
    for (int i = 0; i < test->GetSize(); i++)
    {
        assert(test->ShowElement(i) == b[i]);
    }
}

void TestStackConcat()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int ab[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Stack<int> test1(a, 4);
    assert(test1.GetSize() == 4);
    Stack<int> test2(b, 4);
    assert(test2.GetSize() == 4);
    Stack<int>* test3 = test1.Concat(test2);
    assert(test3->GetSize() == 8);
    for (int i = 0; i < test3->GetSize(); i++)
    {
        assert(test3->ShowElement(i) == ab[i]);
    }
}

void TestStackGetSubStack()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {1, 2, 3, 4, 5};
    Stack<int> test1(a, 8);
    assert(test1.GetSize() == 8);
    Stack<int>* test2 = test1.GetSubStack(1, 5);
    for (int i = 0; i < test2->GetSize(); i++)
    {
        assert(test2->ShowElement(i) == b[i]);
    }
}

int main(int argc, const char * argv[]) {
//    TestVectorSum();
//    TestVectorMultiOnScalar();
//    TestVectorMulti();
//    TestStackPush();
//    TestStackConstructors();
//    TestStackConcat();
    TestStackGetSubStack();
    return 0;
}

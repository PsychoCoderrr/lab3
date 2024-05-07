#include "assert.h"
#include <iostream>
#include <string>

typedef std::string PersonId;

template <typename T> class Sequence
{
  public:
    virtual ~Sequence()
    {
    }
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) const = 0;
    virtual int GetLength() const = 0;

    virtual Sequence<T> *GetSubSequence(int startIndex, int endIndex) = 0;
    virtual Sequence<T> *Append(const T &item) = 0;
    virtual Sequence<T> *Prepend(const T &item) = 0;
    virtual Sequence<T> *InsertAt(const T &item, int index) = 0;
    virtual Sequence<T> *Concat(Sequence<T> &list) = 0;
    virtual T &operator[](int index) = 0;
};

template <typename T> class DynamicArray
{
  private:
    T *elements = nullptr;
    int capacity;
    int size;

    void Reserve(int newCapacity)
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
    DynamicArray() : size(0), capacity(0), elements(nullptr)
    {
    }

    DynamicArray(int size) : size(size), capacity(size + 1), elements(nullptr)
    {
        if (size <= 0)
        {
            throw std::out_of_range("invalid argument for size");
        }
        else
        {
            elements = new T[capacity];
        }
    }

    DynamicArray(T *items, int count) : DynamicArray(count)
    {
        if (items == nullptr)
        {
            throw std::out_of_range("invalid argument in elems for constructor");
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                elements[i] = items[i];
            }
        }
    }

    DynamicArray(const DynamicArray<T> &dynamicArray) : DynamicArray<T>(dynamicArray.elements, dynamicArray.size)
    {
    }

    ~DynamicArray()
    {
        delete[] elements;
    }

    T Get(int index)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("invalid argument");
        }
        return elements[index];
    }

    int GetSize() const
    {
        return size;
    }

    void Set(const T &value, int index)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("invalid argument");
        }
        Resize(size + 1);
        for (int i = size; i > index; i--)
        {
            elements[i] = elements[i - 1];
        }
        elements[index] = value;
    }

    void Resize(int newSize)
    {
        if (newSize < 0)
        {
            throw std::invalid_argument("invalid argument");
        }
        if (newSize == 0)
        {
            delete[] elements;
            elements = nullptr;
        }
        if (newSize > capacity)
        {
            Reserve(newSize * 2);
        }
        size = newSize;
    }

    T &operator[](int index)
    {
        if (size <= index)
        {
            throw std::out_of_range("Invalid argument");
        }
        return elements[index];
    }

    bool operator==(const DynamicArray<T> &array)
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
    TheNode(T value) : data(value), next(nullptr)
    {
    }
    T data;
    TheNode<T> *next = nullptr;
};

template <typename T> class LinkedList
{
  private:
    int size;
    TheNode<T> *head;

  public:
    LinkedList(T *items, int count) : size(0), head(nullptr)
    {
        if (count < 0)
        {
            throw std::invalid_argument("invalid argument");
        }
        for (int i = 0; i < count; i++)
        {
            Append(items[i]);
        }
    }

    LinkedList() : size(0), head(nullptr)
    {
    }

    LinkedList(const LinkedList<T> &list) : LinkedList()
    {
        TheNode<T> *intermediate = list.head;
        for (int i = 0; i < list.size; i++)
        {
            Append(intermediate->data);
            intermediate = intermediate->next;
        }
        this->size = list.size;
    }

    virtual ~LinkedList()
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

    T GetFirst()
    {
        if (head == nullptr)
        {
            throw std::invalid_argument("index out of range");
        }
        return head->data;
    }

    T GetLast()
    {
        if (head == nullptr)
        {
            throw std::invalid_argument("index out of range");
        }
        TheNode<T> *intermediate = head;
        for (int i = 0; i < this->size - 1; i++)
        {
            intermediate = intermediate->next;
        }
        return intermediate->data;
    }

    T Get(int index)
    {
        if (index < 0 || index >= this->size)
        {
            throw std::invalid_argument("index out of range");
        }
        TheNode<T> *intermediate = head;
        for (int i = 0; i < index; i++)
        {
            intermediate = intermediate->next;
        }
        return intermediate->data;
    }

    LinkedList<T> *GetSubList(int startIndex, int endIndex)
    {
        if (startIndex < 0 || endIndex < 0 || startIndex > endIndex || endIndex >= size)
        {
            throw std::invalid_argument("index out of range");
        }
        LinkedList<T> *ResultList = new LinkedList();
        TheNode<T> *intermediate = head;
        for (int i = 0; i < startIndex; i++)
        {
            intermediate = intermediate->next;
        }
        for (int i = startIndex; i < endIndex; i++)
        {
            ResultList->Append(intermediate->data);
            intermediate = intermediate->next;
        }
        return ResultList;
    }

    int GetLength()
    {
        return this->size;
    }

    void Append(const T &item)
    {
        if (head == nullptr)
        {
            TheNode<T> *buf = new TheNode<T>(item);
            this->head = buf;
            size++;
        }
        else
        {
            TheNode<T> *buf = new TheNode<T>(item);
            TheNode<T> *intermediate = head;
            for (int i = 0; i < this->size - 1; i++)
            {
                intermediate = intermediate->next;
            }
            intermediate->next = buf;
            this->size++;
        }
    }

    void Prepend(const T &item)
    {
        TheNode<T> *buf = new TheNode<T>(item);
        buf->next = head;
        head = buf;
        this->size++;
    }

    void InsertAt(T item, int index)
    {
        if (index < 0 || index >= this->size)
        {
            throw std::invalid_argument("index out of range");
        }
        TheNode<T> *newElem = new TheNode<T>(item);
        TheNode<T> *intermediate = head;
        for (int i = 0; i < index - 1; i++)
        {
            intermediate = intermediate->next;
        }
        newElem->next = intermediate->next;
        intermediate->next = newElem;
        this->size++;
    }

    LinkedList<T> *Concat(LinkedList<T> &list)
    {
        LinkedList<T> *resultList = new LinkedList<T>();
        for (int i = 0; i < this->size; i++)
        {
            resultList->Append(this->Get(i));
        }
        TheNode<T> *intermediate = list.head;
        for (int i = 0; i < list.size; i++)
        {
            resultList->Append(intermediate->data);
            intermediate = intermediate->next;
        }
        return resultList;
    }

    T &operator[](int index)
    {
        if (index > this->size || index < 0)
        {
            throw std::invalid_argument("index out of range");
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
    virtual ListSequence<T> *Instance() = 0;
    LinkedList<T> *list;

    ListSequence<T> *appendWithoutInstance(const T &item)
    {
        ListSequence<T> *result = this;
        result->list->Append(item);
        return result;
    }

  public:
    ListSequence()
    {
        this->list = new LinkedList<T>();
    }
    ListSequence(T *items, int count)
    {
        this->list = new LinkedList<T>(items, count);
    }
    ListSequence(const Sequence<T> &seq)
    {
        this->list = new LinkedList<T>();
        for (int i = 0; i < seq.GetLength(); i++)
        {
            appendWithoutInstance(seq.Get(i));
        }
    }

    ListSequence(const ListSequence<T> &seq)
    {
        this->list = new LinkedList<T>();
        for (int i = 0; i < seq.GetLength(); i++)
        {
            appendWithoutInstance(seq.Get(i));
        }
    }

    T GetFirst() override
    {
        return this->list->GetFirst();
    }

    T GetLast() override
    {
        return this->list->GetLast();
    }

    T Get(int index) const override
    {
        return this->list->Get(index);
    }

    int GetLength() const override
    {
        return this->list->GetLength();
    }

    ListSequence<T> *Append(const T &item) override
    {
        ListSequence<T> *result = Instance();
        result->list->Append(item);
        return result;
    }

    ListSequence<T> *Prepend(const T &item) override
    {
        ListSequence<T> *result = Instance();
        result->list->Prepend(item);
        return result;
    }

    ListSequence<T> *InsertAt(const T &item, int index) override
    {
        ListSequence<T> *result = Instance();
        result->list->InsertAt(item, index);
        return result;
    }

    T &operator[](int index) override
    {
        return (*(this->list))[index];
    }

    ~ListSequence()
    {
        delete list;
    }
};

template <typename T> class MutableListSequence : public ListSequence<T>
{
  private:
    ListSequence<T> *Instance() override
    {
        return static_cast<ListSequence<T> *>(this);
    }

  public:
    using ListSequence<T>::ListSequence;

    MutableListSequence<T> *Concat(Sequence<T> &elements) override
    {
        MutableListSequence<T> *result = new MutableListSequence<T>(static_cast<Sequence<T> &>(*this));
        for (int i = 0; i < elements.GetLength(); i++)
        {
            result->Append(elements.Get(i));
        }
        return result;
    }
    MutableListSequence<T> *GetSubSequence(int startIndex, int endIndex) override
    {
        if (startIndex < 0 || endIndex < startIndex || endIndex >= this->GetLength())
        {
            throw std::invalid_argument("invalid argument");
        }
        T *intermediate = new T[endIndex - startIndex + 1];
        for (int i = 0; i < endIndex - startIndex + 1; i++)
        {
            intermediate[i] = this->Get(startIndex + i - 1);
        }
        MutableListSequence<T> *result = new MutableListSequence<T>(intermediate, endIndex - startIndex + 1);
        delete[] intermediate;
        return result;
    }
};

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

template <typename T> class Stack
{
  private:
    MutableListSequence<T> *elements;

  public:
    Stack()
    {
        elements = new MutableListSequence<T>();
    }

    Stack(T *array, int count)
    {
        elements = new MutableListSequence<T>(array, count);
    }

    Stack(Stack<T> &StackForCopy)
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

    void push(const T &item)
    {
        this->elements->Prepend(item);
    }

    T pop() // удаление элемента из стека с его получением
    {
        T result = elements->GetFirst();
        elements = elements->GetSubSequence(1, elements->GetLength() - 1);
        return result;
    }

    T ShowElement(int index)
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

    bool IsStackEmpty()
    {
        if (this->GetSize() <= 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool IsSubSequenceHere(Stack<T> stack)
    {
        if (this->GetSize() < stack.GetSize())
        {
            return false;
        }
        bool flag = false;
        for (int i = 0; i < this->GetSize() - stack.GetSize(); i++)
        {
            flag = true;
            int j;
            j = 0;
            while (j < stack.GetSize() && flag == true)
            {
                if (this->ShowElement(i + j) == stack.ShowElement(j))
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
                j++;
            }
            if (flag == true)
            {
                break;
            }
        }
        return flag;
    }

    T GetSize()
    {
        return elements->GetLength();
    }

    Stack<T> *Concat(Stack<T> &stack)
    {
        for (int i = 0; i < stack.GetSize(); i++)
        {
            elements->Append(stack.ShowElement(i));
        }
        return this;
    }

    Stack<T> *GetSubStack(int startIndex, int endIndex)
    {
        Stack<T> *resultStack = new Stack<T>();
        resultStack->elements = elements->GetSubSequence(startIndex, endIndex);
        return resultStack;
    }
};

template <typename T> class Queue
{
  private:
    MutableListSequence<T> *elements;

  public:
    Queue()
    {
        elements = new MutableListSequence<T>();
    }

    Queue(T *array, int count)
    {
        elements = new MutableListSequence<T>(array, count);
    }

    Queue(Queue<T> &QueueForCopy)
    {
        elements = new MutableListSequence<T>();
        for (int i = 0; i < QueueForCopy.elements->GetLength(); i++)
        {
            elements->Append(QueueForCopy.elements->Get(i));
        }
    }

    ~Queue()
    {
        delete elements;
    }

    void push(const T &item)
    {
        this->elements->Append(item);
    }

    T pop() // удаление элемента из очереди с его получением
    {
        T result = elements->GetLast();
        elements = elements->GetSubSequence(1, elements->GetLength() - 1);
        return result;
    }

    T GetSize()
    {
        return elements->GetLength();
    }

    T ShowElement(int index)
    {
        return elements->Get(index);
    }

    void QueueShow()
    {
        for (int i = 0; i < this->GetSize(); i++)
        {
            std::cout << this->ShowElement(i) << std::endl;
        }
    }

    bool IsSubSequenceHere(Queue<T> queue)
    {
        if (this->GetSize() < queue.GetSize())
        {
            return false;
        }
        bool flag = false;
        for (int i = 0; i < this->GetSize() - queue.GetSize(); i++)
        {
            flag = true;
            int j;
            j = 0;
            while (j < queue.GetSize() && flag == true)
            {
                if (this->ShowElement(i + j) == queue.ShowElement(j))
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
                j++;
            }
            if (flag == true)
            {
                break;
            }
        }
        return flag;
    }

    Queue<T> *Concat(Queue<T> &queue)
    {
        for (int i = 0; i < queue.GetSize(); i++)
        {
            elements->Append(queue.ShowElement(i));
        }
        return this;
    }

    Queue<T> *GetSubQueue(int startIndex, int endIndex)
    {
        Queue<T> *resultQueue = new Queue<T>();
        resultQueue->elements = elements->GetSubSequence(startIndex, endIndex);
        return resultQueue;
    }
};

class complex
{
  private:
    double Re;
    double Im;

  public:
    complex()
    {
        Re = 0;
        Im = 0;
    }

    complex(double real, double image)
    {
        Re = real;
        Im = image;
    }

    complex(const complex &itemForCopy)
    {
        Re = itemForCopy.Re;
        Im = itemForCopy.Im;
    }

    double GetRe()
    {
        return Re;
    }

    double GetIm()
    {
        return Im;
    }

    complex operator+(complex item)
    {
        double real = this->Re + item.Re;
        double image = this->Im + item.Im;
        complex result(real, image);
        return result;
    }

    complex operator-(complex item)
    {
        double real = this->Re - item.Re;
        double image = this->Im - item.Im;
        complex result(real, image);
        return result;
    }

    complex operator*(complex item)
    {
        double real = this->Re;
        double image = this->Im;
        double realRes = real * item.Re - image * item.Im;
        double imageRes = real * item.Im + image * item.Re;
        complex result(realRes, imageRes);
        return result;
    }

    complex operator/(complex item)
    {
        double real = this->Re;
        double image = this->Im;
        double realRes = (real * item.Re + image * item.Im) / ((item.Re * (item.Re)) + item.Im * item.Im);
        double imageRes = (image * item.Re - real * item.Im) / ((item.Re * (item.Re)) + item.Im * item.Im);
        complex result(realRes, imageRes);
        return result;
    }

    friend std::istream &operator>>(std::istream &in, complex &item)
    {
        std::cout << "Enter real part of complex number ";
        in >> item.Re;
        std::cout << "Enter image part of complex number ";
        in >> item.Im;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const complex &item)
    {
        if (item.Im < 0)
        {
            return out << item.Re << "+i" << item.Im << ")" << std::endl;
        }
        else
        {
            return out << item.Re << "+i" << item.Im << std::endl;
        }
    }

    complex &operator+=(complex item)
    {
        this->Re += item.Re;
        this->Im += item.Im;
        return *this;
    }

    complex &operator-=(complex item)
    {
        double real = this->Re;
        double image = this->Im;
        this->Re = real - item.Re;
        this->Im = image - item.Im;
        return *this;
    }

    complex &operator*=(complex item)
    {
        double real = this->Re;
        double image = this->Im;
        this->Re = real * item.Re - image * item.Im;
        this->Im = real * item.Im + image * item.Re;
        return *this;
    }

    complex &operator/=(complex item)
    {
        double real = this->Re;
        double image = this->Im;
        this->Re = (real * item.Re + image * item.Im) / ((item.Re) * (item.Re) + item.Im * item.Im);
        this->Im = (image * item.Re - real * item.Im) / ((item.Re) * (item.Re) + item.Im * item.Im);
        return *this;
    }

    bool operator==(complex item)
    {
        if (this->Re == item.Re && this->Im == item.Im)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(complex item)
    {
        if (this->Re != item.Re || this->Im != item.Im)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Person
{
  private:
    PersonId id;
    std::string firstName;
    std::string middleName;
    std::string lastName;

  public:
    Person()
    {
        id = "";
        firstName = "";
        middleName = "";
        lastName = "";
    }

    Person(PersonId id, std::string firstName, std::string middleName, std::string lastName)
    {
        this->id = id;
        this->firstName = firstName;
        this->middleName = middleName;
        this->lastName = lastName;
    }

    Person(const Person &man)
    {
        this->id = man.id;
        this->firstName = man.firstName;
        this->middleName = man.middleName;
        this->lastName = man.lastName;
    }

    PersonId GetId()
    {
        return this->id;
    }

    std::string GetFirstName()
    {
        return this->firstName;
    }

    std::string GetMiddleName()
    {
        return this->middleName;
    }

    std::string GetLastName()
    {
        return this->lastName;
    }

    friend std::istream &operator>>(std::istream &in, Person &person)
    {
        std::cout << "Enter first name ";
        in >> person.firstName;
        std::cout << "Enter middle name ";
        in >> person.middleName;
        std::cout << "Enter last name ";
        in >> person.lastName;
        std::cout << "Enter id ";
        in >> person.id;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Person &man)
    {
        return out << man.firstName << " " << man.middleName << " " << man.lastName << " " << man.id << std::endl;
    }
};

void TestVectorSum()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};
    int c[] = {2, 4, 6, 8, 10};
    Vector<int> test1(a, 5);
    Vector<int> test2(b, 5);
    Vector<int> *res = test1.vectorSum(test2);
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i) == c[i]);
    }
}

void TestVectorSumComplex()
{
    complex a(1, 3);
    complex b(2, 4);
    complex c(3, 5);
    complex d(4, 8);
    complex e(4, 8);
    complex f(6, 12);
    complex arr1[] = {a, b};
    complex arr2[] = {c, d};
    complex arrRes[] = {e, f};
    Vector<complex> test1(arr1, 2);
    Vector<complex> test2(arr2, 2);
    Vector<complex> *res = test1.vectorSum(test2);
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i).GetRe() == arrRes[i].GetRe());
        assert(res->Get(i).GetIm() == arrRes[i].GetIm());
    }
}

void TestVectorMultiOnScalar()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 6, 8, 10};
    Vector<int> vec(a, 5);
    Vector<int> *res = vec.vectorMultiOnScalar(2);
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
    Vector<int> vec1(a, 5);
    Vector<int> vec2(b, 5);
    Vector<int> *res = vec1.vectorMulti(vec2);
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i) == c[i]);
    }
}

void TestVectorMultiComplex()
{
    complex a(1, 3);
    complex b(2, 4);
    complex c(3, 5);
    complex d(4, 8);
    complex e(-12, 14);
    complex f(-24, 32);
    complex arr1[] = {a, b};
    complex arr2[] = {c, d};
    complex arrRes[] = {e, f};
    Vector<complex> test1(arr1, 2);
    Vector<complex> test2(arr2, 2);
    Vector<complex> *res = test1.vectorMulti(test2);
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i).GetRe() == arrRes[i].GetRe());
        assert(res->Get(i).GetIm() == arrRes[i].GetIm());
    }
}

void TestStackConstructors()
{
    int a[] = {1, 2, 3, 4};
    Stack<int> test1(a, 4);
    assert(test1.GetSize() == 4);
    for (int i = 0; i < test1.GetSize(); i++)
    {
        assert(test1.ShowElement(i) == a[i]);
    }

    Stack<int> test2(test1);
    for (int i = 0; i < test1.GetSize(); i++)
    {
        assert(test1.ShowElement(i) == test2.ShowElement(i));
    }
}

void TestStackPush()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 1, 2, 3, 4};
    Stack<int> *test = new Stack<int>(a, 4);
    assert(test->GetSize() == 4);
    test->push(5);
    assert(test->GetSize() == 5);
    for (int i = 0; i < test->GetSize(); i++)
    {
        assert(test->ShowElement(i) == b[i]);
    }
}

void TestStackPop()
{
    int a[] = {1, 2, 3, 4};
    Stack<int> test(a, 4);
    int result = test.pop();
    assert(result == 1);
    assert(test.GetSize() == 3);
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
    Stack<int> *test3 = test1.Concat(test2);
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
    Stack<int> *test2 = test1.GetSubStack(1, 5);
    for (int i = 0; i < test2->GetSize(); i++)
    {
        assert(test2->ShowElement(i) == b[i]);
    }
}

void TestStackIsSubSequenceHere()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {1, 2, 3, 4, 5};
    int c[] = {5, 4, 3, 2, 1};
    Stack<int> test1(a, 8);
    Stack<int> test2(b, 5);
    Stack<int> test3(c, 5);
    bool result1 = test1.IsSubSequenceHere(test2);
    assert(result1 == true);
    bool result2 = test1.IsSubSequenceHere(test3);
    assert(result2 == false);
}

void TestQueueCostructors()
{
    int a[] = {1, 2, 3, 4};
    Queue<int> test1(a, 4);
    assert(test1.GetSize() == 4);
    for (int i = 0; i < test1.GetSize(); i++)
    {
        assert(test1.ShowElement(i) == a[i]);
    }

    Queue<int> test2(test1);
    for (int i = 0; i < test1.GetSize(); i++)
    {
        assert(test1.ShowElement(i) == test2.ShowElement(i));
    }
}

void TestQueuePush()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {1, 2, 3, 4, 5};
    Queue<int> *test = new Queue<int>(a, 4);
    assert(test->GetSize() == 4);
    test->push(5);
    assert(test->GetSize() == 5);
    for (int i = 0; i < test->GetSize(); i++)
    {
        assert(test->ShowElement(i) == b[i]);
    }
}

void TestQueuePop()
{
    int a[] = {1, 2, 3, 4};
    Queue<int> test(a, 4);
    int result = test.pop();
    assert(result == 4);
    assert(test.GetSize() == 3);
}

void TestQueueIsSubSequenceHere()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {1, 2, 3, 4, 5};
    int c[] = {5, 4, 3, 2, 1};
    Queue<int> test1(a, 8);
    Queue<int> test2(b, 5);
    Queue<int> test3(c, 5);
    bool result1 = test1.IsSubSequenceHere(test2);
    assert(result1 == true);
    bool result2 = test1.IsSubSequenceHere(test3);
    assert(result2 == false);
}

void TestQueueGetSubStack()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {1, 2, 3, 4, 5};
    Queue<int> test1(a, 8);
    assert(test1.GetSize() == 8);
    Queue<int> *test2 = test1.GetSubQueue(1, 5);
    for (int i = 0; i < test2->GetSize(); i++)
    {
        assert(test2->ShowElement(i) == b[i]);
    }
}

void TestQueueConcat()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int ab[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Queue<int> test1(a, 4);
    assert(test1.GetSize() == 4);
    Queue<int> test2(b, 4);
    assert(test2.GetSize() == 4);
    Queue<int> *test3 = test1.Concat(test2);
    assert(test3->GetSize() == 8);
    for (int i = 0; i < test3->GetSize(); i++)
    {
        assert(test3->ShowElement(i) == ab[i]);
    }
}

void TestComplexSum()
{
    complex test1(2, 4);
    complex test2(1, 3);
    complex test3 = test1 + test2;
    assert(test3.GetRe() == 3);
    assert(test3.GetIm() == 7);
    assert(test1.GetRe() == 2);
    test3 += test1;
    assert(test3.GetRe() == 5);
    assert(test3.GetIm() == 11);
}

void TestComplexSubtract()
{
    complex test1(2, 4);
    complex test2(1, 3);
    complex test3 = test1 - test2;
    assert(test3.GetRe() == 1);
    assert(test3.GetIm() == 1);
    test3 -= test1;
    assert(test3.GetRe() == -1);
    assert(test3.GetIm() == -3);
}

void TestComplexMulti()
{
    complex test1(2, 4);
    complex test2(1, 3);
    complex test3 = test1 * test2;
    assert(test3.GetRe() == -10);
    assert(test3.GetIm() == 10);
    test3 *= test1;
    assert(test3.GetRe() == -60);
    assert(test3.GetIm() == -20);
}

void TestComplexDiv()
{
    complex test1(1, 1);
    complex test2(1, 1);
    complex test3 = test1 / test2;
    assert(test3.GetRe() == 1);
    assert(test3.GetIm() == 0);
}

void TestDynamicArrayConstructors()
{
    int a[] = {1, 2, 3, 4, 5, 6};

    DynamicArray<int> test1(6);
    assert(test1.GetSize() == 6);

    DynamicArray<int> test2(a, 6);
    assert(test2.GetSize() == 6);
    for (int i = 0; i < test2.GetSize(); i++)
    {
        assert(test2.Get(i) == a[i]);
    }

    DynamicArray<int> test3(test2);
    assert(test3.GetSize() == test2.GetSize());
    for (int i = 0; i < test3.GetSize(); i++)
    {
        assert(test2.Get(i) == test3.Get(i));
    }
}

void TestDynamicArraySet()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    DynamicArray<int> test(a, 8);
    assert(test.GetSize() == 8);
    for (int i = 0; i < test.GetSize(); i++)
    {
        assert(test.Get(i) == a[i]);
    }
    test.Set(9, 3);
    assert(test.Get(3) == 9);
    test[3] = 10;
    assert(test[3] == 10);
}

void TestLinkedListConstructors()
{
    int a[] = {1, 2, 3, 4, 5, 6};

    LinkedList<int> test1(a, 6);
    assert(test1.GetLength() == 6);
    for (int i = 0; i < test1.GetLength(); i++)
    {
        assert(test1.Get(i) == a[i]);
    }

    LinkedList<int> test2(test1);
    assert(test2.GetLength() == test1.GetLength());
    for (int i = 0; i < test2.GetLength(); i++)
    {
        assert(test1.Get(i) == test2.Get(i));
    }
}

void TestLinkedListSubList()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {3, 4, 5};
    LinkedList<int> test10(a, 6);
    LinkedList<int> *test11 = test10.GetSubList(2, 4);
    for (int i = 0; i < test11->GetLength(); i++)
    {
        assert(test11->Get(i) == b[i]);
    }
}

void TestLinkedListInput()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    LinkedList<int> test1(a, 8);
    test1.Append(10);
    assert(test1.GetLast() == 10);

    int b[] = {1, 2, 3, 4, 5, 6, 7, 8};
    LinkedList<int> test3(b, 8);
    test3.Prepend(10);
    assert(test3.GetFirst() == 10);

    int c[] = {1, 2, 3, 4, 5, 6, 7, 8};
    LinkedList<int> test2(c, 8);
    test2.InsertAt(10, 3);
    assert(test2[3] == 10);
}

void TestLinkedListConcat()
{
    int b[] = {1, 2, 3};
    int c[] = {4, 5, 6};
    int bc[] = {1, 2, 3, 4, 5, 6};
    LinkedList<int> test6(b, 3);
    LinkedList<int> test7(c, 3);
    LinkedList<int> *test8 = test6.Concat(test7);
    assert(test8->GetLength() == test6.GetLength() + test7.GetLength());
    for (int i = 0; i < test8->GetLength(); i++)
    {
        assert(test8->Get(i) == bc[i]);
    }
}

void TestListSequenceConstructors()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    MutableListSequence<int> testM1(a, 8);
    assert(testM1.GetLength() == 8);
    for (int i = 0; i < testM1.GetLength(); i++)
    {
        assert(testM1.Get(i) == a[i]);
    }

    MutableListSequence<int> testM2(testM1);
    assert(testM2.GetLength() == testM1.GetLength());
    for (int i = 0; i < testM2.GetLength(); i++)
    {
        assert(testM2.Get(i) == testM1.Get(i));
    }
}

void TestListInput()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    MutableListSequence<int> test1(a, 8);
    assert(test1.GetLength() == 8);
    test1.Append(10);
    assert(test1.GetLength() == 9);
    assert(test1.GetLast() == 10);

    int b[] = {1, 2, 3, 4, 5, 6, 7, 8};
    MutableListSequence<int> test2(b, 8);
    assert(test2.GetLength() == 8);
    test2.Prepend(10);
    assert(test2.GetLength());
    assert(test2.GetFirst() == 10);

    int c[] = {1, 2, 3, 4, 5, 6, 7, 8};
    MutableListSequence<int> test3(c, 8);
    assert(test3.GetLength() == 8);
    test3.InsertAt(10, 3);
    assert(test3.GetLength());
    assert(test3.Get(3) == 10);
}

void TestListSequenceConcat()
{
    int b[] = {1, 2, 3};
    int c[] = {4, 5, 6};
    int bc[] = {1, 2, 3, 4, 5, 6};
    MutableListSequence<int> test1(b, 3);
    MutableListSequence<int> test2(c, 3);
    MutableListSequence<int> *result = test1.Concat(test2);
    assert(result->GetLength() == 6);
    for (int i = 0; i < result->GetLength(); i++)
    {
        assert(result->Get(i) == bc[i]);
    }
}

void TestListSequenceGetSubSequence()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {3, 4, 5};
    MutableListSequence<int> test1(a, 6);
    MutableListSequence<int> *result = test1.GetSubSequence(3, 5);
    assert(result->GetLength() == 3);
    for (int i = 0; i < result->GetLength(); i++)
    {
        assert(result->Get(i) == b[i]);
    }
}

void StandartTests()
{
    TestDynamicArrayConstructors();
    TestDynamicArraySet();

    TestLinkedListConstructors();
    TestLinkedListInput();
    TestLinkedListConcat();
    TestLinkedListSubList();

    TestListSequenceConstructors();
    TestListInput();
    TestListSequenceConcat();
    TestListSequenceGetSubSequence();
}

void TestForComplex()
{
    TestComplexSum();
    TestComplexSubtract();
    TestComplexMulti();
    TestComplexDiv();
}

int main(int argc, const char *argv[])
{
    StandartTests();
    TestForComplex();
    int status = 0;
    std::cout << "0. Run tests for Vector\n";
    std::cout << "1. Run tests for Stack\n";
    std::cout << "2. Run tests for Queue\n";
    std::cout << "3. Use Sum of Vectors for int Vectors\n";
    std::cout << "4. Use Multi of Vectors for int Vectors\n";
    std::cout << "5. Stop programm\n";
    int flag = 1;
    while (flag)
    {
        std::cin >> status;
        switch (status)
        {
        case 0:
            TestVectorSum();
            TestVectorSumComplex();
            TestVectorMultiOnScalar();
            TestVectorMulti();
            TestVectorMultiComplex();
            std::cout << "Tests for Vector passed\n";
            break;
        case 1:
            TestStackConstructors();
            TestStackPush();
            TestStackPop();
            TestStackConcat();
            TestStackGetSubStack();
            TestStackIsSubSequenceHere();
            std::cout << "Tests for Stack passed\n";
            break;
        case 2:
            TestQueueCostructors();
            TestQueuePush();
            TestQueuePop();
            TestQueueIsSubSequenceHere();
            TestQueueGetSubStack();
            TestQueueConcat();
            std::cout << "Tests for Queue passed\n";
            break;
        case 3:
            {
                int len1, len2;
                int a, b;
                std::cout << "Enter length of the first vector: ";
                std::cin >> len1;
                std::cout << "Enter length of the second vector: ";
                std::cin >> len2;
                if (len1 != len2)
                {
                    std::cout << "Diffrent sizes!!!";
                    break;
                }
                int* arr1 = new int[len1];
                int* arr2 = new int[len2];
                for (int i = 0; i < len1; i++)
                {
                    std::cout << "Enter " << i+1 << " element of the first vector: ";
                    std::cin >> a;
                    arr1[i] = a;
                }
                for (int i = 0; i < len2; i++)
                {
                    std::cout << "Enter " << i+1 << " element of the second vector: ";
                    std::cin >> b;
                    arr2[i] = b;
                }
                Vector<int> test1(arr1, len1);
                Vector<int> test2(arr2, len2);
                Vector<int>* test3 = test1.vectorSum(test2);
                std::cout << "Vector Result: ";
                for (int i = 0; i < len1; i++)
                {
                    std::cout << test3->Get(i) << " ";
                }
                std::cout << std::endl;
                break;
            }
        case 4:
            {
                int len1, len2;
                int a, b;
                std::cout << "Enter length of the first vector: ";
                std::cin >> len1;
                std::cout << "Enter length of the second vector: ";
                std::cin >> len2;
                if (len1 != len2)
                {
                    std::cout << "Diffrent sizes!!!";
                    break;
                }
                int* arr1 = new int[len1];
                int* arr2 = new int[len2];
                for (int i = 0; i < len1; i++)
                {
                    std::cout << "Enter " << i+1 << " element of the first vector: ";
                    std::cin >> a;
                    arr1[i] = a;
                }
                for (int i = 0; i < len2; i++)
                {
                    std::cout << "Enter " << i+1 << " element of the second vector: ";
                    std::cin >> b;
                    arr2[i] = b;
                }
                Vector<int> test1(arr1, len1);
                Vector<int> test2(arr2, len2);
                Vector<int>* test3 = test1.vectorMulti(test2);
                std::cout << "Vector Result: ";
                for (int i = 0; i < len1; i++)
                {
                    std::cout << test3->Get(i) << " ";
                }
                std::cout << std::endl;
                break;
            }
        case 5:
            flag = 0;
            break;
        default:
            std::cout << "Неизвестная команда\n";
        }
        std::cout << "0. Run tests for Vector\n";
        std::cout << "1. Run tests for Stack\n";
        std::cout << "2. Run tests for Queue\n";
        std::cout << "3. Use Sum of Vectors for int Vectors\n";
        std::cout << "4. Use Multi of Vectors for int Vectors\n";
        std::cout << "5. Stop programm\n";
    }

    return 0;
}

#pragma once
#include "ListSequence.h"

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

    int GetSize()
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

#pragma once
#include <iostream>
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

    Queue(const Queue<T> &QueueForCopy)
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

    T Peek(int index) // Peek
    {
        return elements->Get(index);
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
                if (this->Peek(i + j) == queue.Peek(j))
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
            elements->Append(queue.Peek(i));
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

template <typename T> void QueueShow(Queue<T> &que)
{
    for (int i = 0; i < que.GetSize(); i++)
    {
        std::cout << que.Peek(i) << " ";
    }
    std::cout << std::endl;
}

template <typename T> void QueueShow(Queue<T> *que)
{
    for (int i = 0; i < que->GetSize(); i++)
    {
        std::cout << que->Peek(i) << " ";
    }
    std::cout << std::endl;
}

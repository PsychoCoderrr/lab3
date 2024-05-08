#pragma once
#include "ListSequence.h"

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
        this->elements->Append(item);
    }

    T pop() // удаление элемента из стека с его получением
    {
        T result = elements->GetLast();
        elements->RemoveLast();
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
            std::cout << this->ShowElement(i) << " ";
        }
        std::cout << std::endl;
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

    int GetSize()
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


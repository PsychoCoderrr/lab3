#pragma once
#include "assert.h"
#include <iostream>
#include <compare>
#include "Complex.h"
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "ListSequence.h"
#include "Person.h"
#include "DynamicArray.h"

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
        assert(test1.Peek(i) == a[i]);
    }

    Stack<int> test2(test1);
    for (int i = 0; i < test1.GetSize(); i++)
    {
        assert(test1.Peek(i) == test2.Peek(i));
    }
}

void TestStackPush()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {1, 2, 3, 4, 5};
    Stack<int> *test = new Stack<int>(a, 4);
    assert(test->GetSize() == 4);
    test->push(5);
    assert(test->GetSize() == 5);
    for (int i = 0; i < test->GetSize(); i++)
    {
        assert(test->Peek(i) == b[i]);
    }
}

void TestStackPop()
{
    int a[] = {1, 2, 3, 4};
    Stack<int> test(a, 4);
    int result = test.pop();
    assert(result == 4);
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
        assert(test3->Peek(i) == ab[i]);
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
        assert(test2->Peek(i) == b[i]);
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

void TestLinkedListRemoveLast()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {1, 2, 3, 4, 5};
    LinkedList<int> test1(a, 6);
    test1.RemoveLast();
    for (int i = 0; i < test1.GetLength(); i++)
    {
        assert(test1.Get(i) == b[i]);
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

void TestListSequenceRemoveLast()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {1, 2, 3, 4, 5};
    MutableListSequence<int> test1(a, 6);
    test1.RemoveLast();
    for (int i = 0; i < test1.GetLength(); i++)
    {
        assert(test1.Get(i) == b[i]);
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


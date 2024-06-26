#include <iostream>
#include <string>
#include "Complex.h"
#include "Person.h"
#include "Queue.h"
#include "Stack.h"
#include "UiPrint.h"
#include "Vector.h"
#include "tests.h"
#include "FuncForUi.h"

int main(int argc, const char *argv[])
{

    StandartTests();
    TestForComplex();
    TestVectorSum();
    TestVectorSumComplex();
    TestVectorMultiOnScalar();
    TestVectorMulti();
    TestVectorMultiComplex();
    TestStackConstructors();
    TestStackPush();
    TestStackPop();
    TestStackConcat();
    TestStackGetSubStack();
    TestStackIsSubSequenceHere();
    TestQueueCostructors();
    TestQueuePush();
    TestQueuePop();
    TestQueueIsSubSequenceHere();
    TestQueueGetSubStack();
    TestQueueConcat();
    int flag = 1;
    int status;
    std::string comand;
    PrintUI();
    while (flag)
    {
        std::cout << "Enter command"<< std::endl;
        std::getline(std::cin, comand);
        status = getStatus(comand);
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
        case 3: {
            int len1, len2;
            int a, b;
            std::cout << "Enter length of the first vector: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the second vector: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (len1 != len2)
            {
                std::cout << "Diffrent sizes!!!";
                break;
            }
            int *arr1 = new int[len1];
            int *arr2 = new int[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first vector: ";
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second vector: ";
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Vector<int> test1(arr1, len1);
            Vector<int> test2(arr2, len2);
            Vector<int> *test3 = test1 + test2;
            std::cout << "Vector Result: ";
            VectorShow(test3);
            break;
        }
        case 4: {
            int len1, len2;
            int a, b;
            std::cout << "Enter length of the first vector: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the second vector: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (len1 != len2)
            {
                std::cout << "Diffrent sizes!!!";
                break;
            }
            int *arr1 = new int[len1];
            int *arr2 = new int[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first vector: ";
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second vector: ";
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Vector<int> test1(arr1, len1);
            Vector<int> test2(arr2, len2);
            Vector<int> *test3 = test1 * test2;
            std::cout << "Vector Result: ";
            VectorShow(test3);
            break;
        }
        case 5: {
            int len1;
            int a;
            std::cout << "Enter length of vector: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int *arr1 = new int[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first vector: ";
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Vector<int> test1(arr1, len1);
            int scalar;
            std::cout << "Enter scalar: ";
            std::cin >> scalar;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Vector<int> *test2 = test1 * scalar;
            std::cout << "Vector Result: ";
            VectorShow(test2);
            break;
        }
        case 6: {
            int len1, len2;
            complex a, b;
            std::cout << "Enter length of the first vector: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the second vector: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (len1 != len2)
            {
                std::cout << "Diffrent sizes!!!";
                break;
            }
            complex *arr1 = new complex[len1];
            complex *arr2 = new complex[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first vector: \n";
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second vector: \n";
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Vector<complex> test1(arr1, len1);
            Vector<complex> test2(arr2, len2);
            Vector<complex> *test3 = test1 + test2;
            std::cout << "Vector Result: \n";
            VectorShow(test3);
            break;
        }
        case 7: {
            int len1, len2;
            complex a, b;
            std::cout << "Enter length of the first vector: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the second vector: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (len1 != len2)
            {
                std::cout << "Diffrent sizes!!!";
                break;
            }
            complex *arr1 = new complex[len1];
            complex *arr2 = new complex[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first vector: \n";
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second vector: \n";
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Vector<complex> test1(arr1, len1);
            Vector<complex> test2(arr2, len2);
            Vector<complex> *test3 = test1 * test2;
            std::cout << "Vector Result: \n";
            VectorShow(test3);
            break;
        }
        case 8: {
            int len1, len2;
            int a, b;
            std::cout << "Enter length of the first stack: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the second stack: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int *arr1 = new int[len1];
            int *arr2 = new int[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first stack: ";
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second stack: ";
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Stack<int> test1(arr1, len1);
            Stack<int> test2(arr2, len2);
            Stack<int> *testResult = test1.Concat(test2);
            StackShow(testResult);
            break;
        }
        case 9: {
            int len1;
            int a;
            int start, end;
            std::cout << "Enter length of stack: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int *arr1 = new int[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first stack: ";
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Enter first index of SubStack: ";
            std::cin >> start;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter last index of SubStack: ";
            std::cin >> end;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Stack<int> test1(arr1, len1);
            Stack<int> *test2 = test1.GetSubStack(start, end);
            StackShow(test2);
            break;
        }
        case 10: {
            int len1, len2;
            int a, b;
            std::cout << "Enter length of the main stack: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the  SubStack: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int *arr1 = new int[len1];
            int *arr2 = new int[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the main stack: ";
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the  SubStack: ";
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Stack<int> test1(arr1, len1);
            Stack<int> test2(arr2, len2);
            bool result = test1.IsSubSequenceHere(test2);
            if (result)
            {
                std::cout << "It`s here!!!";
            }
            else
            {
                std::cout << "It`s not here(((";
            }
            std::cout << std::endl;
            break;
        }
        case 11: {
            int len1, len2;
            complex a, b;
            std::cout << "Enter length of the first stack: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the second stack: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            complex *arr1 = new complex[len1];
            complex *arr2 = new complex[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first stack: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second stack: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Stack<complex> test1(arr1, len1);
            Stack<complex> test2(arr2, len2);
            Stack<complex> *testResult = test1.Concat(test2);
            StackShow(testResult);
            break;
        }
        case 12: {
            int len1;
            complex a;
            int start, end;
            std::cout << "Enter length of stack: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            complex *arr1 = new complex[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the stack: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Enter first index of SubStack: ";
            std::cin >> start;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter last index of SubStack: ";
            std::cin >> end;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Stack<complex> test1(arr1, len1);
            Stack<complex> *test2 = test1.GetSubStack(start, end);
            StackShow(test2);
            break;
        }
        case 13: {
            int len1, len2;
            complex a, b;
            std::cout << "Enter length of the main stack: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the  SubStack: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            complex *arr1 = new complex[len1];
            complex *arr2 = new complex[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first stack: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second stack: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Stack<complex> test1(arr1, len1);
            Stack<complex> test2(arr2, len2);
            bool result = test1.IsSubSequenceHere(test2);
            if (result)
            {
                std::cout << "It`s here!!!";
            }
            else
            {
                std::cout << "It`s not here(((";
            }
            std::cout << std::endl;
            break;
        }
        case 14: {
            int len1, len2;
            Person a, b;
            std::cout << "Enter length of the first stack: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the second stack: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Person *arr1 = new Person[len1];
            Person *arr2 = new Person[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first stack: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second stack: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Stack<Person> test1(arr1, len1);
            Stack<Person> test2(arr2, len2);
            Stack<Person> *testResult = test1.Concat(test2);
            StackShow(testResult);
            break;
        }
        case 15: {
            int len1;
            Person a;
            int start, end;
            std::cout << "Enter length of stack: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Person *arr1 = new Person[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of stack: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Enter first index of SubStack: ";
            std::cin >> start;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter last index of SubStack: ";
            std::cin >> end;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Stack<Person> test1(arr1, len1);
            Stack<Person> *test2 = test1.GetSubStack(start, end);
            StackShow(test2);
            break;
        }
        case 16: {
            int len1, len2;
            Person a, b;
            std::cout << "Enter length of the main stack: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the  SubStack: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Person *arr1 = new Person[len1];
            Person *arr2 = new Person[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the main stack: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the SubStack: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Stack<Person> test1(arr1, len1);
            Stack<Person> test2(arr2, len2);
            bool result = test1.IsSubSequenceHere(test2);
            if (result)
            {
                std::cout << "It`s here!!!";
            }
            else
            {
                std::cout << "It`s not here(((";
            }
            std::cout << std::endl;
            break;
        }
        case 17: {
            int len1, len2;
            int a, b;
            std::cout << "Enter length of the first queue: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the second queue: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int *arr1 = new int[len1];
            int *arr2 = new int[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first queue: ";
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second queue: ";
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Queue<int> test1(arr1, len1);
            Queue<int> test2(arr2, len2);
            Queue<int> *testResult = test1.Concat(test2);
            QueueShow(testResult);
            break;
        }
        case 18: {
            int len1;
            int a;
            int start, end;
            std::cout << "Enter length of queue: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int *arr1 = new int[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first queue: ";
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Enter first index of SubQueue: ";
            std::cin >> start;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter last index of SubQueue: ";
            std::cin >> end;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Queue<int> test1(arr1, len1);
            Queue<int> *test2 = test1.GetSubQueue(start, end);
            QueueShow(test2);
            break;
        }
        case 19: {
            int len1, len2;
            int a, b;
            std::cout << "Enter length of the main queue: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the  SubQueue: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int *arr1 = new int[len1];
            int *arr2 = new int[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the main queue: ";
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the  SubQueue: ";
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Queue<int> test1(arr1, len1);
            Queue<int> test2(arr2, len2);
            bool result = test1.IsSubSequenceHere(test2);
            if (result)
            {
                std::cout << "It`s here!!!";
            }
            else
            {
                std::cout << "It`s not here(((";
            }
            std::cout << std::endl;
            break;
        }
        case 20: {
            int len1, len2;
            complex a, b;
            std::cout << "Enter length of the first queue: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the second queue: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            complex *arr1 = new complex[len1];
            complex *arr2 = new complex[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first queue: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second queue: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Queue<complex> test1(arr1, len1);
            Queue<complex> test2(arr2, len2);
            Queue<complex> *testResult = test1.Concat(test2);
            QueueShow(testResult);
            break;
        }
        case 21: {
            int len1;
            complex a;
            int start, end;
            std::cout << "Enter length of queue: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            complex *arr1 = new complex[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the queue: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Enter first index of SubQueue: ";
            std::cin >> start;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter last index of SubQueue: ";
            std::cin >> end;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Queue<complex> test1(arr1, len1);
            Queue<complex> *test2 = test1.GetSubQueue(start, end);
            QueueShow(test2);
            break;
        }
        case 22: {
            int len1, len2;
            complex a, b;
            std::cout << "Enter length of the main queue: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the  SubQueue: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            complex *arr1 = new complex[len1];
            complex *arr2 = new complex[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first Queue: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second Queue: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Queue<complex> test1(arr1, len1);
            Queue<complex> test2(arr2, len2);
            bool result = test1.IsSubSequenceHere(test2);
            if (result)
            {
                std::cout << "It`s here!!!";
            }
            else
            {
                std::cout << "It`s not here(((";
            }
            std::cout << std::endl;
            break;
        }
        case 23: {
            int len1, len2;
            Person a, b;
            std::cout << "Enter length of the first queue: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the second queue: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Person *arr1 = new Person[len1];
            Person *arr2 = new Person[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first queue: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second queue: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Queue<Person> test1(arr1, len1);
            Queue<Person> test2(arr2, len2);
            Queue<Person> *testResult = test1.Concat(test2);
            QueueShow(testResult);
            break;
        }
        case 24: {
            int len1;
            Person a;
            int start, end;
            std::cout << "Enter length of queue: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Person *arr1 = new Person[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of queue: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Enter first index of SubQueue: ";
            std::cin >> start;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter last index of SubQueue: ";
            std::cin >> end;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Queue<Person> test1(arr1, len1);
            Queue<Person> *test2 = test1.GetSubQueue(start, end);
            QueueShow(test2);
            break;
        }
        case 25: {
            int len1, len2;
            Person a, b;
            std::cout << "Enter length of the main queue: ";
            std::cin >> len1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length of the  SubQueue: ";
            std::cin >> len2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Person *arr1 = new Person[len1];
            Person *arr2 = new Person[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the main queue: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the SubQueue: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Queue<Person> test1(arr1, len1);
            Queue<Person> test2(arr2, len2);
            bool result = test1.IsSubSequenceHere(test2);
            if (result)
            {
                std::cout << "It`s here!!!";
            }
            else
            {
                std::cout << "It`s not here(((";
            }
            std::cout << std::endl;
            break;
        }
        case 26:
            flag = 0;
            break;
        default:
            std::cout << "Неизвестная команда\n";
        }
        PrintUI();
    }
    return 0;
}

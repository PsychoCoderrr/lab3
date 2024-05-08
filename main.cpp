#include <iostream>
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include "Complex.h"
#include "tests.h"
#include "Person.h"

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
    std::cout << "5. Use Multi on scalar For int Vector\n";
    std::cout << "6. Use Sum of Vectors for complex Vectors\n";
    std::cout << "7. Use Multi of Vectors for complex Vectors\n";
    std::cout << "8. Use Concat for Stack of int\n";
    std::cout << "9. Use SubStack for Stack of int\n";
    std::cout << "10. Use IsSuqSequenceHere for Stack of int\n";
    std::cout << "11. Use Concat for Stack of complex\n";
    std::cout << "12. Use SubStack for Stack of complex\n";
    std::cout << "13. Use IsSuqSequenceHere for Stack of complex\n";
    std::cout << "14. Use Concat for Stack of Person\n";
    std::cout << "15. Use SubStack for Stack of Person\n";
    std::cout << "16. Use IsSuqSequenceHere for Stack of Person\n";
    std::cout << "17. Use Concat for Queue of int\n";
    std::cout << "18. Use SubStack for Queue of int\n";
    std::cout << "19. Use IsSuqSequenceHere for Queue of int\n";
    std::cout << "20. Use Concat for Queue of complex\n";
    std::cout << "21. Use SubStack for Queue of complex\n";
    std::cout << "22. Use IsSuqSequenceHere for Queue of complex\n";
    std::cout << "23. Use Concat for Queue of Person\n";
    std::cout << "24. Use SubStack for Queue of Person\n";
    std::cout << "25. Use IsSuqSequenceHere for Queue of Person\n";
    std::cout << "26. Stop programm\n";
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
        case 3: {
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
            int *arr1 = new int[len1];
            int *arr2 = new int[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first vector: ";
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second vector: ";
                std::cin >> b;
                arr2[i] = b;
            }
            Vector<int> test1(arr1, len1);
            Vector<int> test2(arr2, len2);
            Vector<int> *test3 = test1.vectorSum(test2);
            std::cout << "Vector Result: ";
            for (int i = 0; i < len1; i++)
            {
                std::cout << test3->Get(i) << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 4: {
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
            int *arr1 = new int[len1];
            int *arr2 = new int[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first vector: ";
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second vector: ";
                std::cin >> b;
                arr2[i] = b;
            }
            Vector<int> test1(arr1, len1);
            Vector<int> test2(arr2, len2);
            Vector<int> *test3 = test1.vectorMulti(test2);
            std::cout << "Vector Result: ";
            for (int i = 0; i < len1; i++)
            {
                std::cout << test3->Get(i) << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 5: {
            int len1;
            int a;
            std::cout << "Enter length of vector: ";
            std::cin >> len1;
            int *arr1 = new int[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first vector: ";
                std::cin >> a;
                arr1[i] = a;
            }
            Vector<int> test1(arr1, len1);
            int scalar;
            std::cout << "Enter scalar: ";
            std::cin >> scalar;
            Vector<int> *test2 = test1.vectorMultiOnScalar(scalar);
            std::cout << "Vector Result: ";
            for (int i = 0; i < len1; i++)
            {
                std::cout << test2->Get(i) << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 6: {
            int len1, len2;
            complex a, b;
            std::cout << "Enter length of the first vector: ";
            std::cin >> len1;
            std::cout << "Enter length of the second vector: ";
            std::cin >> len2;
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
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second vector: \n";
                std::cin >> b;
                arr2[i] = b;
            }
            Vector<complex> test1(arr1, len1);
            Vector<complex> test2(arr2, len2);
            Vector<complex> *test3 = test1.vectorMulti(test2);
            std::cout << "Vector Result: \n";
            for (int i = 0; i < len1; i++)
            {
                std::cout << test3->Get(i) << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 7: {
            int len1, len2;
            complex a, b;
            std::cout << "Enter length of the first vector: ";
            std::cin >> len1;
            std::cout << "Enter length of the second vector: ";
            std::cin >> len2;
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
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second vector: \n";
                std::cin >> b;
                arr2[i] = b;
            }
            Vector<complex> test1(arr1, len1);
            Vector<complex> test2(arr2, len2);
            Vector<complex> *test3 = test1.vectorMulti(test2);
            std::cout << "Vector Result: \n";
            for (int i = 0; i < len1; i++)
            {
                std::cout << test3->Get(i) << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 8: {
            int len1, len2;
            int a, b;
            std::cout << "Enter length of the first stack: ";
            std::cin >> len1;
            std::cout << "Enter length of the second stack: ";
            std::cin >> len2;
            int *arr1 = new int[len1];
            int *arr2 = new int[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first stack: ";
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second stack: ";
                std::cin >> b;
                arr2[i] = b;
            }
            Stack<int> test1(arr1, len1);
            Stack<int> test2(arr2, len2);
            Stack<int> *testResult = test1.Concat(test2);
            testResult->StackShow();
            break;
        }
        case 9: {
            int len1;
            int a;
            int start, end;
            std::cout << "Enter length of stack: ";
            std::cin >> len1;
            int *arr1 = new int[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first stack: ";
                std::cin >> a;
                arr1[i] = a;
            }
            std::cout << "Enter first index of SubStack: ";
            std::cin >> start;
            std::cout << "Enter last index of SubStack: ";
            std::cin >> end;
            Stack<int> test1(arr1, len1);
            Stack<int> *test2 = test1.GetSubStack(start, end);
            test2->StackShow();
            break;
        }
        case 10: {
            int len1, len2;
            int a, b;
            std::cout << "Enter length of the main stack: ";
            std::cin >> len1;
            std::cout << "Enter length of the  SubStack: ";
            std::cin >> len2;
            int *arr1 = new int[len1];
            int *arr2 = new int[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the main stack: ";
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the  SubStack: ";
                std::cin >> b;
                arr2[i] = b;
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
            std::cout << "Enter length of the second stack: ";
            std::cin >> len2;
            complex *arr1 = new complex[len1];
            complex *arr2 = new complex[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first stack: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second stack: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
            }
            Stack<complex> test1(arr1, len1);
            Stack<complex> test2(arr2, len2);
            Stack<complex> *testResult = test1.Concat(test2);
            testResult->StackShow();
            break;
        }
        case 12: {
            int len1;
            complex a;
            int start, end;
            std::cout << "Enter length of stack: ";
            std::cin >> len1;
            complex *arr1 = new complex[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the stack: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
            }
            std::cout << "Enter first index of SubStack: ";
            std::cin >> start;
            std::cout << "Enter last index of SubStack: ";
            std::cin >> end;
            Stack<complex> test1(arr1, len1);
            Stack<complex> *test2 = test1.GetSubStack(start, end);
            test2->StackShow();
            break;
        }
        case 13: {
            int len1, len2;
            complex a, b;
            std::cout << "Enter length of the main stack: ";
            std::cin >> len1;
            std::cout << "Enter length of the  SubStack: ";
            std::cin >> len2;
            complex *arr1 = new complex[len1];
            complex *arr2 = new complex[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first stack: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second stack: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
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
            std::cout << "Enter length of the second stack: ";
            std::cin >> len2;
            Person *arr1 = new Person[len1];
            Person *arr2 = new Person[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first stack: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second stack: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
            }
            Stack<Person> test1(arr1, len1);
            Stack<Person> test2(arr2, len2);
            Stack<Person> *testResult = test1.Concat(test2);
            testResult->StackShow();
            break;
        }
        case 15: {
            int len1;
            Person a;
            int start, end;
            std::cout << "Enter length of stack: ";
            std::cin >> len1;
            Person *arr1 = new Person[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of stack: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
            }
            std::cout << "Enter first index of SubStack: ";
            std::cin >> start;
            std::cout << "Enter last index of SubStack: ";
            std::cin >> end;
            Stack<Person> test1(arr1, len1);
            Stack<Person> *test2 = test1.GetSubStack(start, end);
            test2->StackShow();
            break;
        }
        case 16: {
            int len1, len2;
            Person a, b;
            std::cout << "Enter length of the main stack: ";
            std::cin >> len1;
            std::cout << "Enter length of the  SubStack: ";
            std::cin >> len2;
            Person *arr1 = new Person[len1];
            Person *arr2 = new Person[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the main stack: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the SubStack: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
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
            std::cout << "Enter length of the second queue: ";
            std::cin >> len2;
            int *arr1 = new int[len1];
            int *arr2 = new int[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first queue: ";
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second queue: ";
                std::cin >> b;
                arr2[i] = b;
            }
            Queue<int> test1(arr1, len1);
            Queue<int> test2(arr2, len2);
            Queue<int> *testResult = test1.Concat(test2);
            testResult->QueueShow();
            break;
        }
        case 18: {
            int len1;
            int a;
            int start, end;
            std::cout << "Enter length of queue: ";
            std::cin >> len1;
            int *arr1 = new int[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first queue: ";
                std::cin >> a;
                arr1[i] = a;
            }
            std::cout << "Enter first index of SubQueue: ";
            std::cin >> start;
            std::cout << "Enter last index of SubQueue: ";
            std::cin >> end;
            Queue<int> test1(arr1, len1);
            Queue<int> *test2 = test1.GetSubQueue(start, end);
            test2->QueueShow();
            break;
        }
        case 19: {
            int len1, len2;
            int a, b;
            std::cout << "Enter length of the main queue: ";
            std::cin >> len1;
            std::cout << "Enter length of the  SubQueue: ";
            std::cin >> len2;
            int *arr1 = new int[len1];
            int *arr2 = new int[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the main queue: ";
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the  SubQueue: ";
                std::cin >> b;
                arr2[i] = b;
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
            std::cout << "Enter length of the second queue: ";
            std::cin >> len2;
            complex *arr1 = new complex[len1];
            complex *arr2 = new complex[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first queue: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second queue: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
            }
            Queue<complex> test1(arr1, len1);
            Queue<complex> test2(arr2, len2);
            Queue<complex> *testResult = test1.Concat(test2);
            testResult->QueueShow();
            break;
        }
        case 21: {
            int len1;
            complex a;
            int start, end;
            std::cout << "Enter length of queue: ";
            std::cin >> len1;
            complex *arr1 = new complex[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the queue: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
            }
            std::cout << "Enter first index of SubQueue: ";
            std::cin >> start;
            std::cout << "Enter last index of SubQueue: ";
            std::cin >> end;
            Queue<complex> test1(arr1, len1);
            Queue<complex> *test2 = test1.GetSubQueue(start, end);
            test2->QueueShow();
            break;
        }
        case 22: {
            int len1, len2;
            complex a, b;
            std::cout << "Enter length of the main queue: ";
            std::cin >> len1;
            std::cout << "Enter length of the  SubQueue: ";
            std::cin >> len2;
            complex *arr1 = new complex[len1];
            complex *arr2 = new complex[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first Queue: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second Queue: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
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
            std::cout << "Enter length of the second queue: ";
            std::cin >> len2;
            Person *arr1 = new Person[len1];
            Person *arr2 = new Person[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the first queue: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the second queue: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
            }
            Queue<Person> test1(arr1, len1);
            Queue<Person> test2(arr2, len2);
            Queue<Person> *testResult = test1.Concat(test2);
            testResult->QueueShow();
            break;
        }
        case 24: {
            int len1;
            Person a;
            int start, end;
            std::cout << "Enter length of queue: ";
            std::cin >> len1;
            Person *arr1 = new Person[len1];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of queue: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
            }
            std::cout << "Enter first index of SubQueue: ";
            std::cin >> start;
            std::cout << "Enter last index of SubQueue: ";
            std::cin >> end;
            Queue<Person> test1(arr1, len1);
            Queue<Person> *test2 = test1.GetSubQueue(start, end);
            test2->QueueShow();
            break;
        }
        case 25: {
            int len1, len2;
            Person a, b;
            std::cout << "Enter length of the main queue: ";
            std::cin >> len1;
            std::cout << "Enter length of the  SubQueue: ";
            std::cin >> len2;
            Person *arr1 = new Person[len1];
            Person *arr2 = new Person[len2];
            for (int i = 0; i < len1; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the main queue: " << std::endl;
                std::cin >> a;
                arr1[i] = a;
            }
            for (int i = 0; i < len2; i++)
            {
                std::cout << "Enter " << i + 1 << " element of the SubQueue: " << std::endl;
                std::cin >> b;
                arr2[i] = b;
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
        std::cout << "0. Run tests for Vector\n";
        std::cout << "1. Run tests for Stack\n";
        std::cout << "2. Run tests for Queue\n";
        std::cout << "3. Use Sum of Vectors for int Vectors\n";
        std::cout << "4. Use Multi of Vectors for int Vectors\n";
        std::cout << "5. Use Multi on scalar For int Vector\n";
        std::cout << "6. Use Sum of Vectors for complex Vectors\n";
        std::cout << "7. Use Multi of Vectors for complex Vectors\n";
        std::cout << "8. Use Concat for Stack of int\n";
        std::cout << "9. Use SubStack for Stack of int\n";
        std::cout << "10. Use IsSuqSequenceHere for Stack of int\n";
        std::cout << "11. Use Concat for Stack of complex\n";
        std::cout << "12. Use SubStack for Stack of complex\n";
        std::cout << "13. Use IsSuqSequenceHere for Stack of complex\n";
        std::cout << "14. Use Concat for Stack of Person\n";
        std::cout << "15. Use SubStack for Stack of Person\n";
        std::cout << "16. Use IsSuqSequenceHere for Stack of Person\n";
        std::cout << "17. Use Concat for Queue of int\n";
        std::cout << "18. Use SubStack for Queue of int\n";
        std::cout << "19. Use IsSuqSequenceHere for Queue of int\n";
        std::cout << "20. Use Concat for Queue of complex\n";
        std::cout << "21. Use SubStack for Queue of complex\n";
        std::cout << "22. Use IsSuqSequenceHere for Queue of complex\n";
        std::cout << "23. Use Concat for Queue of Person\n";
        std::cout << "24. Use SubStack for Queue of Person\n";
        std::cout << "25. Use IsSuqSequenceHere for Queue of Person\n";
        std::cout << "26. Stop programm\n";
    }
    return 0;
}

#include <iostream>
#include "example.h"
#include "ArraySearch.cpp"
#include "ArraySorting.cpp"
#include "Array.cpp"
#include "List.cpp"



void Task1()
{
    std::cout << "template\n";
    int i, d, c, s;
    int I[5] = {1,2,3,4,5};
    double D[5] = {0,0.4,-1,5,10};
    char C[5] = {'4','.','r','5','t'};
    char* S[4] = { (char*)"text", (char*)"txt", (char*)"pltext", (char*)"room" };

    i = Index(I, 3);  std::cout << "i= " << i << std::endl;
    d = Index(D, 0.4); std::cout << "d= " << d << std::endl;
    c = Index(C, '.');  std::cout << "c= " << c << std::endl; 
    s = Index<char*>(S, (char*)"pltext"); std::cout << "s= " << s << std::endl;
}

template <typename T>
void Print(T Array[], int N)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << " " << Array[i];
    }
    std::cout << std::endl;
}

template<>  void Print(char* Array[], int N)
{
    std::cout << "Print char*\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << " " << Array[i];
    }
    std::cout << std::endl;
}

void Task2()
{
    int I[5] = { 2,1,3,4,0 };
    double D[8] = { 0, 0.4, 1.4, 1.2, 1.2, -1, 5, 10};
    char C[5] = { '4','.','r','5','t' };
    char* S[4] = { (char*)"txt", (char*)"text", (char*)"pltext", (char*)"room" };

    std::cout << "I: " << std::endl;
    Print(I, 5);

    std::cout << "D: " << std::endl;
    Print(D, 8);

    std::cout << "C: " << std::endl;
    Print(C, 5);

    std::cout << "S: " << std::endl;
    Print<char*>(S, 4);

    QuickSort(I, 5);
    QuickSort(D, 8);
    QuickSort(C, 5);
    QuickSort(S, 4);

    std::cout << std::endl << "Sorting Arrays: " << std::endl;
    std::cout << "I: " << std::endl;
    Print(I, 5);

    std::cout << "D: " << std::endl;
    Print(D, 8);

    std::cout << "C: " << std::endl;
    Print(C, 5);

    std::cout << "S: " << std::endl;
    Print<char*>(S, 4);
    std::cout << std::endl;
}

void Task3()
{
    
    Array<int> A(5);
    Array<int> B(5);
    Array<int> C(5);

    // Initialize a
    for (int i = 0; i < 5; ++i) {
        A[i] = i;
    }
    for (int i = 0; i < 5; ++i) {
        B[i] = i * 2;
    }

    std::cout << "A: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "B: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    C = A + B;

    std::cout << "C = A + B: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    C = C - A;
    std::cout << "C = C - A: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    A += A;
    std::cout << "A += A: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    B -= A;
    std::cout << "B -= A: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;
}

void Task4()
{
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);

    std::cout << "Our array: ";
    for (DoublyLinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
}
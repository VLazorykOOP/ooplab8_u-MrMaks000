#include <string.h>
#include <iostream>

//  функція - шаблон швидкого сортування */
template <typename T>
void QuickSort(T Array[], /* масив для сортування */
    unsigned int N, /* розмір масиву */
    int L = 0, /* ліва межа сортування */
    int R = 0) /* права межа сортування */
{
    if (R == 0) R = N - 1;
    int iter = L,
        jter = R;

    int middle = (R + L) / 2;

    T x = Array[middle];
    T w = Array[0];

    do
    {
        while (Array[iter] < x)
        {
            iter++;
        }

        while (x < Array[jter])
        {
            jter--;
        }

        if (iter <= jter)
        {
            w = Array[iter];
            Array[iter] = Array[jter];
            Array[jter] = w;

            iter++;
            jter--;
        }
    } while (iter < jter);

    if (L < jter)
    {
        QuickSort(Array, N, L, jter);
    }

    if (iter < R)
    {
        QuickSort(Array, N, iter, R);
    }
}


//template<>  void QuickSort(char* Array[], /* масив для сортування */
//    unsigned int N, /* розмір масиву */
//    int L, /* ліва межа сортування */
//    int R) /* права межа сортування */
//{
//    int iter = L,
//        jter = R;
//
//    int middle = (R + L) / 2;
//
//    char* x = Array[middle];
//    char* w = Array[0];
//
//    do
//    {
//        while (Array[iter] < x)
//        {
//            iter++;
//        }
//
//        while (x < Array[jter])
//        {
//            jter--;
//        }
//
//        if (iter <= jter)
//        {
//            w = Array[iter];
//            Array[iter] = Array[jter];
//            Array[jter] = w;
//
//            iter++;
//            jter--;
//        }
//    } while (iter < jter);
//
//    if (L < jter)
//    {
//        QuickSort<char*>(Array, N, L, jter);
//    }
//
//    if (iter < R)
//    {
//        QuickSort<char*>(Array, N, iter, R);
//    }
//}
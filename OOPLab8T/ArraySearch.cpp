#include <string.h>
#include <iostream>

//  функція - шаблон
template <typename T>
int Index(T Array[], T key) {
    int index = 0;
    for (int i = 0; i < sizeof(Array); i++)
    {
        if (Array[i] == key) index = i;
    }
    return index;
}



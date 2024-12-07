#include <iostream>
#include "array.cpp"


template<typename T, size_t S>
void print(Array<T, S>& array)
{
    for (int i = 0; i<array.Size(); ++i)
    {
        std::cout<< array[i] << std::endl;
    }
}


int main()
{   
    Array<int, 10> array;

    memset(array, 0, sizeof(int) * array.Size());
    
    array[0] = 10;
    array[1] = 2;
    array[3] = 4;

    print(array);

    return 0;
}
#include <iostream>
#include "Array.hpp"
#include <cstdlib> // for srand() and rand()
#include <ctime> 

// Introduction to Templates Classes.
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int *int_default = new int();
    for (int i = 0; i < MAX_VAL; i++) {
        if (numbers[i] != *int_default){
            std::cout << "Different Initialization" << std::endl;
            return (1);
        }
    }
    delete (int_default);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        bool    different = false;
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        for (size_t i = 0; i < tmp.size() && !different; i++){
            if ((tmp[i] != test[i]) || (numbers[i] != tmp[i]))
                different = true;
        }
        std::cout << ((different) ? "Different Value." : "No Difference Found") << std::endl;
        std::cout << tmp[5] << ", " << test[5] << ", " << numbers[5] << std::endl;
        tmp[5] = 15;
        std::cout << tmp[5] << ", " << test[5] << ", " << numbers[5] << std::endl;
        test[5] = 16;
        std::cout << tmp[5] << ", " << test[5] << ", " << numbers[5] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

/*
Introduction to Template Classes
*/
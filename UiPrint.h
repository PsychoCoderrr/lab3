#pragma once
#include <iostream>

void PrintUI()
{
    std::cout<<std::endl;
    std::cout << "Vector types: int, complex" << std::endl;
    std::cout << "Stack types: int, complex, person" << std::endl;
    std::cout << "Queue types: int, complex, person" << std::endl;
    std::cout << "Vector functions: sum, multi, multionscalar"<< std::endl;
    std::cout << "Stack functions: concat, substack, issubsequencehere" << std::endl;
    std::cout << "Queue functions: concat, subqueue, issubsequencehere" << std::endl;
    std::cout << "Comands you can enter:" << std::endl;
    std::cout << "Run tests for <name of container>" << std::endl;
    std::cout << "Use <type> <name of container> for <function>" << std::endl;
    std::cout << "Stop" << std::endl << std::endl;
    
}

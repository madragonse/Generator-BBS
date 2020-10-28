#include <iostream>
#include "BBS.h"


int main()
{
    BBS test = BBS();

    //std::cout << "\n" << test.generatePrime((long long)1000) << "\n";
    
    test.generate(200000);

    std::vector<bool> wyn = test.getNumbers();

    for (auto a : wyn)
    {
        std::cout << a << " " ;
    }


}

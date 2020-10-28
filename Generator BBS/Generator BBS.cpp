#include <iostream>
#include "BBS.h"
#include "RC4.h"
#include <time.h>


int main()
{

    /*int i[256];

    std::cout << i << std::endl;

    BBS test = BBS();

    //std::cout << "\n" << test.generatePrime((long long)1000) << "\n";
    
    test.generate(200000);

    std::vector<bool> wyn = test.getNumbers();

    for (auto a : wyn)
    {
        std::cout << a << " " ;
    }*/

    uint8_t key[128];

    

    RC4 test2 = RC4(key, 100);
    test2.generateKey();

    std::vector<uint8_t> wynik = test2.generate(200000);

    for (auto e : wynik)
    {
        std::cout << (int)(e%2) << " ";
    }


}

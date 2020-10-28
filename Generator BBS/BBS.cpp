#include "BBS.h"
#include <time.h>
#include <iostream>

 BBS::BBS(long long N, long long xi) 
{
	this->N = N;
	this->xi = xi;


}

 BBS::BBS()
 {
	 this->generateN();
	 this->generateX();
 };


void BBS::generate(int ile)
{

	this->x = std::vector<bool> ();

	for (int i = 0; i < ile; i++)
	{
		this->xi = (this->xi * this->xi) % this->N;
		this->x.push_back(this->xi % 2);

	}


}

std::vector<bool> BBS::getNumbers()
{
	return this->x;
}

void BBS::generateN()
{
	std::srand(time(nullptr));

	//N = ((rand() % (long long)1000000 * 4 + 3) * (rand() % (long long)1000000 * 4 + 3));
	N = this->generatePrime(rand() % (long long)10000000) * this->generatePrime(rand() % (long long)10000000);
}
 
void BBS::generateX()
{
	do
	{
		for (int i = 0; i < 10000; i++)
		{
			this->xi += rand() % (long long)10000000;
		}

		
	} while (this->nwd(this->xi, this->N) != 1);

	std::cout << "\n" << "N: " << this->N << " xi: " << this->xi << "\n";
}

long long BBS::nwd(long long a, long long b)
{
	long long tem = 0;
	while (b != 0) {
		tem = a % b;
		a = b;
		b = tem;
	}
	return a;
}

long long BBS::generatePrime(long long from)
{
	std::vector<long long> sito;
	bool clasify = true;


	for (long long i = 2; true; i++)
	{
		clasify = true;
		for (auto e : sito)
		{
			if (i % e == 0)
			{
				clasify = false;
				break;
			}
		}

		if (clasify == true)
		{
			if ((from < i) && (i % 4 == 3))
			{
				/*for (auto e : sito)
				{
					std::cout << e << " ";
				}
				std::cout << "\n";*/

				return i;
			}
			else
				sito.push_back(i);
		}

	}

}
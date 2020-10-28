#pragma once
#include <vector>

class BBS
{
private: 
	long long N;
	long long xi;
	std::vector<bool> x;

	void generateN();
	void generateX();
	long long nwd(long long a, long long b);
		
public:
	BBS();
	BBS(long long N, long long xi);
	void generate(int ile);
	std::vector<bool> getNumbers();

	long long generatePrime(long long from);
	


};


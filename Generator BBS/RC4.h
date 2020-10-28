#pragma once
#include <vector>
class RC4
{
private:
	uint8_t S[256];
	uint8_t key[128];
	int key_length;
	std::vector<uint8_t> wynik;

public:
	RC4(uint8_t key[128], int key_length);

	void generateKey();
	std::vector<uint8_t> generate(long long ile);




};


#include "RC4.h"
#include <xpolymorphic_allocator.h>

RC4::RC4(uint8_t key[128], int key_length)
{
    this->key_length = key_length;

    for (int i = 0; i < this->key_length; i++)
        this->key[i] = key[i];

}

void RC4::generateKey()
{
    for (int i = 0; i < 256; i++)//for i from 0 to 255
    {
        this->S[i] = i; //S[i] : = i
        
    }
    long long j = 0; //j := 0
    for (int i = 0; i < 256; i++) //for i from 0 to 255
    {
        j = ((j + this->S[i] + this->key[i % this->key_length]) % 256); //j: = (j + S[i] + klucz[i mod d³ugoœæ_klucza]) mod 256
        std::swap(S[i], S[j]); //zamieñ(S[i], S[j])

    }
        

}

std::vector<uint8_t> RC4::generate(long long ile)
{
    this->wynik = std::vector<uint8_t>();
    int i = 0;//i: = 0
    int j = 0;//j : = 0
    for (int l = 0; l < ile; l++)//while TworzonyStrumieñSzyfruj¹cy :
    {
        i = (i + 1) % 256;//i: = (i + 1) mod 256
        j = (j + this->S[i]) % 256; //j : = (j + S[i]) mod 256
        std::swap(this->S[i], this->S[j]);//zamieñ(S[i], S[j])
        this->wynik.push_back(this->S[(this->S[i] + this->S[j]) % 256]);//wynik S[(S[i] + S[j]) mod 256]
    }
        
    return this->wynik;
}

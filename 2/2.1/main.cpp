#include <stdio.h>
#include <iostream>
#include <cctype>
#include "Cipher.h"
#include <locale>
using namespace std;
void check(const wstring& Text, const int & key)
{
    wstring s=Text;
    try {
        Cipher skey(key);
        wcout<<skey.Coder(key, s)<<endl;
        wstring g=skey.Coder(key, s);
        wcout<<skey.Decoder(key,g)<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main()
{
    int k;
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"HELLOPARNIDAROVA",8);

    return 0;
}

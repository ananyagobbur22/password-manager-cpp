#include "encryption.h"

using namespace std;

string encrypt(string data)
{
    for (int i = 0; i < data.length(); i++)
    {
        data[i] = data[i] + 3;
    }
    return data;
}

string decrypt(string data)
{
    for (int i = 0; i < data.length(); i++)
    {
        data[i] = data[i] - 3;
    }
    return data;
}
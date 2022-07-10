#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cmath>

std::string convertBinary(int decimal);
std::string convertText(std::string data);
int binaryToDecimal(std::string binary);

int main()
{
    std::string txt = "Hola mundo en binario";
    
    std::ofstream fileBin;
    fileBin.open("binarios.bin", std::ios::out | std::ios::binary);

    for(int i = 0; i < txt.length(); i++)
    {
        fileBin<<convertBinary((int) txt[i])<<" ";
    }
    fileBin.close();

    std::ifstream fileBin2("binarios.bin");
    std::string content;
    getline(fileBin2, content);
    fileBin2.close();

    std::ofstream fileTxt;
    fileTxt.open("palabras.txt", std::ios::out);
    fileTxt<<convertText(content);
    return 0;
}

std::string convertBinary(int decimal)
{
    char bin[8];

    for(int i = 7; i >= 0; i--)
    {
        bin[i] = (decimal % 2 == 0 ? '0' : '1');
        decimal /= 2;
    }
    return bin;
}

std::string convertText(std::string data)
{
    std::string binaries, words;
    std::stringstream input_stringstream(data);
    while(getline(input_stringstream, binaries, ' '))
    {
        words += binaryToDecimal(binaries);
    }
    return words;
}

int binaryToDecimal(std::string binary)
{
    int decimal = 0, i = 0, remainder;
    int binaryInt = std::stoi(binary, nullptr, 10);

    while (binaryInt != 0)
    {
        remainder = binaryInt%10;
        binaryInt /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    return decimal;
}

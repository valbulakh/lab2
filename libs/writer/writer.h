#pragma once
#include <iostream>

class Writer
{
public:
    Writer(){std::cout<<"\nxxxxxxxxxxxxxx\n";};
    void writeWavFile ();
    ~Writer(){};
};


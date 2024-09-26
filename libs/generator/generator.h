#ifndef GENERATOR_H
#define GENERATOR_H
#include <iostream>

//struct Params{
//    duration = 4; // c
//    fs = 48000; // Hz
//    f = 440; // Hz
//    snr = 6; // dB
//}

class Generator
{
public:
    Generator(){std::cout<<"\nmmmmmmmmmm\n";};
    void generate();
    ~Generator(){};
private:
    void genSin();
    void genNoise();
};

#endif // GENERATOR_H

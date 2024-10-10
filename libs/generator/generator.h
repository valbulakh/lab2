#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <cstdint>

// Структура параметров генерации
struct Params {
    double duration = 4.0;  // Длительность сигнала в секундах
    int fs = 48000;         // Частота дискретизации (Гц)
    double f = 440.0;       // Частота сигнала (Гц) - Нота Ля
    double snr = 6.0;       // Отношение сигнал/шум (дБ)
};

// Класс генерации сигнала
class Generator {
public:
    Generator(); // Конструктор по умолчанию
    Generator(const Params& params); // Конструктор с параметрами
    std::vector<int16_t> genSin();   // Метод генерации синусоиды
private:
    Params params;  // Параметры генерации
};

#endif // GENERATOR_H

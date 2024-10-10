#include "generator.h"
#include <cmath>

// Конструктор по умолчанию
Generator::Generator() {
    params.duration = 4.0;
    params.fs = 48000;
    params.f = 440.0;
    params.snr = 6.0;
}

// Конструктор с пользовательскими параметрами
Generator::Generator(const Params& params) : params(params) {}

// Генерация синусоиды
std::vector<int16_t> Generator::genSin() {
    std::vector<int16_t> signal;
    int N = params.duration * params.fs; // Количество отсчетов
    double amplitude = 32767 * 0.5;  // 50% от максимальной амплитуды для 16 бит

    for (int n = 0; n < N; ++n) {
        double t = static_cast<double>(n) / params.fs; // Текущее время
        double value = amplitude * sin(2.0 * M_PI * params.f * t); // Синусоида
        signal.push_back(static_cast<int16_t>(value));  // Записываем отсчеты
    }

    return signal;  // Возвращаем сигнал
}

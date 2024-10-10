#include "generator.h"
#include "writer.h"
#include <iostream> // Для вывода в консоль

int main() {
    // Задаем параметры для генератора
    Params params;
    params.duration = 4.0;  // Длительность 4 секунды
    params.fs = 48000;      // Частота дискретизации 48000 Гц
    params.f = 440.0;       // Частота 440 Гц (Нота Ля)
    params.snr = 6.0;       // Отношение сигнал/шум 6 дБ

    // Генерация синусоиды
    Generator generator(params);
    std::vector<int16_t> audioData = generator.genSin();

    std::cout << "Размер сгенерированных данных: " << audioData.size() << " отсчетов" << std::endl;

    // Запись сгенерированного сигнала в WAV файл
    Writer writer(params.fs);

    // Здесь указываем полный путь, где хотим сохранить файл
    writer.writeWavFile("C:/Users/My_com/Desktop/note_a.wav", audioData);

    return 0;
}


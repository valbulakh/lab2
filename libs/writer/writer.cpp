#include "writer.h"
#include <iostream>
#include <fstream>

Writer::Writer(int sampleRate) : sampleRate(sampleRate) {}

void Writer::writeWavHeader(std::ofstream& file, int dataSize) {
    int bitsPerSample = 16;
    int numChannels = 1;
    int byteRate = sampleRate * numChannels * bitsPerSample / 8;
    int blockAlign = numChannels * bitsPerSample / 8;
    int subchunk2Size = dataSize * numChannels * bitsPerSample / 8;

    // RIFF заголовок
    file.write("RIFF", 4);
    int chunkSize = 36 + subchunk2Size;
    file.write(reinterpret_cast<const char*>(&chunkSize), 4);
    file.write("WAVE", 4);

    // Subchunk1 (fmt)
    file.write("fmt ", 4);
    int subchunk1Size = 16;  // 16 для PCM
    file.write(reinterpret_cast<const char*>(&subchunk1Size), 4);
    int audioFormat = 1;  // PCM формат
    file.write(reinterpret_cast<const char*>(&audioFormat), 2);
    file.write(reinterpret_cast<const char*>(&numChannels), 2);
    file.write(reinterpret_cast<const char*>(&sampleRate), 4);
    file.write(reinterpret_cast<const char*>(&byteRate), 4);
    file.write(reinterpret_cast<const char*>(&blockAlign), 2);
    file.write(reinterpret_cast<const char*>(&bitsPerSample), 2);

    // Subchunk2 (data)
    file.write("data", 4);
    file.write(reinterpret_cast<const char*>(&subchunk2Size), 4);
}

void Writer::writeWavFile(const std::string& filename, const std::vector<int16_t>& audioData) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла: " << filename << std::endl;
        return;
    }

    std::cout << "Файл открыт успешно: " << filename << std::endl;

    // Размер данных
    int dataSize = audioData.size() * sizeof(int16_t);
    std::cout << "Размер данных: " << dataSize << " байт" << std::endl;

    // Запись заголовка
    writeWavHeader(file, dataSize);

    // Запись аудиоданных
    file.write(reinterpret_cast<const char*>(audioData.data()), dataSize);

    if (!file) {
        std::cerr << "Ошибка при записи в файл" << std::endl;
    } else {
        std::cout << "Данные успешно записаны" << std::endl;
    }

    file.close();
    std::cout << "Файл закрыт" << std::endl;
}



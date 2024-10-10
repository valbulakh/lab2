#ifndef WRITER_H
#define WRITER_H

#include <string>
#include <vector>
#include <fstream>
#include <cstdint>

class Writer {
public:
    Writer(int sampleRate); // Конструктор с частотой дискретизации
    void writeWavFile(const std::string& filename, const std::vector<int16_t>& audioData); // Метод записи в файл

private:
    int sampleRate;
    void writeWavHeader(std::ofstream& file, int dataSize); // Запись заголовка WAV файла
};

#endif // WRITER_H


#include "RingBuffer.hpp"
#include <string.h>

al::RingBuffer::RingBuffer() {
    RingBuffer(512);
}

al::RingBuffer::RingBuffer(int size) {
    _size = size;
    _buffer = new char[size];
}

al::RingBuffer::~RingBuffer() {
    delete[] _buffer;
}

int al::RingBuffer::read(char *buffer, int lenght) {
    memcpy(buffer, _buffer, lenght);
    return lenght;
}

int al::RingBuffer::write(char *data, int length) {
    memcpy(_buffer, data, length);
    return length;
}
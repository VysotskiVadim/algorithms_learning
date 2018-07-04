#include "RingBuffer.hpp"
#include <string.h>
#include "RingBufferHelper.hpp"

al::RingBuffer::RingBuffer() {
    RingBuffer(512);
}

al::RingBuffer::RingBuffer(int size) {
    _size = size;
    _head = 0;
    _tail = 0;
    _buffer = new char[size];
}

al::RingBuffer::~RingBuffer() {
    delete[] _buffer;
}

int al::RingBuffer::read(char *buffer, int lenght) {
    int usedSpace = getUsedSpace();
    if (usedSpace < lenght) {
        lenght = usedSpace;
    }
    memcpy(buffer, &_buffer[_head], lenght);
    _head += lenght;
    return lenght;
}

int al::RingBuffer::write(char *data, int length) {
    int freeSpace = getFreeSpace();
    if (freeSpace < length) {
        length = freeSpace;
    }
    memcpy(&_buffer[_tail], data, length);
    _tail += length;
    return length;
}

int al::RingBuffer::getFreeSpace() {
    return getFreeSpaceOfCycleBuffer(_head, _tail, _size);
}

int al::RingBuffer::getUsedSpace() {
    return getUsedSpaceOfCycleBuffer(_head, _tail, _size);
}
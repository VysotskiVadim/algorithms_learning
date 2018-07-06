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

    int spaceBeforeEndOfBuffer = _size - _head;
    if (spaceBeforeEndOfBuffer >= lenght) {
        memcpy(buffer, &_buffer[_head], lenght);
        _head += lenght;
    }
    else {
        memcpy(buffer, &_buffer[_head], spaceBeforeEndOfBuffer);
        int leftToRead = lenght - spaceBeforeEndOfBuffer;
        memcpy(&buffer[spaceBeforeEndOfBuffer], _buffer, leftToRead);
        _head = leftToRead;
    }
    
    return lenght;
}

int al::RingBuffer::write(char *data, int length) {
    int freeSpace = getFreeSpace();
    if (freeSpace < length) {
        length = freeSpace;
    }

    int spaceBeforeEndOfBuffer = _size - _tail;
    if (spaceBeforeEndOfBuffer >= length) {
        memcpy(&_buffer[_tail], data, length);
        _tail += length;
    }
    else {
        memcpy(&_buffer[_tail], data, spaceBeforeEndOfBuffer);
        int leftToWtire = length - spaceBeforeEndOfBuffer;
        memcpy(_buffer, &data[spaceBeforeEndOfBuffer], leftToWtire);
        _tail = leftToWtire;
    }
    
    return length;
}

int al::RingBuffer::getFreeSpace() {
    return getFreeSpaceOfCycleBuffer(_head, _tail, _size);
}

int al::RingBuffer::getUsedSpace() {
    return getUsedSpaceOfCycleBuffer(_head, _tail, _size);
}
#include "RingBuffer.hpp"
#include <string.h>
#include "RingBufferHelper.hpp"

al::RingBuffer::RingBuffer() {
    RingBuffer(512);
}

al::RingBuffer::RingBuffer(int size) {
    _size = size;
    _tail = 0;
    _head = 0;
    _isEmpty = true;
    _buffer = new char[_size];
}

al::RingBuffer::~RingBuffer() {
    delete[] _buffer;
}

int al::RingBuffer::read(char *buffer, int lenght) {
    int usedSpace = getUsedSpace();
    if (usedSpace <= lenght) {
        lenght = usedSpace;
        _isEmpty = true;
    }

    int spaceBeforeEndOfBuffer = _size - _tail;
    if (spaceBeforeEndOfBuffer >= lenght) {
        memcpy(buffer, &_buffer[_tail], lenght);
        _tail += lenght;
    }
    else {
        memcpy(buffer, &_buffer[_tail], spaceBeforeEndOfBuffer);
        int leftToRead = lenght - spaceBeforeEndOfBuffer;
        memcpy(&buffer[spaceBeforeEndOfBuffer], _buffer, leftToRead);
        _tail = leftToRead;
    }

    return lenght;
}

int al::RingBuffer::write(char *data, int length) {
    int freeSpace = getFreeSpace();
    if (freeSpace < length) {
        length = freeSpace;
    }

    int spaceBeforeEndOfBuffer = _size - _head;
    if (spaceBeforeEndOfBuffer >= length) {
        memcpy(&_buffer[_head], data, length);
        _head += length;
    }
    else {
        memcpy(&_buffer[_head], data, spaceBeforeEndOfBuffer);
        int leftToWrire = length - spaceBeforeEndOfBuffer;
        memcpy(_buffer, &data[spaceBeforeEndOfBuffer], leftToWrire);
        _head = leftToWrire;
    }

    if (length > 0) {
        _isEmpty = false;
    }
    
    return length;
}

int al::RingBuffer::getFreeSpace() {
    return getFreeSpaceOfCycleBuffer(_tail, _head, _size, _isEmpty);
}

int al::RingBuffer::getUsedSpace() {
    return getUsedSpaceOfCycleBuffer(_tail, _head, _size, _isEmpty);
}
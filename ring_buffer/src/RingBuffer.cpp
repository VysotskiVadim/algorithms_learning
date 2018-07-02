#include "RingBuffer.hpp"

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
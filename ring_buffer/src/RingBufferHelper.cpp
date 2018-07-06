#include "RingBufferHelper.hpp"

int al::getFreeSpaceOfCycleBuffer(int tailOffset, int headOffset, int size, bool isEmpty) {
    if (headOffset == tailOffset) {
        return isEmpty ? size : 0;
    }
    else if (headOffset > tailOffset) {
        return size - headOffset + tailOffset;
    }
    else {
        return tailOffset - headOffset;
    }
    
}

int al::getUsedSpaceOfCycleBuffer(int tailOffset, int headOffset, int size, bool isEmpty) {
    if (headOffset == tailOffset) {
        return isEmpty ? 0 : size;
    }
    else if (headOffset < tailOffset) {
        return size - (tailOffset - headOffset);
    }
    else {
        return headOffset - tailOffset;
    }
}

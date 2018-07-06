#include "RingBufferHelper.hpp"

int al::getFreeSpaceOfCycleBuffer(int tailOffset, int headOffset, int size) {
    if (headOffset >= tailOffset) {
        return size - headOffset + tailOffset;
    }
    else {
        return tailOffset - headOffset;
    }
    
}

int al::getUsedSpaceOfCycleBuffer(int tailOffset, int headOffset, int size) {
    if (headOffset < tailOffset) {
        return size - (tailOffset - headOffset);
    }
    else {
        return headOffset - tailOffset;
    }
}

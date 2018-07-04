#include "RingBufferHelper.hpp"

int al::getFreeSpaceOfCycleBuffer(int headOffset, int tailOffset, int lenght) {
    if (tailOffset >= headOffset) {
        return lenght - tailOffset + headOffset;
    }
    else {
        return headOffset - tailOffset;
    }
    
}
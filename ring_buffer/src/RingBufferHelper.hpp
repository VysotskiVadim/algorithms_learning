#pragma once

namespace al {

    int getFreeSpaceOfCycleBuffer(int tailOffset, int headOffset, int size, bool isEmpty);
    int getUsedSpaceOfCycleBuffer(int tailOffset, int headOffset, int size, bool isEmpty);

}
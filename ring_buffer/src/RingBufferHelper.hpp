#pragma once

namespace al {

    int getFreeSpaceOfCycleBuffer(int tailOffset, int headOffset, int size);
    int getUsedSpaceOfCycleBuffer(int tailOffset, int headOffset, int size);

}
#pragma once

namespace al {

    int getFreeSpaceOfCycleBuffer(int headOffset, int tailOffset, int lenght);
    int getUsedSpaceOfCycleBuffer(int headOffset, int tailOffset, int lenght);

}
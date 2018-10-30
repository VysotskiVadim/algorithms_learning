#pragma once

namespace al {
    template <typename T> class Comparer {
    public:
        virtual int compare(T a, T b) = 0;
    };
}
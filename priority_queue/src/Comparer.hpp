#pragma once

namespace al {
    template <class T>
    class Comparer {
    public:
        virtual int compare(T a, T b) = 0;
    };
}
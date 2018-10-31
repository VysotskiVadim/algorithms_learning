#pragma once

#include "Comparer.hpp"

namespace al {
    template <typename T> class GenericComparer: public Comparer<T> {
    public:
        GenericComparer() { }
        int compare(T a, T b) override;
        ~GenericComparer() override { };
    };

    template <typename T>
    int GenericComparer<T>::compare(T a, T b) {
        if (a == b) return 0;
        else if (a > b) return 1;
        else return -1;
    }
}
#pragma once;

#include "Comparer.hpp"

namespace al {
    template <class T>
    class PriorityQueue {
    public:
        virtual void addItem(T item) = 0;
        virtual T removeNext() = 0;

        PriorityQueue(Comparer<T> comparer)
        : _comparer(comparer)
        { }
    private:
        Comparer<T> _comparer;
    };
}
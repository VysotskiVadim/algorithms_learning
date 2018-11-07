#pragma once

#include <memory>
#include "GenericComparer.hpp"

namespace al {

    template <typename T>
    class BinaryHeap {
    public:
        BinaryHeap(
            std::unique_ptr< Comparer<T> > comprarer = std::unique_ptr< Comparer<T> >(new GenericComparer<T>),
            T *initialHeap = new T[10],
            int size = 10
        );
        int getSize();
    private:
        int _size;
        std::unique_ptr< Comparer<T> > _comparer;
        T *_heap;
    };


    template <typename T>
    BinaryHeap<T>::BinaryHeap(std::unique_ptr< Comparer<T> > comparer, T *initialHeap, int size) :
    _heap(initialHeap),
    _size(size),
    _comparer(std::move(comparer))
    { }

    template <typename T>
    int BinaryHeap<T>::getSize() {
        return _size;
    }
}
#pragma once

#include <memory>
#include "Comparer.hpp"
#include "GenericComparer.hpp"

namespace al {
    template <typename T> class PriorityQueue {
    public:
        virtual void addItem(T item) = 0;
        virtual T removeNext() = 0;

        PriorityQueue(std::unique_ptr< Comparer<T> > comparer)
        : _comparer(std::move(comparer))
        { }

        PriorityQueue() : _comparer(std::unique_ptr< GenericComparer<T> >(new GenericComparer<T>))
        { }
    protected:
        std::unique_ptr< Comparer<T> > _comparer;
    };
}
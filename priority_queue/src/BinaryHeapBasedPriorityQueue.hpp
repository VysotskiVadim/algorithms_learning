#pragma once

#include <memory>
#include "PriorityQueue.hpp"
#include "Comparer.hpp"

namespace al {
    template <typename T> class BinaryHeapBasedPriorityQueue: public PriorityQueue<T> {
    public:
        BinaryHeapBasedPriorityQueue(std::unique_ptr< Comparer<T> > comparer) : PriorityQueue<T>(std::move(comparer)) { }
        BinaryHeapBasedPriorityQueue() : PriorityQueue<T>() { }
        void addItem(T item) override;
        T removeNext() override;
        int getCount() override;
        ~BinaryHeapBasedPriorityQueue() override { }
    private:
        T _item;
    };

    template <typename T>
    void BinaryHeapBasedPriorityQueue<T>::addItem(T item) {
        _item = item;
    }

    template <typename T>
    T BinaryHeapBasedPriorityQueue<T>::removeNext() {
        return _item;
    }

    template <typename T>
    int BinaryHeapBasedPriorityQueue<T>::getCount() {
        return 0;
    }
}
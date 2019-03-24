#pragma once

#include <memory>
#include "PriorityQueue.hpp"
#include "Comparer.hpp"
#include "BinaryHeap.hpp"

namespace al {
    template <typename T> class BinaryHeapBasedPriorityQueue: public PriorityQueue<T> {
    public:
        BinaryHeapBasedPriorityQueue(std::unique_ptr< Comparer<T> > comparer);
        BinaryHeapBasedPriorityQueue();
        void addItem(T item) override;
        bool removeNext(T &item) override;
        int getCount() override;
        ~BinaryHeapBasedPriorityQueue() override { }
    private:
        BinaryHeap<T> _heap;
    };

    template<typename T>
    BinaryHeapBasedPriorityQueue<T>::BinaryHeapBasedPriorityQueue() { }

    template<typename T>
    BinaryHeapBasedPriorityQueue<T>::BinaryHeapBasedPriorityQueue(std::unique_ptr< Comparer<T> > comparer)
    : _heap(std::move(comparer))
    { }

    template <typename T>
    void BinaryHeapBasedPriorityQueue<T>::addItem(T item) {
        _heap.insertItem(item);
    }

    template <typename T>
    bool BinaryHeapBasedPriorityQueue<T>::removeNext(T &item) {
        return _heap.removeItemFromTop(item);
    }

    template <typename T>
    int BinaryHeapBasedPriorityQueue<T>::getCount() {
        return _heap.getSize();
    }
}
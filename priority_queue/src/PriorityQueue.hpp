#pragma once

#include <memory>

namespace al {
    template <typename T> class PriorityQueue {
    public:
        virtual void addItem(T item) = 0;
        virtual bool removeNext(T &item) = 0;
        virtual int getCount() = 0;
        virtual ~PriorityQueue() { }
    };
}
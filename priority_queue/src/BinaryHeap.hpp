#pragma once

#include <memory>
#include "GenericComparer.hpp"
#include <cstring>
#include <sstream>

namespace al {

    template <typename T>
    class BinaryHeap {
    public:
        BinaryHeap(
            std::unique_ptr< Comparer<T> > comparer,
            T *initialHeap,
            int size,
            int capacity
        );

        BinaryHeap(std::unique_ptr< Comparer<T> > comparer)
            : BinaryHeap(comparer, new T[10], 0, 10) { }

        BinaryHeap(T *initialHeap, int size, int capacity)
            : BinaryHeap(std::unique_ptr< Comparer<T> >(new GenericComparer<T>), initialHeap, size, capacity) { }

        BinaryHeap()
            :BinaryHeap(std::unique_ptr< Comparer<T> >(new GenericComparer<T>), new T[10], 0, 10) { }

        ~BinaryHeap();

        int getSize();
        int getCapacity();
        void insertItem(T item);
        T removeItemFromTop();

        T* getInnerHeap();
        T getItem(int index);
        void setItem(int index, T item);
    private:
        int _capacity;
        int _size;
        std::unique_ptr< Comparer<T> > _comparer;
        T *_heap;

        void exchangeItems(int index1, int index2);
        void swim(int index);
        bool isTopNode(int index);
        int getParentIndex(int index);
        bool isMore(int index1, int index2);
        bool isLess(int index1, int index2);
        void increaseHeapSize();
        void sink(int index);
        bool getMaxChild(int index, int &childIndex);
    };


    template <typename T>
    BinaryHeap<T>::BinaryHeap(std::unique_ptr< Comparer<T> > comparer, T *initialHeap, int size, int capacity) :
    _heap(initialHeap),
    _capacity(capacity),
    _size(size),
    _comparer(std::move(comparer))
    { }

    template <typename T>
    BinaryHeap<T>::~BinaryHeap() {
        delete [] _heap;
    }

    template <typename T>
    int BinaryHeap<T>::getSize() {
        return _size;
    }

    template <typename T>
    int BinaryHeap<T>::getCapacity() {
        return _capacity;
    }

    template <typename T>
    T* BinaryHeap<T>::getInnerHeap() {
        return _heap;
    }

    template <typename T>
    T BinaryHeap<T>::getItem(int index) {
        if (index < 1 || index > _size) {
            std::stringstream errorMessage;
            errorMessage << "BinaryHeap.getItem: given index is " << index;
            throw std::out_of_range(errorMessage.str());
        }
        return _heap[index - 1];
    }

    template <typename T>
    void BinaryHeap<T>::setItem(int index, T item) {
        if (index < 1 || index > _capacity) {
            std::stringstream errorMessage;
            errorMessage << "BinaryHeap.setItem: given index is " << index;
            throw std::out_of_range(errorMessage.str());
        }
        _heap[index - 1] = item;
    }

    template <typename T>
    void BinaryHeap<T>::exchangeItems(int index1, int index2) {
        T firstItem = getItem(index1);
        setItem(index1, getItem(index2));
        setItem(index2, firstItem);
    }

    template <typename T>
    bool BinaryHeap<T>::isTopNode(int index) {
        return index == 1;
    }

    template <typename T>
    bool BinaryHeap<T>::getMaxChild(int index, int &childIndex) {
        int firstChildIndex = index * 2;
        if (firstChildIndex > getSize()) {
            return false;
        }
        int secondChildIndex = firstChildIndex + 1;
        if (secondChildIndex > getSize()) {
            childIndex = firstChildIndex;
        }
        else if (isMore(firstChildIndex, secondChildIndex)) {
            childIndex = firstChildIndex;
        }
        else {
            childIndex = secondChildIndex;
        }
        return true;
    }

    template <typename T>
    int BinaryHeap<T>::getParentIndex(int index) {
        int parent = index / 2;
        return parent;
    }

    template <typename T>
    bool BinaryHeap<T>::isMore(int index1, int index2) {
        return _comparer->compare(getItem(index1), getItem(index2)) > 0;
    }

    template <typename T>
    bool BinaryHeap<T>::isLess(int index1, int index2) {
        return _comparer->compare(getItem(index1), getItem(index2)) < 0;
    }

    template <typename T>
    void BinaryHeap<T>::increaseHeapSize() {
        int newCapacity = getCapacity() * 2;
        int* newHeap = new T[newCapacity];
        std::memcpy(newHeap, _heap, sizeof(T) * getCapacity());
        delete [] _heap;
        _heap = newHeap;
        _capacity = newCapacity;
    }

    template <typename T>
    void BinaryHeap<T>::swim(int index) {
        while (!isTopNode(index) && isMore(index, getParentIndex(index))) {
            int parentIndex = getParentIndex(index);
            exchangeItems(index, parentIndex);
            index = parentIndex;
        }
    }

    template <typename T>
     void BinaryHeap<T>::sink(int index) {
        int maxChildIndex = -1;
        while(getMaxChild(index, maxChildIndex) && !isMore(index, maxChildIndex)){
            exchangeItems(index, maxChildIndex);
            index = maxChildIndex;
        }
    }


    template <typename T>
    void BinaryHeap<T>::insertItem(T item) {
        int nextElementPosition = getSize() + 1;
        if (nextElementPosition > getCapacity()) {
            increaseHeapSize();
        }
        setItem(nextElementPosition, item);
        _size++;
        swim(nextElementPosition);
    }


    template <typename T>
    T BinaryHeap<T>::removeItemFromTop() {
        T topItem = getItem(1);
        setItem(1, getItem(_size));
        _size--;
        sink(1);
        return topItem;
    }
}
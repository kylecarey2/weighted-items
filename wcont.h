#ifndef WCONT_H
#define WCONT_H

#include "weightedItem.h"

// Class declaration
template <class T>
class WCont {
public:
    // Big 4
    WCont();
    WCont(const WCont<T>& other);
    ~WCont();
    WCont<T>& operator=(const WCont<T>& other);

    // Feature functions
    // Adding items
    void add(const WeightedItem<T>& item, int index = -1);
    void add(const T& data, const unsigned& weight, int index = -1);
    void insert(const WeightedItem<T>& item, int index = 0);
    void insert(const T& data, const unsigned& weight, int index = 0);

    // Remove items
    // void remove(int index);
    // void remove(const WeightedItem<T>& item);

    // bool exists(const WeightedItem<T>& item);
    // bool exists(const T& data, const unsigned& weight);

    // Misc.
    int size() const;
    WeightedItem<T>& at(int index) const;


    // Randomize 


private:
    WeightedItem<T>* data;
    int used;
    int capacity;
    // int current_index;

    void resize();
};

// Implementation
template <class T>
WCont<T>::WCont() {
    used = 0;
    capacity = 5;
    data = new WeightedItem<T>[capacity]; // create an array
}

template <class T>
WCont<T>::~WCont() {
    delete[] data;
}

template <class T>
WCont<T>::WCont(const WCont<T>& other) {
    // Copy member data from other to this
    used = other.used;
    capacity = other.capacity;

    data = new WeightedItem<T>[capacity];
    for (int i = 0; i < other.used; i++) {
        data[i] = other.data[i];
    }
}

template <class T>
WCont<T>& WCont<T>::operator=(const WCont<T>& other) {
    // Return object if this and other are the same object
    if (this == &other) {
        return *this;
    }

    // Free current memory of this
    delete[] data;

    // Copy member data from other to this
    used = other.used;
    capacity = other.capacity;

    data = new WeightedItem<T>[capacity];
    for (int i = 0; i < other.used; i++) {
        data[i] = other.data[i];
    }

    return *this;
}

template <class T>
void WCont<T>::resize() {
    // Update capacity and create a temporary array with new capacity
    capacity += 5;
    WeightedItem<T>* tmp = new WeightedItem<T>[capacity];

    // Copy the elements from data to tmp
    for (int i = 0; i < used; i++) {
        tmp[i] = data[i];
    }

    // Free old array and assign data the new array
    delete[] data;
    data = tmp;
}

template <class T>
void WCont<T>::add(const WeightedItem<T>& item, int index) {
    // Handle invalid index
    if (index < -1 || index > used) {
        return;
    }

    if (used == capacity) {
        resize();
    }


    // Add to end if index is not specified
    if (index == -1) {
        data[used] = item;
    }
    else {
        // Move all elements one to the right of index down by one
        for (int i = used; i > index + 1; i--) {
            data[i] = data[i - 1];
        }
        
        // Set the element at index+1 to the item
        data[index + 1] = item;
    }

    used++; // increment used
}

template <class T>
void WCont<T>::add(const T& data, const unsigned& weight, int index) {
    WeightedItem<T> item(data, weight);
    add(item, index);
}

template <class T>
void WCont<T>::insert(const WeightedItem<T>& item, int index) {
    // Handle invalid index
    if (index < -1 || index > used) {
        return;
    }
    
    if (used == capacity) {
        resize();
    }

    // Move elements from the specified index to the end over by one
    for (int i = used; i > index; i--) {
        data[i] = data[i - 1];
    }

    // Insert data and increment used
    data[index] = item;
    used++;
}

template <class T>
void WCont<T>::insert(const T& data, const unsigned& weight, int index) {
    WeightedItem<T> item(data, weight);
    insert(item, index);
}

template <class T>
int WCont<T>::size() const {
    return used;
}

template <class T>
WeightedItem<T>& WCont<T>::at(int index) const{
    return data[index];
}
#endif
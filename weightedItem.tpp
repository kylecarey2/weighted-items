#include "weightedItem.h"

template <class T>
WeightedItem<T>::WeightedItem(T d, unsigned value) {
    data = d;
    weight = value;
}

template <class T>
unsigned WeightedItem<T>::get_weight() const {
    return weight;
}

template <class T>
T WeightedItem<T>::get_data() const {
    return data;
}

template <class T>
void WeightedItem<T>::set_data(T d) {
    data = d;
}

template <class T>
void WeightedItem<T>::set_weight(unsigned value) {
    weight = value;
}

template <class T>
void WeightedItem<T>::add_weight(unsigned value) {
    weight += value;
}

template <class T>
void WeightedItem<T>::remove_weight(unsigned value) {
    if (weight < value) {
        weight = 0;
    }
    else {
        weight -= value;
    }
}

template <class T>
void WeightedItem<T>::input(std::istream& ins) {
    ins >> std::ws;
    ins >> data;
    ins >> std::ws;
    ins >> weight;
}

template <class T>
void WeightedItem<T>::output(std::ostream& outs) const {
    outs << data;
    outs << " - ";
    outs << weight;
}

template <class T>
WeightedItem<T>& WeightedItem<T>::operator=(const WeightedItem<T>& other) {
    data = other.data;
    weight = other.weight;
    return *this;
}

template <class T>
bool WeightedItem<T>::operator==(const WeightedItem<T>& other) const {
    return (data == other.data && weight == other.weight);
}

template <class T>
bool WeightedItem<T>::operator<(const WeightedItem<T>& other) const {
    return weight < other.weight;
}

// Non-member functions implementation
template <class T>
std::ostream& operator<<(std::ostream& outs, const WeightedItem<T>& item) {
    item.output(outs);
    return outs;
}

template <class T>
std::istream& operator>>(std::istream& ins, WeightedItem<T>& item) {
    item.input(ins);
    return ins;
}
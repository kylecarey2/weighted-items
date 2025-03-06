#ifndef WEIGHTEDITEM_H
#define WEIGHTEDITEM_H

template <class T>
class WeightedItem {
 public:
    /**
     * Function:    WeightedItem
     *              Default constructor, sets data to default constructor for data type and weight to 0
     *
     * @param d - data to store in container along with the weight
     * @param value- the amount of weight to give the object
     */
    WeightedItem(T d = T(), unsigned value = 0);

    // Getters
    /**
     * Function:    get_weight
     *              returns the weight of the object
     *
     * @return - the weight as an unsigned int
     */
    unsigned get_weight() const;

    /**
     * Function:    get_data
     *              returns the data that the weighted container is holding
     *
     * @param paramName - paramDescription
     * @return - the data stored in the weighted container
     */
    T get_data() const;

    // Setters
    /**
     * Function:    set_data
     *              set the data that is held in this weighted container
     *
     * @param d - the data to set to
     */
    void set_data(T d);

    /**
     * Function:    set_weight
     *              set the weight of the container
     *
     * @param value - the value to set the weight to
     */
    void set_weight(unsigned value);

    /**
     * Function:    add_weight
     *              add the value specified to the weight of the container
     *
     * @param value - the value to add to the weight
     */
    void add_weight(unsigned value);

    /**
     * Function:    remove_weight
     *              removes the specified value from the container's weight
     *
     * @param value - the value to remove from the weight of the container
     */
    void remove_weight(unsigned value);

 private:
    T data;           // data stored in container
    unsigned weight;  // weight of the container
};

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

#endif
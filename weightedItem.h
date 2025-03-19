#ifndef WEIGHTEDITEM_H
#define WEIGHTEDITEM_H

#include <iostream>

// Class declaration
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
    WeightedItem(T d = T(), unsigned value = 1);

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

    /**
     * Function:    input
     *              inputs the data and the weight separated by whitespace
     *
     * @param ins - input stream
     */
    void input(std::istream& ins);

    /**
     * Function:    output
     *              outputs the data and weight separated by a dash
     *
     * @param outs - output stream
     */
    void output(std::ostream& outs) const;

    /**
     * Function:    operator=
     *              assigns the same values of other to this current object
     *
     * @param other - right hand object
     * @return - WeightedItem object
     */
    WeightedItem<T>& operator=(const WeightedItem<T>& other);

    /**
     * Function:    operator==
     *              overloaded equality symbol, returns true if both data and weight are the same
     *
     * @param other - right hand side object
     * @return - bool
     */
    bool operator==(const WeightedItem<T>& other) const;

    /**
     * Function:    operator<
     *              returns a boolean of if the weight of the object on the left is less than the object on the right
     *
     * @param other - WeightedItem object on the right
     * @return - boolean
     */
    bool operator<(const WeightedItem<T>& other) const;

 private:
    T data;           // data stored in container
    unsigned weight;  // weight of the container
};

/**
 * Function:    operator<<
 *              overloaded << operator to output a WeightedItem with the data it holds then the weight
 *
 * @param outs - output stream
 * @param item - a WeightedItem
 * @return - output stream
 */
template <class T>
std::ostream& operator<<(std::ostream& outs, const WeightedItem<T>& item);

/**
 * Function:    operator>>
 *              overloaded >> operator to input data to the WeightedItem object
 *
 * @param ins - input stream
 * @param item - a WeightedItem
 * @return - input stream
 */
template <class T>
std::istream& operator>>(std::istream& ins, WeightedItem<T>& item);

#include "weightedItem.tpp"

#endif
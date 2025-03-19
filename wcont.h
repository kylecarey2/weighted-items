#ifndef WCONT_H
#define WCONT_H

#include "weightedItem.h"

// Class declaration
template <class T>
class WCont {
 public:
    // Big 4
    /**
     * Function:    WCont
     *              default constructor that creates the dynamic array
     */
    WCont();

    /**
     * Function:    WCont
     *              copy constructor performs deep copy on object passed in
     *
     * @param other - WCont object of the same type
     */
    WCont(const WCont<T>& other);

    /**
     * Function:    ~WCont
     *              destructor. Destroys all dynamic data
     *
     */
    ~WCont();

    /**
     * Function:    operator==
     *              performs a deep copy freeing any memory in the process and returns the new object
     *
     * @param other  - WCont object
     * @return - WCont object
     */
    WCont<T>& operator=(const WCont<T>& other);

    // Feature functions
    // Adding items
    /**
     * Function:    add
     *              adds the WeightedItem to the array at the index specified
     *
     * @param item - a WeightedItem object
     * @param index - the index to add the object to in the array
     * @return - void
     */
    void add(const WeightedItem<T>& item, int index = -1);

    /**
     * Function:    add
     *              adds the data and weight to the array as a WeightedItem after the index specified
     *
     * @param data - data of the specified datatype of the container
     * @param data - weight of the specified data
     * @param index - the index to add the object to in the array
     * @return - void
     */
    void add(const T& data, const unsigned& weight, int index = -1);

    /**
     * Function:    insert
     *              inserts the WeightedItem before the specified index
     *
     * @param item - a WeightedItem object
     * @param index - index to insert the object at
     * @return - void
     */
    void insert(const WeightedItem<T>& item, int index = 1);

    /**
     * Function:    insert
     *              inserts the data and weight as a WeightedItem before the specified index
     *
     * @param data - data of the specified datatype of the container
     * @param data - weight of the specified data
     * @param index - index to insert the object at
     * @return - void
     */
    void insert(const T& data, const unsigned& weight, int index = 1);

    // Remove items
    /**
     * Function:    remove
     *              removes the WeightedItem at the index specified
     *
     * @param index - the index to remove the object at
     * @return - void
     */
    void remove(int index);

    /**
     * Function:    remove
     *              removes the WeightedItem specifed from the container
     *
     * @param item - a WeightedItem object
     * @return - void
     */
    void remove(const WeightedItem<T>& item);

    /**
     * Function:    remove_all
     *              removes all instances of the WeightedItem from the container
     *
     * @param item - a WeightedItem object
     * @return - void
     */
    void remove_all(const WeightedItem<T>& item);

    /**
     * Function:    exists
     *              returns if the object exists in the container as a boolean
     *
     * @param item - a WeightedItem object
     * @return - bool
     */
    bool exists(const WeightedItem<T>& item) const;

    /**
     * Function:    exists
     *              returns if a object of the data and weight exists in the container as a boolean
     *
     * @param item - a WeightedItem object
     * @return - bool
     */
    bool exists(const T& data, const unsigned& weight) const;

    // Misc.

    /**
     * Function:    size
     *              returns how many items are in the container
     *
     * @return - size of container, as int
     */
    int size() const;

    /**
     * Function:    sort
     *              sorts all WeightedItems in the container from the least weight to the greatest weight
     */
    void sort();

    /**
     * Function:    shuffle
     *              shuffles the WeightedItems in the container into a random order.
     *              Uses the Fisher-Yates shuffle algorithm
     */
    void shuffle();

    /**
     * Function:    at
     *              returns the WeightedItem at the specified index. Returns out_of_range error if invalid index
     *
     * @param index - index of the container
     * @return - const WeightedItem&
     */
    const WeightedItem<T>& at(int index) const;

    /**
     * Function:    at
     *              returns the WeightedItem at the specified index. Returns out_of_range error if invalid index
     *
     * @param index - index of the container
     * @return - WeightedItem&
     */
    WeightedItem<T>& at(int index);

    // Randomize
    /**
     * Function:    randomize_this
     *              randomizes the container and edits it directly
     */
    void randomize_this();

    /**
     * Function:    randomize
     *              randomizes the container and returns a new WCont container that is randomized. Does not edit current container.
     *
     * @param paramName - paramDescription
     * @return - whatIsReturned
     */
    WCont<T> randomize() const;

 private:
    WeightedItem<T>* data;
    int used;
    int capacity;
    // int current_index;

    void resize();
};

#include "wcont.tpp"

#endif
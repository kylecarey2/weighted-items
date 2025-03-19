/**
 *        @file: main.cc
 *      @author: Kyle Carey
 *        @date: March 06, 2025
 *       @brief: Testing ground for the weighted containers
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>

#include "wcont.h"

/// function prototypes
/**
 * Function:    print
 *              prints the WCont to the terminal
 *
 * @param container - WCont container
 * @return - void
 */
template <class T>
void print(const WCont<T>& container);

/**
 * Function:    outputStats
 *              outputs the stats used of the test rand
 *
 * @param ous - output stream
 * @param container - WCont container
 * @param n - number of times to run the fuction that is being tested
 * @param specificValue - a specific value to output the results of. If not specified it will output all 
 * @return - void
 */
template <class T>
void outputStats(std::ostream& ous, WCont<T>& container, int n = 1000, T specificValue = T());

/**
 * Function:    loadContainer
 *              loads the container with the specified weight value and how many. Must change this function to work with other datatype
 *
 * @param container - WCont container to load to
 * @param weight - the weight of the objects to load 
 * @param n - number of objects to load 
 * @return - void
 */
template <class T>
void loadContainer(WCont<T>& container, int weight, int n = 100);

int main() {
    std::srand(time(NULL)); // must seed in main program
    WeightedItem<std::string> s1("Kyle", 25);
    WeightedItem<std::string> s2("Carter", 20);
    WeightedItem<std::string> s3("Cameron", 15);
    WeightedItem<std::string> s4("Ryan", 15);
    WeightedItem<std::string> s5("Michelle", 20);
    WeightedItem<std::string> s6("Milo", 10);

    WCont<std::string> container;
    loadContainer(container, 5, 5); // load container with objects of 5 weight

    // Add these objects to container
    container.add(s1); 
    container.add(s2);
    container.add(s6);

    // Output stats to terminal of 100 test of "Kyle"
    outputStats(std::cout, container, 100, std::string("Kyle"));

    return 0;
}  /// main

template <class T>
void print(const WCont<T>& container) {
    for (int i = 0; i < container.size(); i++) {
        std::cout << container.at(i) << "\n";
    }
}

template <class T>
void outputStats(std::ostream& ous, WCont<T>& container, int n, T specificValue) {
    std::map<T, std::map<int, int>> dataMap; // STRING - PLACE _ #

    // Initialize map
    for (int i = 0; i < container.size(); i++) {
        for (int j = 0; j < container.size(); j++) {
            dataMap[container.at(i).get_data()][j + 1] = 0;
        }
    }

    // Test and update map
    for (int i = 0; i < n; i++) {
        WCont<T> copy = container.randomize(); // member function to test
        // copy.shuffle();
        for (int j = 0; j < container.size(); j++) {
            dataMap[copy.at(j).get_data()][j + 1]++;
        }

        // Output to console where the processing is at 
        if (i % (n / 10) == 0) {
            std::cout << "Iteration " << i << "\n";
        }
    }

    // Output Map
    if (specificValue == T()) { // default constructor, output all values
        for (const auto& numberData : dataMap) {
            ous << numberData.first << ":\n";
            for (const auto& nums : numberData.second) {
                ous << "  " << nums.first << ": " << nums.second << "\n";
            }
        }
    }
    else { // output specific value
        if (dataMap.find(specificValue) != dataMap.end()) {
            ous << specificValue << ":\n";

            // Each time it is below 750 add to stats
            int count = 0;
            int occurrences = 0;
            for (const auto& nums : dataMap[specificValue]) {
                ous << "  " << nums.first << ": " << nums.second << "\n";
                occurrences += nums.second;
                count++;
                if (count == 750) {
                    break;
                }
            }

            // output to Terminal 
            std::cout << "# of first time slot: " << occurrences << " (" << (static_cast<double>(occurrences) / n) * 100 << "%)\n";
        }
        else {
            ous << "Key does not exist in container.\n";
        }
    }
}

template <class T>
void loadContainer(WCont<T>& container, int weight, int n) {
    // Create dummy WeightedItems and add them to the container
    std::cout << "Loading container...\n";
    for (int i = 0; i < n; i++) {
        WeightedItem<T> dummy("Person #" + std::to_string(i + 1), weight);
        container.add(dummy);
    }
}
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
// using namespace std;

/// function prototypes
template <class T>
void print(const WCont<T>& container);

template <class T>
void outputStats(std::ostream& ous, WCont<T>& container, int n = 1000);

int main() {
    std::srand(time(NULL));
    WeightedItem<std::string> s1("Kyle", 5);
    WeightedItem<std::string> s2("Carter", 1);
    WeightedItem<std::string> s3("Cameron", 1);
    WeightedItem<std::string> s4("Ryan", 1);
    WeightedItem<std::string> s5("Michelle", 1);
    WeightedItem<std::string> s6("Milo", 1);

    WCont<std::string> container;
    container.add(s1);
    container.add(s2);
    container.add(s3);
    container.add(s4);
    container.add(s5);
    container.add(s6);
    // print(container);
    // std::cout << "\n";
    // container.shuffle();
    // print(container);

    outputStats(std::cout, container, 100);



    return 0;
}  /// main

template <class T>
void print(const WCont<T>& container) {
    for (int i = 0; i < container.size(); i++) {
        std::cout << container.at(i) << "\n";
    }
}

template <class T>
void outputStats(std::ostream& ous, WCont<T>& container, int n) {
    std::map<T, std::map<int, int>> dataMap; // STRING - PLACE _ #

    // Initialize map
    for (int i = 0; i < container.size(); i++) {
        for (int j = 0; j < container.size(); j++) {
            dataMap[container.at(i).get_data()][j + 1] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        WCont<T> copy(container);
        copy.randomize_this();
        for (int j = 0; j < container.size(); j++) {
            dataMap[copy.at(j).get_data()][j + 1]++;
        }
    }

    // Output Map
    for (const auto& numberData : dataMap) {
        ous << numberData.first << ":\n";
        for (const auto& nums : numberData.second) { // Access the second element (the inner map)
            ous << "  " << nums.first << ": " << nums.second << "\n";
        }
    }
}
# Weighted-Items-And-Container

This project was made to help me create a random algorithm that included some weight to it. I started this to see how different weights on objects affected placements in an ordered list. This can be used to create a system that creates a randomized list that takes merit into account. I created a custom template class called WeightedItem that holds any datatype and a weight value to go along with it. Along with that, I created a dynamic array container (WCont) that stores WeightedItem objects with many member functions including some random functions to help my use case for this project. The only external library used for this was <iostream>. 

## Compilation

Compile the code using g++

```bash
g++ -c *.cc && g++ -Wall -std=c++11 *.o -o a.out
```
This creates an executable file called ./a.out. Alternatively you can name your executable to something more meaningful by substituting in your own name instead of a.out

## Usage
To use WeightedItem, you must declare it like any other template class.
```cpp
#include "WCont.h"
#include <string>

WeightedItem<std::string> item1;
WeightedItem<double> item2(24.5, 5); // Holds 24.5 with a weight of 5
item1.set_data("Hello World"); // Data it holds is "Hello World"
item1.set_weight(25); // Has a weight of 25
```
Full documentation and member functions can be found in weightedItem.h. Implementation can be found in weightedItem.tpp. Using these with wcont.h is easy. It can be done as shown in the code snippet below. NOTE: It is important to seed the random number generator in your main program if you want to use the randomization member functions on any WCont objects. 
```cpp
std::srand(time(NULL));
WeightedItem<std::string> item3("GoodBye World", 5);
WCont<std::string> container;
container.add(item1); // Adds item1 to container
container.add(item3); // Adds item3 to container
container.remove(item1); // Removes item1 from container
```
As before, the full member functions can be found in wcont.h with their implementation in wcont.tpp. It is important to use the same datatype of data in the WCont as you did in the WeightedItem. If you wish to use a std::vector or a std::list with the WeightedItems instead, you can do so. The WCont object was for me to practice with dynamic memory and to build my own custom member functions. 
```cpp
#include <list>

std::list<WeightedItem<std::string>> WeightedList; // Ensure that you still declare the datatype of the WeightedItem
``` 
You can also refer to the main.cc here to see how I used WeightedItem and WCont. 

Feel free to use this and modify the code in any way to suit your needs. This is an elementary project I created to test out a weighted-random algorithm and collect statistics on it but just wanted to show it on the GitHub in case it is useful to anyone in anyway. Also, reach out if you see any improvements that could be made. 
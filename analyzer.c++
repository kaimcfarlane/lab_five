#include <iostream>
#include "StringData.h"

// Worked with Kai McFarlane

// Searches a vector for element using a linear search
unsigned long long linearSearch(const std::vector<std::string>& data, const std::string& element) {
    for(unsigned long long i = 0; i < data.size(); i++) {
        if(data[i] == element) {
            return i;
        }
    }
    return -1;
}

// The binary search implementation from my python lab.
unsigned long long binarySearch(const std::vector<std::string>& data, const std::string& element) {
    // Setup
    unsigned long long current_start = 0;
    unsigned long long current_end = data.size();
    // Do the search
    while(current_end - current_start > 1) {
        unsigned long long half = (current_end - current_start) / 2;
        const std::string& current = data[half];
        if(element < current)
            current_end -= half;
        else if(element > current)
            current_start += half;
        else
            return half;
    }
    if(data[current_start] == element)
        return current_start;
    return -1;
}

// Used to test the different searches
// An integer of 1 means linear search, and 0 means binary search.
// Prints out information about the search too.
void testSearch(const std::vector<std::string> &data, const std::string& element, int search) {
    long long start = systemTimeNanoseconds();
    unsigned long long index = search ? linearSearch(data, element) : binarySearch(data, element);
    long long duration = systemTimeNanoseconds() - start;

    std::cout << (index == -1 ? "Did not find " : "Found ") << element
              << " at index " << (index == -1 ? -1 : index)  // I don't like the long number...
              << " in " << duration
              << " ns using " << (search ? "linear search" : "binary search")
              << "." << std::endl;
}

// The main function that runs on start
int main() {
    const std::vector<std::string>& data = getStringData();
    const std::string cases[] = {"not_here", "mzzzz", "aaaaa"};
    for(const std::string& element : cases) {
        testSearch(data, element, 1);
        testSearch(data, element, 0);
        std::cout << std::endl;
    }
    return 0;
}

// Kai McFarlane worked with Desperto Esperto

#include <iostream>
#include "StringData.h"
#include <string>
#include <vector>
using namespace std;

// Searches for target string with binary search
int binarySearch(std::vector<std::string> arr, string target)
{
    // Starts timer
    float start = systemTimeNanoseconds();
    // Initializes start, end, and middle pointers
    int lIdx = 0;
    int rIdx = arr.size();
    int mIdx = std::floor((lIdx + rIdx) / 2);
    // Loops while left pointer is less than right pointer
    while (lIdx < rIdx)
    {
        // If strings match then strings are the same, and returns index and stops timer
        if (arr[mIdx] == target)
        {
            float end = systemTimeNanoseconds();
            cout << "Time Taken: " << end - start << " seconds"
                 << "\n";
            return mIdx;
        }
        // If middle string is less than target, moves left pointer to middle, and gets new middle index
        else if (arr[mIdx] < target)
        {
            lIdx = mIdx;
            mIdx = std::floor((lIdx + rIdx) / 2);
            if (lIdx == mIdx)
            {
                lIdx++;
            }
        }
        // If middle string is more than target, moves right pointer to middle, and gets new middle index
        else
        {
            rIdx = mIdx;
            mIdx = std::floor((lIdx + rIdx) / 2);
            if (rIdx == mIdx)
            {
                rIdx--;
            }
        }
    }
    // Stops timer and returns -1 if string not found
    float end = systemTimeNanoseconds();
    cout << "Time Taken: " << start - end << " seconds"
         << "\n";
    return -1;
}

int linearSearch(std::vector<std::string> arr, string target)
{
    // Starts timer
    float start = systemTimeNanoseconds();
    // Iterates through vector until target fund and ends time
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == target)
        {
            float end = systemTimeNanoseconds();
            cout << "Time Taken: " << end - start << " seconds"
                 << "\n";
            return i;
        }
    }
    // Returns -1 if target not found
    float end = systemTimeNanoseconds();
    cout << "Time Taken: " << float(end - start) << " seconds"
         << "\n";
    return -1;
}

int main()
{
    // Gets strings dataset
    std::vector<std::string> data = getStringData();
    cout << "\n";
    // Prints out different searches and times
    cout << "Searching for 'not_here' with Linear Search \n";
    int index = linearSearch(data, "not_here");
    if (index == -1)
    {
        cout << "'not_here' not found, returning: -1 \n";
    }
    else
    {
        cout << "Linear Search of 'not_here returns index: " << index << "\n";
    }
    cout << "\n";
    cout << "Searching for 'not_here' with Binary Search"
         << "\n";
    index = binarySearch(data, "not_here");
    if (index == -1)
    {
        cout << "'not_here' not found, returning: -1 \n";
    }
    else
    {
        cout << "Linear Search of 'not_here' returns index: " << index << "\n";
    }
    cout << "\n";
    cout << "Searching for 'mzzzz' with Linear Search"
         << "\n";
    index = linearSearch(data, "mzzzz");
    if (index == -1)
    {
        cout << "'mzzzz' not found, returning: -1 \n";
    }
    else
    {
        cout << "Linear Search of 'mzzzz' returns index: " << index << "\n";
    }
    cout << "\n";
    cout << "Searching for 'mzzzz' with Binary Search"
         << "\n";
    index = binarySearch(data, "mzzzz");
    if (index == -1)
    {
        cout << "'mzzzz' not found, returning: -1 \n";
    }
    else
    {
        cout << "Linear Search of 'mzzzz' returns index: " << index << "\n";
    }
    cout << "\n";
    cout << "Searching for 'aaaaa' with Linear Search"
         << "\n";
    index = linearSearch(data, "aaaaa");
    if (index == -1)
    {
        cout << "'aaaaa' not found, returning: -1 \n";
    }
    else
    {
        cout << "Linear Search of 'aaaaa' returns index: " << index << "\n";
    }
    cout << "\n";
    cout << "Searching for 'aaaaa' with Binary Search"
         << "\n";
    index = binarySearch(data, "aaaaa");
    if (index == -1)
    {
        cout << "'aaaaa' not found, returning: -1 \n";
    }
    else
    {
        cout << "Linear Search of 'aaaaa' returns index: " << index << "\n";
    }
    return 0;
}
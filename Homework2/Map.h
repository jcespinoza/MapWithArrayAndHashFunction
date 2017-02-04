#ifndef MAP_H
#define MAP_H

#include <map>
#include <iostream>

using namespace std;

class Map
{
public:
    Map();
    void put(string key, int value);
    int get(string key);
    int hashFunction(string key, int rerun);
    bool exists(string key);
    void remove(string key);
private:
    string* keys;
    int* values;
    void initializeKeysArray(int size) const;
    bool isRemoved(int index);
};


#endif // MAP_H

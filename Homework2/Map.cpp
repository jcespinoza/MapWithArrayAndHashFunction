#include "Map.h"
#include <algorithm>

Map::Map()
{
    int size = 10000;
    keys = new string[size];
    values = new int[size];

    initializeKeysArray(size);
}

void Map::initializeKeysArray(int size) const {
    for(int i = 0; i < size; i++)
        keys[i] = "";
}

int Map::hashFunction(string key, int rerun)
{
    int sum = 0;
    for(int i=0;i<key.size();i++)
    {
        sum += key[i];
    }
    return sum + rerun;
}

void Map::put(string key, int value)
{
    int reRun = 0;
    int index;
    do
    {
        index = hashFunction(key, reRun);
        reRun++;
    }while(!isRemoved(index));

    keys[index] = key;
    values[index] = value;
}

int Map::get(string key)
{
    int reRun = 0;
    int index;
    do
    {
        index = hashFunction(key, reRun);
        reRun++;

    }while(keys[index] != key && !isRemoved(index) );

    if (isRemoved(index))
        return -1;

    return values[index];
}

bool Map::isRemoved(int index){
    return keys[index] == "" || keys[index] == "-1";
}

bool Map::exists(string key)
{
    int value = get(key);

    return value != -1;
}

void Map::remove(string key)
{
    int rerun = 0;
    int index;
    do
    {
        index = hashFunction(key, rerun);
        rerun++;

    }while(keys[index] != key && !isRemoved(index) );

    if(!isRemoved(index))
        keys[index] = "-1";
}
#include <bits/stdc++.h>
using namespace std;
#include "hash_map.h"
#include <cmath>

int hashing_function(float value, int capacity);

hash_map::hash_map(size_t capacity)
{
    _size = 0;
    _capacity = capacity;
    _head = new hash_list[capacity];
}

//
hash_map::hash_map(const hash_map &other)
{
    
    // create empty hashmap
    _size = 0;
    _capacity = other._capacity;
    _head = NULL;

    //get all element size
    int allsizes[other._capacity] = other.get_bucket_size();
    int totalsize = 0;
    for(int i = 0; i < other._capacity; i++)
    {
        totalsize += allsizes[i];
    }

    //get all keys
    int allkeys[totalsize] = other.get_all_keys();
    for(size_t i = 0; i < totalsize; i++)
    {
        int k = allkeys[i];
        int v = other.get_value(k);
        insert(k, (float)v);
    }

    return;
}

hash_map &hash_map::operator=(const hash_map &other)
{
    if(_head == other._head){
        return *this;
    }
    hash_map hm = other;
    return hash_map& hm;
}

void hash_map::insert(int key, float value)
{
    int i = hashing_function(key, _capacity); // get index
    _size -= _head[i].get_size();
    _head[i].insert(key, value);
    _size += _head[i].get_size();
}

std::optional<float> hash_map::get_value(int key) const
{
    int i = hashing_function(key, _capacity); // get index
    return _head[i].get_value(key);
}

bool hash_map::remove(int key)
{
    int i = hashing_function(key, _capacity);
    _size -= _head[i].get_size();
    bool isSuccessful = _head[i].remove(key);
    _size += _head[i].get_size();
    return isSuccessful;
}

size_t hash_map::get_size() const
{
    return _size;
}


size_t hash_map::get_capacity() const
{
    return _capacity;
}

void hash_map::get_all_keys(int *keys)
{   
    for (size_t i = 0; i < _capacity; i++)
    {   
        for (size_t j = 0; j < _head[i].get_size(); j++)
        {   
            std::optional<std::pair<int *, float *>> temp = _head[i].get_iter_value();
            keys[j] = temp.first;
            _head[i].increment_iter();
        }
        _head[i].reset_iter();
    }


void hash_map::get_bucket_sizes(size_t *buckets)
{
    for (size_t i = 0; i < _capacity; i++)
    {
        buckets[i] = _head[i].get_size();
    }
    return;
}

hash_map::~hash_map()
{
    free(_head);
}

// this is the hashing function
int hashing_function(float value, int capacity)
{
    return (int(abs(value)) % (capacity));
}
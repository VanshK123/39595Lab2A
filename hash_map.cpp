#include <bits/stdc++.h>
using namespace std;
#include "hash_map.h"
#include <cmath>

hash_map::hash_map(size_t capacity){
    size = 0;
    _capacity = capacity;
    head = NULL;
}

hash_map::hash_map(const hash_map &other){
    size = 0;
    capacity = 0;
    head = NULL;

}

hash_map::hash_map &operator=(const hash_map &other){
    
}

void hash_map::insert(int key, float value){

}

std::optional<float> hash_map::get_value(int key) const{

}

bool hash_map::remove(int key){
    
}

size_t hash_map::get_size() const{
    return _size;
}

 size_t hash_map::get_capacity() const{
    return _capacity;
 }

 void hash_map::get_all_keys(int* keys){

 }

void hash_map::get_bucket_sizes(size_t * buckets){

}

hash_map::~hash_map(){

}


//this is the hashing function
int hashing_function(float value, int capacity)
{
    return (abs(value)) % capacity;
}
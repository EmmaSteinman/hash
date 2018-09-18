//=============================================================================
//Lindsey Siegfried and Emma Steinman
//HashTable.h
//This file contains the function declarations for the HashTable class
//November 10, 2017
//=============================================================================

#include <iostream>
#include <stdlib.h>
//#include <string>
#include "List.h"
using namespace std;

//=============================================================================

#ifndef HASHTABLE_H
#define HASHTABLE_H


template <class KeyType>
class HashTable
{
public:
                        HashTable   (int numSlots);
                        HashTable   (const HashTable<KeyType>& h);
                        ~HashTable  (void);
    KeyType*            get         (const KeyType& k) const;
    void                insert      (KeyType *k);
    void                remove      (const KeyType& k);
    string              toString    (int slot) const;
    HashTable<KeyType>& operator=   (const HashTable<KeyType>& h);

private:
    int           slots;
    List<KeyType> *table; // an array of List<KeyType>’s
};

#include "HashTable.cpp"
#endif

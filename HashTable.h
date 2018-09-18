/*
* hash table class
* lindsey siegfried
* 6 november 2017
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "llist.h"
using namespace std;


template <class KeyType>
class HashTable
{
public:
                        HashTable     ( void );
                        HashTable     (int numSlots);
                        HashTable     (const HashTable<KeyType>& h);
                        ~HashTable    (void);
    KeyType*            get           (const KeyType& k) const;
    void                insert        (KeyType* k);
    void                remove        (const KeyType& k);
    string              toString      (int slot) const;
    bool                Empty         (void) const;
    HashTable<KeyType>& operator=     (const HashTable<KeyType>& h);



private:
    int           slots;
    List<KeyType> *table;


};


#endif
#include "HashTable.cpp"

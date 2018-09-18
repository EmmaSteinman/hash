#include <iostream>
#include <functional>
using namespace std;
#include "HashTable.h"

void test (void)
{
  HashTable<int> t;
  int x = 5;
  t.insert(&x);
}


int main (void)
{
  test();
}

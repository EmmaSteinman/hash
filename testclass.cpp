#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;
#include <math.h>
#include <string>
#include "HashTable.h"


/*
* test class
* this is a class to test our hash table
*/

class test
{
public:
  int key;

  test(void){key = 0;};       //default constructor
  test(int k){key = k;};      //specified int constructor
  ~test(void){};              //destructor
  string toString(void)       //toString
  {
    return to_string(key);
  };

  int hash ( int slots ) const    //lame hash table
  {
    int hval = (key*3)%slots;
    return hval;
  }
  bool operator< ( test& a) const     //overloaded operators
  {
    return this->key < a.key;
  };
  bool operator> (const test& a)           //overloading comparison operators
  {                                         //to compare key specifically
    return this->key > a.key;
  };
  bool operator== (const test& a)
  {
    return this->key == a.key;
  };
  bool operator!= (const test& a)
  {
    return this->key != a.key;
  };
  friend ostream& operator<<(ostream& os, const test& m)    //cout
  {
  	os << m.key;
  	return os;
  }
};

//testing default constructor
void testDefaultConstructor()
{
  HashTable<test> t1;
  assert(t1.Empty()==1);
}

//test specified slots constructor
void testConstructor()
{
  HashTable<test> t1(10);
  assert(t1.Empty()==0);      //not empty because it has 10 slots
}


//testing the copy constructor
void testCopyConstructor()
{
  HashTable<test> t1(10);
  HashTable<test> t2(t1);
  assert(t2.Empty()==0);    //same as previous test
}
//testing insert method
void testInsert1()
{
  HashTable<test> t1(100);
  test *t = new test;
  t->key = 5;
  t1.insert(t);
  assert((t1.toString(t->hash(100))=="5 "));
}

//testing many inserts
void testInsert2()
{
  HashTable<test> t1=HashTable<test>(10);
  test *a = new test;
  a->key = 5;
  test *b = new test;
  b->key = 20;
  test *c = new test;
  c->key = 9;
  test *d = new test;
  d->key = 2;
  test *e = new test;
  e->key = 8;
  test *f = new test;
  f->key = 10;
  test *g = new test;
  g->key = 22;
  t1.insert(a);
  t1.insert(b);
  t1.insert(c);
  t1.insert(d);
  t1.insert(e);
  t1.insert(f);
  t1.insert(g);
  assert((t1.toString(d->hash(10))=="22 2 "));
}

//testing get
void testGet()
{
  HashTable<test> t1(100);
  test *t = new test;
  t->key = 5;
  t1.insert(t);
  //cout << t->key << endl;
  test *s = t1.get(t->key);
  assert(s->key==5);
}

//testing get on something that is not in the HT
void testGetNotThere()
{
  HashTable<test> t1=HashTable<test>(10);
  test *a = new test;
  a->key = 5;
  test *b = new test;
  b->key = 20;
  test *c = new test;
  c->key = 9;
  test *d = new test;
  d->key = 2;
  test *e = new test;
  e->key = 8;  t1.insert(a);
  t1.insert(b);
  test *f = new test;
  f->key = 10;
  test *g = new test;
  g->key = 22;
  t1.insert(a);
  t1.insert(b);
  t1.insert(c);
  t1.insert(d);
  t1.insert(e);
  t1.insert(f);
  //t1.insert(g);

  test* x = t1.get(g->key);
  assert(x == 0);
}

//testing assignment operator
void testAsst()
{
  HashTable<test> t1 = HashTable<test>(10);
  test *a = new test;
  a->key = 5;
  test *b = new test;
  b->key = 20;
  t1.insert(a);
  t1.insert(b);

  HashTable<test> t2 = t1;
  test* t1a = t1.get(a->key);
  test* t2a = t2.get(a->key);

  assert(t1a->key == t2a->key);
}

//testing removal of something that is not there
void isItThere()
{
  HashTable<test> t1 = HashTable<test>(10);
  test *a = new test;
  a->key = 5;
  test *b = new test;
  b->key = 20;

  t1.insert(a);
  t1.remove(b->key);
}

//testing regular removal
void testRemove()
{
  HashTable<test> t1 = HashTable<test>(10);
  test *a = new test;
  a->key = 5;
  test *b = new test;
  b->key = 20;

  t1.insert(a);
  t1.insert(b);
  t1.remove(b->key);
  test* x = t1.get(b->key);
  assert(x == 0);
}



int main ( void )
{
  testConstructor();
  testCopyConstructor();
  testInsert1();
  testInsert2();

  testGet();
  testGetNotThere();
  testAsst();
  isItThere();

  testRemove();

  return 0;
}

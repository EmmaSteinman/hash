//Hannah Kerr and Emma Steinman
//test file for bst


#include <iostream>
#include <assert.h>
#include "bst.h"
using namespace std;

//------------------------------------------------------------------------
// defConst
// tests default constructor
//------------------------------------------------------------------------
int defConst(void)
{
    BST<int> t;
    //cout << t << endl;
    assert(t.inOrder() == "Empty tree");
}
//------------------------------------------------------------------------
// testInsert
// tests insert
//------------------------------------------------------------------------
int testInsert (void)
{
  BST<int> t;
  int x = 2;
  t.insert(&x);
  int y = 9;
  t.insert(&y);
  int z = 5;
  t.insert(&z);
  int a = 1;
  t.insert(&a);
  assert(t.inOrder() == "1 2 5 9");
}
//------------------------------------------------------------------------
// copyConst
// tests copy constructor
//------------------------------------------------------------------------
int copyConst (void)
{
  BST<int> t;
  int x = 2;
  t.insert(&x);
  int y = 9;
  t.insert(&y);
  int z = 5;
  t.insert(&z);
  int a = 1;
  t.insert(&a);

  BST<int> t2(t);
  assert(t2.inOrder() == "1 2 5 9");
}
//------------------------------------------------------------------------
// testEmpty
// tests if bst is empty
//------------------------------------------------------------------------
int testEmpty(void)
{
  BST<int> t1;
  BST<int> t2;
  int a = 1;
  int b = 4;
  int c = 7;
  t2.insert(&a);
  t2.insert(&b);
  t2.insert(&c);

  assert(t1.Empty() == 1);
  assert(t2.Empty() == 0);
}
//------------------------------------------------------------------------
// testGet
// tests get function
//------------------------------------------------------------------------
int testGet(void)
{
  BST<int> t1;
  int a = 1;
  int b = 4;
  int c = 7;
  t1.insert(&a);
  t1.insert(&b);
  t1.insert(&c);
  int* g = t1.get(4);
  assert(*g == 4);
}
//------------------------------------------------------------------------
// testRemove
// tests remove
//------------------------------------------------------------------------
int testRemove(void)
{
  BST<int> t;
  int x = 2;
  t.insert(&x);
  int y = 9;
  t.insert(&y);
  int z = 5;
  t.insert(&z);
  int a = 1;
  t.insert(&a);
  int b = 15;
  int c = 4;
  int d = 10;
  int e = 20;
  t.insert(&b);
  t.insert(&c);
  t.insert(&d);
  t.insert(&e);

  t.remove(1);
  assert(t.inOrder() == "2 4 5 9 10 15 20");
  t.insert(&a);
  t.remove(5);
  assert(t.inOrder() == "1 2 4 9 10 15 20");
  t.insert(&z);
  t.remove(9);
  assert(t.inOrder() == "1 2 4 5 10 15 20");
}
//------------------------------------------------------------------------
// testMax
// tests maximum
//------------------------------------------------------------------------
void testMax(void)
{
  BST<int> t;
  int x = 2;
  t.insert(&x);
  int y = 9;
  t.insert(&y);
  int z = 5;
  t.insert(&z);
  int a = 1;
  t.insert(&a);
  int b = 15;
  int c = 4;
  int d = 10;
  int e = 20;
  t.insert(&b);
  t.insert(&c);
  t.insert(&d);
  t.insert(&e);
  assert(*(t.maximum()) == 20);
}

//------------------------------------------------------------------------
// testMin
// tests minimum
//------------------------------------------------------------------------
void testMin(void)
{
  BST<int> t;
  int x = 2;
  t.insert(&x);
  int y = 9;
  t.insert(&y);
  int z = 5;
  t.insert(&z);
  int a = 1;
  t.insert(&a);
  int b = 15;
  int c = 4;
  int d = 10;
  int e = 20;
  t.insert(&b);
  t.insert(&c);
  t.insert(&d);
  t.insert(&e);
  assert(*(t.minimum()) == 1);
}

//------------------------------------------------------------------------
// testSuccessor
// tests successor method
//------------------------------------------------------------------------
void testSuccessor (void)
{
  BST<int> t;
  int x = 2;
  t.insert(&x);
  int y = 9;
  t.insert(&y);
  int z = 5;
  t.insert(&z);
  int a = 1;
  t.insert(&a);
  int b = 15;
  int c = 4;
  int d = 10;
  int e = 20;
  t.insert(&b);
  t.insert(&c);
  t.insert(&d);
  t.insert(&e);
  assert(*(t.successor(9)) == 10);
  assert(*(t.successor(1)) == 2);
}

//------------------------------------------------------------------------
// testPred
// tests predecessor function
//------------------------------------------------------------------------
void testPred (void)
{
  BST<int> t;
  int x = 2;
  t.insert(&x);
  int y = 9;
  t.insert(&y);
  int z = 5;
  t.insert(&z);
  int a = 1;
  t.insert(&a);
  int b = 15;
  int c = 4;
  int d = 10;
  int e = 20;
  t.insert(&b);
  t.insert(&c);
  t.insert(&d);
  t.insert(&e);
  assert(*(t.predecessor(15)) == 10);
  assert(*(t.predecessor(9)) == 5);
}

//------------------------------------------------------------------------
// testPre
// tests pre-order
//------------------------------------------------------------------------
void testPre (void)
{
  BST<int> t;
  int x = 2;
  t.insert(&x);
  int y = 9;
  t.insert(&y);
  int z = 5;
  t.insert(&z);
  int a = 1;
  t.insert(&a);
  int b = 15;
  int c = 4;
  int d = 10;
  int e = 20;
  t.insert(&b);
  t.insert(&c);
  t.insert(&d);
  t.insert(&e);
  string pre = t.preOrder();
  assert(pre == "2 1 9 5 4 15 10 20");
}
//------------------------------------------------------------------------
// testPost
// tests post-order
//------------------------------------------------------------------------
void testPost (void)
{
  BST<int> t;
  int x = 2;
  t.insert(&x);
  int y = 9;
  t.insert(&y);
  int z = 5;
  t.insert(&z);
  int a = 1;
  t.insert(&a);
  int b = 15;
  int c = 4;
  int d = 10;
  int e = 20;
  t.insert(&b);
  t.insert(&c);
  t.insert(&d);
  t.insert(&e);
  string post = t.postOrder();
  assert(post == "1 4 5 10 20 15 9 2");
}
//------------------------------------------------------------------------
// testEqOp
// tests assignment operator
//------------------------------------------------------------------------
void testEqOp(void)
{
  BST<int> t;
  int x = 2;
  t.insert(&x);
  int y = 9;
  t.insert(&y);
  int z = 5;
  t.insert(&z);
  int a = 1;
  t.insert(&a);
  int b = 15;
  int c = 4;
  int d = 10;
  int e = 20;
  t.insert(&b);
  t.insert(&c);
  t.insert(&d);
  t.insert(&e);

  BST<int> t2;
  t2 = t;
  assert(t2.inOrder() == t.inOrder());
}
int main(void)
{
  defConst();
  testInsert();
  copyConst();
  testGet();
  testRemove();
  testMax();
  testMin();
  testSuccessor();
  testPred();
  testPre();
  testEqOp();
  return 0;
}

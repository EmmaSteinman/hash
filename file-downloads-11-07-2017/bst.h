//------------------------------------------------------------------------
// Hannah Kerr and Emma Steinman
//bst.h
//method declarations for the bst class
//November 1, 2017
//------------------------------------------------------------------------


#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
using namespace std;
// ===========================================================
#ifndef BST_H
#define BST_H

template <class KeyType>
struct Node
{
    KeyType *data;
    Node *  left;
    Node *  right;

};

template <class KeyType>
class BST
{
protected:
  string          inHelper      (Node<KeyType> * r, stringstream &s)const;
  string          preHelper     (Node<KeyType> * r, stringstream &s) const;
  string          postHelper    (Node<KeyType> * r, stringstream &s) const;
  Node<KeyType>*  find           (Node<KeyType> *ptr, KeyType item) const;
  Node<KeyType>   *copy       (Node<KeyType> *ptr);
  Node<KeyType>   *findParent	(Node<KeyType> *, KeyType item) const;
  void            clear       (Node<KeyType> *&ptr );
public:
    Node<KeyType> * root;        // root pointer for binary search tree
                BST         (void);
               ~BST         (void);
                BST         (const BST<KeyType> & );

    bool        Empty       (void) const;
    KeyType     *get        (const KeyType& k);
    void        insert      (KeyType *k);
    void        remove      (const KeyType& k);
    KeyType     *maximum    (void) const;
    KeyType     *minimum    (void) const;
    KeyType     *successor  (const KeyType& k) const;
    KeyType     *predecessor(const KeyType& k) const;
    string      inOrder     (void) const;
    string      preOrder    (void) const;
    string      postOrder   (void) const;

    BST<KeyType>    operator=   (const BST<KeyType> &ptr);

    friend ostream & operator<< ( ostream &os, const BST<KeyType> &bst )
    {
        os << bst.inOrder();
        return os;
    };
};
#include "bst.cpp"
#endif

//
// Created by ioana-adriana on 4/23/2016.
//

#ifndef LAB8_BINARYSEARCHTREE_H
#define LAB8_BINARYSEARCHTREE_H

#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;

    Node(const T& data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

template <typename T>
class BinarySearchTree
{
    Node<T> *root;
    int nodeCount;

    void inOrderDisplayGivenNode(Node<T> *node)
    {
        if(node == NULL)
            return;
        inOrderDisplayGivenNode(node->left);
        std::cout << node->data << " ";
        inOrderDisplayGivenNode(node->right);
    }

    Node<T>* findInOderSuccesor(Node<T> *node)
    {
      Node<T> *current = node->right;
      if(current == NULL)
        return node;
      while(current->left != NULL)
      {
        current = current->left;
      }
      return current;

    }

    bool deleteKeyStartingFromNode(Node<T> *parent, Node<T> *current, const T& x)
    {
      if(current == NULL)
        return false;
      else
      {
        if(current->data == x)
        {
          if(current->left == NULL || current->right == NULL) //1 or 0 kids
          {
            Node<T> *temp = current->right ? current->right : current->left;
            if(parent)
            {
              if(current == parent->left)
                parent->left = temp;
              else
                parent->right = temp;
            }
            else
              root = temp;
          }
          else
          {
            Node<T> *succesor = this->findInOderSuccesor(current);
            std::swap(succesor->data, current->data);
            return deleteKeyStartingFromNode(current, current->right, succesor->data);
          }
          delete current;
          nodeCount--;
          return true;
        }
        return deleteKeyStartingFromNode(current, current->left, x) ||
          deleteKeyStartingFromNode(current, current->right, x);
      }
    }

    void recursiveDelete(Node<T> *current)
    {
      if (current == NULL)
        return;
      recursiveDelete(current->left);
      recursiveDelete(current->right);
      delete current;
    }

public:
    BinarySearchTree() {
        root = NULL;
        nodeCount = 0;
    }
    ~BinarySearchTree() {
        this->recursiveDelete(root);
    }

    bool isEmpty() {
        return (root == NULL);
    }

    void insertKey(const T& x) {
        if (root == NULL)
        {
            root = new Node<T>(x);
            nodeCount++;
        }
        else
        {
            Node<T>* current = root;
            Node<T> *parent = NULL;
            while(current != NULL)
            {
                parent = current;
                if(x < current->data)
                {
                    parent = current;
                    current = current->left;
                }
                else
                {
                    parent = current;
                    current = current->right;
                }
            }
            if(x < parent->data)
            {
              parent-> left = new Node<T>(x);
              nodeCount++;
            }
            else
            {
              parent->right = new Node<T>(x);
              nodeCount++;
            }

        }
    }

    Node<T>* searchKey(const T& x) {
        Node<T> *current = root;
        while(current != NULL && current->data != x)
        {
            if(x < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return current;
    }



    void inOrderDisplay()
    {
        inOrderDisplayGivenNode(root);
        std::cout<< std::endl;
    }

    int nodesCount()
    {
      return nodeCount;
    }

    T findMin()
    {
        Node<T> *current = root;
        while(current->left != NULL)
        {
            current = current->left;
        }

        return current->data;
    }

    T findMax()
    {
        Node<T> *current = root;
        while(current->right != NULL)
        {
            current = current->right;
        }

        return current->data;
    }

    bool deleteKey(const T& x)
    {
      return this->deleteKeyStartingFromNode(NULL, root, x);
    }

};


#endif //LAB8_BINARYSEARCHTREE_H

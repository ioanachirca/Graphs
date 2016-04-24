//
// Created by ioana-adriana on 4/23/2016.
//
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "BinarySearchTree.h"


int main(){
  BinarySearchTree<int> *bst = new BinarySearchTree<int>();
  std::ifstream in("bst.in");

  int nNumbers,key;
  in>>nNumbers;
  for (int i = 0; i < nNumbers; i++)
  {
      in>>key;;
      bst->insertKey(key);
  }
  in.close();

  bst->inOrderDisplay();
  std::cout<< bst->findMin() <<std::endl;
  std::cout<< bst->findMax() <<std::endl;

  key = 45;
  if(bst->searchKey(key) != NULL)
    std::cout << "Key " << key << " found." << std::endl;
  else
    std::cout << "Key " << key << " not found." << std::endl;

  bst->deleteKey(45);
  bst->inOrderDisplay();
  bst->deleteKey(90);
  bst->inOrderDisplay();
  std::cout << bst->nodesCount() << std::endl;
  delete bst;
  return 0;
}

//
// Created by ioana-adriana on 5/1/2016.
//

#include<iostream>
#include "Heap.h"

using namespace std;

int main(){
    Heap<int, Min<int> > heap; // Heap<int, Max<int> > heap; also works
    srand(time(0));
    for (int i = 0; i < 10; i++)
        heap.insert(rand() % 20);
    cout << "Size: " << heap.size() << endl;
    heap.print();

    heap.pop();
    cout << "Size: " << heap.size() << endl;
    heap.print();
    cout << heap.peek() << endl;

    for(int i = 0; i < 9; i++) {
        heap.pop();
        heap.print();
    }
    cout << "Size: " << heap.size() << endl;
    heap.insert(rand() % 20);
    heap.print();
    heap.pop();
    //heap.pop();
    return 0;

}
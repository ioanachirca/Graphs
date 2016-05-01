//
// Created by ioana-adriana on 5/1/2016.
//

#ifndef LAB8_HEAP_H
#define LAB8_HEAP_H

#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

template <typename T>
class Min{
public:
    bool operator () (const T& val1, const T& val2){
        return val1 < val2;
    }
};

template <typename T>
class Max{
public:
    bool operator () (const T& val1, const T& val2){
        return val1 > val2;
    }

};

template <typename T, class Comp>
class Heap{
public:
    Heap () {}

    int size(){
        return array.size();
    }

    void insert(const T& val){
        array.push_back(val);
        bubbleUp();
    }

    void pop(){
        if(array.size() == 0)
            throw runtime_error("ERROR: pop() called on empty heap.");
        if (array.size() == 1)
            array.pop_back();
        else{
            swap(array[0], array[array.size()-1]);
            array.pop_back();
            bubbleDown();
        }

    }

    T peek(){
        if (array.size() == 0){
            throw runtime_error("ERROR: peek() called on empty head.");
        }
        return array[0];
    }

    void print(){
        cout << "Elements: " << endl;
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
        cout << endl;
    }


private:
    vector<T> array;
    Comp compare;

    int rightIndex(int index){
        return 2*index + 2;
    }

    int leftIndex(int index){
        return 2*index + 1;
    }

    int parentIndex(int index){
        if(index % 2 == 0)
            return (index-1)/2;
        else
            return index/2;
    }

    void bubbleUp(){
        int i = array.size() - 1;
        //check if parent doesn't satisfy heap condition
        while(i != 0 && !compare(array[parentIndex(i)], array[i])){
            swap(array[i], array[parentIndex(i)]);
            i = parentIndex(i);
        }
    }

    void bubbleDown() {
        int i = 0;
        while (1) {
            int temp = i;
            //check if right son doesn't satisfy heap condition
            if (rightIndex(i) < array.size() && compare(array[rightIndex(i)], array[i]))
                temp = rightIndex(i);
            //check if left son doesn't satisfy heap condition / is affected by swap
            if (leftIndex(i) < array.size() && compare(array[leftIndex(i)], array[temp]))
                temp = leftIndex(i);


            if (temp != i) {
                swap(array[temp], array[i]);
                i = temp;
            }

            else
                break;
        }
    }

};


#endif //LAB8_HEAP_H

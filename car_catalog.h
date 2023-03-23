#pragma once

#include <iostream>
#include "car.h"

class CarCatalog {
public:
	static constexpr int MAX_HEAP_SIZE = 32; //size of heap
	CarCatalog() {m_size = 0;} //constructor

	void insert(Car c);
	bool erase(Car c);
	void display();
private:
	Car m_catalog[MAX_HEAP_SIZE];
    int m_size = 0;

	void min_heapify(int heap_size, int i); 
	void heapsort();
};


void CarCatalog::insert(Car a) { //insert method
    m_catalog[m_size++] = a;
}

bool CarCatalog::erase(Car a) { //erase method from m_catalog
    for (int i = 0; i < m_size; i++) {
        if (m_catalog[i] == a) {
            std::swap(m_catalog[i], m_catalog[m_size - 1]);
            m_catalog[m_size - 1] = Car();
            m_size--;
            return true;
        }
    }
    return false;
}

void CarCatalog::display() {
    cout << m_size << endl;
    heapsort();
    for (int i = m_size - 1; i >= 0; i--) {
        
        m_catalog[i].displayCarNamePower();
        cout << endl;
    }
}
void CarCatalog::heapsort() { //heapsort
    // build min heap
	int heap_size = m_size;
    for (int i = m_size - 1; i >= 0; i--) 
        min_heapify(heap_size, i);

    for (int i = m_size - 1; i > 0; i--) {
        std::swap(m_catalog[0], m_catalog[i]);
        heap_size--;
        min_heapify(heap_size, 0);
    }
}

void CarCatalog::min_heapify(int heap_size, int i) {
    int l = i*2 + 1;//left child index
    int r = i*2 + 2;//right child index 
    int smallest = i;
    if (l < heap_size && m_catalog[l] < m_catalog[smallest]) smallest = l;
    if (r < heap_size && m_catalog[r] < m_catalog[smallest]) smallest = r;
    if (smallest != i) {
        std::swap(m_catalog[i], m_catalog[smallest]);   
        min_heapify(heap_size, smallest);
    }
}

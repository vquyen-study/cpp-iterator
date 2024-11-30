#ifndef _XNS_FIXSIZEARRAY_H
#define _XNS_FIXSIZEARRAY_H 1

#include <stddef.h>
#include "xns_iterator.h"

namespace xns {

template<typename T>
class FixedSizeArray{
    using Pointer = T*;
    private:

    private:
        Pointer m_data;
        size_t m_capacity;
    public:
        typedef xns::__normal_iterator<Pointer, FixedSizeArray> iterator;

        FixedSizeArray(int capacity) : m_capacity(capacity){
            m_data = new T[capacity];
        }
        ~FixedSizeArray(){
            if(nullptr != m_data){
                delete[] m_data;
                m_data = nullptr;
            }
        }

        T& operator[](size_t index){
            return m_data[index];
        }
        size_t capacity(){
            return m_capacity;
        }

        iterator begin(){
            return iterator(&m_data[0]);
        }
        iterator end(){
            return iterator(&m_data[m_capacity]);
        }
};

}

#endif
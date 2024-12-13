#ifndef _XNS_FIXSIZEARRAY_H
#define _XNS_FIXSIZEARRAY_H 1

#include <stddef.h>
#include "xns_iterator.h"

namespace xns {

template<typename T>
class FixedSizeArray{
    using Pointer = T*;

    private:
        Pointer m_data;
        Pointer m_end_of_storage;
        size_t m_capacity;
    public:
        typedef xns::__normal_iterator<Pointer, FixedSizeArray> iterator;
        typedef T                       value_type;
        typedef size_t                  size_type;
        FixedSizeArray(int capacity) : m_capacity(capacity){
            m_data = new T[capacity];
        }
        ~FixedSizeArray(){
            if(nullptr != m_data){
                delete[] m_data;
                m_data = nullptr;
            }
        }

        FixedSizeArray(std::initializer_list<value_type> __l){
            m_capacity = xns::distance(__l.begin(), __l.end());
            m_data = new value_type[m_capacity];

            m_end_of_storage = m_data + m_capacity;
            std::copy_n( __l.begin(), m_capacity, m_data );
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

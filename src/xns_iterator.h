#ifndef _XNS_ITERATOR_H
#define _XNS_ITERATOR_H 1

#include "iterator-types.h"

namespace xns {

using xns::iterator_traits;

template<typename _Iterator, typename _Container>
class __normal_iterator{
    protected:
        _Iterator _M_current;
        typedef iterator_traits<_Iterator>    __traits_type;
    public:
        typedef _Iterator					                iterator_type;
        typedef typename __traits_type::iterator_category   iterator_category;
        typedef typename __traits_type::value_type  	    value_type;
        typedef typename __traits_type::difference_type 	difference_type;
        typedef typename __traits_type::reference 	        reference;
        typedef typename __traits_type::pointer   	        pointer;

        __normal_iterator() : _M_current(iterator_type()) { }
        
        explicit
        __normal_iterator(const iterator_type& __i) : _M_current(__i) { }

        __normal_iterator operator++(){
            ++_M_current;
            return *this;
        }
        __normal_iterator operator++(int){
            return __normal_iterator(_M_current++);
        }

        friend bool operator==(const __normal_iterator& __lhs, const __normal_iterator& __rhs){
            return __lhs._M_current == __rhs._M_current;
        }
        
        friend bool operator!=(const __normal_iterator& __lhs, const __normal_iterator& __rhs){
            return __lhs._M_current != __rhs._M_current;
        }
        reference operator*() const{
            return *_M_current;
        }
        pointer operator->() const{ 
            return _M_current; 
        }

        difference_type operator-(const __normal_iterator& b) const{
            return (_M_current - b._M_current);
        }
    };
}

#endif
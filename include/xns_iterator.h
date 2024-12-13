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

        bool operator<(const __normal_iterator& b){
            return _M_current != b._M_current;
        }

        __normal_iterator& operator+=(difference_type __n){
            _M_current += __n; return *this;
        }
    };
///@{ begin  implement the distance oepration for iterator.

template<typename _input_iterator>
inline typename iterator_traits<_input_iterator>::difference_type
__distance(_input_iterator __first, _input_iterator __last, input_iterator_tag)
{
    typename iterator_traits<_input_iterator>::difference_type __n = 0;
    while (__first != __last) {
        ++__first;
        ++__n;
    }
    return __n;
}

template<typename _random_access_iterator>
inline typename iterator_traits<_random_access_iterator>::difference_type
__distance(_random_access_iterator __first,
           _random_access_iterator __last,
           random_access_iterator_tag)
{
    return __last - __first;
}

template<typename _iterator_type>
inline typename iterator_traits<_iterator_type>::difference_type
distance(_iterator_type __first, _iterator_type __last)
{
    return __distance(__first, __last, xns::__iterator_category(__first));
}
/// @} end
/// @{ begin implement the advance operation for iterator.
template<typename _InputIterator, typename _Distance>
inline void
__advance(_InputIterator& __i, _Distance __n, input_iterator_tag)
{
    // concept requirements
    while (__n--)
        ++__i;
}

template<typename _BidirectionalIterator, typename _Distance>
inline void
__advance(_BidirectionalIterator& __i, _Distance __n,
          bidirectional_iterator_tag)
{
    // concept requirements

    if (__n > 0)
        while (__n--)
            ++__i;
    else
        while (__n++)
            --__i;
}

template<typename _RandomAccessIterator, typename _Distance>
inline void
__advance(_RandomAccessIterator& __i, _Distance __n,
          random_access_iterator_tag)
{
    // concept requirements
    __i += __n;
}

/**
 *  @brief A generalization of pointer arithmetic.
 *  @param  __i  An input iterator.
 *  @param  __n  The @a delta by which to change @p __i.
 *  @return  Nothing.
 *
 *  This increments @p i by @p n.  For bidirectional and random access
 *  iterators, @p __n may be negative, in which case @p __i is decremented.
 *
 *  For random access iterators, this uses their @c + and @c - operations
 *  and are constant time.  For other %iterator classes they are linear time.
*/
template<typename _InputIterator, typename _Distance>
inline void
advance(_InputIterator& __i, _Distance __n)
{
    // concept requirements -- taken care of in __advance
    typename iterator_traits<_InputIterator>::difference_type __d = __n;
    xns::__advance(__i, __d, xns::__iterator_category(__i));
}
/// @} end
/// @{ begin implement the next/pre operation for iterator.
template<typename _ForwardIterator>
inline _ForwardIterator
next(_ForwardIterator __x, typename
     iterator_traits<_ForwardIterator>::difference_type __n = 1)
{
    xns::advance(__x, __n);
    return __x;
}

template<typename _BidirectionalIterator>
inline _BidirectionalIterator
prev(_BidirectionalIterator __x, typename
     iterator_traits<_BidirectionalIterator>::difference_type __n = 1)
{
    xns::advance(__x, -__n);
    return __x;
}




/// @} end

}

#endif

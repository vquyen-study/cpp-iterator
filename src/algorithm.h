#ifndef _ALGORITHM_H
#define _ALGORITHM_H 1

#include <cstddef>
#include "iterator-types.h"

using xns::iterator_traits;

namespace xns {

/**
 *  @brief Count the number of copies of a value in a sequence.
 *  @ingroup non_mutating_algorithms
 *  @param  __first  An input iterator.
 *  @param  __last   An input iterator.
 *  @param  __value  The value to be counted.
 *  @return   The number of iterators @c i in the range @p [__first,__last)
 *  for which @c *i == @p __value
*/
template<typename _InputIterator, typename _Tp>
inline typename iterator_traits<_InputIterator>::difference_type
count(_InputIterator __first, _InputIterator __last, const _Tp& __value)
{
    typename iterator_traits<_InputIterator>::difference_type __n = 0;
    for (; __first != __last; ++__first)
        if (__pred(__first))
            ++__n;
    return __n;
}

}


#endif

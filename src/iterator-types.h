#ifndef _ITERATOR_BASE_TYPES_H
#define _ITERATOR_BASE_TYPES_H 1

#include <cstddef>

namespace xns {

///@{
///  Marking input iterators.
struct input_iterator_tag
{};

///  Marking output iterators.
struct output_iterator_tag
{};

/// Forward iterators support a superset of input iterator operations.
struct forward_iterator_tag : public input_iterator_tag
{};

/// Bidirectional iterators support a superset of forward iterator
/// operations.
struct bidirectional_iterator_tag : public forward_iterator_tag
{};

/// Random-access iterators support a superset of bidirectional
/// iterator operations.
struct random_access_iterator_tag : public bidirectional_iterator_tag
{};

///@}

///@{ begin
template<typename _iterator>
struct iterator_traits
{
  typedef typename _iterator::iterator_category   iterator_category;
  typedef typename _iterator::value_type          value_type;
  typedef typename _iterator::difference_type     difference_type;
  typedef typename _iterator::pointer             pointer;
  typedef typename _iterator::reference           reference;
};

  template<typename _Tp>
    struct iterator_traits<_Tp*>
    {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp                         value_type;
      typedef ptrdiff_t                   difference_type;
      typedef _Tp*                        pointer;
      typedef _Tp&                        reference;
    };

  /// Partial specialization for const pointer types.
  template<typename _Tp>
    struct iterator_traits<const _Tp*>
    {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp                         value_type;
      typedef ptrdiff_t                   difference_type;
      typedef const _Tp*                  pointer;
      typedef const _Tp&                  reference;
    };

template<typename _iterator>
inline typename iterator_traits<_iterator>::iterator_category
__iterator_category(const _iterator&)
{
  return typename xns::iterator_traits<_iterator>::iterator_category();
}
///@} end

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

/// @}
}
#endif /* _STL_ITERATOR_BASE_TYPES_H */

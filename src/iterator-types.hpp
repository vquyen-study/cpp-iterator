#ifndef _ITERATOR_BASE_TYPES_H
#define _ITERATOR_BASE_TYPES_H 1

#include <cstddef>
#include <iostream>

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
  typedef typename _iterator::iterator_category iterator_category;
  typedef typename _iterator::value_type value_type;
  typedef typename _iterator::difference_type difference_type;
  typedef typename _iterator::pointer pointer;
  typedef typename _iterator::reference reference;
};

template<typename _iterator>
inline typename iterator_traits<_iterator>::iterator_category
__iterator_category(const _iterator&)
{
  return typename xns::iterator_traits<_iterator>::iterator_category();
}
///@} end

/// @ { start iterator
template<typename _Category,
         typename _Tp,
         typename _Distance = ptrdiff_t,
         typename _Pointer = _Tp*,
         typename _Reference = _Tp&>
struct iterator
{

public:
  /// One of the @link iterator_tags tag types@endlink.
  typedef _Category iterator_category;
  /// The type "pointed to" by the iterator.
  typedef _Tp value_type;
  /// Distance between iterators is represented as this type.
  typedef _Distance difference_type;
  /// This type represents a pointer-to-value_type.
  typedef _Pointer pointer;
  /// This type represents a reference-to-value_type.
  typedef _Reference reference;

  /// Default constructor.
  iterator() {}
  iterator(const iterator& obj) { this->_val = obj._val; }

  iterator(_Pointer val)
    : _val{ val }
  {
  }

  bool operator!=(const iterator& b) const { return this->_val != b._val; }

  iterator& operator++()
  {
    ++_val;
    return *this;
  }

  // implement the difference operator.
  difference_type operator-(const iterator& rhs) const
  {
    return this->_val - rhs._val;
  }

  value_type& operator*() { return *(this->_val); }

  /// Destructor.
  ~iterator() {}

private:
  pointer _val;
};

/// } @ end
///@{ begin  implement the distance oepration for iterator.

template<typename _input_iterator>
inline typename iterator_traits<_input_iterator>::difference_type
__distance(_input_iterator __first, _input_iterator __last, input_iterator_tag)
{
  typename iterator_traits<_input_iterator>::difference_type __n = 0;
  std::cout << __PRETTY_FUNCTION__ << std::endl;
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
  return xns::__distance(__first, __last, xns::__iterator_category(__first));
}
/// @} end

/// @{ begin implement the advance operation for iterator.

/// @}
}
#endif /* _STL_ITERATOR_BASE_TYPES_H */

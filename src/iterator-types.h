#ifndef _ITERATOR_BASE_TYPES_H
#define _ITERATOR_BASE_TYPES_H 1

#include <cstddef>

namespace xns
{

  ///@{
  ///  Marking input iterators.
  struct input_iterator_tag { };

  ///  Marking output iterators.
  struct output_iterator_tag { };

  /// Forward iterators support a superset of input iterator operations.
  struct forward_iterator_tag : public input_iterator_tag { };

  /// Bidirectional iterators support a superset of forward iterator
  /// operations.
  struct bidirectional_iterator_tag : public forward_iterator_tag { };

  /// Random-access iterators support a superset of bidirectional
  /// iterator operations.
  struct random_access_iterator_tag : public bidirectional_iterator_tag { };


  template <typename _category, typename _tp, typename _distance = ptrdiff_t, typename _pointer = _tp*, typename _reference = _tp&>
  struct iterator {
    typedef _category iterator_category;
    typedef _tp value_type;
    typedef _distance difference_type;
    typedef _pointer pointer;
    typedef _reference reference;
  };

  ///@}

  ///@{ begin
  template <typename _iterator>
  struct iterator_traits {
    typedef typename _iterator::iterator_category iterator_category;
    typedef typename _iterator::value_type value_type;
    typedef typename _iterator::difference_type difference_type;
    typedef typename _iterator::pointer pointer;
    typedef typename _iterator::reference reference;
    
  };


  template <typename _iterator>
  inline typename iterator_traits<_iterator>::iterator_category __iterator_category(const _iterator&)
  {
    return typename iterator_traits<_iterator>::iterator_category();
  }
  ///@} end


  template <typename _input_iterator>
  inline typename iterator_traits<_input_iterator>::difference_type __distance(_input_iterator __first, _input_iterator __last, input_iterator_tag)
  {
    typename iterator_traits<_input_iterator>::difference_type __n = 0;
    while(__first != __last)
      {
	++__first;
	++__n;
      }
    return __n;
  }

  template <typename _random_access_iterator>
  inline typename iterator_traits<_random_access_iterator>::difference_type __distance(_random_access_iterator __first, _random_access_iterator __last, random_access_iterator_tag) {
    return __last - __first;
  }

  template<typename _iterator_type>
  inline typename iterator_traits<_iterator_type>::difference_type distance(_iterator_type __first, _iterator_type __last){
    return __distance(__first, __last, __iterator_category(__first);
  }
  

#endif /* _STL_ITERATOR_BASE_TYPES_H */

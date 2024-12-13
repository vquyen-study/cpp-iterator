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


}
#endif /* _STL_ITERATOR_BASE_TYPES_H */

#ifndef __XNS_STREAM_ITERATOR__
#define __XNS_STREAM_ITERATOR__

#include <cstddef>
#include <istream>
#include <string>

#include "iterator-types.hpp"

namespace xns {
template<typename _Tp,
         typename _CharT = char,
         typename _Traits = std::char_traits<_CharT>,
         typename _Dist = ptrdiff_t>
class istream_iterator
{
public:
  /// One of the @link iterator_tags tag types@endlink.
  typedef input_iterator_tag iterator_category;
  /// The type "pointed to" by the iterator.
  typedef _Tp value_type;
  /// Distance between iterators is represented as this type.
  typedef _Dist difference_type;
  /// This type represents a pointer-to-value_type.
  typedef const _Tp* pointer;
  /// This type represents a reference-to-value_type.
  typedef const _Tp& reference;

  typedef _CharT char_type;
  typedef _Traits traits_type;
  typedef std::basic_istream<_CharT, _Traits> istream_type;

  // member function.
  istream_iterator()
    : _m_stream{ 0 }
    , _m_value{}
    , _m_ok{ false }
  {}

  istream_iterator(istream_iterator& __s)
    : _m_stream(__s._m_stream)
    , _m_value(__s._m_value)
    , _m_ok(__s._m_ok)
  {}

  istream_iterator(std::istream& __s)
    : _m_stream(__s._m_stream)
    , _m_value(__s._m_value)
    , _m_ok(__s._m_ok)
  {}

  istream_iterator(const istream_iterator& __s)
    : _m_stream(__s._m_stream)
    , _m_value(__s._m_value)
    , _m_ok(__s._m_ok)
  {}

  const _Tp& operator*() const { return _m_value; }

  istream_iterator& operator++()
  {
    _m_read();
    return *this;
  }

  istream_iterator operator++(int)
  {
    istream_iterator __tmp = *this;
    _m_read();
    return __tmp;
  }

  friend bool operator==(const istream_iterator& _x, const istream_iterator& _y)
  {
    return _x._m_equal(_y);
  }

private:
  istream_type* _m_stream;
  _Tp _m_value;
  bool _m_ok;

  void _m_read()
  {
    if (_m_stream && !(*_m_stream >> _m_value)) {
      _m_stream = 0;
      _m_ok = false;
    }
  }

  bool _m_equal(const istream_iterator& _x) const
  {
    return _m_ok == _x._m_ok && (!_m_ok || _m_stream == _x._m_stream);
  }
};
}

#endif // __XNS_STREAM_ITERATOR__

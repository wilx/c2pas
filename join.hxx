#ifndef _JOIN_HXX_
#define _JOIN_HXX_

#include <ios>

// Generic template.
template <typename _Seq, typename _SepT>
class _join_into_stream
{
  const _Seq & m_seq;
  const _SepT & m_sep;

public:
  _join_into_stream (const _Seq & seq, const _SepT & sep)
    : m_seq (seq), m_sep (sep)
  { }

  friend inline
  std::basic_ostream<typename _SepT::value_type> & 
  operator << (std::basic_ostream<typename _SepT::value_type> & os,
               const _join_into_stream & jism)
  {
    if (jism.m_seq.empty ())
      return os;

    typename _Seq::const_iterator it = jism.m_seq.begin ();
    os << *it;
    for (++it; it != jism.m_seq.end (); ++it)
	os << jism.m_sep << *it;
    
    return os;
  }
};


// Specialization for pointer types (think char *).
template <typename _Seq, typename _SepT>
class _join_into_stream<_Seq, const _SepT *>
{
  const _Seq & m_seq;
  const _SepT * m_sep;

public:
  _join_into_stream (const _Seq & seq, const _SepT * sep)
    : m_seq (seq), m_sep (sep)
  { }

  friend inline
  std::basic_ostream<_SepT> & 
  operator << (std::basic_ostream<_SepT> & os,
               const _join_into_stream & jism)
  {
    if (jism.m_seq.empty ())
      return os;
    
    typename _Seq::const_iterator it = jism.m_seq.begin ();
    os << *it;
    for (++it; it != jism.m_seq.end (); ++it)
	os << jism.m_sep << *it;    
    
    return os;
  }
};


template <typename _Seq, typename _SepT>
inline
_join_into_stream<_Seq, _SepT>
join_into_stream (const _Seq & seq, const _SepT sep)
{
  return _join_into_stream<_Seq, _SepT> (seq, sep);
}

#endif // _JOIN_HXX_

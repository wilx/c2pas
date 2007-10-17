/*
Copyright (c) 1997-2007, Václav Haisman

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
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

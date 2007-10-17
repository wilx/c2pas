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
#ifndef ALLTYPES_HXX
#define ALLTYPES_HXX


//
union AllTypes
{
  long double fpval;
  long long int intval;
  unsigned long long int uintval;
  char charval;
  bool boolval;

  AllTypes (long double x) : fpval(x) {}
  AllTypes (long long int x) : intval(x) {}
  AllTypes (unsigned long long int x) : uintval(x) {}
  AllTypes (char x) : charval(x) {}
  AllTypes (bool x) : boolval(x) {}

  operator long double () const
  {
    return fpval;
  }

  operator long long int () const
  {
    return intval;
  }

  operator unsigned long long int () const
  {
    return uintval;
  }

  operator char () const
  {
    return charval;
  }

  operator bool () const
  {
    return boolval;
  }

  operator int () const
  {
    return intval;
  }

  operator unsigned () const
  {
    return uintval;
  }
};


#endif // ALLTYPES_HXX

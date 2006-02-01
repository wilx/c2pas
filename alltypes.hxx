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

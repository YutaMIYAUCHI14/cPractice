#include <stdio.h>
#include "rational.h"

static int gcd(int a, int b)
{
  if(b == 0)
    {
      return a;
    }
  return gcd(b, a % b);
}

RATIONAL raReduce(RATIONAL x)
{
  int n;

  n = gcd(x.bunshi, x.bunbo);
  x.bunshi /= n;
  x.bunbo /= n;
  if(x.bunbo < 0)
    {
      x.bunshi = -x.bunshi;
      x.bunbo = -x.bunbo;
    }

  return x;
}

RATIONAL newRational(int a, int b)
{
  RATIONAL v = {a, b};

  return raReduce(v);
}

RATIONAL raAdd(RATIONAL a, RATIONAL b)
{
  RATIONAL v;

  v.bunshi = a.bunshi * b.bunbo + b.bunshi * a.bunbo;
  v.bunbo = a.bunbo * b.bunbo;

  return raReduce(v);
}

RATIONAL raSub(RATIONAL a, RATIONAL b)
{
  RATIONAL v;

  v.bunshi = a.bunshi * b.bunbo - b.bunshi * a.bunbo;
  v.bunbo = a.bunbo * b.bunbo;

  return raReduce(v);
}

RATIONAL raMul(RATIONAL a, RATIONAL b)
{
  RATIONAL v;

  v.bunshi = a.bunshi * b.bunshi;
  v.bunbo = a.bunbo * b.bunbo;

  return raReduce(v);
}

RATIONAL raDiv(RATIONAL a, RATIONAL b)
{
  RATIONAL v;

  v.bunshi = a.bunshi * b.bunbo;
  v.bunbo = a.bunbo * b.bunshi;

  return raReduce(v);
}

int raEq(RATIONAL a, RATIONAL b)
{
  if(raSub(a,b).bunshi == 0)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

int raGt(RATIONAL a, RATIONAL b)
{
  if(raSub(a,b).bunshi > 0)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

void raPrint(RATIONAL v)
{
  printf("%d/%d", v.bunshi, v.bunbo);
}

void raPrintN1(RATIONAL v)
{
  raPrint(v);
  printf("\n");
}

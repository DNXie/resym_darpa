#include "/share/binary_recovery/clang-parser/defs.hh"
int __fastcall sub_403FD4(FILE *a1)
{
  if ( !a1 || !__freading(a1) )
    return fflush(a1);
  sub_403FA1(a1);
  return fflush(a1);
}
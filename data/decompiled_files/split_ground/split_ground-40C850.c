#include "/share/binary_recovery/clang-parser/defs.hh"
int __fastcall sub_40C850(void (__fastcall *a1)(void *))
{
  void *v1; // rdx

  if ( &qword_6102C8 )
    v1 = (void *)qword_6102C8;
  else
    v1 = 0LL;
  return __cxa_atexit(a1, 0LL, v1);
}
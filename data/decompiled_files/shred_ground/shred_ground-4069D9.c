#include "/share/binary_recovery/clang-parser/defs.hh"
_QWORD *__fastcall sub_4069D9(__int64 a1)
{
  _QWORD *result; // rax

  result = (_QWORD *)sub_408AAE(24LL);
  *result = a1;
  result[2] = 0LL;
  result[1] = result[2];
  return result;
}
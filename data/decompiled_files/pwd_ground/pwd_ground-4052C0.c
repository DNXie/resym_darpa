#include "/share/binary_recovery/clang-parser/defs.hh"
__ino_t *__fastcall sub_4052C0(__ino_t *a1)
{
  struct stat stat_buf; // [rsp+10h] [rbp-90h] BYREF

  if ( (unsigned int)sub_405660("/", &stat_buf) )
    return 0LL;
  *a1 = stat_buf.st_ino;
  a1[1] = stat_buf.st_dev;
  return a1;
}
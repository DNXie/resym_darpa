#include "/share/binary_recovery/clang-parser/defs.hh"
int __fastcall sub_40C870(int fildes, struct stat *stat_buf)
{
  return __fxstat(1, fildes, stat_buf);
}
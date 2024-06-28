#include "/share/binary_recovery/clang-parser/defs.hh"
void *__fastcall sub_403BF5(void *a1, size_t a2)
{
  void *result; // rax
  __int64 v3; // rdx
  void *ptr; // [rsp+8h] [rbp-8h]

  if ( a2 || !a1 )
  {
    ptr = realloc(a1, a2);
    if ( !ptr )
    {
      if ( a2 )
        sub_403D42(a1, a2, v3);
    }
    result = ptr;
  }
  else
  {
    free(a1);
    result = 0LL;
  }
  return result;
}
#include "/share/binary_recovery/clang-parser/defs.hh"
void sub_404D1D()
{
  unsigned int i; // [rsp+4h] [rbp-Ch]
  void **ptr; // [rsp+8h] [rbp-8h]

  ptr = (void **)off_6091F0;
  for ( i = 1; i < dword_6091D0; ++i )
    free(ptr[2 * i + 1]);
  if ( ptr[1] != &unk_6092A0 )
  {
    free(ptr[1]);
    qword_6091E0 = 256LL;
    off_6091E8 = &unk_6092A0;
  }
  if ( ptr != (void **)&qword_6091E0 )
  {
    free(ptr);
    off_6091F0 = &qword_6091E0;
  }
  dword_6091D0 = 1;
}
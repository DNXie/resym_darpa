#include "/share/binary_recovery/clang-parser/defs.hh"
// attributes: thunk
int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout)
{
  return select(nfds, readfds, writefds, exceptfds, timeout);
}

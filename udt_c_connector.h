#ifndef __UDT_C_CONNECTOR_H__
#define __UDT_C_CONNECTOR_H__
#include "udt_base.h"
#ifdef WIN32
#include <stdint.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
// For some reason the name htons isn't addressable in Go, so we have a function
// that wraps htons and is called _htons, which makes Go happy.
uint16_t _htons(uint16_t hostshort);

#undef ERROR
extern const int ERROR;
extern const UDTSOCKET INVALID_SOCK;


int udt_startup();
int udt_cleanup();
UDTSOCKET udt_socket(int af, int type, int protocol);
int udt_bind(UDTSOCKET u, const struct sockaddr* name, int namelen);
int udt_bind2(UDTSOCKET u, UDPSOCKET udpsock);
int udt_listen(UDTSOCKET u, int backlog);
UDTSOCKET udt_accept(UDTSOCKET u, struct sockaddr* addr, int* addrlen);
int udt_connect(UDTSOCKET u, const struct sockaddr* name, int namelen);
int udt_close(UDTSOCKET u);
int udt_getpeername(UDTSOCKET u, struct sockaddr* name, int* namelen);
int udt_getsockname(UDTSOCKET u, struct sockaddr* name, int* namelen);
int udt_getsockopt(UDTSOCKET u, int level, SOCKOPT optname, void* optval, int* optlen);
int udt_setsockopt(UDTSOCKET u, int level, SOCKOPT optname, const void* optval, int optlen);
int udt_send(UDTSOCKET u, const char* buf, int len, int flags);
int udt_recv(UDTSOCKET u, char* buf, int len, int flags);
int udt_sendmsg(UDTSOCKET u, const char* buf, int len, int ttl, int inorder);
int udt_recvmsg(UDTSOCKET u, char* buf, int len);
int64_t udt_sendfile2(UDTSOCKET u, const char* path, int64_t* offset, int64_t size, int block);
int64_t udt_recvfile2(UDTSOCKET u, const char* path, int64_t* offset, int64_t size, int block);
int udt_epoll_create();
int udt_epoll_add_usock(int eid, UDTSOCKET u, const int* events);
int udt_epoll_add_ssock(int eid, SYSSOCKET s, const int* events);
int udt_epoll_remove_usock(int eid, UDTSOCKET u);
int udt_epoll_remove_ssock(int eid, SYSSOCKET s);
int udt_epoll_wait2(int eid, UDTSOCKET* readfds, int* rnum, UDTSOCKET* writefds, int* wnum, int64_t msTimeOut,
   SYSSOCKET* lrfds, int* lrnum, SYSSOCKET* lwfds, int* lwnum);
int udt_epoll_release(int eid);
int udt_getlasterror_code();
const char* udt_getlasterror_desc();
int udt_perfmon(UDTSOCKET u, TRACEINFO* perf, int clear);
enum UDTSTATUS udt_getsockstate(UDTSOCKET u);
#ifdef __cplusplus
}
#endif
#endif

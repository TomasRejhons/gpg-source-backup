/*-------------------------------------------------------------------------
 *
 * ip.h
 *	  Definitions for IPv6-aware network access.
 *
 * These definitions are used by both frontend and backend code.  Be careful
 * what you include here!
 *
 * Copyright (c) 2003-2006, PostgreSQL Global Development Group
 *
 * $PostgreSQL: pgsql/src/include/libpq/ip.h,v 1.18 2006/06/20 19:56:52 tgl Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef IP_H
#define IP_H

#include "getaddrinfo.h"
#include "libpq/pqcomm.h"


extern int pg_getaddrinfo_all(const char *hostname, const char *servname,
				   const struct addrinfo * hintp,
				   struct addrinfo ** result);
extern void pg_freeaddrinfo_all(int hint_ai_family, struct addrinfo * ai);

extern int pg_getnameinfo_all(const struct sockaddr_storage * addr, int salen,
				   char *node, int nodelen,
				   char *service, int servicelen,
				   int flags);

extern int pg_range_sockaddr(const struct sockaddr_storage * addr,
				  const struct sockaddr_storage * netaddr,
				  const struct sockaddr_storage * netmask);

extern int pg_sockaddr_cidr_mask(struct sockaddr_storage * mask,
					  char *numbits, int family);

#ifdef HAVE_IPV6
extern void pg_promote_v4_to_v6_addr(struct sockaddr_storage * addr);
extern void pg_promote_v4_to_v6_mask(struct sockaddr_storage * addr);
#endif

#ifdef	HAVE_UNIX_SOCKETS
#define IS_AF_UNIX(fam) ((fam) == AF_UNIX)
#else
#define IS_AF_UNIX(fam) (0)
#endif

#endif   /* IP_H */

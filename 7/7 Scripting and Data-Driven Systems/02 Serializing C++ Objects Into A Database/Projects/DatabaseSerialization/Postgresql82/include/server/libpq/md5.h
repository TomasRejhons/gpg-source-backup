/*-------------------------------------------------------------------------
 *
 * md5.h
 *	  Interface to libpq/md5.c
 *
 * These definitions are needed by both frontend and backend code to work
 * with MD5-encrypted passwords.
 *
 * Portions Copyright (c) 1996-2006, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/libpq/md5.h,v 1.3 2006/06/20 19:56:52 tgl Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_MD5_H
#define PG_MD5_H

#define MD5_PASSWD_LEN	35

#define isMD5(passwd)	(strncmp(passwd, "md5", 3) == 0 && \
						 strlen(passwd) == MD5_PASSWD_LEN)


extern bool pg_md5_hash(const void *buff, size_t len, char *hexsum);
extern bool pg_md5_encrypt(const char *passwd, const char *salt,
			   size_t salt_len, char *buf);

#endif

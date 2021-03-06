/*-------------------------------------------------------------------------
 *
 * tablespace.h
 *		Tablespace management commands (create/drop tablespace).
 *
 *
 * Portions Copyright (c) 1996-2006, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/commands/tablespace.h,v 1.13 2006/03/24 04:32:13 tgl Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef TABLESPACE_H
#define TABLESPACE_H

#include "access/xlog.h"
#include "nodes/parsenodes.h"

/* XLOG stuff */
#define XLOG_TBLSPC_CREATE		0x00
#define XLOG_TBLSPC_DROP		0x10

typedef struct xl_tblspc_create_rec
{
	Oid			ts_id;
	char		ts_path[1];		/* VARIABLE LENGTH STRING */
} xl_tblspc_create_rec;

typedef struct xl_tblspc_drop_rec
{
	Oid			ts_id;
} xl_tblspc_drop_rec;


extern void CreateTableSpace(CreateTableSpaceStmt *stmt);
extern void DropTableSpace(DropTableSpaceStmt *stmt);
extern void RenameTableSpace(const char *oldname, const char *newname);
extern void AlterTableSpaceOwner(const char *name, Oid newOwnerId);

extern void TablespaceCreateDbspace(Oid spcNode, Oid dbNode, bool isRedo);

extern Oid	GetDefaultTablespace(void);

extern Oid	get_tablespace_oid(const char *tablespacename);
extern char *get_tablespace_name(Oid spc_oid);

extern bool directory_is_empty(const char *path);

extern void tblspc_redo(XLogRecPtr lsn, XLogRecord *rptr);
extern void tblspc_desc(StringInfo buf, uint8 xl_info, char *rec);

#endif   /* TABLESPACE_H */

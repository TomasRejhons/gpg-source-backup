/*-------------------------------------------------------------------------
 *
 * nodeTidscan.h
 *
 *
 *
 * Portions Copyright (c) 1996-2006, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/executor/nodeTidscan.h,v 1.17 2006/03/05 15:58:56 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef NODETIDSCAN_H
#define NODETIDSCAN_H

#include "nodes/execnodes.h"

extern int	ExecCountSlotsTidScan(TidScan *node);
extern TidScanState *ExecInitTidScan(TidScan *node, EState *estate, int eflags);
extern TupleTableSlot *ExecTidScan(TidScanState *node);
extern void ExecEndTidScan(TidScanState *node);
extern void ExecTidMarkPos(TidScanState *node);
extern void ExecTidRestrPos(TidScanState *node);
extern void ExecTidReScan(TidScanState *node, ExprContext *exprCtxt);

#endif   /* NODETIDSCAN_H */

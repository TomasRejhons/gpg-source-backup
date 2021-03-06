/*-------------------------------------------------------------------------
 *
 * execdebug.h
 *	  #defines governing debugging behaviour in the executor
 *
 * XXX this is all pretty old and crufty.  Newer code tends to use elog()
 * for debug printouts, because that's more flexible than printf().
 *
 *
 * Portions Copyright (c) 1996-2006, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/executor/execdebug.h,v 1.30 2006/05/23 15:21:52 tgl Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef EXECDEBUG_H
#define EXECDEBUG_H

#include "executor/executor.h"
#include "nodes/print.h"

/* ----------------------------------------------------------------
 *		debugging defines.
 *
 *		If you want certain debugging behaviour, then #define
 *		the variable to 1. No need to explicitly #undef by default,
 *		since we can use -D compiler options to enable features.
 *		- thomas 1999-02-20
 * ----------------------------------------------------------------
 */

/* ----------------
 *		EXEC_TUPLECOUNT is a #define which causes the
 *		executor to keep track of tuple counts.  This might be
 *		causing some problems with the decstation stuff so
 *		you might want to undefine this if you are doing work
 *		on the decs  - cim 10/20/89
 * ----------------
#undef EXEC_TUPLECOUNT
 */

/* ----------------
 *		EXEC_NESTLOOPDEBUG is a flag which turns on debugging of the
 *		nest loop node by NL_printf() and ENL_printf() in nodeNestloop.c
 * ----------------
#undef EXEC_NESTLOOPDEBUG
 */

/* ----------------
 *		EXEC_EVALDEBUG is a flag which turns on debugging of
 *		ExecEval and ExecTargetList() stuff by EV_printf() in execQual.c
 * ----------------
#undef EXEC_EVALDEBUG
 */

/* ----------------
 *		EXEC_SORTDEBUG is a flag which turns on debugging of
 *		the ExecSort() stuff by SO_printf() in nodeSort.c
 * ----------------
#undef EXEC_SORTDEBUG
 */

/* ----------------
 *		EXEC_MERGEJOINDEBUG is a flag which turns on debugging of
 *		the ExecMergeJoin() stuff by MJ_printf() in nodeMergejoin.c
 * ----------------
#undef EXEC_MERGEJOINDEBUG
 */

/* ----------------------------------------------------------------
 *		#defines controlled by above definitions
 *
 *		Note: most of these are "incomplete" because I didn't
 *			  need the ones not defined.  More should be added
 *			  only as necessary -cim 10/26/89
 * ----------------------------------------------------------------
 */
#define T_OR_F(b)				((b) ? "true" : "false")
#define NULL_OR_TUPLE(slot)		(TupIsNull(slot) ? "null" : "a tuple")


/* ----------------
 *		tuple count debugging defines
 * ----------------
 */
#ifdef EXEC_TUPLECOUNT
extern int	NTupleProcessed;
extern int	NTupleRetrieved;
extern int	NTupleReplaced;
extern int	NTupleAppended;
extern int	NTupleDeleted;
extern int	NIndexTupleProcessed;
extern int	NIndexTupleInserted;

#define IncrRetrieved()			NTupleRetrieved++
#define IncrAppended()			NTupleAppended++
#define IncrDeleted()			NTupleDeleted++
#define IncrReplaced()			NTupleReplaced++
#define IncrInserted()			NTupleInserted++
#define IncrProcessed()			NTupleProcessed++
#define IncrIndexProcessed()	NIndexTupleProcessed++
#define IncrIndexInserted()		NIndexTupleInserted++
#else
/* stop compiler warnings */
#define IncrRetrieved()			(void)(0)
#define IncrAppended()			(void)(0)
#define IncrDeleted()			(void)(0)
#define IncrReplaced()			(void)(0)
#define IncrInserted()			(void)(0)
#define IncrProcessed()			(void)(0)
#define IncrIndexProcessed()	(void)(0)
#define IncrIndexInserted()		(void)(0)
#endif   /* EXEC_TUPLECOUNT */

/* ----------------
 *		nest loop debugging defines
 * ----------------
 */
#ifdef EXEC_NESTLOOPDEBUG
#define NL_nodeDisplay(l)				nodeDisplay(l)
#define NL_printf(s)					printf(s)
#define NL1_printf(s, a)				printf(s, a)
#define ENL1_printf(message)			printf("ExecNestLoop: %s\n", message)
#else
#define NL_nodeDisplay(l)
#define NL_printf(s)
#define NL1_printf(s, a)
#define ENL1_printf(message)
#endif   /* EXEC_NESTLOOPDEBUG */

/* ----------------
 *		exec eval / target list debugging defines
 * ----------------
 */
#ifdef EXEC_EVALDEBUG
#define EV_nodeDisplay(l)				nodeDisplay(l)
#define EV_printf(s)					printf(s)
#define EV1_printf(s, a)				printf(s, a)
#else
#define EV_nodeDisplay(l)
#define EV_printf(s)
#define EV1_printf(s, a)
#endif   /* EXEC_EVALDEBUG */

/* ----------------
 *		sort node debugging defines
 * ----------------
 */
#ifdef EXEC_SORTDEBUG
#define SO_nodeDisplay(l)				nodeDisplay(l)
#define SO_printf(s)					printf(s)
#define SO1_printf(s, p)				printf(s, p)
#else
#define SO_nodeDisplay(l)
#define SO_printf(s)
#define SO1_printf(s, p)
#endif   /* EXEC_SORTDEBUG */

/* ----------------
 *		merge join debugging defines
 * ----------------
 */
#ifdef EXEC_MERGEJOINDEBUG

#define MJ_nodeDisplay(l)				nodeDisplay(l)
#define MJ_printf(s)					printf(s)
#define MJ1_printf(s, p)				printf(s, p)
#define MJ2_printf(s, p1, p2)			printf(s, p1, p2)
#define MJ_debugtup(slot)				debugtup(slot, NULL)
#define MJ_dump(state)					ExecMergeTupleDump(state)
#define MJ_DEBUG_COMPARE(res) \
  MJ1_printf("  MJCompare() returns %d\n", (res))
#define MJ_DEBUG_QUAL(clause, res) \
  MJ2_printf("  ExecQual(%s, econtext) returns %s\n", \
			 CppAsString(clause), T_OR_F(res))
#define MJ_DEBUG_PROC_NODE(slot) \
  MJ2_printf("  %s = ExecProcNode(...) returns %s\n", \
			 CppAsString(slot), NULL_OR_TUPLE(slot))
#else

#define MJ_nodeDisplay(l)
#define MJ_printf(s)
#define MJ1_printf(s, p)
#define MJ2_printf(s, p1, p2)
#define MJ_debugtup(slot)
#define MJ_dump(state)
#define MJ_DEBUG_COMPARE(res)
#define MJ_DEBUG_QUAL(clause, res)
#define MJ_DEBUG_PROC_NODE(slot)
#endif   /* EXEC_MERGEJOINDEBUG */

/* ----------------------------------------------------------------
 *		DO NOT DEFINE THESE EVER OR YOU WILL BURN!
 * ----------------------------------------------------------------
 */
/* ----------------
 *		NOTYET is placed around any code not yet implemented
 *		in the executor.  Only remove these when actually implementing
 *		said code.
 * ----------------
 */
#undef NOTYET

extern long NDirectFileRead;
extern long NDirectFileWrite;

#endif   /* ExecDebugIncluded */

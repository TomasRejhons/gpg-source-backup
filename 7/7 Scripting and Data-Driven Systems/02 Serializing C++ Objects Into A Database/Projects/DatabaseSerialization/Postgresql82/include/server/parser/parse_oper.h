/*-------------------------------------------------------------------------
 *
 * parse_oper.h
 *		handle operator things for parser
 *
 *
 * Portions Copyright (c) 1996-2006, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/parser/parse_oper.h,v 1.40 2006/10/04 00:30:09 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef PARSE_OPER_H
#define PARSE_OPER_H

#include "access/htup.h"
#include "parser/parse_node.h"


typedef HeapTuple Operator;

/* Routines to look up an operator given name and exact input type(s) */
extern Oid LookupOperName(ParseState *pstate, List *opername,
			   Oid oprleft, Oid oprright,
			   bool noError, int location);
extern Oid LookupOperNameTypeNames(ParseState *pstate, List *opername,
						TypeName *oprleft, TypeName *oprright,
						bool noError, int location);

/* Routines to find operators matching a name and given input types */
/* NB: the selected operator may require coercion of the input types! */
extern Operator oper(ParseState *pstate, List *op, Oid arg1, Oid arg2,
	 bool noError, int location);
extern Operator right_oper(ParseState *pstate, List *op, Oid arg,
		   bool noError, int location);
extern Operator left_oper(ParseState *pstate, List *op, Oid arg,
		  bool noError, int location);

/* Routines to find operators that DO NOT require coercion --- ie, their */
/* input types are either exactly as given, or binary-compatible */
extern Operator compatible_oper(ParseState *pstate, List *op,
				Oid arg1, Oid arg2,
				bool noError, int location);

/* currently no need for compatible_left_oper/compatible_right_oper */

/* Routines for identifying "=", "<", ">" operators for a type */
extern Operator equality_oper(Oid argtype, bool noError);
extern Operator ordering_oper(Oid argtype, bool noError);
extern Operator reverse_ordering_oper(Oid argtype, bool noError);

/* Convenience routines for common calls on the above */
extern Oid	compatible_oper_opid(List *op, Oid arg1, Oid arg2, bool noError);
extern Oid	equality_oper_funcid(Oid argtype);
extern Oid	ordering_oper_opid(Oid argtype);
extern Oid	reverse_ordering_oper_opid(Oid argtype);

/* Extract operator OID or underlying-function OID from an Operator tuple */
extern Oid	oprid(Operator op);
extern Oid	oprfuncid(Operator op);

/* Build expression tree for an operator invocation */
extern Expr *make_op(ParseState *pstate, List *opname,
		Node *ltree, Node *rtree, int location);
extern Expr *make_scalar_array_op(ParseState *pstate, List *opname,
					 bool useOr,
					 Node *ltree, Node *rtree, int location);

#endif   /* PARSE_OPER_H */

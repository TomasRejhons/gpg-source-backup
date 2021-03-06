/* $PostgreSQL: pgsql/src/interfaces/ecpg/include/pgtypes_interval.h,v 1.13 2006/10/04 00:30:11 momjian Exp $ */

#ifndef PGTYPES_INTERVAL
#define PGTYPES_INTERVAL

#include <ecpg_config.h>

#ifndef C_H

#ifdef HAVE_LONG_INT_64
#ifndef HAVE_INT64
typedef long int int64;
#endif
#elif defined(HAVE_LONG_LONG_INT_64)
/* We have working support for "long long int", use that */

#ifndef HAVE_INT64
typedef long long int int64;
#endif
#else							/* not HAVE_LONG_INT_64 and not
								 * HAVE_LONG_LONG_INT_64 */

/* Won't actually work, but fall back to long int so that code compiles */
#ifndef HAVE_INT64
typedef long int int64;
#endif

#define INT64_IS_BUSTED
#endif   /* not HAVE_LONG_INT_64 and not
								 * HAVE_LONG_LONG_INT_64 */

#if defined(USE_INTEGER_DATETIMES) && !defined(INT64_IS_BUSTED)
#define HAVE_INT64_TIMESTAMP
#endif
#endif   /* C_H */

typedef struct
{
#ifdef HAVE_INT64_TIMESTAMP
	int64		time;			/* all time units other than months and years */
#else
	double		time;			/* all time units other than months and years */
#endif
	long		month;			/* months and years, after time for alignment */
}	interval;

#ifdef __cplusplus
extern		"C"
{
#endif

extern interval *PGTYPESinterval_new(void);
extern void PGTYPESinterval_free(interval *);
extern interval *PGTYPESinterval_from_asc(char *, char **);
extern char *PGTYPESinterval_to_asc(interval *);
extern int	PGTYPESinterval_copy(interval *, interval *);

#ifdef __cplusplus
}
#endif

#endif   /* PGTYPES_INTERVAL */

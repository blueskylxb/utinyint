
#ifndef utinyint_H
#define utinyint_H

#include <ctype.h>

#include "fmgr.h"


typedef unsigned char utinyint;

// the functions of SET_1_BYTE() and GET_1_BYTE() implement in include/postgres.h
#define DatumGetutinyint(X) ((utinyint) GET_1_BYTE(X)) 
#define utinyintGetDatum(X) ((Datum) SET_1_BYTE(X))

#define PG_GETARG_utinyint(n)	DatumGetutinyint(PG_GETARG_DATUM(n))
#define PG_RETURN_utinyint(x)	return utinyintGetDatum(x)

extern Datum utinyint_in(PG_FUNCTION_ARGS);
extern Datum utinyint_out(PG_FUNCTION_ARGS);
extern Datum utinyint_recv(PG_FUNCTION_ARGS);
extern Datum utinyint_send(PG_FUNCTION_ARGS);

extern Datum utinyint_to_i2(PG_FUNCTION_ARGS);
extern Datum i2_to_utinyint(PG_FUNCTION_ARGS);
extern Datum utinyint_to_i4(PG_FUNCTION_ARGS);
extern Datum i4_to_utinyint(PG_FUNCTION_ARGS);
extern Datum utinyint_to_bool(PG_FUNCTION_ARGS);
extern Datum bool_to_utinyint(PG_FUNCTION_ARGS);


#endif   /* utinyint_H */

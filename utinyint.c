#include "postgres.h"

#include <ctype.h>
#include <limits.h>

#include "access/hash.h"
#include "catalog/pg_type.h"
#include "libpq/pqformat.h"
#include "utils/array.h"
#include "utinyint.h"
#include "utils/builtins.h"

#define SAMESIGN(a,b)	(((a) < 0) == ((b) < 0))

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(utinyint_in);
PG_FUNCTION_INFO_V1(utinyint_out);
PG_FUNCTION_INFO_V1(utinyint_recv);
PG_FUNCTION_INFO_V1(utinyint_send);

PG_FUNCTION_INFO_V1(utinyint_to_i2);
PG_FUNCTION_INFO_V1(i2_to_utinyint);
PG_FUNCTION_INFO_V1(utinyint_to_i4);
PG_FUNCTION_INFO_V1(i4_to_utinyint);
PG_FUNCTION_INFO_V1(utinyint_to_bool);
PG_FUNCTION_INFO_V1(bool_to_utinyint);


/*****************************************************************************
 *	 USER I/O ROUTINES														 *
 *****************************************************************************/

/*
 *	utinyint_in		- converts "num" to utinyint
 */
Datum
utinyint_in(PG_FUNCTION_ARGS)
{
	char	   *num = PG_GETARG_CSTRING(0);

	PG_RETURN_utinyint(pg_atoi(num, sizeof(utinyint), '\0'));
}

/*
 *	utinyint_out		- converts utinyint to "num"
 */
Datum
utinyint_out(PG_FUNCTION_ARGS)
{
	utinyint		arg1 = PG_GETARG_utinyint(0);
	char	   *result = (char *) palloc(4);	/* 3 digits, '\0' */

	pg_itoa(arg1, result);
	PG_RETURN_CSTRING(result);
}

/*
 *	utinyint_recv		- converts external binary format to utinyint
 */
Datum
utinyint_recv(PG_FUNCTION_ARGS)
{
	StringInfo	buf = (StringInfo) PG_GETARG_POINTER(0);

	PG_RETURN_utinyint((utinyint) pq_getmsgint(buf, sizeof(utinyint)));
}

/*
 * utinyint_send			- converts utinyint to binary format
 */
Datum
utinyint_send(PG_FUNCTION_ARGS)
{
	utinyint		arg1 = PG_GETARG_utinyint(0);
	StringInfoData buf;

	pq_begintypsend(&buf);
	pq_sendint(&buf, arg1, sizeof(utinyint));
	PG_RETURN_BYTEA_P(pq_endtypsend(&buf));
}

/*
 *		===================
 *		CONVERSION ROUTINES
 *		===================
 */

Datum
utinyint_to_i2(PG_FUNCTION_ARGS)
{
	utinyint		arg1 = PG_GETARG_utinyint(0);

	PG_RETURN_UINT16((uint16) arg1);
}

Datum
i2_to_utinyint(PG_FUNCTION_ARGS)
{
	uint16		arg1 = PG_GETARG_UINT16(0);

	if (arg1 < 0 || arg1 > UCHAR_MAX)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("utinyint out of range")));

	PG_RETURN_utinyint((utinyint) arg1);
}

Datum
utinyint_to_i4(PG_FUNCTION_ARGS)
{
	utinyint		arg1 = PG_GETARG_utinyint(0);

	PG_RETURN_UINT32((uint32) arg1);
}

Datum
i4_to_utinyint(PG_FUNCTION_ARGS)
{
	uint32		arg1 = PG_GETARG_UINT32(0);

	if (arg1 < 0 || arg1 > UCHAR_MAX)
		ereport(ERROR,
				(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
				 errmsg("utinyint out of range")));

	PG_RETURN_utinyint((utinyint) arg1);
}

Datum
utinyint_to_bool(PG_FUNCTION_ARGS)
{
	if (PG_GETARG_utinyint(0) == 0)
		PG_RETURN_BOOL(false);
	else
		PG_RETURN_BOOL(true);
}

Datum
bool_to_utinyint(PG_FUNCTION_ARGS)
{
	if (PG_GETARG_BOOL(0) == false)
		PG_RETURN_utinyint(0);
	else
		PG_RETURN_utinyint(1);
}



#include "pg_config.h"

CREATE FUNCTION utinyint_in(cstring) RETURNS utinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE FUNCTION utinyint_out(utinyint) RETURNS cstring AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE FUNCTION utinyint_recv(internal) RETURNS utinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE FUNCTION utinyint_send(utinyint) RETURNS bytea AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;

CREATE TYPE utinyint (
	INPUT = utinyint_in,
	OUTPUT = utinyint_out,
	RECEIVE = utinyint_recv,
	SEND = utinyint_send,
	INTERNALLENGTH = 1,
	PASSEDBYVALUE,
	ALIGNMENT = char,
	STORAGE = plain
);

CREATE FUNCTION utinyint_to_i2(utinyint) RETURNS smallint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (utinyint AS smallint)
WITH FUNCTION utinyint_to_i2(utinyint) AS IMPLICIT;

CREATE FUNCTION i2_to_utinyint(smallint) RETURNS utinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (smallint AS utinyint)
WITH FUNCTION i2_to_utinyint(smallint) AS ASSIGNMENT;

CREATE FUNCTION utinyint_to_i4(utinyint) RETURNS integer AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (utinyint AS integer)
WITH FUNCTION utinyint_to_i4(utinyint) AS IMPLICIT;

CREATE FUNCTION i4_to_utinyint(integer) RETURNS utinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (integer AS utinyint)
WITH FUNCTION i4_to_utinyint(integer) AS ASSIGNMENT;

CREATE FUNCTION utinyint_to_bool(utinyint) RETURNS bool AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (utinyint AS bool)
WITH FUNCTION utinyint_to_bool(utinyint) AS ASSIGNMENT;

CREATE FUNCTION bool_to_utinyint(bool) RETURNS utinyint AS
'MODULE_PATHNAME'
LANGUAGE c IMMUTABLE STRICT;
CREATE CAST (bool AS utinyint)
WITH FUNCTION bool_to_utinyint(bool) AS ASSIGNMENT;

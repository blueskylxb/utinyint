SET client_min_messages = warning;
\set ECHO none
\i utinyint.sql
\set ECHO all
RESET client_min_messages;

SELECT 0::utinyint;

SELECT 128::utinyint;

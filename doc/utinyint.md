utinyint 0.1.1
=============

Synopsis
--------

    % CREATE EXTENSION utinyint;
    CREATE EXTENSION

    % SELECT 1::utinyint;


Description
-----------

This module provides 1 byte signed integer type with operators,
index access methods and support functions. You can use it as
like the corresponding data type in other RDBMS as well as
smallint, integer or bigint in PostgreSQL. Although the byte
used for 1 utinyint is exactly 1 byte, you need to take account
into its position in the row if you really care the table size
since PostgreSQL usually pads extra bytes for the alignment of 4.

utinyint holds -127 to 127. +, -, *, %. min(), max(), sum(), avg(),
btree index and gin index are supported as other integer types.

Support
-------

This library is stored in an open [GitHub
repository](http://github.com/umitanuki/utinyint-postgresql).
Feel free to fork and contribute! Please file bug reports
via [GitHub Issues](http://github.com/umitanuki/utinyint-postgresql/issues/).

Author
------

[lxb]()

Copyright and License
---------------------

Copyright (c) lxb

This module is free software; you can redistribute it and/or modify it under
the [PostgreSQL License](http://www.opensource.org/licenses/postgresql).

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose, without fee, and without a written agreement is
hereby granted, provided that the above copyright notice and this paragraph
and the following two paragraphs appear in all copies.

In no event shall lxb be liable to any party for direct,
indirect, special, incidental, or consequential damages, including
lost profits, arising out of the use of this software and its documentation,
even if lxb has been advised of the possibility of such damage.

lxb specifically disclaim any warranties,
including, but not limited to, the implied warranties of merchantability and 
fitness for a particular purpose. The software provided hereunder is on an "as 
is" basis, and lxb has no obligations to provide maintenance,
support, updates, enhancements, or modifications.


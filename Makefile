EXTENSION = utinyint
EXTVERSION = 0.1.1
EXTSQL = $(EXTENSION)--$(EXTVERSION).sql

MODULES = utinyint
OBJS = utinyint.o
DATA_built = utinyint.sql
DATA = uninstall_utinyint.sql
DOCS = doc/utinyint.md
REGRESS = utinyint

SQL_IN = utinyint.sql.in
EXTRA_CLEAN += $(SQL_IN) $(EXTSQL)

USE_EXTENSION = $(shell pg_config --version | grep -qE " 8\.|9\.0" && echo no || echo yes)

ifeq ($(USE_EXTENSION),yes)
all: $(EXTSQL)

$(EXTSQL): $(EXTENSION).sql
	cp $< $@

DATA = $(EXTSQL)
endif

PGXS := $(shell pg_config --pgxs)
include $(PGXS)

$(SQL_IN): utinyint.sql.in.c
	$(CC) -E -P $(CPPFLAGS) $< > $@

PROJ.NAME=list

LIBS.SHARED:=

DIR.SRC:=src
DIR.INC:=inc
DIR.BIN:=bin

DIR.OUT:=.

FLAGS.PROJ:=-Wall -Wextra -I$(CUSTOM_LIBS_DIR)/include -L$(CUSTOM_LIBS_DIR)/lib
FLAGS.EXEC:=$(foreach lib,-l$(lib),$(LIBS.SHARED))
FLAGS.LIBSH:=$(foreach lib,-l$(lib),$(LIBS.SHARED))

PROJ.NAME=list

LIBS.SHARED:=

DIR.SRC:=src
DIR.INC:=inc
DIR.BIN:=bin

DIR.OUT:=.

FLAGS.PROJ:=-Wall -Wextra -I/home/icenfire/projects/Software/include -L/home/icenfire/projects/Software/lib
FLAGS.EXEC:=$(foreach lib,-l$(lib),$(LIBS.SHARED))
FLAGS.LIBSH:=$(foreach lib,-l$(lib),$(LIBS.SHARED))

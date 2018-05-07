TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=    text/append_line.c \
    text/cd.c \
    text/create_text.c \
    text/cursors.c \
    text/delete_line.c \
    text/i.c \
    text/j.c \
    text/mcb.c \
    text/mp.c \
    text/mplb.c \
    text/mwbb.c \
    text/pp.c \
    text/process_backward.c \
    text/process_even_odd.c \
    text/process_forward.c \
    text/process_forward2.c \
    text/process_forward_extra_option.c \
    text/r1ne.c \
    text/randomic.c \
    text/rc.c \
    text/remove_all.c \
    text/rt.c \
    text/tracer.c \
    text/y.c \
    editor.c \
    load.c \
    mle.c \
    move_cursor.c \
    mpweb.c \
    paste.c \
    rn.c \
    save.c \
    show.c \
    showlastnonspace.c \
    showlengths.c \
    shownonempty.c \
    shownum.c \
    showodd.c \
    showrev.c \
    showreveven.c \
    showunderscores.c \
    showupfirst.c \
    showwordbeginnings.c \
    myfunc.c

HEADERS += \
    myfunc.h \
    text/_text.h \
    text/text.h \
    common.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DISTFILES += \
    text/libtext.a

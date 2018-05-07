include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS +=  \
    ../app/text/_text.h \
    ../app/text/text.h \
    ../app/common.h \
    fibonachi_test.h

SOURCES +=        main.cpp \
../app/text/append_line.c \
    ../app/text/cd.c \
    ../app/text/create_text.c \
    ../app/text/cursors.c \
    ../app/text/delete_line.c \
    ../app/text/i.c \
    ../app/text/j.c \
    ../app/text/mcb.c \
    ../app/text/mp.c \
    ../app/text/mplb.c \
    ../app/text/mwbb.c \
    ../app/text/pp.c \
    ../app/text/process_backward.c \
    ../app/text/process_even_odd.c \
    ../app/text/process_forward.c \
    ../app/text/process_forward2.c \
    ../app/text/process_forward_extra_option.c \
    ../app/text/r1ne.c \
    ../app/text/randomic.c \
    ../app/text/rc.c \
    ../app/text/remove_all.c \
    ../app/text/rt.c \
    ../app/text/tracer.c \
    ../app/text/y.c \
    ../app/load.c \
    ../app/mle.c \
    ../app/move_cursor.c \
    ../app/mpweb.c \
    ../app/paste.c \
    ../app/rn.c \
    ../app/save.c \
    ../app/show.c \
    ../app/showlastnonspace.c \
    ../app/showlengths.c \
    ../app/shownonempty.c \
    ../app/shownum.c \
    ../app/showodd.c \
    ../app/showrev.c \
    ../app/showreveven.c \
    ../app/showunderscores.c \
    ../app/showupfirst.c \
    ../app/showwordbeginnings.c

DEFINES += SAMPLES_DIR=\\\"$$PWD\\\"

INCLUDEPATH += ../app

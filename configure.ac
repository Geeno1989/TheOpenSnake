AC_PREREQ(2.59)
AC_INIT([TheOpenSnake], [1.0], [BUG: ptkdev@gmail.com])

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_PROG_CC

AC_CONFIG_HEADERS([config.h])

PKG_CHECK_MODULES(gtk2, [gtk+-2.0 >= 2.30], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have gtk+-2.0 >= 2.39
])])

AC_SUBST(gtk_CFLAGS)
AC_SUBST(gtk_LIBS)

AC_CONFIG_FILES([
Makefile
src/Makefile
share/icons/Makefile
share/applications/Makefile
])
AC_OUTPUT

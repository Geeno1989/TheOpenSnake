bin_PROGRAMS = snake
twc_SOURCES = \
gui/main.c \
main.c

twc_LDADD = @gtk3_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@"\" \
	@gtk3_CFLAGS@ \

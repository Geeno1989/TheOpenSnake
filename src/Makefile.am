bin_PROGRAMS = snake
snake_SOURCES = \
gui/gui_lnx.c \
core/game.c \
gui/images.c \
main.c

snake_LDADD = @gtk2_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@"\" \
	@gtk2_CFLAGS@ 

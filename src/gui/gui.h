/*
 *	TheOpenSnake is free snake game for linux, windows, and mac osx
 *		Copyright (C) 2011  TheOpenSnake Team
 *
 *		This program is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		This program is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * 
 */
 
#ifndef GUI_MAIN_H


#define GUI_MAIN_H

#define MY_ENCODING "ISO-8859-1"

#include <gtk/gtk.h>
#include <glib.h>
#include <pthread.h>
#include <gdk/gdkkeysyms.h>

#define ICON_CLOSE ICONS_DIR"/menu.close.png"
#define ICON_FAVICON ICONS_DIR"/snake.favicon.png"

int gui_main();
GtkWidget* gtk_window_main_create();
GtkWidget* gtk_menu_item_create(GtkWidget* menu, const gchar const* title, const gchar const* image_path);
GtkWidget* gtk_menu_create(GtkWidget* menu_bar, const gchar const* name);
GtkWidget* gtk_menu_bar_create();
GtkWidget* gtk_status_bar_create();

#endif

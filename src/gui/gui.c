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

#include "gui.h"
 
GtkWidget*
gtk_status_bar_create()
{
  GtkWidget* statusbar = gtk_statusbar_new ();

  //gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR (statusbar), TRUE); deprecated gtk+-2.0
  gtk_statusbar_push (GTK_STATUSBAR (statusbar), 0, "");

  return statusbar;
}

GtkWidget*
gtk_menu_item_create(GtkWidget* menu, const gchar* title, const gchar* image_path)
{
  GtkWidget* item = gtk_image_menu_item_new_with_label(title);
  GtkWidget* image = gtk_image_new_from_file (image_path);

  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item), image);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);

  return item;
}

GtkWidget*
gtk_menu_create(GtkWidget* menu_bar, const gchar* name)
{
  GtkWidget* menu = gtk_menu_new();
  GtkWidget* item = gtk_menu_item_new_with_label(name);

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(item), menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), item);

  return menu;
}


GtkWidget*
gtk_menu_bar_create()
{
  GtkWidget* menubar = gtk_menu_bar_new();
  GtkWidget* menu;
  GtkWidget* item;

  menu = gtk_menu_create(menubar, "File");

  item = gtk_menu_item_create(menu, "Exit", ICON_CLOSE);
  g_signal_connect (G_OBJECT (item), 
                    "activate",
                    G_CALLBACK(gtk_main_quit), 
                    NULL);

  return menubar;
}
 
 
GtkWidget*
gtk_window_main_create()
{
  GtkWidget* window;
  GtkWidget* container;
  GtkWidget* menubar;
  GtkWidget* statusbar;

  GError* error = NULL;

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW(window), 300, 200);
  gtk_widget_set_size_request (window, 300, 200);
  gtk_window_set_title (GTK_WINDOW(window), TITLE);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_FAVICON, &error);

  container = gtk_vbox_new (FALSE, 0);

  menubar = gtk_menu_bar_create();
  statusbar = gtk_status_bar_create();

  gtk_box_pack_start(GTK_BOX(container), menubar, FALSE, TRUE, 0);	
  gtk_box_pack_end(GTK_BOX(container), statusbar, FALSE, TRUE, 0);

  gtk_container_add (GTK_CONTAINER (window), container);

  g_signal_connect_swapped(G_OBJECT(window), 
                    "destroy",
                    G_CALLBACK(gtk_main_quit), 
                    G_OBJECT(window));

  return window;
}

int
gui_main()
{
  g_thread_init (NULL);
  gdk_threads_init ();
  gtk_init (0, NULL);

  gtk_widget_show_all(gtk_window_main_create());

  gdk_threads_enter();
  gtk_main ();
  gdk_threads_leave ();

  return 0;
}


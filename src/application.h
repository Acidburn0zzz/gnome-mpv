/*
 * Copyright (c) 2016 gnome-mpv
 *
 * This file is part of GNOME MPV.
 *
 * GNOME MPV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GNOME MPV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNOME MPV.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include <gtk/gtk.h>
#include <mpv/client.h>
#include <mpv/opengl_cb.h>

#include "main_window.h"
#include "playlist.h"

G_BEGIN_DECLS

#define APPLICATION_TYPE (application_get_type ())

#define	APPLICATION(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), APPLICATION_TYPE, Application))

#define	APPLICATION_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), APPLICATION_TYPE, ApplicationClass))

#define	IS_APPLICATION(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), APPLICATION_TYPE))

#define	IS_APPLICATION_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE((klass), APPLICATION_TYPE))

struct _Application
{
	GtkApplication parent;
	mpv_handle *mpv_ctx;
	mpv_opengl_cb_context *opengl_ctx;
	gchar **files;
	gboolean opengl_ready;
	gboolean paused;
	gboolean loaded;
	gboolean new_file;
	gboolean sub_visible;
	gboolean init_load;
	gint64 vid_area_wid;
	guint inhibit_cookie;
	GSList *log_level_list;
	GSList *keybind_list;
	GSettings *config;
	MainWindow *gui;
	GtkWidget *fs_control;
	Playlist *playlist_store;
};

struct _ApplicationClass
{
	GtkApplicationClass parent_class;
};

typedef struct _Application Application;
typedef struct _ApplicationClass ApplicationClass;

Application *application_new(gchar *id, GApplicationFlags flags);
GType application_get_type(void);

G_END_DECLS

#endif

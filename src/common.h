/*
 * Copyright (c) 2014-2015 gnome-mpv
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

#ifndef COMMON_H
#define COMMON_H

#include <mpv/client.h>
#include <mpv/opengl_cb.h>

#include "main_window.h"

typedef struct module_log_level module_log_level;
typedef struct gmpv_handle gmpv_handle;

struct module_log_level
{
	gchar *prefix;
	mpv_log_level level;
};

struct gmpv_handle
{
	mpv_handle *mpv_ctx;
	gchar **files;
	mpv_opengl_cb_context *opengl_ctx;
	gboolean opengl_ready;
	gboolean paused;
	gboolean loaded;
	gboolean new_file;
	gboolean sub_visible;
	gboolean init_load;
	gint64 vid_area_wid;
	guint inhibit_cookie;
	gint playlist_move_dest;
	GSList *log_level_list;
	GSList *keybind_list;
	GSettings *config;
	GtkApplication *app;
	MainWindow *gui;
	GtkWidget *fs_control;
	GtkListStore *playlist_store;
};

gchar *get_config_dir_path(void);
gchar *get_config_file_path(void);
gchar *get_path_from_uri(const gchar *uri);
gchar *get_name_from_path(const gchar *path);
gboolean quit(gpointer data);
gboolean migrate_config(gmpv_handle *ctx);
gboolean update_seek_bar(gpointer data);
void seek(gmpv_handle *ctx, gdouble time);
void show_error_dialog(gmpv_handle *ctx, const gchar *prefix, const gchar *msg);
void remove_current_playlist_entry(gmpv_handle *ctx);
void resize_window_to_fit(gmpv_handle *ctx, gdouble multiplier);
void toggle_fullscreen(gmpv_handle *ctx);
GMenu *build_full_menu(void);
void load_keybind(	gmpv_handle *ctx,
			const gchar *config_path,
			gboolean notify_ignore );

#endif

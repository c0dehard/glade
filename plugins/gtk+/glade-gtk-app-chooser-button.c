/*
 * glade-gtk-app-chooser-button.c - GladeWidgetAdaptor for GtkAppChooserButton
 *
 * Copyright (C) 2013 Tristan Van Berkom
 *
 * Authors:
 *      Tristan Van Berkom <tristan.van.berkom@gmail.com>
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <config.h>
#include <glib/gi18n-lib.h>
#include <gladeui/glade.h>

#include "glade-app-chooser-button-editor.h"

void
glade_gtk_app_chooser_button_post_create (GladeWidgetAdaptor *adaptor,
                                          GObject            *object, 
                                          GladeCreateReason   reason)
{
  GladeWidget *gwidget;

  /* Chain Up */
  GLADE_WIDGET_ADAPTOR_GET_ADAPTOR_CLASS (GTK_TYPE_COMBO_BOX)->post_create (adaptor, object, reason);

  /* No customization of the cell renderers on a GtkAppChooserButton. */
  gwidget = glade_widget_get_from_gobject (object);
  glade_widget_set_action_visible (gwidget, "launch_editor", FALSE);
}

GladeEditable *
glade_gtk_app_chooser_button_create_editable (GladeWidgetAdaptor *adaptor,
                                              GladeEditorPageType type)
{
  if (type == GLADE_PAGE_GENERAL)
    {
      return (GladeEditable *) glade_app_chooser_button_editor_new ();
    }

  return GLADE_WIDGET_ADAPTOR_GET_ADAPTOR_CLASS (GTK_TYPE_CONTAINER)->create_editable (adaptor, type);
}

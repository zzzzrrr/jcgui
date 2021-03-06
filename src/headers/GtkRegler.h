/*
  * Copyright (C) 2009 Hermann Meyer and James Warden
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

// ***** GtkRegler.h *****
/******************************************************************************
part of Jc_Gui, use  knobs with Gtk
******************************************************************************/
#pragma once

class GtkRegler
{
private:

public:
    GtkRange parent;
    int regler_type;
    double start_x, start_y, start_value;

    GtkRegler();
    ~GtkRegler();

    static void gtk_regler_destroy ( );
    GtkWidget *gtk_hslider_new_with_adjustment(GtkAdjustment *_adjustment);
    GtkWidget *gtk_vslider_new_with_adjustment(GtkAdjustment *_adjustment);

    GtkWidget *gtk_regler_new_with_adjustment(GtkAdjustment *_adjustment);
    GtkWidget *gtk_big_regler_new_with_adjustment(GtkAdjustment *_adjustment);

    GtkWidget *gtk_button_toggle_new_with_adjustment(const char * label, GtkAdjustment *_adjustment);
    GtkWidget *gtk_button_new_with_adjustment(const char * label, GtkAdjustment *_adjustment);
};


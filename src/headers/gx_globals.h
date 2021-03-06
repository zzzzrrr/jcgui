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
 * --------------------------------------------------------------------------
 *
 *  This is the Jc_Gui global variable declarations for all namespaces
 *  These global vars are created  /  initialized in gx_globals.cpp
 *
 * --------------------------------------------------------------------------
 */

#pragma once

/* ----- main engine ----- */
namespace gx_engine
{
  /* engine state : can be on or off */
  typedef enum {
    kEngineOff    = 0,
    kEngineOn     = 1,
  } GxEngineState;

  /* global var  declarations */

  extern float  checky;
  extern float* get_frame;
  extern float* get_frame1;

  /* number of channels */
  extern int    gNumInChans;
  extern int    gNumOutChans;

  extern float* gInChannel [4];
  extern float* gOutChannel[4];

  /* latency warning  switch */
  extern float fwarn_swap;
  extern float fwarn;

  /* engine init state  */
  extern bool initialized;

  /* buffer ready state */
  extern bool buffers_ready;

  extern int is_setup;
}

/* -------------------------------------------------------------------------- */

/* ----- jack namespace ----- */
namespace gx_jack
{
  extern const int nIPorts; // mono input
  extern const int nOPorts; // stereo output + jconv
  extern int NO_CONNECTION;

  /* variables */
  extern jack_client_t*      client ;
  extern jack_port_t*        output_ports[];
  extern jack_port_t*        input_ports [];
  extern string              client_name;
  extern string              client_out_graph;
  extern string              gx_port_names[];

  /* lists of jack port types for menu items */
  enum {
    kAudioInput1    = 0,
    kAudioInput2    = 1,
    kAudioOutput1  = 2,
    kAudioOutput2  = 3,
    kMidiOutput    = 4
  };
}

/* -------------------------------------------------------------------------- */

/* ----- JConv namespace ----- */
namespace gx_jconv
{
  /* some global vars */
  extern float checkbox7;
  extern bool jconv_is_running;
}

/* -------------------------------------------------------------------------- */

/* ----- preset namespace ----- */
namespace gx_preset
{
  /* global var declarations */
  extern GdkModifierType list_mod[];
  extern const char* preset_accel_path[];
  extern const char* preset_menu_name[];
  extern map<GtkMenuItem*, string> preset_list[];

  extern string gx_current_preset;
  extern string old_preset_name;

  extern GtkWidget* presmenu[];
  extern GtkWidget* presMenu[];

  extern vector<string> plist;
  extern bool setting_is_preset;

  extern GCallback preset_action_func[];
}

/* -------------------------------------------------------------------------- */

/* ----- system namespace ----- */
namespace gx_system
{
  /* message handling */
  typedef enum {
    kInfo    = 1,
    kWarning,
    kError
  } GxMsgType;

  /* variables and constants */
  extern const int SYSTEM_OK;

  extern string rcpath;

  extern const char*  jc_gui_dir;
  extern const char*  jc_gui_preset;
  extern const char*  default_setting;
  extern const string gx_pixmap_dir;
  extern const string gx_user_dir;

  /* shell variable names */
  extern const char* shell_var_name[];
}

/* -------------------------------------------------------------------------- */

/* ----- GUI namespace ----- */
namespace gx_gui
{
  typedef enum {
    kWvMode1 = 1,
    kWvMode2,
    kWvMode3
  } GxWaveviewMode;


  /* global GUI widgets */
  extern GtkWidget* fWindow;
  extern GtkWidget* menuh;
  extern GtkWidget* pb;
  extern GtkWidget* fbutton;
  extern GtkWidget* jc_dialog;

  /* wave view widgets */

  extern GdkPixbuf* ib;
  extern GdkPixbuf* ibr;
  extern GdkPixbuf *tribeimage;
  extern GdkPixbuf *_image;
 // extern  const char * tribe_xpm[];

  /* jack server status */
  extern GtkWidget* gx_jackd_on_image;
  extern GtkWidget* gx_jackd_off_image;

  /* engine status images */
  extern GtkWidget* gx_engine_on_image;
  extern GtkWidget* gx_engine_off_image;

  extern GtkWidget* gx_engine_item;

  /* some more widgets */
  extern GtkWidget* label6;
  extern GtkWidget* label1;

  extern GtkStatusIcon* status_icon;

  extern int refresh_jack;
  extern int refresh_ports;

  extern bool new_wave_view;

  /* for level display */
  extern int meter_falloff;
  extern int meter_display_timeout;
  extern int update_gui;

  /* names of port lists (exclude MIDI for now) */
  extern string port_list_names[];

  /* client port queues */
  class StringComp
  {
  public:
    bool operator()(const string s1, const string s2) const
    {
      return s1.size() < s2.size();
    }
  };

  extern multimap<string, int, StringComp> gx_client_port_queue;
  extern multimap<string, int, StringComp> gx_client_port_dequeue;
}

/* -------------------------------------------------------------------------- */

//=============================================================================
//
// Adventure Game Studio (AGS)
//
// Copyright (C) 1999-2011 Chris Jones and 2011-20xx others
// The full list of copyright holders can be found in the Copyright.txt
// file, which is part of this source code distribution.
//
// The AGS source code is provided under the Artistic License 2.0.
// A copy of this license can be found in the file License.txt and at
// http://www.opensource.org/licenses/artistic-license-2.0.php
//
//=============================================================================
//
// Plugin system functions.
//
//=============================================================================
#ifndef __AGS_EE_PLUGIN__PLUGINENGINE_H
#define __AGS_EE_PLUGIN__PLUGINENGINE_H

#include <vector>
#include "game/game_init.h"
#include "game/plugininfo.h"

#define PLUGIN_FILENAME_MAX (49)

class IAGSEngine;
namespace AGS { namespace Common { class Stream; }}
using namespace AGS; // FIXME later

void pl_stop_plugins();
void pl_startup_plugins();
int  pl_run_plugin_hooks (int event, long data);
void pl_run_plugin_init_gfx_hooks(const char *driverName, void *data);
int  pl_run_plugin_debug_hooks (const char *scriptfile, int linenum);
// Tries to register plugins, either by loading dynamic libraries, or getting any kind of replacement
Engine::GameInitError pl_register_plugins(const std::vector<Common::PluginInfo> &infos);
bool pl_is_plugin_loaded(const char *pl_name);

//  Initial implementation for apps to register their own inbuilt plugins

struct InbuiltPluginDetails {
    char      filename[PLUGIN_FILENAME_MAX+1];
    void      (*engineStartup) (IAGSEngine *);
    void      (*engineShutdown) ();
    int       (*onEvent) (int, int);
    void      (*initGfxHook) (const char *driverName, void *data);
    int       (*debugHook) (const char * whichscript, int lineNumber, int reserved);
};

// Register a builtin plugin.
int pl_register_builtin_plugin(InbuiltPluginDetails const &details);

#endif // __AGS_EE_PLUGIN__PLUGINENGINE_H

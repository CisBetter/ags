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
//
//
//=============================================================================
#ifndef __AGS_EE_AC__PROPERTIES_H
#define __AGS_EE_AC__PROPERTIES_H

#include "game/customproperties.h"

int get_int_property (const AGS::Common::StringIMap &cprop, const char *property);
void get_text_property (const AGS::Common::StringIMap &cprop, const char *property, char *bufer);
const char* get_text_property_dynamic_string(const AGS::Common::StringIMap &cprop, const char *property);

void set_int_property(AGS::Common::StringIMap &cprop, const char *property, int value);
void set_text_property(AGS::Common::StringIMap &cprop, const char *property, const char* value);

#endif // __AGS_EE_AC__PROPERTIES_H

/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"
#include <serial_config.h>

#define USE_I2C
#define USE_SERIAL

#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    10
#define MOUSEKEY_MAX_SPEED      5
#define MOUSEKEY_WHEEL_MAX_SPEED 1
#define MOUSEKEY_WHEEL_DELAY 100
#define MOUSEKEY_WHEEL_TIME_TO_MAX 5

#define PREVENT_STUCK_MODIFIERS
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#ifdef USE_Link_Time_Optimization
  // LTO has issues with macros (action_get_macro) and "functions" (fn_actions),
  //  so just disable them
  #define NO_ACTION_MACRO
  #define NO_ACTION_FUNCTION

  #define DISABLE_LEADER
#endif // USE_Link_Time_Optimization

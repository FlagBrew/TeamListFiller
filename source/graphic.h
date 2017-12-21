/* This file is part of TeamListFiller

Copyright (C) 2017 Bernardo Giordano
	 
>    This program is free software: you can redistribute it and/or modify
>    it under the terms of the GNU General Public License as published by
>    the Free Software Foundation, either version 3 of the License, or
>    (at your option) any later version.
>
>    This program is distributed in the hope that it will be useful,
>    but WITHOUT ANY WARRANTY; without even the implied warranty of
>    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
>    GNU General Public License for more details.
>
>    You should have received a copy of the GNU General Public License
>    along with this program.  If not, see <http://www.gnu.org/licenses/>.
>    See LICENSE for information.
*/

#pragma once

#include "pp2d/pp2d.h"

#define WARNINGTOP 1
#define WARNINGBOTTOM 2
#define BORDER 3

#define BLUE      RGBA8(104, 137, 205, 255)
#define YELLOW    RGBA8(237, 247, 157, 255)
#define LIGHTBLUE RGBA8(187, 208, 254, 255)
#define DARKBLUE  RGBA8( 35,  69, 167, 255)
#define HIGHBLUE  RGBA8( 28,  45,  86, 255) 
#define PALEBLUE  RGBA8( 70,  95, 144, 255)
#define MENUBLUE  RGBA8( 35,  69, 137, 255)

#define BLACK RGBA8(0, 0, 0, 255)
#define SHINYRED RGBA8(255, 17, 17, 255)
#define WHITE RGBA8(255, 255, 255, 255)

#define FONT_SIZE_18 0.72f
#define FONT_SIZE_15 0.6f
#define FONT_SIZE_12 0.50f
#define FONT_SIZE_9 0.37f

#ifdef __cplusplus
extern "C" {
#endif
void GUIElementsInit();
void gameSelectorMenu(int n);
void infoDisp(const char* message);
void freezeMsg(const char* message);
#ifdef __cplusplus
}
#endif
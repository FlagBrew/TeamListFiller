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

#include <stdio.h>
#include "graphic.h"

char *gamesList[] = {"US", "UM"};

void GUIElementsInit() {
	pp2d_load_texture_png(WARNINGTOP, "romfs:/res/Warning Top.png");
	pp2d_load_texture_png(WARNINGBOTTOM, "romfs:/res/Warning Bottom.png");
	pp2d_load_texture_png(BORDER, "romfs:/res/3dsborder.png");
}

void printMenuTop() {
	pp2d_draw_rectangle(0, 0, 400, 240, MENUBLUE);
	pp2d_draw_rectangle(0, 0, 400, 25, HIGHBLUE);
}

void printMenuBottom() {
	pp2d_draw_rectangle(0, 0, 320, 240, PALEBLUE);
	pp2d_draw_rectangle(0, 219, 320, 21, MENUBLUE);
}

void infoDisp(const char* message) {
	while (aptMainLoop()) {
		hidScanInput();

		if (hidKeysDown() & KEY_A) break;
		
		pp2d_begin_draw(GFX_TOP, GFX_LEFT);
			pp2d_draw_texture(WARNINGTOP, 0, 0);
			pp2d_draw_text_center(GFX_TOP, 95, FONT_SIZE_15, FONT_SIZE_15, WHITE, message);
			pp2d_draw_text_center(GFX_TOP, 130, FONT_SIZE_12, FONT_SIZE_12, WHITE, "Press A to continue.");
		
			pp2d_draw_on(GFX_BOTTOM, GFX_LEFT);
			pp2d_draw_texture(WARNINGBOTTOM, 0, 0);
		pp2d_end_draw();
	}
}

int confirmDisp() {
	while (aptMainLoop()) {
		hidScanInput();

		if (hidKeysDown() & KEY_A) return 1;
		if (hidKeysDown() & KEY_B) return 0;
		
		pp2d_begin_draw(GFX_TOP, GFX_LEFT);
			pp2d_draw_texture(WARNINGTOP, 0, 0);
			pp2d_draw_text_center(GFX_TOP, 95, FONT_SIZE_15, FONT_SIZE_15, WHITE, "Cartridge or digital copy?");
			pp2d_draw_text_center(GFX_TOP, 130, FONT_SIZE_12, FONT_SIZE_12, WHITE, "A for cartridge, B for digital.");

			pp2d_draw_on(GFX_BOTTOM, GFX_LEFT);
			pp2d_draw_texture(WARNINGBOTTOM, 0, 0);
		pp2d_end_draw();
	}
	return 0;
}

void freezeMsg(const char* message) {
	pp2d_begin_draw(GFX_TOP, GFX_LEFT);
		pp2d_draw_texture(WARNINGTOP, 0, 0);
		pp2d_draw_text_center(GFX_TOP, 95, FONT_SIZE_15, FONT_SIZE_15, WHITE, message);
		pp2d_draw_text_center(GFX_TOP, 130, FONT_SIZE_12, FONT_SIZE_12, WHITE, "Please wait.");
	
		pp2d_draw_on(GFX_BOTTOM, GFX_LEFT);
		pp2d_draw_texture(WARNINGBOTTOM, 0, 0);
	pp2d_end_draw();
}

void printBottomIndications(const char* message) {
	pp2d_draw_text_center(GFX_BOTTOM, 225, FONT_SIZE_9, FONT_SIZE_9, LIGHTBLUE, message);
}

void gameSelectorMenu(int n) {
	pp2d_begin_draw(GFX_TOP, GFX_LEFT);
		printMenuTop();
		pp2d_draw_text_center(GFX_TOP, 6, FONT_SIZE_9, FONT_SIZE_9, BLUE, "Cart has priority over digital copy.");
		pp2d_draw_texture(BORDER, 146 + 60 * n, 112);
		
		for (int i = 0; i < 2; i++) 
			pp2d_draw_text(142 + 60 * i + (68 - pp2d_get_text_width(gamesList[i], FONT_SIZE_18, FONT_SIZE_18)) / 2, 129, FONT_SIZE_18, FONT_SIZE_18, LIGHTBLUE, gamesList[i]);
	
		pp2d_draw_on(GFX_BOTTOM, GFX_LEFT);
		printMenuBottom();
		printBottomIndications("Move your DPAD. Press A to continue, B to exit.");
	pp2d_end_draw();
}
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

#include <3ds.h>
#include <stdio.h>

#define PKMNLENGTH 232
#define MOVELENGTH 2
#define EVLENGTH 1
#define IVLENGTH 4
#define POKEDEXNUMBERLENGTH 2
#define ABILITYLENGTH 1
#define NATURELENGTH 1
#define GENDERLENGTH 1
#define ITEMLENGTH 2
#define EXPPOINTLENGTH 4

struct {
	u8 pkmData[961][42];
} personal;

u32 seedStep(const u32 seed);
void shuffleArray(u8* pkmn, const u32 encryptionkey);
void decryptPkmn(u8* pkmn);
int getPkmnAddress(const int boxnumber, const int indexnumber);
void getPkmn(u8* mainbuf, const int boxnumber, const int indexnumber, u8* pkmn);

u8 getGender(u8* pkmn);
u16 getPokedexNumber(u8* pkmn);
u8 getNature(u8* pkmn);
u8 getEV(u8* pkmn, const int stat);
u8 getIV(u8* pkmn, const int stat);
u16 getMove(u8* pkmn, int nmove);
u16 getItem(u8* pkmn);
u8 getLevel(u8* pkmn);
u8 getForm(u8* pkmn);
u16 getStat(u8* pkmn, const int stat);
u8 getAbility(u8* pkmn);
u8 getHPType(u8* pkmn);
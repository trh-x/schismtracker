/*
 * Schism Tracker - a cross-platform Impulse Tracker clone
 * copyright (c) 2003-2005 Storlek <storlek@rigelseven.com>
 * copyright (c) 2005-2008 Mrs. Brisby <mrs.brisby@nimh.org>
 * copyright (c) 2009 Storlek & Mrs. Brisby
 * copyright (c) 2010-2012 Storlek
 * URL: http://schismtracker.org/
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "backend/init.h"

#include <SDL.h>

int sdl2_init(void)
{
	int r = SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
	if (r < 0) {
		fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
		return r;
	}

	SDL_StartTextInput();
	SDL_SetHint(SDL_HINT_GRAB_KEYBOARD, "1");
	SDL_EventState(SDL_DROPFILE, SDL_ENABLE);

#ifdef SCHISM_CONTROLLER
	controller_init();
#endif

#ifdef SCHISM_WIN32
	SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
#endif

	return r;
}

void sdl2_quit(void)
{
#ifdef SCHISM_CONTROLLER
	controller_quit();
#endif

	SDL_Quit();
}

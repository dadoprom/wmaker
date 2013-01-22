/*
 *  Window Maker window manager
 *
 *  Copyright (c) 1997-2003 Alfredo K. Kojima
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


#ifndef WMICON_H_
#define WMICON_H_

#include "wcore.h"
#include "window.h"
#include "funcs.h"

#define TILE_NORMAL	0
#define TILE_CLIP	1

typedef struct WIcon {
	WCoreWindow 	*core;
	WWindow 	*owner;		/* owner window */
	char 		*icon_name;	/* the icon name hint */

	Window 		icon_win;	/* client suplied icon window */

	char		*file;		/* the file with the icon image */
	RImage 		*file_image;	/* the image from the file */

	unsigned int 	tile_type:4;
	unsigned int 	show_title:1;
	unsigned int 	selected:1;
	unsigned int	step:3;		/* selection cycle step */
	unsigned int	shadowed:1;	/* If the icon is to be blured */
	unsigned int 	mapped:1;
	unsigned int	highlighted:1;

	Pixmap 		pixmap;

	WMHandlerID	handlerID;	/* timer handler ID for cycling select
					 * color */
} WIcon;

WIcon *icon_create_for_dock(WScreen *scr, char *command, char *wm_instance, char *wm_class, int tile);
WIcon *icon_create_for_wwindow(WWindow *wwin);

void set_icon_image_from_database(WIcon *icon, char *wm_instance, char *wm_class, char *command);
void wIconDestroy(WIcon *icon);
void wIconPaint(WIcon *icon);
void wIconUpdate(WIcon *icon, RImage *image);
void wIconSelect(WIcon *icon);
void wIconChangeTitle(WIcon *icon, char *new_title);
void update_icon_pixmap(WIcon *icon);

Bool wIconChangeImageFile(WIcon *icon, char *file);

RImage *wIconValidateIconSize(RImage *icon, int max_size);
RImage *get_rimage_icon_from_wm_hints(WIcon *icon);

char *wIconStore(WIcon *icon);
char *get_name_for_instance_class(char *wm_instance, char *wm_class);

void wIconSetHighlited(WIcon *icon, Bool flag);

#endif /* WMICON_H_ */

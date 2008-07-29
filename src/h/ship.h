#ifndef SHIP_H
#define SHIP_H

#include <libxml/xmlstring.h>


/****************************************************************************
			     Function prototypes
****************************************************************************/

void
ship_create (int number);


void
ship_room_set_door (int room_id, xmlChar *direction);


#endif /* SHIP_H */

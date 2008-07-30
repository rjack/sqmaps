#ifndef SHIP_H
#define SHIP_H

#include <libxml/xmlstring.h>


/****************************************************************************
			     Function prototypes
****************************************************************************/


/* Ship creation functions. */


void
ship_create (int number);


void
ship_room_set_door (int room_id, xmlChar *direction);


void
ship_room_set_extra (int room_id);


void
ship_room_set_power_up (int room_id);


void
ship_room_set_self_destruct (int room_id);


void
ship_room_set_sonic_key (int room_id);


void
ship_room_set_stairs (int room_id, xmlChar *direction, int destination_id);


void
ship_room_set_symbol (int room_id);


void
ship_room_set_teleport (int room_id);


void
ship_room_set_weapon (int room_id);


/* Ship map functions. */


void
ship_compute_shortest_path (void);


void
ship_find_paths (void);


void
ship_output_solution (void);

#endif /* SHIP_H */

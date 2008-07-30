#include "h/const.h"
#include "h/types.h"

#include <libxml/xmlstring.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


/****************************************************************************
			       Static variables
****************************************************************************/

static struct ship Ship;


/****************************************************************************
			     Function prototypes
****************************************************************************/

static void room_init (struct room *room);


/****************************************************************************
			       Public functions
****************************************************************************/

/* Ship creation functions. */


void
ship_create (int id)
{
	int i;

	assert (id > 0 && id < 8);

	Ship.s_room_quantity = ROOMS_PER_LEVEL * id;
	Ship.s_symbol_quantity = 0;
	Ship.s_sonic_key_quantity = 0;
	Ship.s_mirror_quantity = 0;
	Ship.s_weapon_quantity = 0;
	Ship.s_extra_quantity = 0;
	Ship.s_power_up_quantity = 0;

	Ship.s_room = malloc (Ship.s_room_quantity * sizeof(struct room));
	if (Ship.s_room == NULL) {
		perror ("Cannot allocate memory.");
		exit (EXIT_FAILURE);
	}

	for (i = 0; i < Ship.s_room_quantity; i++)
		room_init (&Ship.s_room[i]);
}


void
ship_room_set_door (int room_id, xmlChar *direction)
{
	assert (direction != NULL);

	if (xmlStrEqual (direction, BAD_CAST "north"))
		Ship.s_room[room_id].r_north = room_id - 4;
	else if (xmlStrEqual (direction, BAD_CAST "east"))
		Ship.s_room[room_id].r_east = room_id + 1;
	else if (xmlStrEqual (direction, BAD_CAST "west"))
		Ship.s_room[room_id].r_west = room_id - 1;
	else if (xmlStrEqual (direction, BAD_CAST "south"))
		Ship.s_room[room_id].r_south = room_id + 4;
	else {
		fprintf (stderr, "Invalid door direction: %s\n", direction);
		exit (EXIT_FAILURE);
	}
}


void
ship_room_set_extra (int room_id)
{
	Ship.s_room[room_id].r_extra = 1;
	Ship.s_extra_quantity++;
}


void
ship_room_set_power_up (int room_id)
{
	Ship.s_room[room_id].r_power_up = 1;
	Ship.s_power_up_quantity++;
}


void
ship_room_set_self_destruct (int room_id)
{
	Ship.s_room[room_id].r_self_destruct = 1;
}


void
ship_room_set_sonic_key (int room_id)
{
	Ship.s_room[room_id].r_sonic_key = 1;
	Ship.s_sonic_key_quantity++;
}


void
ship_room_set_stairs (int room_id, xmlChar *direction, int destination_id)
{
	assert (direction != NULL);

	if (xmlStrEqual (direction, BAD_CAST "up"))
		Ship.s_room[room_id].r_up = destination_id;
	else if (xmlStrEqual (direction, BAD_CAST "down"))
		Ship.s_room[room_id].r_down = destination_id;
	else {
		fprintf (stderr, "Invalid stairs direction: %s\n", direction);
		exit (EXIT_FAILURE);
	}
}


void
ship_room_set_symbol (int room_id)
{
	Ship.s_room[room_id].r_symbol = 1;
	Ship.s_symbol_quantity++;
}


void
ship_room_set_teleport (int room_id)
{
	Ship.s_room[room_id].r_teleport = 1;
}


void
ship_room_set_weapon (int room_id)
{
	Ship.s_room[room_id].r_weapon = 1;
	Ship.s_weapon_quantity++;
}


/* Ship map functions. */


void
ship_compute_shortest_path (void)
{
	/* TODO */
}


void
ship_find_paths (void)
{
	/* TODO */
}


void
ship_output_solution (void)
{
	/* TODO */
}


/****************************************************************************
			       Static functions
****************************************************************************/

static void
room_init (struct room *room)
{
	assert (room != NULL);

	room->r_north = -1;
	room->r_south = -1;
	room->r_east = -1;
	room->r_west = -1;

	room->r_up = -1;
	room->r_down = -1;
	room->r_mirror = -1;

	room->r_symbol = 0;
	room->r_sonic_key = 0;
	room->r_weapon = 0;
	room->r_teleport = 0;
	room->r_self_destruct = 0;
	room->r_power_up = 0;
	room->r_extra = 0;
}

/*
 * Copyright (c) 2008 Giacomo Ritucci
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY GIACOMO RITUCCI ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 * NO EVENT SHALL GIACOMO RITUCCI BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "h/types.h"
#include "h/util.h"

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

	for (i = 0; i < ROOM_TYPES_NUM; i++)
		Ship.s_room_quantity[i] = 0;

	Ship.s_room_quantity[GENERIC_ROOM] = ROOMS_PER_LEVEL * id;

	Ship.s_room = malloc (Ship.s_room_quantity[GENERIC_ROOM] * sizeof(struct room));
	check_allocation (Ship.s_room);

	for (i = 0; i < Ship.s_room_quantity[GENERIC_ROOM]; i++)
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
ship_room_set_type (int room_id, room_type_t room_type)
{
	struct room *room;

	assert (room_type != GENERIC_ROOM);

	room = &Ship.s_room[room_id];
	
	room->r_type = room_type;
	Ship.s_room_quantity[room_type]++;

	assert (room->r_targets == NULL);
	room->r_targets = calloc (1, sizeof(struct path_to));
	check_allocation (room->r_targets);
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

	room->r_type = GENERIC_ROOM;

	room->r_targets = NULL;
}

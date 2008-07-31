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

static void room_init (struct room *room, room_id_t room_id);


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
		room_init (&Ship.s_room[i], i);
}


void
ship_room_set_door (room_id_t room_id, xmlChar *direction)
{
	/* FIXME
	struct room *current_room;
	struct node *new_adj;
	room_id_t destination_id;

	assert (direction != NULL);

	new_adj= create_node ();
	current_room = &Ship.s_room[room_id];

	if (xmlStrEqual (direction, BAD_CAST "north"))
		destination_id = room_id - 4;
	else if (xmlStrEqual (direction, BAD_CAST "east"))
		destination_id = room_id + 1;
	else if (xmlStrEqual (direction, BAD_CAST "west"))
		destination_id = room_id - 1;
	else if (xmlStrEqual (direction, BAD_CAST "south"))
		destination_id = room_id + 4;
	else {
		fprintf (stderr, "Invalid door direction: %s\n", direction);
		exit (EXIT_FAILURE);
	}

	new_adj->n_room = &Ship.s_room[destination_id];

	* Inserimento in testa alla lista degli adiacenti. *
	new_adj->n_next = current_room->r_adjacent;
	current_room->r_adjacent = new_adj;
	*/
}


void
ship_room_set_stairs (int room_id, xmlChar *direction, int destination_id)
{
	assert (direction != NULL);

	if (xmlStrEqual (direction, BAD_CAST "up"))
		/* FIXME Ship.s_room[room_id].r_up = destination_id; */
		;
	else if (xmlStrEqual (direction, BAD_CAST "down"))
		/* FIXME Ship.s_room[room_id].r_down = destination_id; */
		;
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

	/* FIXME
	assert (room->r_targets == NULL);
	room->r_targets = calloc (1, sizeof(struct path_to));
	check_allocation (room->r_targets);
	*/
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
room_init (struct room *room, room_id_t room_id)
{
	assert (room != NULL);

	room->r_id = room_id;

	/* FIXME room->r_adjacent = NULL; */

	room->r_type = GENERIC_ROOM;

	/* FIXME room->r_targets = NULL; */
}

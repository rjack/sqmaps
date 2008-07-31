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


#include "h/ship.h"

#include <libxml/xmlreader.h>
#include <libxml/xmlstring.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/****************************************************************************
			     Function prototypes
****************************************************************************/

static void 		process_node		(xmlTextReaderPtr reader);

static int 		node_has_name		(xmlTextReaderPtr reader,
						 xmlChar *node_name,
						 char *str);


/****************************************************************************
			       Public functions
****************************************************************************/

int
main (int argc, char **argv)
{
	int ret;
	char *file_path;
	xmlTextReaderPtr reader;

	file_path = argv[1];
	reader = xmlNewTextReaderFilename (file_path);
	if (reader != NULL) {
		while ((ret = xmlTextReaderRead (reader)) == 1)
			process_node (reader);
		xmlFreeTextReader (reader);
		if (ret != 0)
			fprintf (stderr, "Errore durante la lettura del file %s\n", file_path);
	} else
		fprintf (stderr, "Impossibile aprire il file %s\n", file_path);

	ship_find_paths ();

	ship_compute_shortest_path ();

	ship_output_solution ();

	return 0;
}


/****************************************************************************
			       Static functions
****************************************************************************/

static void
process_node (xmlTextReaderPtr reader)
{
	static int cur_room_id;
	xmlChar *element_name;
	xmlChar *attr_value;

	attr_value = NULL;
	element_name = xmlTextReaderName (reader);
	if (element_name == NULL)
		element_name = xmlStrdup (BAD_CAST "--");

	/* ship */
	else if (node_has_name (reader, element_name, "ship")) {
		attr_value = xmlTextReaderGetAttribute (reader,
				BAD_CAST "number");
		ship_create (atoi ((char *)attr_value));
	}

	/* new room */
	else if (node_has_name (reader, element_name, "room")) {
		attr_value = xmlTextReaderGetAttribute (reader,
				BAD_CAST "id");
		cur_room_id = atoi ((char *)attr_value);
	}

	/* door */
	else if (node_has_name (reader, element_name, "door")) {
		attr_value = xmlTextReaderGetAttribute (reader,
				BAD_CAST "dir");
		ship_room_set_door (cur_room_id, attr_value);
	}

	/* start */
	else if (node_has_name (reader, element_name, "start"))
		ship_room_set_type (cur_room_id, START_ROOM);

	/* extra */
	else if (node_has_name (reader, element_name, "extra"))
		ship_room_set_type (cur_room_id, EXTRA_ROOM);

	/* power-up */
	else if (node_has_name (reader, element_name, "power-up"))
		ship_room_set_type (cur_room_id, POWER_UP_ROOM);

	/* self-destruct */
	else if (node_has_name (reader, element_name, "self-destruct"))
		ship_room_set_type (cur_room_id, SELF_DESTRUCT_ROOM);

	/* sonic-key */
	else if (node_has_name (reader, element_name, "sonic-key"))
		ship_room_set_type (cur_room_id, SONIC_KEY_ROOM);

	/* mirror */
	else if (node_has_name (reader, element_name, "mirror"))
		ship_room_set_type (cur_room_id, MIRROR_ROOM);

	/* stairs */
	else if (node_has_name (reader, element_name, "stairs")) {
		xmlChar *direction;
		xmlChar *destination;

		direction = xmlTextReaderGetAttribute (reader, BAD_CAST "dir");
		destination = xmlTextReaderGetAttribute (reader, BAD_CAST "to");

		ship_room_set_stairs (cur_room_id, direction,
				atoi ((char *)destination));
		free (direction);
		free (destination);
	}

	/* symbol */
	else if (node_has_name (reader, element_name, "symbol"))
		ship_room_set_type (cur_room_id, SYMBOL_ROOM);

	/* teleport */
	else if (node_has_name (reader, element_name, "teleport"))
		ship_room_set_type (cur_room_id, TELEPORT_ROOM);

	/* weapon */
	else if (node_has_name (reader, element_name, "weapon"))
		ship_room_set_type (cur_room_id, WEAPON_ROOM);

	free (element_name);
	if (attr_value != NULL)
		free (attr_value);
}


static int
node_has_name (xmlTextReaderPtr reader, xmlChar *node_name, char *str)
{
	return (xmlTextReaderNodeType (reader) == XML_ELEMENT_NODE
		&& xmlStrEqual (node_name, BAD_CAST str));
}

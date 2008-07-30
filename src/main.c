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
	xmlChar *name;

	name = xmlTextReaderName (reader);
	if (name == NULL)
		name = xmlStrdup (BAD_CAST "--");

	/* ship */
	else if (node_has_name (reader, name, "ship"))
		ship_create (atoi ((char *)xmlTextReaderGetAttribute (reader, BAD_CAST "number")));

	/* new room */
	else if (node_has_name (reader, name, "room"))
		cur_room_id = atoi ((char *)xmlTextReaderGetAttribute (reader, BAD_CAST "id"));

	/* door */
	else if (node_has_name (reader, name, "door")) {
		xmlChar *direction;

		direction = xmlTextReaderGetAttribute (reader, BAD_CAST "dir");
		ship_room_set_door (cur_room_id, direction);
	}

	/* extra */
	else if (node_has_name (reader, name, "extra"))
		ship_room_set_extra (cur_room_id);

	/* power-up */
	else if (node_has_name (reader, name, "power-up"))
		ship_room_set_power_up (cur_room_id);

	/* self-destruct */
	else if (node_has_name (reader, name, "self-destruct"))
		ship_room_set_self_destruct (cur_room_id);

	/* sonic-key */
	else if (node_has_name (reader, name, "sonic-key"))
		ship_room_set_sonic_key (cur_room_id);

	/* stairs */
	else if (node_has_name (reader, name, "stairs")) {
		xmlChar *direction;
		xmlChar *destination;

		direction = xmlTextReaderGetAttribute (reader, BAD_CAST "dir");
		destination = xmlTextReaderGetAttribute (reader, BAD_CAST "to");

		ship_room_set_stairs (cur_room_id, direction,
				atoi ((char *)destination));
	}

	/* symbol */
	else if (node_has_name (reader, name, "symbol"))
		ship_room_set_symbol (cur_room_id);

	/* teleport */
	else if (node_has_name (reader, name, "teleport"))
		ship_room_set_teleport (cur_room_id);

	/* weapon */
	else if (node_has_name (reader, name, "weapon"))
		ship_room_set_weapon (cur_room_id);
}


static int
node_has_name (xmlTextReaderPtr reader, xmlChar *node_name, char *str)
{
	return (xmlTextReaderNodeType (reader) == XML_ELEMENT_NODE
		&& xmlStrEqual (node_name, BAD_CAST str));
}

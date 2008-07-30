/* 
 * sqm - calcola il percorso migliore per risolvere un livello di SecretQuest
 *
 * uso:
 *
 * 	sqm [ FILE ... ]
 *
 * se FILE e' assente, legge da standard input.
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
	/* 
	 * TODO
	 * [x] lettura file xml mappe
	 * [x] costruzione struttura dati
	 * [ ] calcola soluzione
	 * [ ] manda in output la soluzione
	 */

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

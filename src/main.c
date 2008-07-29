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


void
processNode (xmlTextReaderPtr reader)
{
	static int cur_room_id;
	xmlChar *name;

	name = xmlTextReaderName (reader);
	if (name == NULL)
		name = xmlStrdup (BAD_CAST "--");

	/* ship */
	if (xmlTextReaderNodeType (reader) == XML_ELEMENT_NODE
	    && xmlStrEqual (name, BAD_CAST "ship"))
		ship_create (atoi ((char *)xmlTextReaderGetAttribute (reader, BAD_CAST "number")));

	/* room */
	if (xmlTextReaderNodeType (reader) == XML_ELEMENT_NODE
	    && xmlStrEqual (name, BAD_CAST "room")) {
		cur_room_id = atoi ((char *)xmlTextReaderGetAttribute (reader, BAD_CAST "id"));
	}

	/* door */
	if (xmlTextReaderNodeType (reader) == XML_ELEMENT_NODE
	    && xmlStrEqual (name, BAD_CAST "door")) {
		xmlChar *direction;

		direction = xmlTextReaderGetAttribute (reader, BAD_CAST "dir");
		ship_room_set_door (cur_room_id, direction);
	}
}


int
main (int argc, char **argv)
{
	/* 
	 * TODO
	 * [ ] lettura file xml mappe
	 * [ ] costruzione struttura dati
	 * [ ] per ogni livello
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
			processNode (reader);
		xmlFreeTextReader (reader);
		if (ret != 0)
			fprintf (stderr, "Errore durante la lettura del file %s\n", file_path);
	} else
		fprintf (stderr, "Impossibile aprire il file %s\n", file_path);

	return 0;
}

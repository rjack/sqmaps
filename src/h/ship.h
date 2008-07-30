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

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


#ifndef SQMAPS_TYPES_H
#define SQMAPS_TYPES_H

#include <sys/types.h>


#define     ROOMS_PER_LEVEL     16

#define     ROOM_TYPES_NUM      10 


enum room_types {
	GENERIC_ROOM,
	START_ROOM,
	SYMBOL_ROOM,
	SONIC_KEY_ROOM,
	MIRROR_ROOM,
	WEAPON_ROOM,
	EXTRA_ROOM,
	POWER_UP_ROOM,
	SELF_DESTRUCT_ROOM,
	TELEPORT_ROOM
};


typedef u_int8_t bool_t;

#ifdef      TRUE
#undef      TRUE
#endif
#ifdef      FALSE
#undef      FALSE
#endif
#define     TRUE       ((bool_t)1)
#define     FALSE      ((bool_t)0)


typedef u_int8_t room_id_t;

typedef enum room_types room_type_t;

typedef unsigned int path_lenght_t;

struct path {
	path_lenght_t p_length;

	/* Array di puntatori a room, lungo p_length. */
	struct room *p_step;
};


/* Struttura per memorizzare i percorsi verso i vari punti importanti della
 * mappa. */
struct path_to {
	/* Sono tutti array di puntatori a path, tranne per sp_self_destruct e
	 * sp_teleport che sono sicuramente singoli in una nave. */
	struct path **sp_symbol;
	struct path **sp_sonic_key;
	struct path **sp_mirror;
	struct path **sp_weapon;
	struct path **sp_bonus;
	struct path **sp_power_up;
	struct path *sp_self_destruct;
	struct path *sp_teleport;
};


struct room {
	room_id_t r_id;
	room_type_t r_type;
};


struct ship {
	/* Quantita' di stanze speciali. */
	unsigned int s_room_quantity[ROOM_TYPES_NUM];

	/* Array di room, lungo room_quantity. */
	struct room *s_room;
};


#endif /* SQMAPS_TYPES_H */

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


typedef unsigned int path_lenght_t;


struct room {
	/* Id della room di destinazione, -1 se assente. */
	int r_east;
	int r_north;
	int r_south;
	int r_west;

	/* Id della room di destinazione, -1 se assente. */
	int r_down;
	int r_mirror;
	int r_up;

	/* Booleani */
	unsigned int r_extra:1;
	unsigned int r_power_up:1;
	unsigned int r_self_destruct:1;
	unsigned int r_sonic_key:1;
	unsigned int r_symbol:1;
	unsigned int r_teleport:1;
	unsigned int r_weapon:1;
};


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


struct ship {
	/* Quantita' di oggetti presenti nella nave. */
	unsigned int s_room_quantity;
	unsigned int s_symbol_quantity;
	unsigned int s_sonic_key_quantity;
	unsigned int s_mirror_quantity;
	unsigned int s_weapon_quantity;
	unsigned int s_extra_quantity;
	unsigned int s_power_up_quantity;

	/* Array di room, lungo room_quantity. */
	struct room *s_room;
};


#endif /* SQMAPS_TYPES_H */

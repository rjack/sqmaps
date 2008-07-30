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

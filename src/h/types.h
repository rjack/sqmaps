#ifndef SQMAPS_TYPES_H
#define SQMAPS_TYPES_H

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


struct ship {
	/* da 1 a 8, determina il numero di room. */
	int s_id;

	struct room *s_room;
};


#endif /* SQMAPS_TYPES_H */

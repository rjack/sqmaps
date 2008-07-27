struct room {
	/* da 0 a 127 */
	int id;

	/* Id della room di destinazione, -1 se assente. */
	int north;
	int south;
	int west;
	int east;

	/* Id della room di destinazione, -1 se assente. */
	int up;
	int down;
	int mirror;

	/* Booleani */
	unsigned int symbol:1;
	unsigned int sonic_key:1;
	unsigned int weapon:1;
	unsigned int teleport:1;
	unsigned int self_destruct:1;
	unsigned int zap:1;
	unsigned int power_up:1;
	unsigned int extra:1;
};


struct ship {
	/* da 0 a 7, determina il numero di room. */
	int id;

	struct room *room;
};

/*
	Map maker
	load map from txt file and put in lvl file with map data and objects

*/

#include "MZRUN/GLOBALS.H"

struct Creator {
	struct Save data;
	char cmap[MaxY][MaxX];
	char list[50];
	struct coord pos;
	bool end;
	/*
	void draw();
	void input();
	bool move(int PosX, int PosY);
	void create_object(char c);
	void make_map();
	void create_lvl();*/
};

void Creator_init(struct Creator *this) {
	this->pos.x = this->pos.y = 1;	this->end = false;
}

void Creator_draw(struct Creator *this) {
}

void Creator_create_object(struct Creator *this, char c) {
}

void Creator_make_map(struct Creator *this)  {
}

void Creator_input(struct Creator *this) {
	/*gotoxy(1,25);	cout<<this->x<<", "<<this->y;
	gotoxy(this->x, this->y);
	switch(getch()) {
		case 'w':   this->move(+0, -1);
					break;
		case 's':   this->move(+0, +1);
					break;
		case 'a':   this->move(-1, +0);
					break;
		case 'd':   this->move(+1, +0);
					break;
		case '3':
		case '#':	wall.draw();
					map[this->y-1][this->x-1].block();
					break;
		case '.':	air.draw();
					map[this->y-1][this->x-1].unblock();
					for(int i = 1; i < level->totalEntities; i++) {
						if(entityObjects[i].isThere(this->x, this->y)) {
							for(int j = i; j < level->totalEntities; j++) {
								entityObjects[j] = entityObjects[j+1];
							}
							level->totalEntities--;
							break;
						}
					}
					break;
		case '@':	create_object('@');
					break;
		case '*':	create_object('*');
					break;
		//case 13:	create_object();
		//			break;
		case 27:   this->end = true;
					break;
	}*/
}

bool Creator_move(struct Creator *this, int PosX, int PosY) {
	return true;
}

void Creator_create_lvl(struct Creator *this) {
	int i = 0, j;
	struct Object *temp;
	struct tmp;
	FILE *file;
	//Create Map file
	coord_init(&fullmap, 60, 20);
	file = fopen("./MZRUN/map.txt","r");
	while(!feof(file)) {
		fscanf(file, "%s", &cmap[i++]);
	}
	fclose(file);
	for(i = 0; i<fullmap.y; i++) {
		for(j = 0; j<fullmap.x; j++) {
			Tile_block(&map[i][j]);
			coord_init(&tmp, j, i);
			if(cmap[i][j]=='@') {
				temp = (struct Object*) malloc(sizeof(struct Object));
				Object_init(temp, j, i, RIGHT, '@', "player", GREEN, BLACK, 0, 0);
				cmap[i][j] = '.';	entityObjects[0] = *temp;	free(temp);
				Tile_unblock(&map[i][j]);
			} else if(cmap[i][j] == '*') {
				temp = (struct Object*) malloc(sizeof(struct Object));
				Object_init(temp, j, i, STOP, '*', "monster", RED, BLACK, 5, 4); //RED
				cmap[i][j] = '.';	entityObjects[totalEntities++] = *temp;	free(temp);
			} else if(cmap[i][j] == '#') {
				Tile_blockSight(&map[i][j]);
			} else if(cmap[i][j] == 'g') {
				Object_reloc(&goal, tmp);
				cmap[i][j] = '.';
				Tile_unblock(&map[i][j]);
			} else {
				Tile_unblock(&map[i][j]);
			}
		}
	}
	Save_Export(&this->data, "./MZRUN/LEVELS/area2.lvl");
}

int main() {
	struct Creator creator;
	clrscr();
	Creator_create_lvl(&creator);
	/*creator.draw();
	while(!creator.end) {
		creator.input();
	}*/
	return 0;
}
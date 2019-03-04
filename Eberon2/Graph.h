#ifndef Graph_H
#define Graph_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
#include <random>
//enum Directions { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3 };

using namespace std;

class Graph {
private:
	struct Area {
		int code;
		int symbol;
		int color;
		pair<int, int> yx;
		string title;
		string description;
		Area *north = NULL;
		Area *east = NULL;
		Area *south = NULL;
		Area *west = NULL;
		Area *previous = NULL;
		//Area *Adjacents[4]{ nullptr, nullptr, nullptr, nullptr };
	};

	Area *Start;
	Area *End;
	Area *Current;
	
	list<Area*> Listing;
	vector<pair<int, int>> Visited;
	
public:
	Graph();
	int Node_Count;
	int Current_Code = 0;
	vector<vector<Area*>> Adj;
	vector<Area*> Adjacent;
	//map<pair<int, int>, Area*> Adjacents;
	map<pair<int, int>, Area*> Exists;
	Area *temp; Area *init; Area *pointer;
	Area* Get_Start();
	Area* Get_Current();
	void Set_Current(int option);
	//Area *Collection;
	Area* Connect_Nodes(pair<int, int> yx, int coordinate);
	//pair<int, int> Connect_Nodes();
	void Create(int y, int x);
	int Add_Node(Area *before, int code, int symbol, int color, pair<int, int> yx, string title, string description, int coordinate, pair<int,int>& out);
	void Get_Nodes();
	void Compass(int existing[]);
	pair<int, int> Get_Directed(pair<int, int> yx, int direction);
	Area* Directed_Pointer(int option);
	//int Get_Code();
	//int Get_Title();
	void DFS_Marker(Area* node, bool visited[]);
	void DFS(int node);
	
	int* Check_Neighbors(Area &area,int existing[]);
	void Display();
	pair<int, int> Get_yx(Area* a);
};

class Map {
private:
	int X, Y;
	int current_Tile;
	int replaced_Tile;
	int replacedCounter;
	int position;
	int Grid[50][50];
public:
	Map();
	void Reveal(int player_y, int player_x);
	int get_Map_Tile(int y, int x);
	int CheckMove(int Move);
	void Change(int y, int x, int symbol);
};

#endif

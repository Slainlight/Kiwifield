#pragma once
#include "olcPixelGameEngine.h"
#include "fileCollision.h"
#include "image.h"
#include "files.h"
#include <ostream>
#include <fstream>
#include <Vector>
#include <string>
#include <filesystem>

// Use C++17
namespace fs = std::filesystem;

using namespace std;
using namespace olc;

class Stage
{
public:
	string name;

	vector<vector<bool>> collision;
	vector<Image> images;

	//Game Reference
	PixelGameEngine* g;

	vector<int>* layers;

	vi2d stageSize = vi2d(0,0);

public:
	void inline createCollisionVector();
	Stage(string name, vi2d size, PixelGameEngine& g);
	Stage(string name, PixelGameEngine& g);
	void save();
	void load(string file);
	bool inbound(vi2d pos);
	void drawCollider();

	void setCollision(vi2d pos, bool boolean);
	bool getCollision(vi2d pos);
	int getWidth();
	int getHeight();
	void cameraFollow(vi2d pos);
	void drawBackground(string img);
	void drawImages();
};
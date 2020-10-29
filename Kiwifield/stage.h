#pragma once
#include "olcPixelGameEngine.h"
#include "files.h"
#include "portal.h"
#include "img.h"
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
	string name{ "" };
	string backgroundPath{ "" };

	vector<vector<bool>> collision;
	vector<Img> imgs{};
	vector<Portal> portals{};

	//Game Reference
	PixelGameEngine* g;

	vector<int>* layers;

	vi2d stageSize = vi2d(0,0);

public:
	void inline CreateCollisionVector();
	Stage(string name, vi2d size, PixelGameEngine& g);
	Stage(string name, PixelGameEngine& g);
	void Save();
	void Load(string file);
	bool Inbound(vi2d pos);
	void DrawCollider();

	void SetCollision(vi2d pos, bool boolean);
	bool GetCollision(vi2d pos);
	int GetWidth();
	int GetHeight();
	void CameraFollow(vi2d pos);
	void DrawBackground(string img);
	void Update(float fElapsedTime, vf2d& p);
};
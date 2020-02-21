#pragma once
#ifndef BIOME_STAIRSBIOME_HPP
#define BIOME_STAIRSBIOME_HPP
#include <ofxPlanet.h>
#include <string>

class StairsBiome : public ofxPlanet::BasicBiome {
public:
	explicit StairsBiome(const std::string& structure, int weight);
protected:
	void onBeginGenerateWorld(ofxPlanet::BlockTable& blockTable) override;
	float onFixHeight(float y) override;
	void onGenerateStructures(ofxPlanet::BlockTable& blockTable) override;
	void onGenerateCave(ofxPlanet::BlockTable& blockTable, int x, int y, int z, float noise) override;
	void onEndGenerateTerrain(ofxPlanet::BlockTable& blockTable) override;
private:
	std::string structure;
	int weight;
};
#endif
#pragma once
#ifndef BIOME_HILLBIOME_HPP
#define BIOME_HILLBIOME_HPP
#include <ofxPlanet.h>

class HillBiome : public ofxPlanet::BasicBiome {
public:
	explicit HillBiome();
	void onGenerateCave(ofxPlanet::BlockTable& blockTable, int x, int y, int z, float noise) override;
	void onEndGenerateTerrain(ofxPlanet::BlockTable& blockTable) override;
private:
};
#endif
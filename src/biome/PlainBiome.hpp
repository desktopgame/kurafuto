#pragma once
#ifndef BIOME_PLAINBIOME_HPP
#define BIOME_PLAINBIOME_HPP
#include<ofxPlanet.h>
class PlainBiome : public ofxPlanet::BasicBiome {
public:
	explicit PlainBiome(const std::string& structure, int weight);
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
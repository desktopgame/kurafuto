#include "PlainBiome.hpp"
#include <algorithm>

PlainBiome::PlainBiome(const std::string & structure, int weight) : BasicBiome(), structure(structure),weight(weight) {
}

void PlainBiome::onBeginGenerateWorld(ofxPlanet::BlockTable & blockTable) {
	if (!structure.empty()) {
		ofxPlanet::MultiBlock mb;
		this->registerStruct("Model", structure);
	}
}

float PlainBiome::onFixHeight(float y) {
	return std::max(0.0f, y);
}

void PlainBiome::onGenerateStructures(ofxPlanet::BlockTable & blockTable) {
	if (!structure.empty()) {
		generateStruct(blockTable, "Model", weight, 1);
	}
}

void PlainBiome::onGenerateCave(ofxPlanet::BlockTable & blockTable, int x, int y, int z, float noise)
{
}

void PlainBiome::onEndGenerateTerrain(ofxPlanet::BlockTable & blockTable) {
}

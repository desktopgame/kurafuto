#include "HillBiome.hpp"

HillBiome::HillBiome() : BasicBiome()
{
}

void HillBiome::onGenerateCave(ofxPlanet::BlockTable & blockTable, int x, int y, int z, float noise)
{
}

void HillBiome::onEndGenerateTerrain(ofxPlanet::BlockTable & blockTable) {
	auto water = ofxPlanet::BlockPack::getCurrent()->getBlock("Water")->getID();
	for (int x = 0; x < blockTable.getXSize(); x++) {
		for (int z = 0; z < blockTable.getZSize(); z++) {
			for (int y = 0; y < (blockTable.getYSize() / 2)-5; y++) {
				auto block = blockTable.getBlock(x, y, z);
				if (block.id == -1) {
					blockTable.setBlock(x, y, z, ofxPlanet::BlockPrefab(water, false));
				}
			}
		}
	}
}

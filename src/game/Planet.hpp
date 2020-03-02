#pragma once
#ifndef GAME_PLANET_HPP
#define GAME_PLANET_HPP
#include <ofxPlanet.h>


class Planet {
public:
	explicit Planet(ofShader& shader);

	void allocate(glm::ivec3 size);
	void generate(glm::ivec3 size, std::shared_ptr<ofxPlanet::Biome> biome);
	std::shared_ptr<ofxPlanet::FixedWorld> getWorld() const;
private:
	ofShader& shader;
	std::shared_ptr<ofxPlanet::FixedWorld> world;
};
#endif
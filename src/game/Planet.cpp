#include "Planet.hpp"

Planet::Planet(ofShader& shader) : shader(shader), world() {
}

void Planet::allocate(glm::ivec3 size) {
	this->world = ofxPlanet::FixedWorld::create(shader, size);
}

void Planet::generate(glm::ivec3 size, std::shared_ptr<ofxPlanet::Biome> biome)
{
	allocate(size);
	ofxPlanet::BlockTable bt(size.x, size.y, size.z);
	biome->generate(bt);
	this->world->load(bt);
}

std::shared_ptr<ofxPlanet::FixedWorld> Planet::getWorld() const {
	return this->world;
}

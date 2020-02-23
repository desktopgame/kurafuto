﻿#pragma once
#ifndef SHADER_CAMERA_HPP
#define SHADER_CAMERA_HPP
#include <ofEasyCam.h>
#include <ofTypes.h>
#include <glm/glm.hpp>

#include <memory>
#include <vector>

class Camera : public std::enable_shared_from_this<Camera> {
public:
	explicit Camera();

	void setFOV(float fov);
	float getFOV() const;

	void setNearPlane(float nearPlane);
	float getNearPlane() const;

	void setFarPlane(float farPlane);
	float getFarPlane() const;

	void setScreenSize(const glm::vec2& screenSize);
	glm::vec2 getScreenSize() const;

	void setPosition(const glm::vec3& position);
	glm::vec3 getPosition() const;

	void setLookAt(const glm::vec3& lookAt);
	glm::vec3 getLookAt() const;

	void setUp(const glm::vec3& up);
	glm::vec3 getUp() const;

	bool rehash();
	glm::mat4 getProjectionMatrix() const;
	glm::mat4 getViewMatrix() const;
	glm::mat4 computeNormalMatrix(const glm::mat4 model) const;

private:
	bool dirty;
	float fov;
	float nearPlane;
	float farPlane;
	glm::vec2 screenSize;
	glm::vec3 position;
	glm::vec3 lookAt;
	glm::vec3 up;

	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;
};
#endif
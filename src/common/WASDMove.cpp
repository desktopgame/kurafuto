#include "WASDMove.hpp"

#include <ofAppRunner.h>

#include "glfw.hpp"
namespace planet {

WASDMove::WASDMove() : enabled(false), axis(), sprint(false) {}

void WASDMove::enable() { this->enabled = true; }

void WASDMove::disable() { this->enabled = false; }

void WASDMove::update() {
        if (!enabled) {
                return;
        }
        this->sprint = ofGetKeyPressed(ofKey::OF_KEY_LEFT_SHIFT);
        // check key
        this->axis = glm::ivec2();
        if (glfw::getKey(glfw::Key_w)) {
                this->axis.y = 1;
        } else if (glfw::getKey(glfw::Key_s)) {
                this->axis.y = -1;
        }
        if (glfw::getKey(glfw::Key_a)) {
                this->axis.x = -1;
        } else if (glfw::getKey(glfw::Key_d)) {
                this->axis.x = 1;
        }
}

float WASDMove::getScale() const { return isSprint() ? 1.0f : 1; }

glm::ivec2 WASDMove::getAxis() const { return axis; }

bool WASDMove::isSprint() const { return sprint; }
}  // namespace planet

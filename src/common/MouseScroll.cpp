﻿#include "MouseScroll.hpp"

#include <ofBaseApp.h>
#include <ofEvents.h>

#include "glfw.hpp"
namespace planet {

MouseScroll::MouseScroll()
    : oldMousePos(-1, -1), diffMousePos(), enabled(false), ignoreOnce(false) {}

void MouseScroll::enable() {
        if (enabled) {
                return;
        }
        this->enabled = true;
}

void MouseScroll::disable() {
        if (!enabled) {
                return;
        }
        this->enabled = false;
}

void MouseScroll::update() {
        diffMousePos.x = diffMousePos.y = 0;
        double dmx = ofGetMouseX();
        double dmy = ofGetMouseY();
		if (ignoreOnce) {
			this->oldMousePos.x = dmx;
			this->oldMousePos.y = dmy;
			ignoreOnce = false;
			return;
		}
        if (oldMousePos.x == -1 && oldMousePos.y == -1) {
                this->oldMousePos.x = dmx;
                this->oldMousePos.y = dmy;
        } else {
                this->diffMousePos.x = -(dmx - oldMousePos.x);
                this->diffMousePos.y = -(dmy - oldMousePos.y);
                this->oldMousePos.x = dmx;
                this->oldMousePos.y = dmy;
        }
}

glm::vec2 MouseScroll::getAmount() const { return this->diffMousePos; }
}  // namespace planet

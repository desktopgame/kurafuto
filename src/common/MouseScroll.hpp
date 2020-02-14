#pragma once
#ifndef COMMON_MOUSESCROLL_HPP
#define COMMON_MOUSESCROLL_HPP
#include <ofVec3f.h>
namespace planet {
/**
 * MouseScroll
 * �́A���O�̃}�E�X���W�ƌ��݂̃}�E�X���W����ǂꂾ���ړ����������v�Z����N���X�ł��B
 */
class MouseScroll {
       public:
        explicit MouseScroll();
        /**
         * �L�������܂��B
         */
        void enable();
        /**
         * ���������܂��B
         */
        void disable();
        /**
         * �ړ��ʂ��v�Z���܂��B
         */
        void update();
        /**
         * �ړ��ʂ��v�Z���܂��B
         * @return
         */
        glm::vec2 getAmount() const;

		bool ignoreOnce;

       private:
        bool enabled;
        glm::vec2 oldMousePos;
        glm::vec2 diffMousePos;
};
}  // namespace planet
#endif
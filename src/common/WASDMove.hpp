#pragma once
#ifndef COMMON_WASDMOVE_HPP
#define COMMON_WASDMOVE_HPP
#include <ofVec3f.h>
namespace planet {
/**
 * WASDMove
 * �́A��l�̎��_�̃Q�[���ɂ�����L�[�{�[�h����ň�ʓI��WASD���T�|�[�g���܂��B
 */
class WASDMove {
       public:
        explicit WASDMove();

        /**
         * �L�������܂��B
         */
        void enable();

        /**
         * ���������܂��B
         */
        void disable();

        /**
         * �L�[���͂����o���܂��B
         */
        void update();

        /**
         * �X�v�����g���Ȃ� 2 ���A����ȊO�Ȃ� 1 ��Ԃ��܂��B
         * @return
         */
        float getScale() const;

        /**
         * ���݂̈ړ�������Ԃ��܂��B
         * @return
         */
        glm::ivec2 getAxis() const;

        /**
         * �X�v�����g���Ȃ� true ��Ԃ��܂��B
         */
        bool isSprint() const;

       private:
        bool enabled;
        bool sprint;
        glm::ivec2 axis;
};
}  // namespace planet
#endif
#pragma once
#ifndef COMMON_FIRSTPERSONCONTROLLER_HPP
#define COMMON_FIRSTPERSONCONTROLLER_HPP
#include <string>

#include "MouseScroll.hpp"
#include "Transform.hpp"
#include "WASDMove.hpp"
namespace planet {
/**
 * FirstPersonController �́A��l�̂̃J����������s�����߂̃N���X�ł��B
 */
class FirstPersonController {
       public:
        enum class Mode { Mouse, Key };
        explicit FirstPersonController();

        /**
         * �L�������܂��B
         */
        void enable();

        /**
         * ���������܂��B
         */
        void disable();

        /**
         * ���͂��`�F�b�N���Č��݂̐i�s������͂��v�Z���܂��B
         */
        void update();

        /**
         * ���݂̉�]��Ԃ��܂��B
         * @return
         */
        glm::vec3 getRotation() const;

        /**
         * ���݂̕�����Ԃ��܂��B
         * @return
         */
        glm::vec3 getVelocity() const;

        /**
         * ���Ɉړ����Ă���Ȃ� true ��Ԃ��܂��B
         * @return
         */
        bool isMoveLeft() const;

        /**
         * �E�Ɉړ����Ă���Ȃ� true ��Ԃ��܂��B
         * @return
         */
        bool isMoveRight() const;

        /**
         * �O�Ɉړ����Ă���Ȃ� true ��Ԃ��܂��B
         * @return
         */
        bool isMoveFront() const;

        /**
         * ���Ɉړ����Ă���Ȃ� true ��Ԃ��܂��B
         * @return
         */
        bool isMoveBack() const;

        /**
         * ���[�h��ݒ肵�܂��B
         * @param mode
         */
        void setMode(const Mode mode);

        /**
         * ���݂̃��[�h��Ԃ��܂��B
         * @return
         */
        Mode getMode() const;

        /**
         * �ړ����x��ݒ肵�܂��B
         * @param moveSpeed
         */
        void setMoveSpeed(float moveSpeed);

        /**
         * �ړ����x��Ԃ��܂��B
         * @return
         */
        float getMoveSpeed() const;

        /**
         * �W�����v�͂�ݒ肵�܂��B
         * @param jumpSpeed
         */
        void setJumpSpeed(float jumpSpeed);

        /**
         * �W�����v�͂�Ԃ��܂��B
         * @return
         */
        float getJumpSpeed() const;

        /**
         * ��]���x��ݒ肵�܂��B
         * @param rotateSpeed
         */
        void setRotateSpeed(float rotateSpeed);

        /**
         * ��]���x��Ԃ��܂��B
         * @return
         */
        float getRotateSpeed() const;

        /**
         * @return
         */
        Transform& getTransform();

        /**
         * @return
         */
        const Transform& getTransform() const;

       private:
        Mode mode;
        glm::vec3 velocity;
        Transform transform;
        MouseScroll mouseScroll;
        WASDMove wasdMove;
        float moveSpeed;
        float jumpSpeed;
        float rotateSpeed;
        bool moveLeft, moveRight, moveFront, moveBack;
};
}  // namespace planet
#endif
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Player.cpp
*/

#include <iostream>
#include "Player.hpp"

Player::Player(irr::IrrlichtDevice* device, std::vector<std::string> path_text, std::string &path_mesh, irr::s16 pos_x, irr::s16 pos_y) : ACharacter(device)
{
    _device = device;
    irr::core::vector3df pos(pos_x, pos_y, 0);
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setRotation(irr::core::vector3df(90,180,0));
    this->getDisplayInfo().addColision(irr::core::vector3df(2, 2, 2));
}

void Player::update(MyEventReceiver event, Map *map)
{
    this->getPlayerController().action(event, 1);
    irr::core::vector3df pos = this->getDisplayInfo().getPosition();
    irr::core::vector3df rot = this->getDisplayInfo().getRotation();
    switch(rot.X % 90) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    }

    if (getDisplayInfo().getFrontObj(3, GameObject::WALL) != nullptr)
        std::cout << "ok" << std::endl;
}
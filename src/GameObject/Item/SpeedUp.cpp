/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SpeedUp.cpp
*/

#include "SpeedUp.hpp"

SpeedUp::SpeedUp(irr::IrrlichtDevice* device, irr::u16 pos_x, irr::u16 pos_y) : AItem(device)
{
    std::string path_mesh = "./assets/meshs/Mushroom/Mushroom.obj";
    std::vector<std::string> path_text;
    path_text.push_back("./assets/meshs/Mushroom/betamush.png");
    irr::core::vector3df pos_world_tmp(pos_x, pos_y + 4, 5);
    irr::core::vector3df pos_map_tmp(pos_x / 10, pos_y / 1, 0);
    this->setPosWorld(pos_world_tmp);
    this->setPosMap(pos_map_tmp);
    this->getDisplayInfo().setPosition(pos_world_tmp);
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setScale(irr::core::vector3df(0.04, 0.04, 0.04));
    this->getDisplayInfo().setRotation(irr::core::vector3df(90, 180, 0));
    this->getDisplayInfo().addColision(irr::core::vector3df(2, 2, 2));
}

bool SpeedUp::applyEffect(ACharacter &player)
{
    player.getStats().setSpeed(player.getStats().getSpeed() + 1);
    return true;
}

GameObject::objecType_t SpeedUp::getType()
{
    return SPEEDUP;
}
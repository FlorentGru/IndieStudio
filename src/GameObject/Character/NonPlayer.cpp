/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** NonPlayer.cpp
*/


#include "NonPlayer.hpp"

NonPlayer::NonPlayer(irr::IrrlichtDevice *device, Map &map) : ACharacter(device), _ia(map, *this)
{

}

void NonPlayer::update(Map &map, std::vector<irr::s32> &idToDel, MyEventReceiver event)
{
    (void)map;
    (void)event;
    (void)idToDel;
    //TODO with IA
}

GameObject::objecType_t NonPlayer::getType()
{
    return (GameObject::objectType_s::NONPLAYER);
}
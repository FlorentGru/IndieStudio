/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Wall.hpp
*/

#ifndef WALL_HPP
#define WALL_HPP

#include "PrintableObject.hpp"
#include "Life.hpp"
#include "Map.hpp"

class Wall : public PrintableObject
{
private:
    bool _isBreakable;
    Life _life;

public:
    // IItem* createRandomItem();

    Wall(irr::u16 x, irr::u16 y, bool isBreakable = true);
    Wall(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver, std::string texture, irr::u16 x, irr::u16 y, bool isBreakable = true);
    ~Wall();

    void createPowerUp(Map *map, irr::u16 x, irr::u16 y);
    bool isBreakable();
    objecType_t getType() override;
};

#endif

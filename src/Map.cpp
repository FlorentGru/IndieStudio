/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Map.cpp
*/

#include <time.h>
#include "Map.hpp"
#include "Wall.hpp"

Map::Map(irr::IrrlichtDevice *device, irr::u16 size) : _device(device), _map(boost::extents[size][size]), _width(size), _heigh(size)
{
    srand(time(NULL));
    genMap(size);
    setMap();
}

Map::~Map()
{
}

void Map::genMap(irr::u16 size)
{
    std::string str;

    if (size % 2 == 0)
        size++;
    for (int i = 0; i < size; i++)
        str += '_';
    for (int i = 0; i < size; i++)
        _mapGen.push_back(str);
    for (irr::u16 i = 0; i < (size * size) - size; i++)
        _mapGen.at(std::rand() % size).at(std::rand() % size) = 'O';
    for (irr::u16 i = 2; i < size; i = i + 2) {
        for (irr::u16 j = 2; j < size; j = j + 2) {
            _mapGen.at(i).at(j) = 'X';
        }
    }
    for (irr::u16 i = 0; i < size; i++) {
        for (irr::u16 j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                _mapGen.at(i).at(j) = 'X';
        }
    }
    _mapGen.at(1).at(1) = '_';
    _mapGen.at(2).at(1) = '_';
    _mapGen.at(1).at(2) = '_';
    _mapGen.at(2).at(2) = 'X';
    _mapGen.at(size - 2).at(1) = '_';
    _mapGen.at(size - 2).at(2) = '_';
    _mapGen.at(size - 3).at(1) = '_';
    _mapGen.at(size - 3).at(2) = 'X';
    _mapGen.at(1).at(size - 2) = '_';
    _mapGen.at(2).at(size - 2) = '_';
    _mapGen.at(1).at(size - 3) = '_';
    _mapGen.at(2).at(size - 3) = 'X';
    _mapGen.at(size - 2).at(size - 2) = '_';
    _mapGen.at(size - 3).at(size - 2) = '_';
    _mapGen.at(size - 2).at(size - 3) = '_';
    _mapGen.at(size - 3).at(size - 3) = 'X';
}

void Map::setMap()
{
    std::vector<std::string> brkwall;
    std::vector<std::string> wall;

    brkwall.push_back("./assets/meshs/Brick_block/brick.png");
    wall.push_back("./assets/meshs/Strong_block/block.png");
    for (irr::u16 i = 0; i < _mapGen.size(); i++) {
        for (irr::u16 j = 0; j < _mapGen.size(); j++) {
            if (_mapGen.at(i).at(j) == 'X') {
                Wall *newWall = new Wall(_device, "./assets/meshs/Strong_block/Block.obj", wall, i, j, false);
                addToMap(i, j, newWall);
            }
            if (_mapGen.at(i).at(j) == 'O') {
                Wall *newWall = new Wall(_device, "./assets/meshs/Brick_block/Brick_Block.obj", brkwall, i, j, true);
                addToMap(i, j, newWall);
            }
        }
    }
}

void Map::addToMap(irr::u16 x, irr::u16 y, GameObject *obj)
{
    if (x >= _width || y >= _heigh || obj == nullptr)
        return;
    _map[x][y].push_back(obj);
}

boost::multi_array<std::vector<GameObject*>, 2> &Map::getMap()
{
    return (_map);
}

irr::u16 Map::getWidth() const
{
    return (_width);
}

irr::u16 Map::getHeigh() const
{
    return (_heigh);
}

void Map::updateColision()
{
    irr::scene::ISceneManager* smgr = _device->getSceneManager();
    PrintableObject *current = nullptr;

    if (!smgr)
        return;
    for (irr::u16 x = 0; x < getWidth(); x++) {
        for (irr::u16 y = 0; y < getHeigh(); y++) {
            for (auto it : _map[x][y]) {
                if (it->getType() == GameObject::PLAYER || it->getType() == GameObject::PRINTABLE_OBJ) {
                    current = dynamic_cast<PrintableObject *>(it);
                    if (current)
                        current->updateColision();
                }
            }
        }
    }
}

irr::core::vector2df Map::getPosition(GameObject *obj)
{
    irr::core::vector2df pos;

    for (irr::u16 x = 0; x < _width; x++) {
        for (irr::u16 y = 0; y < _heigh; y++) {
            for (auto &it : _map[x][y]) {
                if (obj == it) {
                    pos.X = x;
                    pos.Y = y;
                    return (pos);
                }
            }
        }
    }
    return (pos);
}
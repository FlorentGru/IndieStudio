/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Menu.hpp
*/

#ifndef MENU_HPP
#define MENU_HPP

#include "irrlicht/irrlicht.h"
#include <IGUISkin.h>
#include "Camera.hpp"
#include "AScene.hpp"
#include "background.hpp"

class Menu : public AScene
{
private:
    irr::gui::IGUIEnvironment *guienv;
    irr::gui::IGUIStaticText *texte;
    irr::video::ITexture *texture;
    irr::gui::IGUIImage *title;
    irr::gui::IGUIButton *play;
    irr::gui::IGUIButton *load;
    irr::gui::IGUIButton *settings;
    irr::gui::IGUIButton *how_play;
    irr::gui::IGUIButton *scoreboard;
    irr::gui::IGUIButton *quit;
    irr::gui::IGUISkin* skin;
    irr::gui::IGUIFont* font;
    IScene *_background;
    irr::core::dimension2d<f32> sizescreen;

public:
    Menu(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background);
    ~Menu();
    IScene* update() override;
    void display() override;
    bool button();
    void setSkin();
    void tittle();
};

#endif
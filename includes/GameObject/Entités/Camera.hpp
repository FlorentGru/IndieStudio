/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Camera.hpp
*/

#ifndef CAMERA_HPP
#define CAMERA_HPP

#ifdef _WIN64
	#include <irrlicht.h>
#else
	#include <irrlicht/irrlicht.h>
#endif


class Camera
{
private:
    irr::scene::ISceneManager *_smgr;
    irr::core::vector3df _cameraPosition;
    irr::core::vector3df _cameraPointMire;
    irr::scene::ICameraSceneNode *_camera;

public:
    Camera(irr::scene::ISceneManager *smgr, irr::core::vector3df _cameraPosition = irr::core::vector3df(0, 0, 0), irr::core::vector3df _cameraPointMire = irr::core::vector3df(0, 0, 0));
    Camera();
    const irr::core::vector3df& getCameraPosition() const;
    const irr::core::vector3df& getCameraMirePoint() const;
    void setCameraPosition(irr::core::vector3df &);
    void setCameraMirePoint(irr::core::vector3df &);
    bool firstCamera();
};

#endif

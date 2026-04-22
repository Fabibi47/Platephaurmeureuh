#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "ResourceManager.h"
#include "InstanceManager.h"
#include "Engine.h"
#include "Entity.h"
#include "Transformable.h"
#include "Drawable.h"
#include "Movable.h"
#include "Damageable.h"
#include "Scene.h"
#include "Physics.h"
#include "RigidBody.h"
#include "BoxCollider.h"
#include "CapsuleCollider.h"
#include "PlayerBehavior.h"
#include "Camera.h"
#include "MenuScene.h"
#include "SwitcherBehavior.h"
#include "Jump.h"
#include "Crouch.h"
#include "EndScene.h"
#include "LoseScene.h"
#include "SceneLvl1.h"
#include "SceneLvl2.h"

int main()
{
    InstanceManager* instance = InstanceManager::getInstance();
    ResourceManager* resources = ResourceManager::getInstance();
    Physics physics({0, 9});

    Engine engine(&physics);
    Scene* mainMenu = new MenuScene(&engine);
    SceneLvl1* level1 = new SceneLvl1(&engine);
    SceneLvl2* level2 = new SceneLvl2(&engine);
    Scene* loseMenu = new LoseScene(&engine);
    Scene* endMenu = new EndScene(&engine);
    engine.AddScene(mainMenu);
    engine.AddScene(level1);
    engine.AddScene(level2);
    engine.AddScene(endMenu);
    engine.AddScene(loseMenu);
    
    level2->setPhysicsActive(false);

    sf::Clock clock;

    engine.Update();
}


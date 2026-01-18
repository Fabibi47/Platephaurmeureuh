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
#include "Text.h"
#include "CapsuleCollider.h"
#include "PlayerBehavior.h"
#include "Camera.h"
#include "MenuScene.h"
#include "SwitcherBehavior.h"

int main()
{
    InstanceManager* instance = InstanceManager::getInstance();
    ResourceManager* resources = ResourceManager::getInstance();
    Physics physics({0, 9});

    Engine engine(&physics);
    Scene* mainMenu = new MenuScene(&engine);
    Scene* level1 = new Scene(&engine);
    Scene* level2 = new Scene(&engine);
    Scene* loseMenu = new Scene(&engine);
    Scene* endMenu = new Scene(&engine);
    engine.AddScene(mainMenu);
    engine.AddScene(level1);
    engine.AddScene(level2);
    engine.AddScene(loseMenu);
    engine.AddScene(endMenu);

    Entity* ground = new Entity(level1);
    ground->AddComponent(new Transformable(ground, {700, 500}, {1600, 128}));
    ground->AddComponent(new Drawable(ground, *resources->LoadTexture("terrain_purple_block_top.png"), {0, 0 }, true));
    ground->AddComponent(new RigidBody(ground, false));
    ground->AddComponent(new BoxCollider(ground, { 1600, 128 }));
    level1->AddEntityToAdd(ground);
    level1->AddEntities();

    Entity* player = new Entity(level1);
    player->AddComponent(new Transformable(player, { 200, 160 }, {256, 256}));
    player->AddComponent(new Drawable(player, *resources->LoadTexture("spritesheet-characters-double.png"), { 256, 256 }));
    player->AddComponent(new RigidBody(player, true));
    player->AddComponent(new CapsuleCollider(player, { 256, 256 }));
    player->AddComponent(new Movable(player, 100));
    player->AddComponent(new PlayerBehavior(player));
    sf::Vector2u windowSize = engine.getWindow()->getSize();
    sf::Vector2f windowSizef = sf::Vector2f{ (float)windowSize.x, (float)windowSize.y};
    player->AddComponent(new Camera(player, windowSizef));

    level1->AddEntityToAdd(player);
    level1->AddEntities();
    level1->setActiveCamera(player->GetComponent<Camera>());

    Entity* switcher = new Entity(level1);
    switcher->AddComponent(new Transformable(switcher, { 900, 350 }, {128, 128}));
    switcher->AddComponent(new Drawable(switcher, *resources->LoadTexture("flag_blue_a.png"), {0, 0}));
    switcher->AddComponent(new RigidBody(switcher, false));
    switcher->AddComponent(new BoxCollider(switcher, {128, 128}));
    switcher->AddComponent(new SwitcherBehavior(switcher));

    level1->AddEntityToAdd(switcher);
    level1->AddEntities();

    Entity* player2 = new Entity(level2);
    player2->AddComponent(new Transformable(player2, { 200, 160 }, { 256, 256 }));
    player2->AddComponent(new Drawable(player2, *resources->LoadTexture("spritesheet-characters-double.png"), { 256*3, 256*2 }));
    player2->AddComponent(new RigidBody(player2, true));
    player2->AddComponent(new CapsuleCollider(player2, { 256, 256 }));
    player2->AddComponent(new Movable(player2, 100));
    player2->AddComponent(new PlayerBehavior(player2));
    player2->AddComponent(new Camera(player2, windowSizef));

    level2->AddEntityToAdd(player2);
    level2->AddEntities();
    level2->setActiveCamera(player2->GetComponent<Camera>());


    Entity* ground2 = new Entity(level2);
    ground2->AddComponent(new Transformable(ground2, { 700, 500 }, { 1600, 128 }));
    ground2->AddComponent(new Drawable(ground2, *resources->LoadTexture("terrain_grass_block_top.png"), { 0, 0 }, true));
    ground2->AddComponent(new RigidBody(ground2, false));
    ground2->AddComponent(new BoxCollider(ground2, { 1600, 128 }));
    level2->AddEntityToAdd(ground2);
    level2->AddEntities();

    level2->setPhysicsActive(false);

    sf::Clock clock;

    engine.Update();
}


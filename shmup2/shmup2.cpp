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

int main()
{
    InstanceManager* instance = InstanceManager::getInstance();
    ResourceManager* resources = ResourceManager::getInstance();
    Physics physics({0, 9});

    Engine engine(&physics);
    Scene* mainMenu = new MenuScene(&engine);
    Scene* level1 = new Scene(&engine);
    Scene* level2 = new Scene(&engine);
    Scene* loseMenu = new LoseScene(&engine);
    Scene* endMenu = new EndScene(&engine);
    engine.AddScene(mainMenu);
    engine.AddScene(level1);
    engine.AddScene(level2);
    engine.AddScene(endMenu);
    engine.AddScene(loseMenu);


    /////////////////////////////////////////////////////////////////////NIVEAU 1/////////////////////////////////////////////////////////////////

    Entity* ground1 = new Entity(level1);
    ground1->AddComponent(new Transformable(ground1, {300, 500}, {600, 128}));
    ground1->AddComponent(new Drawable(ground1, *resources->LoadTexture("terrain_purple_block_top.png"), {0, 0 }, true));
    ground1->AddComponent(new RigidBody(ground1, false));
    ground1->AddComponent(new BoxCollider(ground1, { 600, 128 }));
    level1->AddEntityToAdd(ground1);
    level1->AddEntities();

    Entity* ground2 = new Entity(level1);
    ground2->AddComponent(new Transformable(ground2, { 1500, 500 }, { 600, 128 }));
    ground2->AddComponent(new Drawable(ground2, *resources->LoadTexture("terrain_purple_block_top.png"), { 0, 0 }, true));
    ground2->AddComponent(new RigidBody(ground2, false));
    ground2->AddComponent(new BoxCollider(ground2, { 600, 128 }));
    level1->AddEntityToAdd(ground2);
    level1->AddEntities();

    Entity* lWall = new Entity(level1);
    lWall->AddComponent(new Transformable(lWall, { -350, 0 }, { 700, 2000 }));
    lWall->AddComponent(new Drawable(lWall, *resources->LoadTexture("terrain_purple_block_center.png"), { 0, 0 }, true));
    lWall->AddComponent(new RigidBody(lWall, false));
    lWall->AddComponent(new BoxCollider(lWall, { 700, 2000 }));
    level1->AddEntityToAdd(lWall);
    level1->AddEntities();

    Entity* ceiling = new Entity(level1);
    ceiling->AddComponent(new Transformable(ceiling, { -10, -1000 }, { 5000, 500 }));
    ceiling->AddComponent(new Drawable(ceiling, *resources->LoadTexture("terrain_purple_block_center.png"), { 0, 0 }, true));
    ceiling->AddComponent(new RigidBody(ceiling, false));
    ceiling->AddComponent(new BoxCollider(ceiling, { 5000, 500 }));
    level1->AddEntityToAdd(ceiling);
    level1->AddEntities();

    Entity* platform1 = new Entity(level1);
    platform1->AddComponent(new Transformable(platform1, { 700, 300 }, { 200, 128 }));
    platform1->AddComponent(new Drawable(platform1, *resources->LoadTexture("terrain_purple_block_top.png"), { 0, 0 }, true));
    platform1->AddComponent(new RigidBody(platform1, false));
    platform1->AddComponent(new BoxCollider(platform1, { 200, 128 }));
    level1->AddEntityToAdd(platform1);
    level1->AddEntities();

    Entity* pillar = new Entity(level1);
    pillar->AddComponent(new Transformable(pillar, { 1200, 200 }, { 200, 800 }));
    pillar->AddComponent(new Drawable(pillar, *resources->LoadTexture("terrain_purple_block_center.png"), { 0, 0 }, true));
    pillar->AddComponent(new RigidBody(pillar, false));
    pillar->AddComponent(new BoxCollider(pillar, { 200, 800 }));
    level1->AddEntityToAdd(pillar);
    level1->AddEntities();

    Entity* player = new Entity(level1);
    player->AddComponent(new Transformable(player, { 200, 160 }, {256, 256}));
    player->AddComponent(new Drawable(player, *resources->LoadTexture("spritesheet-characters-double.png"), { 256, 256 }));
    player->AddComponent(new RigidBody(player, true));
    player->AddComponent(new CapsuleCollider(player, { 165, 200 }));
    player->AddComponent(new Movable(player, 100));
    player->AddComponent(new PlayerBehavior(player));
    player->AddComponent(new Jump(player, 7));
    sf::Vector2u windowSize = engine.getWindow()->getSize();
    sf::Vector2f windowSizef = sf::Vector2f{ (float)windowSize.x, (float)windowSize.y};
    player->AddComponent(new Camera(player, windowSizef));

    level1->AddEntityToAdd(player);
    level1->AddEntities();
    level1->setActiveCamera(player->GetComponent<Camera>());

    Entity* switcher = new Entity(level1);
    switcher->AddComponent(new Transformable(switcher, { 1400, 360 }, {128, 128}));
    switcher->AddComponent(new Drawable(switcher, *resources->LoadTexture("flag_blue_a.png"), {0, 0}));
    switcher->AddComponent(new RigidBody(switcher, false));
    switcher->AddComponent(new BoxCollider(switcher, {128, 128}));
    switcher->AddComponent(new SwitcherBehavior(switcher, 2));

    level1->AddEntityToAdd(switcher);
    level1->AddEntities();


    /////////////////////////////////////////////////////////////////////////NIVEAU 2////////////////////////////////////////////////////////////////////

    Entity* player2 = new Entity(level2);
    player2->AddComponent(new Transformable(player2, { 200, 160 }, { 256, 256 }));
    player2->AddComponent(new Drawable(player2, *resources->LoadTexture("character_green_walk_b.png"), { 0, 0 }));
    player2->AddComponent(new RigidBody(player2, true));
    player2->AddComponent(new CapsuleCollider(player2, { 165, 200 }));
    player2->AddComponent(new Movable(player2, 100));
    player2->AddComponent(new PlayerBehavior(player2));
    player2->AddComponent(new Camera(player2, windowSizef));
    sf::Sprite* player2CrouchSprite = new sf::Sprite(*resources->LoadTexture("character_green_duck.png"));
    player2->AddComponent(new Crouch(player2, player2CrouchSprite, 25));

    level2->AddEntityToAdd(player2);
    level2->AddEntities();
    level2->setActiveCamera(player2->GetComponent<Camera>());


    Entity* ground3 = new Entity(level2);
    ground3->AddComponent(new Transformable(ground3, { 450, 500 }, { 900, 128 }));
    ground3->AddComponent(new Drawable(ground3, *resources->LoadTexture("terrain_grass_block_top.png"), { 0, 0 }, true));
    ground3->AddComponent(new RigidBody(ground3, false));
    ground3->AddComponent(new BoxCollider(ground3, { 900, 128 }));
    level2->AddEntityToAdd(ground3);
    level2->AddEntities();

    Entity* ground4 = new Entity(level2);
    ground4->AddComponent(new Transformable(ground4, { 1200, 800 }, { 900, 128 }));
    ground4->AddComponent(new Drawable(ground4, *resources->LoadTexture("terrain_grass_block_top.png"), { 0, 0 }, true));
    ground4->AddComponent(new RigidBody(ground4, false));
    ground4->AddComponent(new BoxCollider(ground4, { 900, 128 }));
    level2->AddEntityToAdd(ground4);
    level2->AddEntities();

    Entity* ground5 = new Entity(level2);
    ground5->AddComponent(new Transformable(ground5, { 450, 1100 }, { 900, 128 }));
    ground5->AddComponent(new Drawable(ground5, *resources->LoadTexture("terrain_grass_block_top.png"), { 0, 0 }, true));
    ground5->AddComponent(new RigidBody(ground5, false));
    ground5->AddComponent(new BoxCollider(ground5, { 900, 128 }));
    level2->AddEntityToAdd(ground5);
    level2->AddEntities();

    Entity* lWall2 = new Entity(level2);
    lWall2->AddComponent(new Transformable(lWall2, { -350, 0 }, { 700, 2000 }));
    lWall2->AddComponent(new Drawable(lWall2, *resources->LoadTexture("terrain_grass_block_center.png"), { 0, 0 }, true));
    lWall2->AddComponent(new RigidBody(lWall2, false));
    lWall2->AddComponent(new BoxCollider(lWall2, { 700, 2000 }));
    level2->AddEntityToAdd(lWall2);
    level2->AddEntities();

    Entity* platform2 = new Entity(level2);
    platform2->AddComponent(new Transformable(platform2, { 900, 200 }, { 200, 128 }));
    platform2->AddComponent(new Drawable(platform2, *resources->LoadTexture("terrain_grass_block_top.png"), { 0, 0 }, true));
    platform2->AddComponent(new RigidBody(platform2, false));
    platform2->AddComponent(new BoxCollider(platform2, { 200, 128 }));
    level2->AddEntityToAdd(platform2);
    level2->AddEntities();

    Entity* switcher2 = new Entity(level2);
    switcher2->AddComponent(new Transformable(switcher2, { 300, 1000 }, { 128, 128 }));
    switcher2->AddComponent(new Drawable(switcher2, *resources->LoadTexture("flag_blue_a.png"), { 0, 0 }));
    switcher2->AddComponent(new RigidBody(switcher2, false));
    switcher2->AddComponent(new BoxCollider(switcher2, { 128, 128 }));
    switcher2->AddComponent(new SwitcherBehavior(switcher2, 3));
    level2->AddEntityToAdd(switcher2);
    level2->AddEntities();

    level2->setPhysicsActive(false);

    sf::Clock clock;

    engine.Update();
}


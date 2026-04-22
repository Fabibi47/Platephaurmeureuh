#pragma once
#include "SceneLvl2.h"
#include "Engine.h"
#include "SceneLvl1.h"
#include "PlayerBehavior.h"
#include "Entity.h"
#include "Transformable.h"
#include "Drawable.h"
#include "RigidBody.h"
#include "BoxCollider.h"
#include "ResourceManager.h"
#include "Crouch.h"
#include "CapsuleCollider.h"
#include "Movable.h"
#include "SwitcherBehavior.h"

SceneLvl2::SceneLvl2(Engine* engine) : Scene(engine) 
{
    ResourceManager* resources = ResourceManager::getInstance();

    Entity* player2 = new Entity(this);
    player2->AddComponent(new Transformable(player2, { 200, 160 }, { 256, 256 }));
    player2->AddComponent(new Drawable(player2, *resources->LoadTexture("character_green_walk_b.png"), { 0, 0 }));
    player2->AddComponent(new RigidBody(player2, true));
    player2->AddComponent(new CapsuleCollider(player2, { 165, 200 }));
    player2->AddComponent(new Movable(player2, 100));
    player2->AddComponent(new PlayerBehavior(player2));
    sf::Vector2u windowSize = engine->getWindow()->getSize();
    sf::Vector2f windowSizef = sf::Vector2f{ (float)windowSize.x, (float)windowSize.y };
    player2->AddComponent(new Camera(player2, windowSizef));
    sf::Sprite* player2CrouchSprite = new sf::Sprite(*resources->LoadTexture("character_green_duck.png"));
    player2->AddComponent(new Crouch(player2, player2CrouchSprite, 25));

    AddEntityToAdd(player2);
    AddEntities();
    setActiveCamera(player2->GetComponent<Camera>());


    Entity* ground3 = new Entity(this);
    ground3->AddComponent(new Transformable(ground3, { 450, 500 }, { 900, 128 }));
    ground3->AddComponent(new Drawable(ground3, *resources->LoadTexture("terrain_grass_block_top.png"), { 0, 0 }, true));
    ground3->AddComponent(new RigidBody(ground3, false));
    ground3->AddComponent(new BoxCollider(ground3, { 900, 128 }));
    AddEntityToAdd(ground3);
    AddEntities();

    Entity* ground4 = new Entity(this);
    ground4->AddComponent(new Transformable(ground4, { 1200, 800 }, { 900, 128 }));
    ground4->AddComponent(new Drawable(ground4, *resources->LoadTexture("terrain_grass_block_top.png"), { 0, 0 }, true));
    ground4->AddComponent(new RigidBody(ground4, false));
    ground4->AddComponent(new BoxCollider(ground4, { 900, 128 }));
    AddEntityToAdd(ground4);
    AddEntities();

    Entity* ground5 = new Entity(this);
    ground5->AddComponent(new Transformable(ground5, { 450, 1100 }, { 900, 128 }));
    ground5->AddComponent(new Drawable(ground5, *resources->LoadTexture("terrain_grass_block_top.png"), { 0, 0 }, true));
    ground5->AddComponent(new RigidBody(ground5, false));
    ground5->AddComponent(new BoxCollider(ground5, { 900, 128 }));
    AddEntityToAdd(ground5);
    AddEntities();

    Entity* lWall2 = new Entity(this);
    lWall2->AddComponent(new Transformable(lWall2, { -350, 0 }, { 700, 2000 }));
    lWall2->AddComponent(new Drawable(lWall2, *resources->LoadTexture("terrain_grass_block_center.png"), { 0, 0 }, true));
    lWall2->AddComponent(new RigidBody(lWall2, false));
    lWall2->AddComponent(new BoxCollider(lWall2, { 700, 2000 }));
    AddEntityToAdd(lWall2);
    AddEntities();

    Entity* platform2 = new Entity(this);
    platform2->AddComponent(new Transformable(platform2, { 900, 200 }, { 200, 128 }));
    platform2->AddComponent(new Drawable(platform2, *resources->LoadTexture("terrain_grass_block_top.png"), { 0, 0 }, true));
    platform2->AddComponent(new RigidBody(platform2, false));
    platform2->AddComponent(new BoxCollider(platform2, { 200, 128 }));
    AddEntityToAdd(platform2);
    AddEntities();

    Entity* switcher2 = new Entity(this);
    switcher2->AddComponent(new Transformable(switcher2, { 300, 1000 }, { 128, 128 }));
    switcher2->AddComponent(new Drawable(switcher2, *resources->LoadTexture("flag_blue_a.png"), { 0, 0 }));
    switcher2->AddComponent(new RigidBody(switcher2, false));
    switcher2->AddComponent(new BoxCollider(switcher2, { 128, 128 }));
    switcher2->AddComponent(new SwitcherBehavior(switcher2, 3));
    AddEntityToAdd(switcher2);
    AddEntities();
}

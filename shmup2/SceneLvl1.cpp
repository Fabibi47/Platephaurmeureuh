#pragma once
#include "Engine.h"
#include "SceneLvl1.h"
#include "PlayerBehavior.h"
#include "Entity.h"
#include "Transformable.h"
#include "Drawable.h"
#include "RigidBody.h"
#include "BoxCollider.h"
#include "ResourceManager.h"
#include "Jump.h"
#include "CapsuleCollider.h"
#include "Movable.h"
#include "SwitcherBehavior.h"

SceneLvl1::SceneLvl1(Engine* engine) : Scene(engine) {
    ResourceManager* resources = ResourceManager::getInstance();

    Entity* ground1 = new Entity(this);
    ground1->AddComponent(new Transformable(ground1, { 300, 500 }, { 600, 128 }));
    ground1->AddComponent(new Drawable(ground1, *resources->LoadTexture("terrain_purple_block_top.png"), { 0, 0 }, true));
    ground1->AddComponent(new RigidBody(ground1, false));
    ground1->AddComponent(new BoxCollider(ground1, { 600, 128 }));
    AddEntityToAdd(ground1);
    AddEntities();

    Entity* ground2 = new Entity(this);
    ground2->AddComponent(new Transformable(ground2, { 1500, 500 }, { 600, 128 }));
    ground2->AddComponent(new Drawable(ground2, *resources->LoadTexture("terrain_purple_block_top.png"), { 0, 0 }, true));
    ground2->AddComponent(new RigidBody(ground2, false));
    ground2->AddComponent(new BoxCollider(ground2, { 600, 128 }));
    AddEntityToAdd(ground2);
    AddEntities();

    Entity* lWall = new Entity(this);
    lWall->AddComponent(new Transformable(lWall, { -350, 0 }, { 700, 2000 }));
    lWall->AddComponent(new Drawable(lWall, *resources->LoadTexture("terrain_purple_block_center.png"), { 0, 0 }, true));
    lWall->AddComponent(new RigidBody(lWall, false));
    lWall->AddComponent(new BoxCollider(lWall, { 700, 2000 }));
    AddEntityToAdd(lWall);
    AddEntities();

    Entity* ceiling = new Entity(this);
    ceiling->AddComponent(new Transformable(ceiling, { -10, -1000 }, { 5000, 500 }));
    ceiling->AddComponent(new Drawable(ceiling, *resources->LoadTexture("terrain_purple_block_center.png"), { 0, 0 }, true));
    ceiling->AddComponent(new RigidBody(ceiling, false));
    ceiling->AddComponent(new BoxCollider(ceiling, { 5000, 500 }));
    AddEntityToAdd(ceiling);
    AddEntities();

    Entity* platform1 = new Entity(this);
    platform1->AddComponent(new Transformable(platform1, { 700, 300 }, { 200, 128 }));
    platform1->AddComponent(new Drawable(platform1, *resources->LoadTexture("terrain_purple_block_top.png"), { 0, 0 }, true));
    platform1->AddComponent(new RigidBody(platform1, false));
    platform1->AddComponent(new BoxCollider(platform1, { 200, 128 }));
    AddEntityToAdd(platform1);
    AddEntities();

    Entity* pillar = new Entity(this);
    pillar->AddComponent(new Transformable(pillar, { 1200, 200 }, { 200, 800 }));
    pillar->AddComponent(new Drawable(pillar, *resources->LoadTexture("terrain_purple_block_center.png"), { 0, 0 }, true));
    pillar->AddComponent(new RigidBody(pillar, false));
    pillar->AddComponent(new BoxCollider(pillar, { 200, 800 }));
    AddEntityToAdd(pillar);
    AddEntities();

    Entity* player = new Entity(this);
    player->AddComponent(new Transformable(player, { 200, 160 }, { 256, 256 }));
    player->AddComponent(new Drawable(player, *resources->LoadTexture("spritesheet-characters-double.png"), { 256, 256 }));
    player->AddComponent(new RigidBody(player, true));
    player->AddComponent(new CapsuleCollider(player, { 165, 200 }));
    player->AddComponent(new Movable(player, 100));
    player->AddComponent(new PlayerBehavior(player));
    player->AddComponent(new Jump(player, 7));

    sf::Vector2u windowSize = engine->getWindow()->getSize();
    sf::Vector2f windowSizef = sf::Vector2f{ (float)windowSize.x, (float)windowSize.y };
    player->AddComponent(new Camera(player, windowSizef));

    AddEntityToAdd(player);
    AddEntities();
    setActiveCamera(player->GetComponent<Camera>());

    Entity* switcher = new Entity(this);
    switcher->AddComponent(new Transformable(switcher, { 1400, 360 }, { 128, 128 }));
    switcher->AddComponent(new Drawable(switcher, *resources->LoadTexture("flag_blue_a.png"), { 0, 0 }));
    switcher->AddComponent(new RigidBody(switcher, false));
    switcher->AddComponent(new BoxCollider(switcher, { 128, 128 }));
    switcher->AddComponent(new SwitcherBehavior(switcher, 2));

    AddEntityToAdd(switcher);
    AddEntities();
}
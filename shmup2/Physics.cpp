#include "Physics.h"
#include "RigidBody.h"
#include "Collider.h"
#include "Scene.h"
#include "ICollisionEvent.h"

b2WorldId Physics::world;
const float Physics::WorldScale = 30;


Physics::Physics(b2Vec2 gravity) {
    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = { gravity };
    this->gravity = worldDef.gravity;
    world = b2CreateWorld(&worldDef);
}

Physics::~Physics() {
    b2DestroyWorld(world);
}

void Physics::Update(std::vector<Entity*> entities) {
    //recup entities
    for (Entity* entity : entities) {
        if (RigidBody* rb = entity->GetComponent<RigidBody>()) {
            //update bodies positions
            rb->UpdateBodyPosition();
        }
    }
    b2World_Step(world, 1.f / 60.f, 4);
    //CONTACT////////////////////////////////////////////////////////////////////////////////////////
    b2ContactEvents contactEvents = b2World_GetContactEvents(world);
    for (int i = 0; i < contactEvents.beginCount; ++i) {
        b2ContactBeginTouchEvent* beginEvent = contactEvents.beginEvents + i;
        b2ShapeId shapeA = beginEvent->shapeIdA;
        b2ShapeId shapeB = beginEvent->shapeIdB;
        Collider* colliderA = nullptr;
        Collider* colliderB = nullptr;
        for (Entity* entity : entities) {
            if (Collider* collider = entity->GetComponent<Collider>()) {
                if (B2_ID_EQUALS(shapeA, collider->getShape())) {
                    colliderA = collider;
                }
                else if (B2_ID_EQUALS(shapeB, collider->getShape())) {
                    colliderB = collider;
                }
            }
        }

        if (colliderA && colliderB) {
            if (ICollisionEvent* a = colliderA->parent->GetComponent<ICollisionEvent>()) {
                a->BeginCollision(colliderA, colliderB);
            }
            if (ICollisionEvent* a = colliderB->parent->GetComponent<ICollisionEvent>()) {
                a->BeginCollision(colliderB, colliderA);
            }
        }
    }
    for (int i = 0; i < contactEvents.endCount; ++i) {
        b2ContactEndTouchEvent* endEvent = contactEvents.endEvents + i;
        b2ShapeId shapeA = endEvent->shapeIdA;
        b2ShapeId shapeB = endEvent->shapeIdB;
        Collider* colliderA = nullptr;
        Collider* colliderB = nullptr;
        for (Entity* entity : entities) {
            if (Collider* collider = entity->GetComponent<Collider>()) {
                if (B2_ID_EQUALS(shapeA, collider->getShape())) {
                    colliderA = collider;
                }
                else if (B2_ID_EQUALS(shapeB, collider->getShape())) {
                    colliderB = collider;
                }
            }
        }
        if (colliderA && colliderB) {
            if (ICollisionEvent* a = colliderA->parent->GetComponent<ICollisionEvent>()) {
                a->EndCollision(colliderA, colliderB);
            }
            if (ICollisionEvent* a = colliderB->parent->GetComponent<ICollisionEvent>()) {
                a->EndCollision(colliderB, colliderA);
            }
        }
    }
    //FIN CONTACT////////////////////////////////////////////////////////////////////

    //update entities avec nouvelle data
    for (Entity* entity : entities) {
        if (RigidBody* rb = entity->GetComponent<RigidBody>()) {
            //update graphics positions
            rb->UpdateGraphicPosition();
        }
    }
}

b2WorldId Physics::getWorldId()
{
    return world;
}

void Physics::Clear(){
    if (b2World_IsValid(world)) {
        b2DestroyWorld(world);
    }
    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = { 0, 9 };
    this->gravity = worldDef.gravity;
    world = b2CreateWorld(&worldDef);
}

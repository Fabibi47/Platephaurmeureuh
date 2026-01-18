#pragma once
#include "Camera.h"
#include "Entity.h"
#include "Transformable.h"
#include "Physics.h"
#include "Engine.h"

Camera::Camera(Entity* parent, sf::Vector2f viewSize) : AComponent(parent) {
	view = new sf::View();
	view->setSize(viewSize);
	Transformable* transform = parent->GetComponent<Transformable>();
	view->setCenter(transform->getPosition());
	
}

void Camera::Update(float dt) {
	Transformable* transform = parent->GetComponent<Transformable>();
	sf::Vector2f targetPos = transform->getPosition();
	view->setCenter(transform->getPosition());
}

Camera::~Camera() {
	if (view) {
		delete(view);
		view = nullptr;
	}
}
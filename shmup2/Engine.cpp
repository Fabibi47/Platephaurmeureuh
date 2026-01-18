#include "Engine.h"
#include "ResourceManager.h"


Engine::Engine(Physics* physics) : physics(physics) {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ 1200, 700 }), "Platephaurmeure");
    this->window = window;
    window->setFramerateLimit(60);
}

void Engine::Update() {
    while (window->isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
        }

        window->clear(sf::Color::Black);

        Scene* scene = scenes[currentScene];
        if (int index = scene->ShouldSwitch()) {
            SwitchScene(index);
            scene = scenes[currentScene];
        }
        physics->Update(scene->getEntities());
        scene->Update(deltaTime);
        scene->RemoveEntities();
        scene->AddEntities();

        window->display();
    }
}

sf::RenderWindow* Engine::getWindow() {
    return window;
}

void Engine::AddScene(Scene* scene) {
    scenes.push_back(scene);
}

void Engine::SwitchScene(int index) {
    if (currentScene >= 0 && currentScene < scenes.size()) scenes[currentScene]->setPhysicsActive(false);
    currentScene = index;
    if (currentScene >= 0 && currentScene < scenes.size()) {
        scenes[currentScene]->setPhysicsActive(true);
    }
}

Physics* Engine::getPhysics() {
    return physics;
}
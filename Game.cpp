#include "Game.hpp"
/*=============================================================================
|                         Constructor/Deconstructor
=============================================================================*/
Game::Game() {   // constructor definition
    this->initVariables();
    this->initWindow();
    platformObj =
        new Platform(this->data);   // make shape(s) in own class and draw it
    player = new Player(this->data);
}

Game::~Game() {   // deconstrutor definition
    // delete this->data;
    std::cout << "shared ptr count at Game destructor: "
              << this->data.use_count() << std::endl;
}
/*=============================================================================
|                          Initialize functions
=============================================================================*/
void
Game::initVariables() {
    this->endGame = false;
}

void
Game::initWindow() {
    // this->videoMode = sf::VideoMode(800, 600);
    // this->window = new sf::RenderWindow(this->videoMode, "Game",
    // sf::Style::Close | sf::Style::Titlebar); //render window needed to draw
    // on
    this->data->create(sf::VideoMode(800, 600), "title",
                       sf::Style::Close | sf::Style::Titlebar);
    std::cout << data->getSize().x << "--- " << data->getSize().y << std::endl;
}
/*=============================================================================
|                          Game System Run & Update
=============================================================================*/
const bool
Game::running() const {
    return this->data->isOpen();
}

void
Game::pollEvents() {   // checks if window was/is closed and
    while (this->data->pollEvent(this->ev)) {
        switch (this->ev.type) {
        case sf::Event::Closed:
            this->data->close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
                this->data->close();
            if (ev.key.code == sf::Keyboard::W) {
                this->player->update(ev.key.code);
            }
            if (ev.key.code == sf::Keyboard::A) {
                this->player->update(ev.key.code);
            }
            if (ev.key.code == sf::Keyboard::S) {
                this->player->update(ev.key.code);
            }
            if (ev.key.code == sf::Keyboard::D) {
                this->player->update(ev.key.code);
            }
            break;
        }
    }
}

void
Game::update() {   // update game variables before rendered
    this->pollEvents();
}

void
Game::render() {   // renders all variables to the screen, last thing done.
    this->data->clear();

    // render stuff here
    platformObj->drawPlatform(*this->data);   // sending at ptr bc shared ptr
                                              // (?)

    player->drawPlayer(*this->data);

    this->data->display();
}

/*=============================================================================
|
=============================================================================*/
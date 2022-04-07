
#include <iostream>
#include<SFML\Graphics.hpp>
#include<math.h>
#include<vector>
#include <ctime>
#include "square.h"

//globals
bool keys[] = { false, false, false, false, false };
enum DIRECTIONS { LEFT, RIGHT, UP, DOWN, CLICK }; //left is 0, right is 1, up is 2, down is 3
int vx, vy;
std::vector<square*> colums;
std::vector<square*> rows;


int main()
{
    square* newSquare = new square(960, 540, 2, 100,false,"joe");
    
    
    //setting up the vector of squarety pointers indexes in memory, not pushing anything to them yet

    for (int x = 0; x < 10; x++) {
        square* newSquare = new square(400, 400, 2, 50, false,"joe");
        colums.push_back(newSquare);
    }
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800, 800), "Platformer");
    std::cout << "Hello World!\n";
    window.setFramerateLimit(240);
    
    while (window.isOpen())
    {


        // Process events----------------------------------------------------------------------------------------------------------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit--------------------------------------------------------------------------------------------------------------------------
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            //key strokes -----------------
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                keys[LEFT] = true;
            }
            else keys[LEFT] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                keys[RIGHT] = true;
            }
            else keys[RIGHT] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                keys[UP] = true;
            }
            else keys[UP] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                keys[DOWN] = true;
            }
            else keys[DOWN] = false;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                keys[CLICK] = true;


            }
            else keys[CLICK] = false;

        }
        if (keys[LEFT] == true) {

            vx = -1;
        }

        else if (keys[RIGHT] == true) {

            vx = 1;
        }

        else vx = 0;

        if (keys[UP] == true) {

            vy = -1;
        }

        else if (keys[DOWN] == true) {

            vy = 1;
        }

        else vy = 0;

        if (keys[CLICK] == true) {
            colums[0]->frmOrigin = true;
            colums[0]->setorigin(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            colums[0]->update();
        }
        else
            colums[0]->frmOrigin = false;
            //velocity ----

            colums[0]->x += vx;
        colums[0]->y += vy;


        
        colums[0]->update();
        //end vel start draw
        colums[0]->draw(window);


        window.display();
        window.clear();
    }//end event loop---------------------------------------------------------------



}

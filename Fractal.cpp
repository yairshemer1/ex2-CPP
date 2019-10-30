//
// Created by Yair Shemer on 04/09/2019.
//
#include "Fractal.h"
#include <cmath>
#include <iostream>

/**
 * A function used to draw the fractal
 */
void Fractal::draw()
{
    for (int i = 0; i < std::pow(_sizeOfShape, _degree); i++)
    {
        for (int j = 0; j < std::pow(_sizeOfShape, _degree); j++)
        {
            if (this->doDraw(i, j))
            {
                std::cout << PRINT_SYMBOL;
            }
            else
            {
                std::cout << SPACE_SYMBOL;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Constructor
 * @param degree the degree of the fractal
 */
SierpinskiCarpet::SierpinskiCarpet(int degree) : Fractal(degree, S_C_SIZE)
{}

/**
 * A boolean function receiving coordinate and decides whether there should be # or ' '
 * @param x coordinate
 * @param y coordinate
 * @return true if there should be #, false for ' '
 */
bool SierpinskiCarpet::doDraw(int x, int y)
{
    while (true)
    {
        if (x == 0 || y == 0)
        {
            return true;
        }
        else if (x % _sizeOfShape == 1 && y % _sizeOfShape == 1)
        {
            return false;
        }
        x /= _sizeOfShape;
        y /= _sizeOfShape;
    }
}

/**
 * Constructor
 * @param degree the degree of the fractal
 */
SierpinskiSieve::SierpinskiSieve(int degree) : Fractal(degree, S_S_SIZE)
{}

/**
 * A boolean function receiving coordinate and decides whether there should be # or ' '
 * @param x coordinate
 * @param y coordinate
 * @return true if there should be #, false for ' '
 */
bool SierpinskiSieve::doDraw(int x, int y)
{
    while (true)
    {
        if (x == 0 || y == 0)
        {
            return true;
        }
        else if (x % _sizeOfShape == 1 && y % _sizeOfShape == 1)
        {
            return false;
        }
        x /= _sizeOfShape;
        y /= _sizeOfShape;
    }
}

/**
 * Constructor
 * @param degree the degree of the fractal
 */
CantorDust::CantorDust(int degree) : Fractal(degree, C_D_SIZE)
{}

/**
 * A boolean function receiving coordinate and decides whether there should be # or ' '
 * @param x coordinate
 * @param y coordinate
 * @return true if there should be #, false for ' '
 */
bool CantorDust::doDraw(int x, int y)
{
    while (true)
    {
        if (x == 0 && y == 0)
        {
            return true;
        }
        else if (x % _sizeOfShape == 1 || y % _sizeOfShape == 1)
        {
            return false;
        }
        x /= _sizeOfShape;
        y /= _sizeOfShape;
    }
}


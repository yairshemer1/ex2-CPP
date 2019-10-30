//
// Created by Yair Shemer on 04/09/2019.
//

#ifndef EX2_FRACTAL_H
#define EX2_FRACTAL_H

static const char *const PRINT_SYMBOL = "#";

static const char *const SPACE_SYMBOL = " ";

static const int C_D_TYPE = 3;

static const int S_S_TYPE = 2;

static const int S_C_TYPE = 1;
static const int S_C_SIZE = 3;

static const int S_S_SIZE = 2;

static const int C_D_SIZE = 3;

#include <utility>

/**
 * This class represents a fractal to be drawn
 */
class Fractal
{
protected:
    int _degree; //the degree of the fractal
    int _sizeOfShape; //size of the shape n*n

public:
    /**
     * Constructor of a fractal
     * @param degree of the fractal
     * @param size of it's pattern
     */
    Fractal(int degree, int size) : _degree(degree), _sizeOfShape(size)
    {}

    /**
     * Copy constructor of a fractal
     * @param other fractal to copy
     */
    Fractal(const Fractal &other) = default;

    /**
     * Destructor as default
     */
    virtual ~Fractal() = default;

    /**
     * A function used to draw the fractal
     */
    void draw();

    /**
     * A boolean function receiving coordinate and decides whether there should be # or ' '
     * @param x coordinate
     * @param y coordinate
     * @return true if there should be #, false for ' '
     */
    virtual bool doDraw(int x, int y) = 0;

    /**
     * Move constructor, default
     * @param other constructor as an r-value
     */
    Fractal(Fractal && other) noexcept = default;

    /**
     * Assignment operator, default
     * @param other fractal to assign
     * @return the reference to the assigned fractal
     */
    Fractal &operator=(const Fractal &other) = default;

    /**
     * Move assignment, default
     * @param other fractal as an r-value
     * @return the reference to the assigned fractal
     */
    Fractal &operator=(Fractal && other) noexcept = default;

};

/**
 * Class to represent a Sierpinski Carpet fractal. Inherit Fractal
 */
class SierpinskiCarpet : public Fractal
{
public:
    /**
     * Constructor
     * @param degree the degree of the fractal
     */
    explicit SierpinskiCarpet(int degree);

    /**
     * Copy constructor
     * @param other S.C fractal to copy
     */
    SierpinskiCarpet(const SierpinskiCarpet &other) : Fractal(other)
    {}

    /**
     * Move constructor
     * @param other S.C fractal to copy
     */
    SierpinskiCarpet(SierpinskiCarpet && other) noexcept = default;

    /**
     * A boolean function receiving coordinate and decides whether there should be # or ' '
     * @param x coordinate
     * @param y coordinate
     * @return true if there should be #, false for ' '
     */
    bool doDraw(int x, int y) override;
};

/**
 * Class to represent a Sierpinski Sieve fractal. Inherit Fractal
 */
class SierpinskiSieve : public Fractal
{
public:
    /**
     * Constructor
     * @param degree the degree of the fractal
     */
    explicit SierpinskiSieve(int degree);

    /**
     * Copy constructor
     * @param other S.S fractal to copy
     */
    SierpinskiSieve(const SierpinskiSieve &other) : Fractal(other)
    {}

    /**
     * Move constructor
     * @param other S.S fractal to copy
     */
    SierpinskiSieve(SierpinskiSieve && other) noexcept = default;

    /**
     * A boolean function receiving coordinate and decides whether there should be # or ' '
     * @param x coordinate
     * @param y coordinate
     * @return true if there should be #, false for ' '
     */
    bool doDraw(int x, int y) override;
};

/**
 * Class represents a Cantor Dust fractal. Inherit Fractal
 */
class CantorDust : public Fractal
{
public:
    /**
     * Constructor
     * @param degree the degree of the fractal
     */
    explicit CantorDust(int degree);

    /**
     * Copy constructor
     * @param other C.D fractal to copy
     */
    CantorDust(const CantorDust &other) : Fractal(other)
    {}

    /**
     * Move constructor
     * @param other C.D fractal to copy
     */
    CantorDust(CantorDust && other) noexcept = default;

    /**
     * A boolean function receiving coordinate and decides whether there should be # or ' '
     * @param x coordinate
     * @param y coordinate
     * @return true if there should be #, false for ' '
     */
    bool doDraw(int x, int y) override;
};

#endif //EX2_FRACTAL_H

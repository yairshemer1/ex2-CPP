#include <iostream>
#include <fstream>
#include <vector>
#include "Fractal.h"

#define INVALID_USAGE std::cerr << "Usage: FractalDrawer <file path>\n"; return EXIT_FAILURE;
#define INVALID_INPUT std::cerr << "Invalid input\n"; return EXIT_FAILURE;
#define MEM_ERR std::cerr << "Memory allocation failed\n"; return EXIT_FAILURE;

static const char ASCII_0 = '0';

static const int MAX_TYPE = 3;

static const int MIN_TYPE = 1;

static const int MIN_DEG = 1;

static const int MAX_DEG = 6;

static const int MAX_LINE_SIZE = 3;

static const int NUM_OF_ARGS = 2;

/**
 * A factory for fractals. Given a type integer it determines which fractal fits and allocate
 * memoty for it and sends it's pointer.
 * @param type of the fractal
 * @param degree of the fractal
 * @return pointer to the fractal, nullptr if allocation failed
 */
Fractal *createFractal(int type, int degree)
{
    if (type == S_C_TYPE)
    {
        return new(std::nothrow)SierpinskiCarpet(degree);
    }
    if (type == S_S_TYPE)
    {
        return new(std::nothrow)SierpinskiSieve(degree);
    }
    if (type == C_D_TYPE)
    {
        return new(std::nothrow)CantorDust(degree);
    }
    return nullptr;
}

/**
 * Frees the allocated space for the vector
 * @param vec vector to free
 */
void deleteVector(std::vector<Fractal *> &vec)
{
    for (Fractal *f:vec)
    {
        delete f;
    }
}

/**
 * The main function will receive a file from user, parse it and create a vector of pointers
 * to fractals, then it will draw them and free the vector.
 * @param argc number of args
 * @param argv args list
 * @return 0 upon success, 1 otherwise
 */
int main(int argc, char **argv)
{
    std::vector<Fractal *> fractals;
    int first, second;
    char ch;
    if (argc != NUM_OF_ARGS)
    {
        INVALID_USAGE
    }
    std::ifstream inFile(argv[1]);
    //fail in opening the file
    if (!inFile)
    {
        INVALID_INPUT
    }
    std::string line;
    //reading line by line
    while (getline(inFile, line))
    {
        first = line[0] - ASCII_0;
        ch = line[1];
        second = line[2] - ASCII_0;
        if (ch != ',' || first < MIN_TYPE || first > MAX_TYPE || second < MIN_DEG ||
            second > MAX_DEG || line.size() != MAX_LINE_SIZE)
        {
            deleteVector(fractals);
            INVALID_INPUT
        }
        //allocate new fractal
        Fractal *newFractal = createFractal(first, second);
        //check if success
        if (newFractal == nullptr)
        {
            deleteVector(fractals);
            MEM_ERR
        }
        //add to vector
        fractals.push_back(newFractal);
    }
    //print vector
    for (int i = (int) fractals.size() - 1; i >= 0; i--)
    {
        fractals[i]->draw();
    }
    deleteVector(fractals);

}

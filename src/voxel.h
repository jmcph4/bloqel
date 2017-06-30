/**
 * @file voxel.h
 * @author Jack McPherson 
 *
 * Contains definition of the `Voxel` class and other code for directly
 * manipulating voxels.
 *
 */

#pragma once

#include <vector>

#include "position.h"
#include "colour.h"

/**
 * Enumerated type representing the faces of a voxel.
 * 
 */
enum VoxelFace
{
    TOP = 0,
    BOTTOM = 1,
    LEFT = 2,
    RIGHT = 3,
    FRONT = 4,
    BACK = 5
};

/**
 * Represents a voxel.
 * 
 * A voxel is a 3D pixel (i.e. a cube). Each voxel stores information such as
 * its position, the colour of each of its faces, and whether it is "solid" or
 * not.
 */
class Voxel
{
    public:
        Voxel(void);
        Voxel(Position position);
        Position getPosition(void);
        void setPosition(Position position);
        
        void setFaceColour(VoxelFace face, Colour colour);
        Colour getFaceColour(VoxelFace face);
        void toggleSolid(void);
        bool isSolid(void);
    
    private:
        Position DEFAULT_POSITION = std::make_tuple(0, 0, 0);
        Colour DEFAULT_COLOUR = WHITE;
        Position pos;
        bool solid;
        std::vector<Colour> colours;

        void initColours(void);
};


/**
 * @file voxel.cpp
 * @author Jack McPherson
 * 
 * Implements the members of the `Voxel` class.
 * 
 */
#include "colour.h"
#include "voxel.h"

/**
 * Default constructor of the `Voxel` class.
 *
 * Initialises the voxel's position to the default (i.e.
 * `Voxel::DEFAULT_POSITION`).
 */
Voxel::Voxel(void)
{
    this->pos = this->DEFAULT_POSITION; // set position
    this->initColours(); // init colours
}

/**
 * Constructor for the `Voxel` class.
 *
 * Sets the voxel's position to `position`.
 * 
 * @param position
 *         the position of the voxel
 */
Voxel::Voxel(Position position)
{
    this->pos = position; // set position
    this->initColours(); // init colours
}

void Voxel::initColours(void)
{
    this->colours.push_back(this->DEFAULT_COLOUR);
    this->colours.push_back(this->DEFAULT_COLOUR);
    this->colours.push_back(this->DEFAULT_COLOUR);
    this->colours.push_back(this->DEFAULT_COLOUR);
    this->colours.push_back(this->DEFAULT_COLOUR);
    this->colours.push_back(this->DEFAULT_COLOUR);

}

/**
 * Returns the position of the voxel.
 *
 * @return the position of the voxel
 */
Position Voxel::getPosition(void)
{
    return this->pos;
}

/**
 * Sets the position of the voxel to `position`.
 *
 * @param position
 *         the new position of the voxel
 */
void Voxel::setPosition(Position position)
{
    this->pos = position;
}

/**
 * Sets the colour of the voxel face at `face` to `colour`.
 *
 * @param face
 *          the face of the voxel
 * @param colour
 *          the colour to set
 *
 */
void Voxel::setFaceColour(VoxelFace face, Colour colour)
{
    this->colours[face] = colour;
}

/**
 * Returns the colour of the specified face of the voxel (i.e. `face`).
 * 
 * @param face
 * @return colour of the face
 * 
 */
Colour Voxel::getFaceColour(VoxelFace face)
{
    return this->colours[face];
}

/**
 * Toggles whether the voxel is solid or not.
 * 
*/
void Voxel::toggleSolid(void)
{
    if(this->solid)
    {
        this->solid = false;
    }
    else
    {
        this->solid = true;
    }
}

/**
 * Returns whether or not the voxel is solid.
 * 
 * @return whether the voxel is solid
*/
bool Voxel::isSolid(void)
{
    return this->solid;
}


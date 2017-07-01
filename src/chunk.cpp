/**
 * @file chunk.cpp
 * @author Jack McPherson
 * 
 * Implements the `Chunk` class.
*/
#include <tuple>

#include "chunk.h"

/**
 * Default constructor for the `Chunk` class.
 *
 * Initialises a chunk of size `chunkSize` at position `chunkPos`.
 * 
 * @param chunkPos
 *         position of the chunk
 * @param chunkSize
 *         size of the chunk (note that chunks are cubes)
 *
 */
Chunk::Chunk(Position chunkPos, unsigned int chunkSize)
{
    this->pos = chunkPos;
    this->size = chunkSize;
    
    // initialise voxel space
    this->initVoxelSpace();
}

/**
 * Returns the position of the chunk.
 * 
 * @return the position of the chunk
 */
Position Chunk::getPosition(void)
{
    return this->pos;
}

/**
 * Sets the position of the chunk.
 * 
 * @param position
 *          the new position of the chunk
 *
*/
void Chunk::setPosition(Position position)
{
    Position diff = std::make_tuple(std::get<0>(this->pos) - std::get<0>(position),
                                    std::get<1>(this->pos) - std::get<1>(position),
                                    std::get<2>(this->pos) - std::get<2>(position));
    
    this->shiftVoxels(diff);
    
    this->pos = position;
}

/**
 * Returns the `Voxel` at `position` <b>relative to the chunk's position</b>.
 *
 * @param position
 *          the position of the desired voxel
 * @return the voxel at the specified position
 *
 */
Voxel Chunk::getVoxelAt(Position position)
{
    // extract co-ordinates
    unsigned long long x = std::get<0>(position);
    unsigned long long y = std::get<1>(position);
    unsigned long long z = std::get<2>(position);

    return this->voxels[x][y][z];
}

/**
 * Performs element-wise addition of `offset` and the position of each voxel.
 * 
 * @param offset
 *          offset vector
 */
void Chunk::shiftVoxels(Position offset)
{
    unsigned long long x;
    unsigned long long y;
    unsigned long long z;

    unsigned long long dx = std::get<0>(offset);
    unsigned long long dy = std::get<1>(offset);
    unsigned long long dz = std::get<2>(offset);

    for(unsigned int i=0;i<this->size;i++)
    {
        for(unsigned int j=0;j<this->size;j++)
        {
            for(unsigned int k=0;k<this->size;k++)
            {
                Voxel currVoxel = this->voxels[i][j][k];

                x = std::get<0>(currVoxel.getPosition());
                y = std::get<1>(currVoxel.getPosition());
                z = std::get<2>(currVoxel.getPosition());
                
                this->voxels[i][j][k].setPosition(std::make_tuple(x+dx, y+dy, z+dz));
            }
        }
    }
}

/**
 * Returns the size of the chunk.
 * 
 * @return the size of the chunk
 */
unsigned int Chunk::getSize(void)
{
    return this->size;
}

/**
 * Initialises the voxel space as a 3D grid.
 *
 */
void Chunk::initVoxelSpace()
{
    unsigned long long x = std::get<0>(this->pos);
    unsigned long long y = std::get<1>(this->pos);
    unsigned long long z = std::get<2>(this->pos);

    this->voxels = std::vector<std::vector<std::vector<Voxel>>>(this->size);

    for(unsigned int i=0;i<this->voxels.size();i++)
    {
        this->voxels[i] = std::vector<std::vector<Voxel>>(this->size);
        
        for(unsigned int j=0;j<this->voxels[i].size();j++)
        {
            this->voxels[i][j] = std::vector<Voxel>(this->size);

            for(unsigned int k=0;k<this->voxels[i][j].size();k++)
            {
                this->voxels[i][j][k].setPosition(std::make_tuple(x+i, y+j, z+k));
            }
        }
    }

    /*for(unsigned int i=0;i<this->size;i++)
    {
        this->voxels.push_back(std::vector<std::vector<Voxel> >());

        for(unsigned int j=0;i<this->size;j++)
        {
            this->voxels[j].push_back(std::vector<Voxel>());
            
            for(unsigned int k=0;i<this->size;k++)
            {
                this->voxels[j][k].push_back(Voxel(std::make_tuple(x+i, y+j, z+k)));
            }
        }
    }*/
}




/**
 * @file chunk.h
 * @author
 * 
 * Contains the `Chunk` class and other code for manipulating chunks.
 *
 */
#pragma once

#include <vector>

#include "position.h"
#include "voxel.h"

/**
 * Represents a chunk of voxels.
 *
 * A chunk is a collection of voxels (geometrically a cube). A chunk is used to
 * manage voxels on a larger scale than individually and provides the first
 * layer of abstraction.
 * 
 */
class Chunk
{
    public:
        Chunk(Position chunkPos, unsigned int chunkSize);
        Position getPosition(void);
        unsigned int getSize(void);
        void setPosition(Position pos);
    private:
        Position pos; // chunk position
        unsigned int size; // size of chunk
        std::vector<std::vector<std::vector<Voxel>>> voxels;
        
        void initVoxelSpace();
        void shiftVoxels(Position offset);
};


/**
 * @file position.h
 * @author Jack McPherson
 * 
 * Contains code for interacting with and modifying `Position` types.
 */

#pragma once

#include <tuple>

/**
 * Represents a position in 3D Euclidean space.
 * 
 */
typedef std::tuple<unsigned long long, unsigned long long, unsigned long long>
        Position;


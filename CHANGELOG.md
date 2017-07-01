# CHANGELOG #
---

## [0.0.2] - 2017-07-01  ##
### Added ###
 - `Chunk` now has a `getVoxelAt` function, allowing direct voxel access

### Changed ###
 - `Voxel` constructors now initialise to solid by default

### Removed ###
None

### Fixed ###
 - Issue #1: `Chunk` constructor fails to initialise voxel position after
    allocation


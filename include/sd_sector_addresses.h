#ifndef SD_SECTOR_ADDRESSES_H
#define SD_SECTOR_ADDRESSES_H

// This file defines the sector addresses of the images to be loaded on the
// screen The sector addresses can be found via the 4D Systems Workshop 4D IDE
// The Graphics Composer of this software should be used:
//  - To load the desired images on the uSD card
//  - To find the sector addresses of said images (via generated .Gc file)

// A sector address on the SD card is defined by
// an address consisting of two parts: high and low bits.
// Both parts specify 2 bytes of the complete address
// So, address = hi << 8 | lo
// These two are split, since that is how the 4dsystems
// serial library addresses images on the SD.
struct SectorAddress {
  unsigned int hi;
  unsigned int lo;
};

// clang-format off

/**********
 * Start menu
 **********/
#define HOME_SIT_START SectorAddress { 0x0000, 0x0000 }
#define HOME_SIT_START_SELECTED SectorAddress { 0x0000, 0x00A2 }
#define HOME_SIT_START_ACTIVATED SectorAddress { 0x0000, 0x0051 }

#define STAND_UP SectorAddress { 0x0000, 0x1209 }
#define STAND_UP_SELECTED SectorAddress { 0x0000, 0x12AB }
#define STAND_UP_ACTIVATED SectorAddress { 0x0000, 0x125A }

#define HOME_STAND_START SectorAddress { 0x0000, 0x01E6 }
#define HOME_STAND_START_SELECTED SectorAddress { 0x0000, 0x0288 }
#define HOME_STAND_START_ACTIVATED SectorAddress { 0x0000, 0x0237 }

#define TURN_OFF_START SectorAddress { 0x0000, 0x14E2 }
#define TURN_OFF_START_SELECTED SectorAddress { 0x0000, 0x1584 }
#define TURN_OFF_START_ACTIVATED SectorAddress { 0x0000, 0x1533 }
/***** Start menu *****/

/**********
 * Walk menu
 **********/
#define WALK SectorAddress { 0x0000, 0x15D5 }
#define SIDE_STEP SectorAddress { 0x0000, 0x03CC }
#define SINGLE_STEP SectorAddress { 0x0000, 0x0603 }

// Walk sizes
#define WALK_SMALL SectorAddress { 0x0000, 0x1950 }
#define WALK_SMALL_SELECTED SectorAddress { 0x0000, 0x19F2 }
#define WALK_SMALL_ACTIVATED SectorAddress { 0x0000, 0x19A1 }

#define WALK_NORMAL SectorAddress { 0x0000, 0x1719 }
#define WALK_NORMAL_SELECTED SectorAddress { 0x0000, 0x17BB }
#define WALK_NORMAL_ACTIVATED SectorAddress { 0x0000, 0x176A }

#define WALK_LARGE SectorAddress { 0x0000, 0x1626 }
// Missing WALK_LARGE_SELECTED and WALK_LARGE_ACTIVATED

// Sidestep
#define SIDE_STEP_LEFT SectorAddress { 0x0000, 0x041D }
#define SIDE_STEP_RIGHT SectorAddress { 0x0000, 0x0510 }

// Side step left
#define SIDE_STEP_LEFT_SMALL SectorAddress { 0x0000, 0x2F76 }
#define SIDE_STEP_LEFT_SMALL_SELECTED SectorAddress { 0x0000, 0x3018 }
#define SIDE_STEP_LEFT_SMALL_ACTIVATED SectorAddress { 0x0000, 0x2FC7 }

#define SIDE_STEP_LEFT_NORMAL SectorAddress { 0x0000, 0x2C9D }
#define SIDE_STEP_LEFT_NORMAL_SELECTED SectorAddress { 0x0000, 0x2D3F }
#define SIDE_STEP_LEFT_NORMAL_ACTIVATED SectorAddress { 0x0000, 0x2CEE }

// Side step right
#define SIDE_STEP_RIGHT_SMALL SectorAddress { 0x0000, 0x3069 }
#define SIDE_STEP_RIGHT_SMALL_SELECTED SectorAddress { 0x0000, 0x310B }
#define SIDE_STEP_RIGHT_SMALL_ACTIVATED SectorAddress { 0x0000, 0x30BA }

#define SIDE_STEP_RIGHT_NORMAL SectorAddress { 0x0000, 0x2D90 }
#define SIDE_STEP_RIGHT_NORMAL_SELECTED SectorAddress { 0x0000, 0x2E32 }
#define SIDE_STEP_RIGHT_NORMAL_ACTIVATED SectorAddress { 0x0000, 0x0000 }

// Single steps
#define SINGLE_STEP_SMALL SectorAddress { 0x0000, 0x097E }
#define SINGLE_STEP_SMALL_SELECTED SectorAddress { 0x0000, 0x0A20 }
#define SINGLE_STEP_SMALL_ACTIVATED SectorAddress { 0x0000, 0x09CF }

#define SINGLE_STEP_NORMAL SectorAddress { 0x0000, 0x0747 }
#define SINGLE_STEP_NORMAL_SELECTED SectorAddress { 0x0000, 0x07E9 }
#define SINGLE_STEP_NORMAL_ACTIVATED SectorAddress { 0x0000, 0x0798 }

#define SINGLE_STEP_LARGE SectorAddress { 0x0000, 0x0654 }
/***** Walk menu *****/

/**********
 * Sit menu
 **********/
#define SIT SectorAddress { 0x0000, 0x222C }
#define SIT_SELECTED SectorAddress { 0x0000, 0x0B13 }
#define SIT_ACTIVATED SectorAddress { 0x0000, 0x0AC2 }

#define HOME_SIT SectorAddress { 0x0000, 0x218A }
#define HOME_SIT_SELECTED SectorAddress { 0x0000, 0x00A2 }
#define HOME_SIT_ACTIVATED SectorAddress { 0x0000, 0x0051 }

#define HOME_STAND SectorAddress { 0x0000, 0x21DB }
#define HOME_STAND_SELECTED SectorAddress { 0x0000, 0x0288 }
#define HOME_STAND_ACTIVATED SectorAddress { 0x0000, 0x0237 }

#define TURN_OFF SectorAddress { 0x0000, 0x227D }
#define TURN_OFF_SELECTED SectorAddress { 0x0000, 0x1491 }
#define TURN_OFF_ACTIVATED SectorAddress { 0x0000, 0x1440 }
/***** Sit menu *****/

/**********
 * Obstacle menu
 **********/
#define SOFA SectorAddress { 0x0000, 0x2505 }

#define SOFA_SIT SectorAddress { 0x0000, 0x25F8 }
#define SOFA_SIT_SELECTED SectorAddress { 0x0000, 0x0E8E }
#define SOFA_SIT_ACTIVATED SectorAddress { 0x0000, 0x0E3D }

#define SOFA_STANDUP SectorAddress { 0x0000, 0x2649 }
#define SOFA_STANDUP_SELECTED SectorAddress { 0x0000, 0x0F81 }
#define SOFA_STANDUP_ACTIVATED SectorAddress { 0x0000, 0x0F30 }

#define STAIRS SectorAddress { 0x0000, 0x2556 }

#define STAIRS_UP SectorAddress { 0x0000, 0x26EB }
#define STAIRS_UP_SELECTED SectorAddress { 0x0000, 0x11B8 }
#define STAIRS_UP_ACTIVATED SectorAddress { 0x0000, 0x1167 }

#define STAIRS_DOWN SectorAddress { 0x0000, 0x269A }
#define STAIRS_DOWN_SELECTED SectorAddress { 0x0000, 0x10C5 }
#define STAIRS_DOWN_ACTIVATED SectorAddress { 0x0000, 0x1074 }
/***** Obstacle menu *****/

// clang-format on

#endif // SD_SECTOR_ADDRESSES_H

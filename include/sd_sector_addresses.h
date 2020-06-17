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
struct SectorAddress
{
  unsigned int hi;
  unsigned int lo;
};

// clang-format off

/**********
 * Start menu arrows at the top
 **********/
#define TURNED_ON SectorAddress { 0x0000, 0x2320 }

#define TURN_OFF SectorAddress { 0x0000, 0x2DE2 }
#define TURN_OFF_SELECTED SectorAddress { 0x0000, 0x2E33 }
#define TURN_OFF_ACTIVATED SectorAddress { 0x0000, 0x2E84 }

#define HOME_SIT SectorAddress { 0x0000, 0x2371 }
#define HOME_SIT_SELECTED SectorAddress { 0x0000, 0x23C2 }
#define HOME_SIT_ACTIVATED SectorAddress { 0x0000, 0x2413 }

#define STAND_UP SectorAddress { 0x0000, 0x2464 }
#define STAND_UP_SELECTED SectorAddress { 0x0000, 0x24B5 }
#define STAND_UP_ACTIVATED SectorAddress { 0x0000, 0x2506 }

#define OBSTACLE_MENU SectorAddress { 0x0000, 0x2557 }
/***** Start menu *****/

#define WALK SectorAddress { 0x0000, 0x34D8 }
#define WALK_SELECTED SectorAddress { 0x0000, 0x1075 }
#define WALK_ACTIVATED SectorAddress { 0x0000, 0x10C6 }
#define SINGLE_STEP_SELECTED SectorAddress { 0x0000, 0x1FA5 }
#define SINGLE_STEP_ACTIVATED SectorAddress { 0x0000, 0x1FF6 }
#define WALK_PLAIN SectorAddress { 0x0000, 0x34D8 }

/**********
 * Start menu squares at the top
 **********/
#define TURNED2_ON SectorAddress { 0x0000, 0x2974 }

#define TURN2_OFF SectorAddress { 0x0000, 0x32A1 }

#define HOME_SIT2 SectorAddress { 0x0000, 0x29C5 }
#define HOME_SIT2_SELECTED SectorAddress { 0x0000, 0x2A16 }
#define HOME_SIT2_ACTIVATED SectorAddress { 0x0000, 0x2A67 }

#define STAND2_UP SectorAddress { 0x0000, 0x2AB8 }
#define STAND2_UP_SELECTED SectorAddress { 0x0000, 0x2B09 }
#define STAND2_UP_ACTIVATED SectorAddress { 0x0000, 0x2B5A }

#define OBSTACLE2_MENU SectorAddress { 0x0000, 0x2BAB }

/**********
 * Escape menu
 **********/
/**********
 * Walk menu + home
 **********/
#define WALK_HOME SectorAddress { 0x0000, 0x213A }
#define WALK_HOME_SELECTED SectorAddress { 0x0000, 0x218B }
#define WALK_HOME_ACTIVATED SectorAddress { 0x0000, 0x21DC }

#define HOME_WALKMENU SectorAddress { 0x0000, 0x31AE }
#define HOME_WALKMENU_SELECTED SectorAddress { 0x0000, 0x227E }
#define HOME_WALKMENU_ACTIVATED SectorAddress { 0x0000, 0x22CF }

/**********
 * Single step menu + home
 **********/
#define SINGLE_STEP_HOME SectorAddress { 0x0000, 0x1F54 }
#define SINGLE_STEP_HOME_SELECTED SectorAddress { 0x0000, 0x1FA5 }
#define SINGLE_STEP_ACTIVATED SectorAddress { 0x0000, 0x1FF6 }

#define HOME_SSMENU SectorAddress { 0x0000, 0x2047 }
#define HOME_SSMENU_SELECTED SectorAddress { 0x0000, 0x2098 }
#define HOME_SSMENU_ACTIVATED SectorAddress { 0x0000, 0x20E9 }

/**********
 * Walk menu + home stand + sit + home
 **********/
#define WALK_4 SectorAddress { 0x0000, 0x31FF }
#define WALK_4_SELECTED SectorAddress { 0x0000, 0x171A }
#define WALK_4_ACTIVATED SectorAddress { 0x0000, 0x176B }

#define HOMESTAND_4_WALKMENU SectorAddress { 0x0000, 0x3250 }
#define HOMESTAND_4_WALKMENU_SELECTED SectorAddress { 0x0000, 0x180D }
#define HOMESTAND_4_WALKMENU_ACTIVATED SectorAddress { 0x0000, 0x185E }

#define SIT_4_WALKMENU SectorAddress { 0x0000, 0x315D }
#define SIT_4_WALKMENU_SELECTED SectorAddress { 0x0000, 0x1900 }
#define SIT_4_WALKMENU_ACTIVATED SectorAddress { 0x0000, 0x1951 }

/**********
 * Single step menu + home stand + sit + home
 **********/
#define SINGLE_STEP_4 SectorAddress { 0x0000, 0x30BB }
#define SINGLE_STEP_4_SELECTED SectorAddress { 0x0000, 0x1627 }
#define SINGLE_STEP_4_ACTIVATED SectorAddress { 0x0000, 0x1678 }

#define HOMESTAND_4_SSMENU SectorAddress { 0x0000, 0x310C }
#define HOMESTAND_4_SSMENU_SELECTED SectorAddress { 0x0000, 0x180D }
#define HOMESTAND_4_SSMENU_ACTIVATED SectorAddress { 0x0000, 0x185E }

#define SIT_4_SSMENU SectorAddress { 0x0000, 0x315D }
#define SIT_4_SSMENU_SELECTED SectorAddress { 0x0000, 0x1900 }
#define SIT_4_SSMENU_ACTIVATED SectorAddress { 0x0000, 0x1951 }

/**********
 * Obstacle menu - normal
 **********/
#define SOFA SectorAddress { 0x0000, 0x0001 }

#define SOFA_SIT SectorAddress { 0x0000, 0x0052 }
#define SOFA_SIT_SELECTED SectorAddress { 0x0000, 0x00A3 }
#define SOFA_SIT_ACTIVATED SectorAddress { 0x0000, 0x00F4 }

#define SOFA_STANDUP SectorAddress { 0x0000, 0x0145 }
#define SOFA_STANDUP_SELECTED SectorAddress { 0x0000, 0x0196 }
#define SOFA_STANDUP_ACTIVATED SectorAddress { 0x0000, 0x01EF }


#define SLALOM SectorAddress { 0x0000, 0x3529 }

#define WALK_2O SectorAddress { 0x0000, 0x357A }
#define WALK_2O_SELECTED SectorAddress { 0x0000, 0x02DA }
#define WALK_2O_ACTIVATED SectorAddress { 0x0000, 0x032B }


#define ROUGH_TERRAIN SectorAddress { 0x0000, 0x037C }

#define HIGHSTEP_RT SectorAddress { 0x0000, 0x03CD }
#define HIGHSTEP_RT_second SectorAddress { 0x0000, 0x06A6 }
#define HIGHSTEP_RT_SELECTED SectorAddress { 0x0000, 0x041E }
#define HIGHSTEP_RT_ACTIVATED SectorAddress { 0x0000, 0x046F }

#define SMALLSTEP_RT SectorAddress { 0x0000, 0x04C0 }
#define SMALLSTEP_RT_second SectorAddress { 0x0000, 0x0799 }
#define SMALLSTEP_RT_SELECTED SectorAddress { 0x0000, 0x0511 }
#define SMALLSTEP_RT_ACTIVATED SectorAddress { 0x0000, 0x0562 }

#define MIDDLESTEP1_RT SectorAddress { 0x0000, 0x3946 }
#define MIDDLESTEP1_RT_SELECTED SectorAddress { 0x0000, 0x3A39 }
#define MIDDLESTEP1_RT_ACTIVATED SectorAddress { 0x0000, 0x3A8A }

#define MIDDLESTEP2_RT SectorAddress { 0x0000, 0x3997 }
#define MIDDLESTEP2_RT_SELECTED SectorAddress { 0x0000, 0x3ADB }
#define MIDDLESTEP2_RT_ACTIVATED SectorAddress { 0x0000, 0x3B2C }

#define MIDDLESTEP3_RT SectorAddress { 0x0000, 0x39E8 }
#define MIDDLESTEP3_RT_SELECTED SectorAddress { 0x0000, 0x3B7D }
#define MIDDLESTEP3_RT_ACTIVATED SectorAddress { 0x0000, 0x3BCE }


#define STAIRS SectorAddress { 0x0000, 0x088C }

#define STAIRS_UP SectorAddress { 0x0000, 0x08DD }
#define STAIRS_UP_SELECTED SectorAddress { 0x0000, 0x092E }
#define STAIRS_UP_ACTIVATED SectorAddress { 0x0000, 0x097F }

#define WALK_STAIRS SectorAddress { 0x0000, 0x09D0 }
#define WALK_STAIRS_SELECTED SectorAddress { 0x0000, 0x0A21 }
#define WALK_STAIRS_ACTIVATED SectorAddress { 0x0000, 0x0A72 }

#define STAIRS_DOWN SectorAddress { 0x0000, 0x0AC3 }
#define STAIRS_DOWN_SELECTED SectorAddress { 0x0000, 0x0B14 }
#define STAIRS_DOWN_ACTIVATED SectorAddress { 0x0000, 0x0B65 }

#define STAIRS_STEP_DOWN SectorAddress { 0x0000, 0x408D }
#define STAIRS_STEP_DOWN_SELECTED SectorAddress { 0x0000, 0x556F }
#define STAIRS_STEP_DOWN_ACTIVATED SectorAddress { 0x0000, 0x55C0 }
#define STAIRS_STEP_UP SectorAddress { 0x0000, 0x40DE }
#define STAIRS_STEP_UP_SELECTED SectorAddress { 0x0000, 0x5611 }
#define STAIRS_STEP_UP_ACTIVATED SectorAddress { 0x0000, 0x5662 }

#define TILTED_PATH SectorAddress { 0x0000, 0x0BB6 }
#define TILTED_PATH_RECHTS SectorAddress { 0x0000, 0x38A4 }
#define TILTED_PATH_LINKS SectorAddress { 0x0000, 0x38F5 }
#define TILTED_PATH_RECHTS2 SectorAddress { 0x0000, 0x4732 }
#define TILTED_PATH_LINKS2 SectorAddress { 0x0000, 0x46E1 }

#define LEFT_STEPUP_TP SectorAddress { 0x0000, 0x505F }
#define LEFT_UP_TP_SELECTED SectorAddress { 0x0000, 0x4C93 }
#define LEFT_UP_TP_ACTIVATED SectorAddress { 0x0000, 0x4E79 }
#define LEFT_STEP_TP_SELECTED SectorAddress { 0x0000, 0x4D35 }
#define LEFT_STEP_TP_ACTIVATED SectorAddress { 0x0000, 0x4F1B }
#define LEFT_LAST_TP_SELECTED SectorAddress { 0x0000, 0x4E28 }
#define LEFT_LAST_TP_ACTIVATED SectorAddress { 0x0000, 0x500E }
#define LEFT_FIRSTSTEP_TP SectorAddress { 0x0000, 0x50B0 }
#define LEFT_SECONDSTEP_TP SectorAddress { 0x0000, 0x5101 }
#define LEFT_THIRDSTEP_TP SectorAddress { 0x0000, 0x5152 }
#define LEFT_FOURTHSTEP_TP SectorAddress { 0x0000, 0x51A3 }
#define LEFT_FIFTHSTEP_TP SectorAddress { 0x0000, 0x51F4 }
#define LEFT_SIXTHSTEP_TP SectorAddress { 0x0000, 0x5245 }
#define LEFT_LASTSTEP_TP SectorAddress { 0x0000, 0x5296 }

#define RIGHT_STEPUP_TP SectorAddress { 0x0000, 0x52E7 }
#define RIGHT_UP_TP_SELECTED SectorAddress { 0x0000, 0x4CE4 }
#define RIGHT_UP_TP_ACTIVATED SectorAddress { 0x0000, 0x4ECA }
#define RIGHT_STEP_TP_SELECTED SectorAddress { 0x0000, 0x4D86 }
#define RIGHT_STEP_TP_ACTIVATED SectorAddress { 0x0000, 0x4F6C }
#define RIGHT_LAST_TP_SELECTED SectorAddress { 0x0000, 0x4DD7 }
#define RIGHT_LAST_TP_ACTIVATED SectorAddress { 0x0000, 0x4FBD }
#define RIGHT_FIRSTSTEP_TP SectorAddress { 0x0000, 0x5338 }
#define RIGHT_SECONDSTEP_TP SectorAddress { 0x0000, 0x5389 }
#define RIGHT_THIRDSTEP_TP SectorAddress { 0x0000, 0x53DA }
#define RIGHT_FOURTHSTEP_TP SectorAddress { 0x0000, 0x542B }
#define RIGHT_FIFTHSTEP_TP SectorAddress { 0x0000, 0x547C }
#define RIGHT_SIXTHSTEP_TP SectorAddress { 0x0000, 0x54CD }
#define RIGHT_LASTSTEP_TP SectorAddress { 0x0000, 0x551E }

#define SLOPE SectorAddress { 0x0000, 0x0EE0 }

#define SLOPE_UP SectorAddress { 0x0000, 0x412F }
#define SLOPE_UP_SELECTED SectorAddress { 0x0000, 0x0F82 }
#define SLOPE_UP_ACTIVATED SectorAddress { 0x0000, 0x0FD3 }

#define WALK_SLOPE SectorAddress { 0x0000, 0x4180 }
#define WALK_SLOPE_SELECTED SectorAddress { 0x0000, 0x1075 }
#define WALK_SLOPE_ACTIVATED SectorAddress { 0x0000, 0x10C6 }

#define SLOPE_DOWN SectorAddress { 0x0000, 0x41D1 }
#define SLOPE_DOWN_SELECTED SectorAddress { 0x0000, 0x1168 }
#define SLOPE_DOWN_ACTIVATED SectorAddress { 0x0000, 0x11B9 }

#define SLOPE_LAST_STEP SectorAddress { 0x0000, 0x4222 }
#define SLOPE_LAST_STEP_SELECTED SectorAddress { 0x0000, 0x57F7 }
#define SLOPE_LAST_STEP_ACTIVATED SectorAddress { 0x0000, 0x5848 }

/***** Obstacle menu *****/


/**********
 * Obstacle menu 2 - blue with dots
 **********/
#define SOFA2 SectorAddress { 0x0000, 0x2BFC }
#define SLALOM2 SectorAddress { 0x0000, 0x2C4D }
#define ROUGH_TERRAIN2 SectorAddress { 0x0000, 0x2C9E }
#define STAIRS2 SectorAddress { 0x0000, 0x2CEF }
#define TILTED_PATH2 SectorAddress { 0x0000, 0x2D40 }
#define SLOPE2 SectorAddress { 0x0000, 0x2D91 }
/***** Obstacle menu 2 - blue with dots *****/

/**********
 * Obstacle menu 3 - blue without dots
 **********/
#define SOFA3 SectorAddress { 0x0000, 0x25A8 }
#define SLALOM3 SectorAddress { 0x0000, 0x25F9 }
#define ROUGH_TERRAIN3 SectorAddress { 0x0000, 0x264A }
#define STAIRS3 SectorAddress { 0x0000, 0x269B }
#define TILTED_PATH3 SectorAddress { 0x0000, 0x26EC }
#define SLOPE3 SectorAddress { 0x0000, 0x273D }
/***** Obstacle menu 3 - blue without dots *****/

/**********
* Obstacle menu - with arrows
 **********/
#define SOFA4 SectorAddress { 0x0000, 0x36BE }
#define SLALOM4 SectorAddress { 0x0000, 0x370F }
#define ROUGH_TERRAIN4 SectorAddress { 0x0000, 0x3760 }
#define STAIRS4 SectorAddress { 0x0000, 0x37B1 }
#define TILTED_PATH4 SectorAddress { 0x0000, 0x3802 }
#define SLOPE4 SectorAddress { 0x0000, 0x3853 }
/***** Obstacle menu - with arrows *****/

/**********
* Overige opties
 **********/
#define FAST_WALK { 0x0000, 0x2ED5 }
#define FAST_WALK_SELECTED { 0x0000, 0x2F26 }
#define FAST_WALK_ACTIVATED { 0x0000, 0x2F77 }

#define REBOOT { 0x0000, 0x2FC8 }
#define REBOOT_SELECTED { 0x0000, 0x3019 }
#define REBOOT_ACTIVATED { 0x0000, 0x306A }

#define WALK_SMALL { 0x0000, 0x3394 }
#define WALK_MEDIUM { 0x0000, 0x32F2 }
#define WALK_LARGE { 0x0000, 0x3343 }

#define STEP_SMALL { 0x0000, 0x3487 }
#define STEP_MEDIUM { 0x0000, 0x33E5 }
#define STEP_LARGE { 0x0000, 0x3436 }

#define STEP_SIZE_UP { 0x0000, 0x3436 }
#define STEP_SIZE_DOWN { 0x0000, 0x3436 }
#define STEP_LARGE { 0x0000, 0x3436 }

#define NOT_POSSIBLE { 0x0000, 0x3436 }
// clang-format on

// clang-format on

#endif  // SD_SECTOR_ADDRESSES_H

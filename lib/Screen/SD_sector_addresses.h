#ifndef SD_ADDRESSES_H
#define SD_ADDRESSES_H

// This file defines the sector addresses of the images to be loaded on the screen
// The sector addresses can be found via the 4D Systems Workshop 4D IDE
// The Graphics Composer of this software should be used:
//  - To load the desired images on the uSD card
//  - To find the sector addresses of said images (via generated .Gc file)

// Big Step Selected
// #define BStepS_Hi           0x0000
// #define BStepS_Lo           0x0000

// // Cups Scroll
// #define Cups_Hi             0x0000
// #define Cups_Lo             0x0051

// // Sit Scroll
// #define Sit_Hi              0x0000
// #define Sit_Lo              0x00A2

// // Slope Once Activated
// #define Slope1x_Hi          0x0000
// #define Slope1x_Lo          0x00F3

// // Slope Up Scroll
// #define SlopeUp_Hi          0x0000
// #define SlopeUp_Lo          0x0144

// // Sofa Scroll
// #define Sofa_Hi             0x0000
// #define Sofa_Lo             0x0195

// // Small Step Selected
// #define SStepS_Hi           0x0000
// #define SStepS_Lo           0x01E6

// // Stairs Up Scroll
// #define StairUp_Hi          0x0000
// #define StairUp_Lo          0x0237

// // Walk
// #define Walk_Hi             0x0000
// #define Walk_Lo             0x0288

// // Walk Activated
// #define WalkA_Hi            0x0000
// #define WalkA_Lo            0x02D9

// // Walk Selected
// #define WalkS_Hi            0x0000
// #define WalkS_Lo            0x032A

// 1HomeSit
#define HomeSit1_Hi             0x0000
#define HomeSit1_Lo             0x0000

// 1StandUp
#define StandUp1_Hi              0x0000
#define StandUp1_Lo              0x0654

// 1StandUpSelected
#define StandUpSelected1_Hi     0x0000
#define StandUpSelected1_Lo     0x06F6

// 1StandUpActivated
#define StandUpActivated1_Hi    0x0000
#define StandUpActivated1_Lo    0x06A5   

// 1TurnOffStart
#define TurnOffStart1_Hi        0x0000
#define TurnOffStart1_Lo        0x083A

// 1HomeStandStart
#define HomeStandStart1_Hi      0x0000
#define HomeStandStart1_Lo      0x00A2

//  1Sit
#define Sit1_Hi                 0x0000
#define Sit1_Lo                 0x0195

//  1SitSelected
#define SitSelected1_Hi         0x0000
#define SitSelected1_Lo         0x0237

//  1SitActivated
#define SitActivated1_Hi        0x0000
#define SitActivated1_Lo        0x01E6

//  1HomeStand
#define HomeStand1_Hi           0x0000
#define HomeStand1_Lo           0x0051

//  1TurnOff
#define TurnOff1_Hi             0x0000
#define TurnOff1_Lo             0x07E9

//  1Stairs
#define Stairs1_Hi              0x0000
#define Stairs1_Lo              0x0D9B

//  1StairsUp
#define StairsUp1_Hi            0x0000
#define StairsUp1_Lo            0x0EDF

//  1StairsUpSelected
#define StairsUpSelected1_Hi    0x0000
#define StairsUpSelected1_Lo    0x0F81

//  1StairsUpActivated
#define StairsUpActivated1_Hi   0x0000
#define StairsUpActivated1_Lo   0x0F30

//  1StairWalk
#define StairsWalk1_Hi          0x0000
#define StairsWalk1_Lo          0x0FD2

//  1StairWalkSelected,
#define StairsWalkSelected1_Hi  0x0000
#define StairsWalkSelected1_Lo  0x1074

//  1StairWalkActivated,
#define StairsWalkActivated1_Hi 0x0000
#define StarisWalkActivated1_Lo 0x1023

//  1StairsDown,
#define StairsDown1_Hi          0x0000
#define StairsDown1_Lo          0x0DEC

//  1StairsDownSelected,
#define StairsDownSelected1_Hi  0x0000
#define StairsDownSelected1_Lo  0x0E8E

//  1StairsDownActivated  
#define StairsDownACtivated1_Hi 0x0000
#define StairsDownActivated1_Lo 0x0E3D

//  1Walk
#define Walk1_Hi                0x0000
#define Walk1_Lo                0x12FC

//  1WalkSmall
#define WalkSmall1_Hi           0x0000
#define WalkSmall1_Lo           0x1491

//  1WalkNormal
#define WalkNormal1_Hi          0x0000
#define WalkNormal1_Lo          0x129E

//  1WalkLarge
#define WalkLarge1_Hi           0x0000
#define WalkLarge1_Lo           0x124D

//  1WalkNormalSelected
#define WalkNormalSelected1_Hi  0x0000
#define WalkNormalSelected1_Lo  0x1440

//  1WalkNormalActivated
#define WalkNormalActivated1_Hi 0x0000
#define WalkNormalActivated1_Lo 0x13EF

#endif //SD_ADDRESSES_H
#ifndef SD_ADDRESSES_H
#define SD_ADDRESSES3_H

//Version 3!!!

// This file defines the sector addresses of the images to be loaded on the screen
// The sector addresses can be found via the 4D Systems Workshop 4D IDE
// The Graphics Composer of this software should be used:
//  - To load the desired images on the uSD card
//  - To find the sector addresses of said images (via generated .Gc file)


// 3HomeSit
#define HomeSit_Hi              0x0000
#define HomeSit_Lo             0x0A71

// 3StandUp
#define StandUp_Hi              0x0000
#define StandUp_Lo              0x10C5

// 3StandUpSelected
#define StandUpSelected_Hi     0x0000
#define StandUpSelected_Lo     0x1167

// 3StandUpActivated
#define StandUpActivated_Hi    0x0000
#define StandUpActivated_Lo    0x1116

// 3TurnOffStart
#define TurnOffStart_Hi        0x0000
#define TurnOffStart_Lo        0x12AB

// 3HomeStandStart
#define HomeStandStart_Hi      0x0000
#define HomeStandStart_Lo      0x0B13

//  3Sit
#define Sit_Hi                 0x0000
#define Sit_Lo                 0x0C06

//  3SitSelected
#define SitSelected_Hi         0x0000
#define SitSelected_Lo         0x0CA8

//  3SitActivated
#define SitActivated_Hi        0x0000
#define SitActivated_Lo        0x0C57

//  3HomeStand
#define HomeStand_Hi           0x0000
#define HomeStand_Lo           0x0AC2

//  3TurnOff
#define TurnOff_Hi             0x0000
#define TurnOff_Lo             0x125A

//  3Stairs
#define Stairs_Hi              0x0000
#define Stairs_Lo              0x0D9B

//  3StairsUp
#define StairsUp_Hi            0x0000
#define StairsUp_Lo            0x0EDF

//  3StairsUpSelected
#define StairsUpSelected_Hi    0x0000
#define StairsUpSelected_Lo    0x0F81

//  3StairsUpActivated
#define StairsUpActivated_Hi   0x0000
#define StairsUpActivated_Lo   0x0F30

//  3StairWalk
#define WalkObstacle_Hi          0x0000
#define WalkObstacle_Lo          0x0FD2

//  3StairWalkSelected,
#define WalkObstacleSelected_Hi  0x0000
#define WalkObstacleSelected_Lo  0x1074

//  3StairWalkActivated,
#define WalkObstacleActivated_Hi 0x0000
#define WalkObstacleActivated_Lo 0x1023

//  3StairsDown,
#define StairsDown_Hi          0x0000
#define StairsDown_Lo          0x0DEC

//  3StairsDownSelected,
#define StairsDownSelected_Hi  0x0000
#define StairsDownSelected_Lo  0x0E8E

//  3StairsDownActivated
#define StairsDownACtivated_Hi 0x0000
#define StairsDownActivated_Lo 0x0E3D

//  3Walk
#define Walk_Hi                0x0000
#define Walk_Lo                0x12FC

//  3WalkSmall
#define WalkSmall_Hi           0x0000
#define WalkSmall_Lo           0x1491

//  3WalkNormal
#define WalkNormal_Hi          0x0000
#define WalkNormal_Lo          0x129E

//  3WalkLarge
#define WalkLarge_Hi           0x0000
#define WalkLarge_Lo           0x124D

//  3WalkNormalSelected
#define WalkNormalSelected_Hi  0x0000
#define WalkNormalSelected_Lo  0x1440

//  3WalkNormalActivated
#define WalkNormalActivated_Hi 0x0000
#define WalkNormalActivated_Lo 0x13EF

// SideStep 
#define SideStep_Hi         0x0000
#define SideStep_Lo         0x11B8          

// Slope
#define Slope_Hi    0x0000   
#define Slope_Lo    0x0CF9

// TiltedPath 
#define TiltedPath_Hi           0x0000
#define TiltedPath_Lo           0x1209

// RoughTerrain 
#define RoughTerrain_Hi         0x0000
#define RoughTerrain_Lo         0x0B64

// Sofa
#define Sofa_Hi        0x0000
#define Sofa_Lo        0x0D4A

// SingleStep 
#define SingleStep_Hi               0x0000
#define SingleStep_Lo               0x0BB5

// HomeSitSelected unknown
#define HomeSitSelected_Hi      0x0000
#define HomeSitSelected_Lo      0x14E2

// HomeSitActivated unknown
#define HomeSitActivated_Hi     0x0000
#define HomeSitActivated_Lo     0x14E2

// TurnOffStartSelected unknown
#define TurnOffStartSelected_Hi     0x0000    
#define TurnOffStartSelected_Lo     0x14E2

// TurnOffStartActivated unknown
#define TurnOffStartActivated_Hi        0x0000
#define TurnOffStartActivated_Lo        0x14E2

// HomeStandStartSelected unknown
#define HomeStandStartSelected_Hi       0x0000
#define HomeStandStartSelected_Lo       0x14E2

// HomeStandStartActivated unknown
#define HomeStandStartActivated_Hi      0x0000
#define HomeStandStartActivated_Lo      0x14E2

// HomeStandSelected unknown
#define HomeStandSelected_Hi        0x0000
#define HomeStandSelected_Lo        0x14E2
                    
// HomeStandActivated unknown
#define HomeStandActivated_Hi       0x0000
#define HomeStandActivated_Lo       0x14E2

// TurnOffSelected unknown
#define TurnOffSelected_Hi      0x0000
#define TurnOffSelected_Lo      0x14E2

// TurnOffActivated unknown
#define TurnOffActivated_Hi     0x0000
#define TurnOffActivated_Lo     0x14E2

// WalkSmallSelected unknown
#define WalkSmallSelected_Hi    0x0000
#define WalkSmallSelected_Lo    0x14E2

// WalkLargeSelected unknown
#define WalkLargeSelected_Hi        0x0000
#define WalkLargeSelected_Lo        0x14E2

// WalkSmallActivated unknown
#define WalkSmallActivated_Hi       0x0000
#define WalkSmallActivated_Lo       0x14E2

// WalkLargeActivated unknown
#define WalkLargeActivated_Hi       0x0000    
#define WalkLargeActivated_Lo       0x14E2

// SingleStepSmall unknown
#define SingleStepSmall_Hi      0x0000
#define SingleStepSmall_Lo      0x14E2

// SingleStepNormal unknown
#define SingleStepNormal_Hi     0x0000
#define SingleStepNormal_Lo     0x14E2

// SingleStepLarge unknown
#define SingleStepLarge_Hi      0x0000
#define SingleStepLarge_Lo      0x14E2

// SingleStepSmallSelected unknown
#define SingleStepSmallSelected_Hi      0x0000
#define SingleStepSmallSelected_Lo      0x14E2

// SingleStepNormalSelected unknown
#define SingleStepNormalSelected_Hi     0x0000
#define SingleStepNormalSelected_Lo     0x14E2

// SingleStepLargeSelected unknown
#define SingleStepLargeSelected_Hi      0x0000
#define SingleStepLargeSelected_Lo      0x14E2

// SingleStepSmallActivated unknown
#define SingleStepSmallActivated_Hi     0x0000
#define SingleStepSmallActivated_Lo     0x14E2

// SingleStepNormalActivated unknown
#define SingleStepNormalActivated_Hi        0x0000
#define SingleStepNormalActivated_Lo        0x14E2

// SingleStepLargeActivated unknown
#define SingleStepLargeActivated_Hi     0x0000
#define SingleStepLargeActivated_Lo     0x14E2

// SideStepLeft unknown
#define SideStepLeft_Hi     0x0000
#define SideStepLeft_Lo     0x14E2

// SideStepRight unknown
#define SideStepRight_Hi        0x0000
#define SideStepRight_Lo        0x14E2

// SideStepLeftSelected unknown
#define SideStepLeftSelected_Hi     0x0000
#define SideStepLeftSelected_Lo     0x14E2

// SideStepRightSelected unknown
#define SideStepRightSelected_Hi        0x0000
#define SideStepRightSelected_Lo        0x14E2

// SideStepLeftActivated unknown
#define SideStepLeftActivated_Hi        0x0000
#define SideStepLeftActivated_Lo        0x14E2

// SideStepRightActivated unknown
#define SideStepRightActivated_Hi       0x0000
#define SideStepRightActivated_Lo       0x14E2

// SofaSit unknown
#define SofaSit_Hi      0x0000
#define SofaSit_Lo      0x14E2

// SofaSitSelected unknown
#define SofaSitSelected_Hi      0x0000
#define SofaSitSelected_Lo      0x14E2

// SofaSitActivated unknown
#define SofaSitActivated_Hi     0x0000
#define SofaSitActivated_Lo     0x14E2

// SofaStandUp uknonwn
#define SofaStandUp_Hi      0x0000
#define SofaStandUp_Lo      0x14E2

// SofaStandUpSelected uknonwn
#define SofaStandUpSelected_Hi      0x0000
#define SofaStandUpSelected_Lo      0x14E2

// SofaStandUpActivated unknown
#define SofaStandUpActivated_Hi     0x0000
#define SofaStandUpActivated_Lo     0x14E2

// SlopeUp unknown
#define SlopeUp_Hi      0x0000
#define SlopeUp_Lo      0x14E2

// SlopeUpSelected unknown
#define SlopeUpSelected_Hi      0x0000
#define SlopeUpSelected_Lo      0x14E2

// SlopeUpActivated unknown
#define SlopeUpActivated_Hi     0x0000
#define SlopeUpActivated_Lo     0x14E2

// SlopeDown unknown
#define SlopeDown_Hi        0x0000
#define SlopeDown_Lo        0x14E2

// SlopeDownSelected unknown
#define SlopeDownSelected_Hi        0x0000
#define SlopeDownSelected_Lo        0x14E2

// SlopeDownActivated unknown
#define SlopeDownActivated_Hi       0x0000
#define SlopeDownActivated_Lo       0x14E2



// RoughTerrainSelected unknown
#define RoughTerrainSelected_Hi     0x0000
#define RoughTerrainSelected_Lo     0x14E2

// RoughTerrainActivated unknown
#define RoughTerrainActivated_Hi        0x0000
#define RoughTerrainActivated_Lo        0x14E2

// TiltedPathSelected unknown
#define TiltedPathSelected_Hi       0x0000
#define TiltedPathSelected_Lo       0x14E2

// TiltedPathActivated unknown
#define TiltedPathActivated_Hi      0x0000
#define TiltedPathActivated_Lo      0x14E2

#endif //SD_ADDRESSES_H
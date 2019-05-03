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

// HomeSit
#define HomeSit_Hi             0x0000
#define HomeSit_Lo             0x0000

// StandUp
#define StandUp_Hi              0x0000
#define StandUp_Lo              0x0654

// StandUpSelected
#define StandUpSelected_Hi     0x0000
#define StandUpSelected_Lo     0x06F6

// StandUpActivated
#define StandUpActivated_Hi    0x0000
#define StandUpActivated_Lo    0x06A5   

// TurnOffStart
#define TurnOffStart_Hi        0x0000
#define TurnOffStart_Lo        0x083A

// HomeStandStart
#define HomeStandStart_Hi      0x0000
#define HomeStandStart_Lo      0x00A2

//  Sit
#define Sit_Hi                 0x0000
#define Sit_Lo                 0x0195

//  SitSelected
#define SitSelected_Hi         0x0000
#define SitSelected_Lo         0x0237

//  SitActivated
#define SitActivated_Hi        0x0000
#define SitActivated_Lo        0x01E6

//  HomeStand
#define HomeStand_Hi           0x0000
#define HomeStand_Lo           0x0051

//  TurnOff
#define TurnOff_Hi             0x0000
#define TurnOff_Lo             0x07E9

//  Stairs
#define Stairs_Hi              0x0000
#define Stairs_Lo              0x032A

//  StairsUp
#define StairsUp_Hi            0x0000
#define StairsUp_Lo            0x046E

//  StairsUpSelected
#define StairsUpSelected_Hi    0x0000
#define StairsUpSelected_Lo    0x0510

//  StairsUpActivated
#define StairsUpActivated_Hi   0x0000
#define StairsUpActivated_Lo   0x04BF

//  StairWalk
#define StairsWalk_Hi          0x0000
#define StairsWalk_Lo          0x0561

//  StairWalkSelected,
#define StairsWalkSelected_Hi  0x0000
#define StairsWalkSelected_Lo  0x0603

//  StairWalkActivated,
#define StairsWalkActivated_Hi 0x0000
#define StarisWalkActivated_Lo 0x05B2

//  StairsDown,
#define StairsDown_Hi          0x0000
#define StairsDown_Lo          0x037B

//  StairsDownSelected,
#define StairsDownSelected_Hi  0x0000
#define StairsDownSelected_Lo  0x041D

//  StairsDownActivated  
#define StairsDownACtivated_Hi 0x0000
#define StairsDownActivated_Lo 0x03CC

//  Walk
#define Walk_Hi                0x0000
#define Walk_Lo                0x088B

//  WalkSmall
#define WalkSmall_Hi           0x0000
#define WalkSmall_Lo           0x0A20

//  WalkNormal
#define WalkNormal_Hi          0x0000
#define WalkNormal_Lo          0x092D

//  WalkLarge
#define WalkLarge_Hi           0x0000
#define WalkLarge_Lo           0x08DC

//  WalkNormalSelected
#define WalkNormalSelected_Hi  0x0000
#define WalkNormalSelected_Lo  0x09CF

//  WalkNormalActivated
#define WalkNormalActivated_Hi 0x0000
#define WalkNormalActivated_Lo 0x097E

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
#define HomeStandStartActivated_lo      0x14E2

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

// SingleStep 
#define SingleStep_Hi               0x0000
#define SingleStep_Lo               0x0144

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

// SideStep 
#define SideStep_Hi         0x0000
#define SideStep_Lo         0x0747      

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

// Sofa
#define Sofa_Hi        0x0000
#define Sofa_Lo        0x02D9

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

// Slope
#define Slope_Hi    0x0000   
#define Slope_Lo    0x0288

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

// RoughTerrain 
#define RoughTerrain_Hi         0x0000
#define RoughTerrain_Lo         0x00F3

// RoughTerrainSelected unknown
#define RoughTerrainSelected_Hi     0x0000
#define RoughTerrainSelected_Lo     0x14E2

// RoughTerrainActivated unknown
#define RoughTerrainActivated_Hi        0x0000
#define RoughTerrainActivated_LO        0x14E2

// TiltedPath 
#define TiltedPath_Hi           0x0000
#define TiltedPath_Lo           0x0798

// TiltedPathSelected unknown
#define TiltedPathSelected_Hi       0x0000
#define TiltedPathSelected_Lo       0x14E2

// TiltedPathActivated unknown
#define TiltedPathActivated_Hi      0x0000
#define TiltedPathActivated_Lo      0x14E2

// WalkObstacle unknown
#define WalkObstacle_Hi     0x0000
#define WalkObstacle_Lo     0x14E2

// WalkObstacleSelected unknown
#define WalkObstacleSelected_Hi     0x0000
#define WalkObstacleSelected_Lo     0x14E2

// WalkObstacleActivated unknown
#define WalkObstacleActivated_Hi       0x0000
#define WalkObstacleActivated_Lo       0x14E2 

#endif //SD_ADDRESSES_H
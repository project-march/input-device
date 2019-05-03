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
#define HomeSitSelected_Hi
#define HomeSitSelected_Lo

// HomeSitActivated unknown
#define HomeSitActivated_Hi
#define HomeSitActivated_Lo

// TurnOffStartSelected unknown
#define TurnOffStartSelected_Hi
#define TurnOffStartSelected_Lo

// TurnOffStartActivated unknown
#define TurnOffStartActivated_Hi
#define TurnOffStartActivated_Lo

// HomeStandStartSelected unknown
#define HomeStandStartSelected_Hi
#define HomeStandStartSelected_Lo

// HomeStandStartActivated unknown
#define HomeStandStartActivated_Hi
#define HomeStandStartActivated_lO

// HomeStandSelected unknown
#define HomeStandSelected_Hi
#define HomeStandSelected_Lo
                    
// HomeStandActivated unknown
#define HomeStandActivated_Hi
#define HomeStandActivated_Lo

// TurnOffSelected unknown
#define TurnOffSelected_Hi
#define TurnOffSelected_Lo

// TurnOffActivated unknown
#define TurnOffActivated_Hi
#define TurnOffActivated_Lo

// WalkSmallSelected unknown
#define WalkSmallSelected_Hi
#define WalkSmallSelected_Lo

// WalkLargeSelected unknown
#define WalkLargeSelected_Hi
#define WalkLargeSelected_Lo

// WalkSmallActivated unknown
#define WalkSmallActivated_Hi
#define WalkSmallActivated_Lo

// WalkLargeActivated unknown
#define WalkLargeActivated_Hi
#define WalkLargeActivated_Lo

// SingleStep 
#define SingleStep_Hi               0x0000
#define SingleStep_Lo               0x0144

// SingleStepSmall unknown
#define SingleStepSmall_Hi
#define SingleStepSmall_Lo

// SingleStepNormal unknown
#define SingleStepNormal_Hi
#define SingleStepNormal_Lo

// SingleStepLarge unknown
#define SingleStepLarge_Hi
#define SingleStepLarge_Lo

// SingleStepSmallSelected unknown
#define SingleStepSmallSelected_Hi
#define SingleStepSmallSelected_Lo

// SingleStepNormalSelected unknown
#define SingleStepNormalSelected_Hi
#define SingleStepNormalSelected_Lo

// SingleStepLargeSelected unknown
#define SingleStepLargeSelected_Hi
#define SingleStepLargeSelected_Lo

// SingleStepSmallActivated unknown
#define SingleStepSmallActivated_Hi
#define SingleStepSmallActivated_Lo

// SingleStepNormalActivated unknown
#define SingleStepNormalActivated_Hi
#define SingleStepNormalActivated_L0

// SingleStepLargeActivated unknown
#define SingleStepLargeActivated_Hi
#define SingleStepLargeActivated_Lo

// SideStep unknown
#define SideStep_Hi
#define SideStep_Lo

// SideStepLeft unknown
#define SideStepLeft_Hi
#define SideStepLeft_Lo

// SideStepRight unknown
#define SideStepRight_Hi
#define SideStepRight_Lo

// SideStepLeftSelected unknown
#define SideStepLeftSelected_Hi
#define SideStepLeftSelected_Lo

// SideStepRightSelected unknown
#define SideStepRightSelected_Hi
#define SideStepRightSelected_Lo

// SideStepLeftActivated unknown
#define SideStepLeftActivated_Hi
#define SideStepLeftActivated_Lo

// SideStepRightActivated unknown
#define SideStepRightActivated_Hi
#define SideStepRightActivated_Lo

// Sofa
#define Sofa_Hi        0x0000
#define Sofa_Lo        0x02D9

// SofaSit unknown
#define SofaSit_Hi
#define SofaSit_Lo

// SofaSitSelected unknown
#define SofaSitSelected_Hi
#define SofaSitSelected_Lo

// SofaSitActivated unknown
#define SofaSitActivated_Hi
#define SofaSitActivated_Lo

// SofaStandUp uknonwn
#define SofaStandUp_Hi
#define SofaStandUp_Lo

// SofaStandUpSelected uknonwn
#define SofaStandUpSelected_Hi
#define SofaStandUpSelected_Lo

// SofaStandUpActivated unknown
#define SofaStandUpActivated_Hi
#define SofaStandUpActivated_Lo

// Slope
#define Slope_Hi    0x0000   
#define Slope_Lo    0x0288

// SlopeUp unknown
#define SlopeUp_Hi
#define SlopeUp_Lo

// SlopeUpSelected unknown
#define SlopeUpSelected_Hi
#define SlopeUpSelected_Lo

// SlopeUpActivated unknown
#define SlopeUpActivated_Hi
#define SlopeUpActivated_Lo

// SlopeDown unknown
#define SlopeDown_Hi
#define SlopeDown_Lo

// SlopeDownSelected unknown
#define SlopeDownSelected_Hi
#define SlopeDownSelected_Lo

// SlopeDownActivated unknown
#define SlopeDownActivated_Hi
#define SlopeDownActivated_Lo

// RoughTerrain 
#define RoughTerrain_Hi         0x0000
#define RoughTerrain_Lo         0x00F3

// RoughTerrainSelected unknown
#define RoughTerrainSelected_Hi
#define RoughTerrainSelected_Lo

// RoughTerrainActivated unknown
#define RoughTerrainActivated_Hi
#define RoughTerrainActivated_LO

// TiltedPath 
#define TiltedPath_Hi           0x0000
#define TiltedPath_Lo           0x0798

// TiltedPathSelected unknown
#define TiltedPathSelected_Hi
#define TiltedPathSelected_Lo

// TiltedPathActivated unknown
#define TiltedPathActivated_Hi
#define TiltedPathActivated_Lo



#endif //SD_ADDRESSES_H
#ifndef SD_ADDRESSES_H
#define SD_ADDRESSES_H

// This file defines the sector addresses of the images to be loaded on the screen
// The sector addresses can be found via the 4D Systems Workshop 4D IDE
// The Graphics Composer of this software should be used:
//  - To load the desired images on the uSD card
//  - To find the sector addresses of said images (via generated .Gc file)

// HomeSit
#define HomeSit_Hi             0x0000
#define HomeSit_Lo             0x0000

// HomeSitSelected
#define HomeSitSelected_Hi      0x0000
#define HomeSitSelected_Lo      0x00A2

// HomeSitActivated
#define HomeSitActivated_Hi     0x0000
#define HomeSitActivated_Lo     0x0051


// StandUp
#define StandUp_Hi              0x0000
#define StandUp_Lo              0x1B36

// StandUpSelected
#define StandUpSelected_Hi     0x0000
#define StandUpSelected_Lo     0x1BD8

// StandUpActivated
#define StandUpActivated_Hi    0x0000
#define StandUpActivated_Lo    0x1B87   


// TurnOffStart
#define TurnOffStart_Hi        0x0000
#define TurnOffStart_Lo        0x14E2

// TurnOffStartSelected
#define TurnOffStartSelected_Hi     0x0000    
#define TurnOffStartSelected_Lo     0x1584

// TurnOffStartActivated
#define TurnOffStartActivated_Hi        0x0000
#define TurnOffStartActivated_Lo        0x1533



// HomeStandStart
#define HomeStandStart_Hi      0x0000
#define HomeStandStart_Lo      0x01E6

// HomeStandStartSelected unknown
#define HomeStandStartSelected_Hi       0x0000
#define HomeStandStartSelected_Lo       0x0288

// HomeStandStartActivated unknown
#define HomeStandStartActivated_Hi      0x0000
#define HomeStandStartActivated_Lo      0x0237


//  Sit
#define Sit_Hi                 0x0000
#define Sit_Lo                 0x0A71

//  SitSelected
#define SitSelected_Hi         0x0000
#define SitSelected_Lo         0x0B13

//  SitActivated
#define SitActivated_Hi        0x0000
#define SitActivated_Lo        0x0AC2


//  HomeStand
#define HomeStand_Hi           0x0000
#define HomeStand_Lo           0x00F3

// HomeStandSelected unknown
#define HomeStandSelected_Hi        0x0000
#define HomeStandSelected_Lo        0x0195
                    
// HomeStandActivated unknown
#define HomeStandActivated_Hi       0x0000
#define HomeStandActivated_Lo       0x0144



//  TurnOff
#define TurnOff_Hi             0x0000
#define TurnOff_Lo             0x13EF

// TurnOffSelected
#define TurnOffSelected_Hi      0x0000
#define TurnOffSelected_Lo      0x1491 

// TurnOffActivated
#define TurnOffActivated_Hi     0x0000
#define TurnOffActivated_Lo     0x1440


// Sofa
#define Sofa_Hi        0x0000
#define Sofa_Lo        0x0D9B

// SofaSit
#define SofaSit_Hi      0x0000
#define SofaSit_Lo      0x0DEC

// SofaSitSelected
#define SofaSitSelected_Hi      0x0000
#define SofaSitSelected_Lo      0x0E8E

// SofaSitActivated
#define SofaSitActivated_Hi     0x0000
#define SofaSitActivated_Lo     0x0E3D

// SofaStandUp
#define SofaStandUp_Hi      0x0000
#define SofaStandUp_Lo      0x1A43

// SofaStandUpSelected
#define SofaStandUpSelected_Hi      0x0000
#define SofaStandUpSelected_Lo      0x1AE5

// SofaStandUpActivated
#define SofaStandUpActivated_Hi     0x0000
#define SofaStandUpActivated_Lo     0x1A94


// Slope
#define Slope_Hi    0x0000   
#define Slope_Lo    0x0B64

// SlopeUp
#define SlopeUp_Hi      0x0000
#define SlopeUp_Lo      0x1D6D

// SlopeUpSelected
#define SlopeUpSelected_Hi      0x0000
#define SlopeUpSelected_Lo      0x0D4A

// SlopeUpActivated
#define SlopeUpActivated_Hi     0x0000
#define SlopeUpActivated_Lo     0x0CF9

// SlopeDown
#define SlopeDown_Hi        0x0000
#define SlopeDown_Lo        0x1C29

// SlopeDownSelected
#define SlopeDownSelected_Hi        0x0000
#define SlopeDownSelected_Lo        0x0C57

// SlopeDownActivated
#define SlopeDownActivated_Hi       0x0000
#define SlopeDownActivated_Lo       0x0C06

// SlopeDownFinal
#define SlopeDownFinal_Hi        0x0000
#define SlopeDownFinal_Lo        0x1C7A

// SlopeDownFinalSelected
#define SlopeDownFinalSelected_Hi        0x0000
#define SlopeDownFinalSelected_Lo        0x1D1C

// SlopeDownFinalActivated
#define SlopeDownFinalActivated_Hi       0x0000
#define SlopeDownFinalActivated_Lo       0x1CCB


// RoughTerrain 
#define RoughTerrain_Hi         0x0000
#define RoughTerrain_Lo         0x02D9

// RoughTerrainSelected unknown
#define RoughTerrainSelected_Hi     0x0000
#define RoughTerrainSelected_Lo     0x037B

// RoughTerrainActivated unknown
#define RoughTerrainActivated_Hi        0x0000
#define RoughTerrainActivated_Lo        0x032A


// TiltedPath 
#define TiltedPath_Hi           0x0000
#define TiltedPath_Lo           0x12FC

// TiltedPathSelected unknown
#define TiltedPathSelected_Hi       0x0000
#define TiltedPathSelected_Lo       0x139E

// TiltedPathActivated unknown
#define TiltedPathActivated_Hi      0x0000
#define TiltedPathActivated_Lo      0x134D


//  Stairs
#define Stairs_Hi              0x0000
#define Stairs_Lo              0x0FD2

//  StairsUp
#define StairsUp_Hi            0x0000
#define StairsUp_Lo            0x1F02

//  StairsUpSelected
#define StairsUpSelected_Hi    0x0000
#define StairsUpSelected_Lo    0x11B8

//  StairsUpActivated
#define StairsUpActivated_Hi   0x0000
#define StairsUpActivated_Lo   0x1167

//  StairsDown
#define StairsDown_Hi          0x0000
#define StairsDown_Lo          0x1DBE

//  StairsDownSelected,
#define StairsDownSelected_Hi  0x0000
#define StairsDownSelected_Lo  0x10C5

//  StairsDownActivated  
#define StairsDownActivated_Hi 0x0000
#define StairsDownActivated_Lo 0x1074

//  StairsDownFinal
#define StairsDownFinal_Hi          0x0000
#define StairsDownFinal_Lo          0x1E0F

//  StairsDownFinalSelected,
#define StairsDownFinalSelected_Hi  0x0000
#define StairsDownFinalSelected_Lo  0x1EB1

//  StairsDownFinalActivated  
#define StairsDownFinalActivated_Hi 0x0000
#define StairsDownFinalActivated_Lo 0x1E60



//  WalkObstacle
#define WalkObstacle_Hi          0x0000
#define WalkObstacle_Lo          0x180C

//  WalkObstacleSmall
#define WalkObstacleSmall_Hi          0x0000
#define WalkObstacleSmall_Lo          0x18FF

//  WalkObstacleNormal
#define WalkObstacleNormal_Hi          0x0000
#define WalkObstacleNormal_Lo          0x18AE

//  WalkObstacleLarge
#define WalkObstacleLarge_Hi          0x0000
#define WalkObstacleLarge_Lo          0x185D

//  WalkObstacleSmallSelected
#define WalkObstacleSmallSelected_Hi  0x0000
#define WalkObstacleSmallSelected_Lo  0x19F2

//  WalkObstacleNormalSelected
#define WalkObstacleNormalSelected_Hi  0x0000
#define WalkObstacleNormalSelected_Lo  0x17BB

//  WalkObstacleLargeSelected
#define WalkObstacleLargeSelected_Hi  0x0000
#define WalkObstacleLargeSelected_Lo  0x16C8

//  WalkObstacleSmallActivated
#define WalkObstacleSmallActivated_Hi 0x0000
#define WalkObstacleSmallActivated_Lo 0x19A1

//  WalkObstacleNormalActivated
#define WalkObstacleNormalActivated_Hi 0x0000
#define WalkObstacleNormalActivated_Lo 0x176A

//  WalkObstacleLargeActivated
#define WalkObstacleLargeActivated_Hi 0x0000
#define WalkObstacleLargeActivated_Lo 0x1677

//  SingleStepObstacle
#define SingleStepObstacle_Hi          0x0000
#define SingleStepObstacle_Lo          0x083A

//  SingleStepObstacleSmall
#define SingleStepObstacleSmall_Hi     0x0000
#define SingleStepObstacleSmall_Lo     0x092D

//  SingleStepObstacleNormal
#define SingleStepObstacleNormal_Hi    0x0000
#define SingleStepObstacleNormal_Lo    0x08DC

//  SingleStepObstacleLarge
#define SingleStepObstacleLarge_Hi     0x0000
#define SingleStepObstacleLarge_Lo     0x088B

//  SingleStepObstacleLargeSelected
#define SingleStepObstacleLargeSelected_Hi  0x0000
#define SingleStepObstacleLargeSelected_Lo  0x06F6

//  SingleStepObstacleSmallSelected
#define SingleStepObstacleSmallSelected_Hi  0x0000
#define SingleStepObstacleSmallSelected_Lo  0x0A20

//  SingleStepObstacleNormalSelected
#define SingleStepObstacleNormalSelected_Hi  0x0000
#define SingleStepObstacleNormalSelected_Lo  0x07E9

//  SingleStepObstacleSmallActivated
#define SingleStepObstacleSmallActivated_Hi 0x0000
#define SingleStepObstacleSmallActivated_Lo 0x09CF

//  SingleStepObstacleNormalActivated
#define SingleStepObstacleNormalActivated_Hi 0x0000
#define SingleStepObstacleNormalActivated_Lo 0x0798

//  SingleStepObstacleLargeActivated
#define SingleStepObstacleLargeActivated_Hi 0x0000
#define SingleStepObstacleLargeActivated_Lo 0x06A5



//  Walk
#define Walk_Hi                0x0000
#define Walk_Lo                0x15D5

//  WalkSmall
#define WalkSmall_Hi           0x0000
#define WalkSmall_Lo           0x1950

//  WalkNormal
#define WalkNormal_Hi          0x0000
#define WalkNormal_Lo          0x1719

//  WalkLarge
#define WalkLarge_Hi           0x0000
#define WalkLarge_Lo           0x1626

//  WalkNormalSelected
#define WalkNormalSelected_Hi  0x0000
#define WalkNormalSelected_Lo  0x17BB

//  WalkNormalActivated
#define WalkNormalActivated_Hi 0x0000
#define WalkNormalActivated_Lo 0x176A


// WalkSmallSelected
#define WalkSmallSelected_Hi    0x0000
#define WalkSmallSelected_Lo    0x19F2

// WalkLargeSelected
#define WalkLargeSelected_Hi        0x0000
#define WalkLargeSelected_Lo        0x16C8

// WalkSmallActivated
#define WalkSmallActivated_Hi       0x0000
#define WalkSmallActivated_Lo       0x19A1

// WalkLargeActivated
#define WalkLargeActivated_Hi       0x0000    
#define WalkLargeActivated_Lo       0x1677

// SingleStep 
#define SingleStep_Hi               0x0000
#define SingleStep_Lo               0x0603

// SingleStepSmall
#define SingleStepSmall_Hi      0x0000
#define SingleStepSmall_Lo      0x097E

// SingleStepNormal
#define SingleStepNormal_Hi     0x0000
#define SingleStepNormal_Lo     0x0747

// SingleStepLarge
#define SingleStepLarge_Hi      0x0000
#define SingleStepLarge_Lo      0x0654

// SingleStepSmallSelected
#define SingleStepSmallSelected_Hi      0x0000
#define SingleStepSmallSelected_Lo      0x0A20

// SingleStepNormalSelected
#define SingleStepNormalSelected_Hi     0x0000
#define SingleStepNormalSelected_Lo     0x07E9

// SingleStepLargeSelected
#define SingleStepLargeSelected_Hi      0x0000
#define SingleStepLargeSelected_Lo      0x06F6

// SingleStepSmallActivated
#define SingleStepSmallActivated_Hi     0x0000
#define SingleStepSmallActivated_Lo     0x09CF

// SingleStepNormalActivated
#define SingleStepNormalActivated_Hi        0x0000
#define SingleStepNormalActivated_Lo        0x0798

// SingleStepLargeActivated
#define SingleStepLargeActivated_Hi     0x0000
#define SingleStepLargeActivated_Lo     0x06A5

// SideStep 
#define SideStep_Hi         0x0000
#define SideStep_Lo         0x03CC      

// SideStepLeft
#define SideStepLeft_Hi     0x0000
#define SideStepLeft_Lo     0x041D

// SideStepRight
#define SideStepRight_Hi        0x0000
#define SideStepRight_Lo        0x0510

// SideStepLeftSelected
#define SideStepLeftSelected_Hi     0x0000
#define SideStepLeftSelected_Lo     0x04BF

// SideStepRightSelected
#define SideStepRightSelected_Hi        0x0000
#define SideStepRightSelected_Lo        0x05B2

// SideStepLeftActivated
#define SideStepLeftActivated_Hi        0x0000
#define SideStepLeftActivated_Lo        0x046E

// SideStepRightActivated
#define SideStepRightActivated_Hi       0x0000
#define SideStepRightActivated_Lo       0x0561

#endif //SD_ADDRESSES_H
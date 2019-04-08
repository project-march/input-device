#ifndef SD_ADDRESSES_H
#define SD_ADDRESSES_H

// This file defines the sector addresses of the images to be loaded on the screen
// The sector addresses can be found via the 4D Systems Workshop 4D IDE
// The Graphics Composer of this software should be used:
//  - To load the desired images on the uSD card
//  - To find the sector addresses of said images (via generated .Gc file)

// Big Step Selected
#define BStepS_Hi           0x0000
#define BStepS_Lo           0x0000

// Cups Scroll
#define Cups_Hi             0x0000
#define Cups_Lo             0x0051

// Sit Scroll
#define Sit_Hi              0x0000
#define Sit_Lo              0x00A2

// Slope Once Activated
#define Slope1x_Hi          0x0000
#define Slope1x_Lo          0x00F3

// Slope Up Scroll
#define SlopeUp_Hi          0x0000
#define SlopeUp_Lo          0x0144

// Sofa Scroll
#define Sofa_Hi             0x0000
#define Sofa_Lo             0x0195

// Small Step Selected
#define SStepS_Hi           0x0000
#define SStepS_Lo           0x01E6

// Stairs Up Scroll
#define StairUp_Hi          0x0000
#define StairUp_Lo          0x0237

// Walk
#define Walk_Hi             0x0000
#define Walk_Lo             0x0288

// Walk Activated
#define WalkA_Hi            0x0000
#define WalkA_Lo            0x02D9

// Walk Selected
#define WalkS_Hi            0x0000
#define WalkS_Lo            0x032A

#endif //SD_ADDRESSES_H
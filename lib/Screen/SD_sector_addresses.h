#ifndef SD_ADDRESSES_H
#define SD_ADDRESSES_H

// This file defines the sector addresses of the images to be loaded on the screen
// The sector addresses can be found via the 4D Systems Workshop 4D IDE
// The Graphics Composer of this software should be used:
//  - To load the desired images on the uSD card
//  - To find the sector addresses of said images (via generated .DAT file)


#define CUP_ADDRESS_HI         0x0000
#define CUP_ADDRESS_LO         0x0000

#define SIT_ADDRESS_HI         0x0000
#define SIT_ADDRESS_LO         0x0051

#define SLOPE_ADDRESS_HI       0x0000
#define SLOPE_ADDRESS_LO       0x00A2

#define SOFA_ADDRESS_HI        0x0000
#define SOFA_ADDRESS_LO        0x00F3

#define STAIRS_ADDRESS_HI      0x0000
#define STAIRS_ADDRESS_LO      0x0144

#endif //SD_ADDRESSES_H
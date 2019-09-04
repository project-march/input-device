#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <Arduino.h>
#include <map>
#include <vector>
#include "SD_sector_addresses.h"

enum class State {  HomeSitStart,
                    HomeSitStartSelected,
                    HomeSitStartActivated,
                    StandUp,
                    StandUpSelected,
                    StandUpActivated,
                    TurnOffStart,
        //            TurnOffStartSelected,
        //            TurnOffStartActivated,
                    HomeStandStart,
                    HomeStandStartSelected,
                    HomeStandStartActivated,

                    Sit,
                    SitSelected,
                    SitActivated,
                    HomeSit,
                    HomeSitSelected,
                    HomeSitActivated,
                    HomeStand,
                    HomeStandSelected,
                    HomeStandActivated,
                    TurnOff,
        //            TurnOffSelected,
        //            TurnOffActivated,

                    Walk,
                    WalkSmall,
                    WalkNormal,
                    WalkLarge,
                    WalkSmallSelected,
                    WalkNormalSelected,
        //            WalkLargeSelected,
                    WalkSmallActivated,
                    WalkNormalActivated,
        //            WalkLargeActivated,
                    SingleStep,
                    SingleStepSmall,
                    SingleStepNormal,
                    SingleStepLarge,
                    SingleStepSmallSelected,
                    SingleStepNormalSelected,
        //            SingleStepLargeSelected,
                    SingleStepSmallActivated,
                    SingleStepNormalActivated,
        //            SingleStepLargeActivated,
                    SideStep,
                    SideStepLeft,
                    SideStepRight,
                    SideStepLeftSelected,
                    SideStepRightSelected,
                    SideStepLeftActivated,
                    SideStepRightActivated,

                    Sofa,
                    SofaSit,
                    SofaSitSelected,
                    SofaSitActivated,
                    SofaStandUp,
                    SofaStandUpSelected,
                    SofaStandUpActivated,

                    TiltedPath,
                    TiltedPathStartHometToMin5,
                    TiltedPathStartHometToMin5Selected,
                    TiltedPathStartHometToMin5Activated,
                    FirstStartStep,
                    FirstStartStepActivated,
                    SecondStartStep,
                    SecondStartStepActivated,
                    HomeStandToMin10,
                    HomeStandToMin10Activated,
                    TiltedPathMiddleStep,
                    TiltedPathMiddleStepActivated,
                    HomeStandToMin5,
                    HomeStandToMin5Activated,
                    FirstEndStep,
                    FirstEndStepActivated,
                    SecondEndStep,
                    SecondEndStepActivated,
                    HomeForWalk25,
                    HomeForWalk25Activated,

                    Stairs,
                    StairsUp,
                    StairsUpSelected,
                    StairsUpActivated,
                    StairsDown,
                    StairsDownSelected,
                    StairsDownActivated,
                    // StairsDownFinal,
                    // StairsDownFinalSelected,
                    // StairsDownFinalActivated,

                    WalkObstacle,
                    WalkObstacleSmall,
                    WalkObstacleNormal,
                    WalkObstacleLarge,
                    WalkObstacleSmallSelected, // same image as WalkSmallSelected
                    WalkObstacleNormalSelected, // same image as WalkNormalSelected
        //            WalkObstacleLargeSelected, // same image as WalkLargeSelected
                    WalkObstacleSmallActivated, // same image as WalkSmallActivated
                    WalkObstacleNormalActivated, // same image as WalkNormalActivated
        //            WalkObstacleLargeActivated, // same image as WalkLargeActivated
                    SingleStepObstacle,
                    SingleStepObstacleSmall,
                    SingleStepObstacleNormal,
                    SingleStepObstacleLarge,
                    SingleStepObstacleSmallSelected, // same image as SingleStepSmallSelected
                    SingleStepObstacleNormalSelected, // same image as SingleStepNormalSelected
        //            SingleStepObstacleLargeSelected, // same image as SignleStepLargeSelected
                    SingleStepObstacleSmallActivated, // same image as SingleStepSmallActivated
                    SingleStepObstacleNormalActivated}; // same image as SingleStepNormalActivated
        //            SingleStepObstacleLargeActivated}; // same image as SingleStepLargeActivated
                    
                

class StateMachine
{
private:
    State currentState;
    State rememberStateWIB;
    State rememberStateSit;
    State rememberStateObstacle;
    State rememberStateObstacleWIB;
    std::map<State,char*> stateToGaitMapping;

public:
    StateMachine();
    void updateState(String joystickState = "NEUTRAL", String joystickPress = "NEUTRAL", String rockerState = "NEUTRAL", String triggerPress = "NEUTRAL");
    int * getScreenImage();
    State getCurrentState();
    std::string getGaitNameOfState(State state);
};




#endif // STATEMACHINE_H
#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <Arduino.h>
#include <vector>

enum class State {  HomeSit,
                    HomeSitSelected,
                    HomeSitActivated,
                    StandUp,
                    StandUpSelected,
                    StandUpActivated,
                    TurnOffStart,
                    TurnOffStartSelected,
                    TurnOffStartActivated,
                    HomeStandStart,
                    HomeStandStartSelected,
                    HomeStandStartActivated,

                    Sit,
                    SitSelected,
                    SitActivated,
                    HomeStand,
                    HomeStandSelected,
                    HomeStandActivated,
                    TurnOff,
                    TurnOffSelected,
                    TurnOffActivated,

                    Walk,
                    WalkSmall,
                    WalkNormal,
                    WalkLarge,
                    WalkSmallSelected,
                    WalkNormalSelected,
                    WalkLargeSelected,
                    WalkSmallActivated,
                    WalkNormalActivated,
                    WalkLargeActivated,
                    SingleStep,
                    SingleStepSmall,
                    SingleStepNormal,
                    SingleStepLarge,
                    SingleStepSmallSelected,
                    SingleStepNormalSelected,
                    SingleStepLargeSelected,
                    SingleStepSmallActivated,
                    SingleStepNormalActivated,
                    SingleStepLargeActivated,
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

                    Slope,
                    SlopeUp,
                    SlopeUpSelected,
                    SlopeUpActivated,
                    SlopeDown,
                    SlopeDownSelected,
                    SlopeDownActivated,
                    
                    RoughTerrain,
                    RoughTerrainSelected,
                    RoughTerrainActivated,

                    TiltedPath,
                    TiltedPathSelected,
                    TiltedPathActivated,

                    Stairs,
                    StairsUp,
                    StairsUpSelected,
                    StairsUpActivated,
                    StairsWalk,
                    StairsWalkSelected,
                    StairsWalkActivated,
                    StairsDown,
                    StairsDownSelected,
                    StairsDownActivated,

                    WalkObstacle,
                    WalkObstacleSelected,
                    WalkObstacleActivated};
                    

class StateMachine
{
private:
    State currentState;
    State rememberStateWIB;
    State rememberStateSit;
    State rememberStateObstacle;
    State rememberStateObstacleWIB;
public:
    StateMachine();
    void updateState(String joystickState = "NEUTRAL", String joystickPress = "NEUTRAL", String rockerState = "NEUTRAL", String triggerPress = "NEUTRAL");
    int * getScreenImage();
};




#endif // STATEMACHINE_H
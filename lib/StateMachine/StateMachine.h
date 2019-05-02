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
                    StartTurnOff,
                    StartTurnOffSelected,
                    StartTurnOffActivated,
                    StartHomeStand,
                    StartHomeStandSelected,
                    StartHomeStandActivated,

                    Sit,
                    SitSelected,
                    SitActivated,
                    SitHomeStand,
                    SitHomeStandSelected,
                    SitHomeStandActivated,
                    SitTurnOff,
                    SitTurnOffSelected,
                    SitTurnOffActivated,

                    Walk,
                    WalkSmall,
                    WalkNormal,
                    WalkBig,
                    WalkSmallSelected,
                    WalkNormalSelected,
                    WalkBigSelected,
                    WalkSmallActivated,
                    WalkNormalActivated,
                    WalkBigActivated,
                    SingleStep,
                    SingleStepSmall,
                    SingleStepNormal,
                    SingleStepBig,
                    SingleStepSmallSelected,
                    SingleStepNormalSelected,
                    SingleStepBigSelected,
                    SingleStepSmallActivated,
                    SingleStepNormalActivated,
                    SingleStepBigActivated,
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
                    StairsDown,
                    StairsDownSelected,
                    StairsDownActivated                   

};


class StateMachine
{
private:
    State currentState;
    State rememberStateWIB;
    State rememberStateSit;
    State rememberStateObstacle;
public:
    StateMachine();
    void updateState(String joystickState = "NEUTRAL", String joystickPress = "NEUTRAL", String rockerState = "NEUTRAL", String triggerPress = "NEUTRAL");
    int * getScreenImage();
};




#endif // STATEMACHINE_H
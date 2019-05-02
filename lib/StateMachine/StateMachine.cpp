#include "StateMachine.h"
#include "SD_sector_addresses.h"

// Constructor
StateMachine::StateMachine()
{
    this->currentState = State::HomeSit;
    this->rememberStateWIB = State::Walk;
    this->rememberStateSit = State::Sit;
    this->rememberStateObstacle = State::Sofa;
}

// Updates the current state based on the button inputs
void StateMachine::updateState(String joystickState, String joystickPress, String rockerState, String triggerPress){
    switch (this->currentState)
    {
        //Start menu
        //Scroll
        case State::HomeSit:
            if(joystickState == "RIGHT"){
                this->currentState = State::StandUp;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::StartTurnOff;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::HomeSitSelected;
            }
            break;
        case State::StandUp:
            if(joystickState == "RIGHT"){
                this->currentState = State::StartHomeStand;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::HomeSit;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::StandUpSelected;
            }
            break;
        case State::StartHomeStand:
            if(joystickState == "RIGHT"){
                this->currentState = State::StartTurnOff;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::StandUp;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::StartHomeStandSelected;
            }
            break;
        case State::StartTurnOff:
            if(joystickState =="RIGHT"){
                this->currentState = State::HomeSit;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::StartHomeStand;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::StartTurnOffSelected;
            }
            break;

        //Selected
        case State::HomeSitSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeSitActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::HomeSit;
            }
            break;
        case State::StandUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StandUpActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::StandUp;
            }
            break;
        case State::StartHomeStandSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StartHomeStandActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::StartHomeStand;
            }
            break;
        case State::StartTurnOffSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StartTurnOffActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::StartTurnOff;
            }
            break;

        //Activated
        case State::HomeSitActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::StandUp;
            }
            break;
        case State::StandUpActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::Walk;
            }
            break;
        case State::StartHomeStandActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::Walk;
            }
            break;
        case State::StartTurnOffActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeSit;
            }
            break;
        
        //Sit menu
        //Scroll
        case State::Sit:
            if(joystickState == "RIGHT"){
                this->currentState = State::SitHomeStand;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SitTurnOff;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SitSelected;
            }
            else if(joystickState == "UP"){
                this->currentState = rememberStateWIB;
                this->rememberStateSit = State::Sit;
            }
            break;
        case State::SitHomeStand:
            if(joystickState == "RIGHT"){
                this->currentState = State::SitTurnOff;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Sit;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SitHomeStandSelected;
            }
            else if(joystickState == "UP"){
                this->currentState = rememberStateWIB;
                this->rememberStateSit = State::SitHomeStand;
            }
            break;
        case State::SitTurnOff:
            if(joystickState == "RIGHT"){
                this->currentState = State::Sit;
            }
            else if(joystickState =="LEFT"){
                this->currentState = State::SitHomeStand;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SitTurnOffSelected;
            }
            else if(joystickState == "UP"){
                this->currentState = rememberStateWIB;
                this->rememberStateSit = State::SitTurnOff;
            }
            break;

        //Selected
        case State::SitSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SitActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::Sit;
            }
            break;
        case State::SitHomeStandSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SitHomeStandActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SitHomeStand;
            }
            break;
        case State::SitTurnOffSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SitTurnOffActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SitTurnOff;
            }
            break;

        //Activated
        case State::SitActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::StandUp;
            }
            break;
        case State::SitHomeStandActivated:
            if(triggerPress = "PUSH"){
                this->currentState = State::Walk;
            }
            break;
        case State::SitTurnOffActivated:
            if(triggerPress = "PUSH"){
                this->currentState = State::HomeSit;
            }
            break;

        //WIB menu
        //Scroll
        case State::Walk:
            if(joystickState == "RIGHT"){
                this->currentState = State::SingleStep;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SideStep;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::WalkNormal;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::Walk;
            }
            else if(joystickState == "DOWN"){
                this->currentState = rememberStateSit;
                this->rememberStateWIB = State::Walk;
            }
            break;
        case State::SingleStep:
            if(joystickState == "RIGHT"){
                this->currentState = State::SideStep;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Walk;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SingleStepNormal;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::Walk;
            }
            else if(joystickState == "DOWN"){
                this->currentState = rememberStateSit;
                this->rememberStateWIB = State::Walk;
            }
            break;
        case State::SideStep:
            if(joystickState == "RIGHT"){
                this->currentState = State::Walk;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SingleStep;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SideStepLeft;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::Walk;
            }
            else if(joystickState == "DOWN"){
                this->currentState = rememberStateSit;
                this->rememberStateWIB = State::Walk;
            }
            break;
        
        //Choose step size
        case State::WalkNormal:
            if(rockerState == "DOWN"){
                this->currentState = State::WalkSmall;
            }
            else if(rockerState =="UP"){
                this->currentState = State::WalkBig;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::WalkNormalSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::Walk;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::WalkNormal;
            }
            else if(joystickState == "DOWN"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateSit;
            }
            break;
        case State::WalkSmall:
            if(rockerState =="UP"){
                this->currentState = State::WalkNormal;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::WalkSmallSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::Walk;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::WalkSmall;
            }
            else if(joystickState == "DOWN"){
                this->currentState = rememberStateSit;
                this->rememberStateWIB = State::WalkSmall;
            }
            break;
        case State::WalkBig:
            if(rockerState =="DOWN"){
                this->currentState = State::WalkNormal;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::WalkBigSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::Walk;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::WalkBig;
            }
            else if(joystickState == "DOWN"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateSit;
            }
            break;
        case State::SingleStepNormal:
            if(rockerState == "DOWN"){
                this->currentState = State::SingleStepSmall;
            }
            else if(rockerState =="UP"){
                this->currentState = State::SingleStepBig;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SingleStepNormalSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SingleStep;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::SingleStepNormal;
            }
            else if(joystickState == "DOWN"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateSit;
            }
            break;
        case State::SingleStepSmall:
            if(rockerState =="UP"){
                this->currentState = State::SingleStepNormal;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SingleStepSmallSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SingleStep;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::SingleStepSmall;
            }
            else if(joystickState == "DOWN"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateSit;
            }
            break;
        case State::SingleStepBig:
            if(rockerState =="DOWN"){
                this->currentState = State::SingleStepNormal;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SingleStepBigSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SingleStep;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::SingleStepBig;
            }
            else if(joystickState == "DOWN"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateSit;
            }
            break;
        case State::SideStepLeft:
            if (joystickState == "LEFT"){
                this->currentState = State::SideStepRight;
            }
            else if (joystickState == "RIGHT"){
                this->currentState = State::SideStepRight;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SideStepLeftSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SideStep;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::SideStepLeft;
            }
            else if(joystickState == "DOWN"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateSit;
            }
            break;
        case State::SideStepRight:
            if (joystickState == "LEFT"){
                this->currentState = State::SideStepLeft;
            }
            else if (joystickState == "RIGHT"){
                this->currentState = State::SideStepLeft;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SideStepRightSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SideStep;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::SideStepRight;
            }
            else if(joystickState == "DOWN"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateSit;
            }
            break;
        
        //Selected
        case State::WalkSmallSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkSmallActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::WalkSmall;
            }
            break;
        case State::WalkNormalSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkNormalActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::WalkNormal;
            }
            break;
        case State::WalkBigSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkBigActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::WalkBig;
            }
            break;
        case State::SingleStepSmallSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepSmallActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SingleStepSmall;
            }
            break;
        case State::SingleStepNormalSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepNormalActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SingleStepNormal;
            }
            break;
        case State::SingleStepBigSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepBigActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SingleStepBig;
            }
            break;
        case State::SideStepLeftSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStepLeftActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SideStepLeft;
            }
        break;
        case State::SideStepRightSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStepRightActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SideStepRight;
            }
            break;

        //Activated
        case State::WalkSmallActivated:

            break;
        case State::WalkNormalActivated:

            break;
        case State::WalkBigActivated:

            break;
        case State::SingleStepSmallActivated:
        break;
        case State::SingleStepNormalActivated:
        break;
        case State::SingleStepBigActivated:
        break;
        case State::SideStepLeftActivated:
        break;
        case State::SideStepRightActivated:

        //Obstacle menu
        //Scroll
        case State::Sofa:
            if(joystickState == "RIGHT"){
                this->currentState = State::Slope;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Stairs;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SofaSit;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            break;
        case State::Slope:
              if(joystickState == "RIGHT"){
                this->currentState = State::RoughTerrain;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Sofa;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SlopeUp;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            break; 
        case State::RoughTerrain:
              if(joystickState == "RIGHT"){
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Slope;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::RoughTerrainSelected;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            break; 
        case State::TiltedPath:
              if(joystickState == "RIGHT"){
                this->currentState = State::Stairs;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::RoughTerrain;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::TiltedPathSelected;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            break; 
        case State::Stairs:
              if(joystickState == "RIGHT"){
                this->currentState = State::Sofa;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::StairsSelected;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            break;

        //Submenu obstacles
        case State::SofaSit:
            if(joystickState == "PUSH"){
                this->currentState = State::SofaSitSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::Sofa;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SofaStandUp;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SofaStandUp;
            }
        case State::SofaStandUp:
            if(joystickState == "PUSH"){
                this->currentState = State::SofaStandUpSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::Sofa;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SofaSit;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SofaSit;
            }

        case State::SlopeUp:
            if(joystickState == "PUSH"){
                this->currentState = State::SlopeUpSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::Slope;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SlopeDown;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SlopeDown;
            }
        case State::SlopeDown:
            if(joystickState == "PUSH"){
                this->currentState = State::SlopeDownSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::Slope;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SlopeUp;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SlopeUp;
            }

        case State::StairsUp:
            if(joystickState == "PUSH"){
                this->currentState = State::StairsUpSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::Stairs;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::StairsDown;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::StairsDown;
            }
        case State::StairsDown:
            if(joystickState == "PUSH"){
                this->currentState = State::StairsDownSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::Stairs;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::StairsUp;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::StairsUp;
            }
        








        default:
            break;
    }
}





// Return the SD addresses of the image that should be drawn in the current state
int * StateMachine::getScreenImage(){
    static int currentSdAddresses[2] = {0, 0};
    switch (this->currentState)
    {
        case State::ScrollSofa:
            currentSdAddresses[0] = Sofa_Hi;
            currentSdAddresses[1] = Sofa_Lo;
            break;
        case State::ScrollCups:
            currentSdAddresses[0] = Cups_Hi;
            currentSdAddresses[1] = Cups_Lo;
            break;
        case State::ScrollSlopeUp:
            currentSdAddresses[0] = SlopeUp_Hi;
            currentSdAddresses[1] = SlopeUp_Lo;
            break;
        case State::ScrollStairsUp:
            currentSdAddresses[0] = StairUp_Hi;
            currentSdAddresses[1] = StairUp_Lo;
            break;
        case State::ScrollSit:
            currentSdAddresses[0] = Sit_Hi;
            currentSdAddresses[1] = Sit_Lo;
            break;
        case State::Walk:
            currentSdAddresses[0] = Walk_Hi;
            currentSdAddresses[1] = Walk_Lo;
            break;
        case State::WalkSelected:
            currentSdAddresses[0] = WalkS_Hi;
            currentSdAddresses[1] = WalkS_Lo;
            break;
        case State::WalkActivated:
            currentSdAddresses[0] = WalkA_Hi;
            currentSdAddresses[1] = WalkA_Lo;
            break;
        case State::BigStep:
            currentSdAddresses[0] = BStepS_Hi;
            currentSdAddresses[1] = BStepS_Lo;
            break;
        case State::SmallStep:
            currentSdAddresses[0] = SStepS_Hi;
            currentSdAddresses[1] = SStepS_Lo;
            break;
        default:
            Serial.println("Can't draw this state");
            currentSdAddresses[0] = 0;
            currentSdAddresses[1] = 0;
            break;
    }
    return currentSdAddresses;
}
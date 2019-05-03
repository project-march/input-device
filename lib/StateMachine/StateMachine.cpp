#include "StateMachine.h"
#include "SD_sector_addresses.h"

// Constructor
StateMachine::StateMachine()
{
    this->currentState = State::1HomeSit;
    this->rememberStateWIB = State::1Walk;
    this->rememberStateSit = State::1Sit;
    this->rememberStateObstacle = State::1Sofa;
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
                this->currentState = State::TurnOffStart;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::HomeSitSelected;
            }
            break;
        case State::StandUp:
            if(joystickState == "RIGHT"){
                this->currentState = State::HomeStandStand;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::HomeSit;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::StandUpSelected;
            }
            break;
        case State::HomeStandStart:
            if(joystickState == "RIGHT"){
                this->currentState = State::TurnOffStart;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::1StandUp;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::HomeStandStartSelected;
            }
            break;
        case State::TurnOffStart:
            if(joystickState =="RIGHT"){
                this->currentState = State::HomeSit;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::HomeStandStart;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::TurnOffStartSelected;
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
        case State::HomeStandStartSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeStandStartActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::HomeStandStart;
            }
            break;
        case State::TurnOffStartSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::TurnOffStartActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::TurnOffStart;
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
        case State::HomeStandStartActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::Walk;
            }
            break;
        case State::TurnOffStartActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeSit;
            }
            break;
        
        //Sit menu
        //Scroll
        case State::Sit:
            if(joystickState == "RIGHT"){
                this->currentState = State::HomeStand;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::TurnOff;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SitSelected;
            }
            else if(joystickState == "UP"){
                this->currentState = rememberStateWIB;
                this->rememberStateSit = State::Sit;
            }
            break;
        case State::HomeStand:
            if(joystickState == "RIGHT"){
                this->currentState = State::TurnOff;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Sit;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::HomeStandSelected;
            }
            else if(joystickState == "UP"){
                this->currentState = rememberStateWIB;
                this->rememberStateSit = State::HomeStand;
            }
            break;
        case State::TurnOff:
            if(joystickState == "RIGHT"){
                this->currentState = State::Sit;
            }
            else if(joystickState =="LEFT"){
                this->currentState = State::HomeStand;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::TurnOffSelected;
            }
            else if(joystickState == "UP"){
                this->currentState = rememberStateWIB;
                this->rememberStateSit = State::TurnOff;
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
        case State::HomeStandSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeStandActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::HomeStand;
            }
            break;
        case State::TurnOffSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::TurnOffActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::TurnOff;
            }
            break;

        //Activated
        case State::SitActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::StandUp;
            }
            break;
        case State::HomeStandActivated:
            if(triggerPress = "PUSH"){
                this->currentState = State::Walk;
            }
            break;
        case State::TurnOffActivated:
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
                this->currentState = State::WalkLarge;
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
        case State::WalkLarge:
            if(rockerState =="DOWN"){
                this->currentState = State::WalkNormal;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::WalkLargeSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::Walk;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::WalkLarge;
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
                this->currentState = State::SingleStepLarge;
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
        case State::SingleStepLarge:
            if(rockerState =="DOWN"){
                this->currentState = State::SingleStepNormal;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::SingleStepLargeSelected;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SingleStep;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
                this->rememberStateWIB = State::SingleStepLarge;
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
        case State::WalkLargeSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkLargeActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::WalkLarge;
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
        case State::SingleStepLargeSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepLargeActivated;
            }
            else if(joystickState == "DOUBLE PRESS"){
                this->currentState = State::SingleStepLarge;
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
            if(triggerPress == "PUSH"){
                this->
            }
            break;

        case State::WalkNormalActivated:
            if(triggerPress == "PUSH"){
                this->

            }
            break;
        
        case State::WalkLargeActivated:
            if(triggerPress == "PUSH"){
                this->

            }
            break;


        case State::SingleStepSmallActivated:
            if(triggerPress == "PUSH"){
                this->

            }
            break;
        
        case State::SingleStepNormalActivated:
            if(triggerPress == "PUSH"){
                this->

            }
            break;
        
        case State::SingleStepBigActivated:
            if(triggerPress == "PUSH"){
                this->

            }
            break;
        
        case State::SideStepLeftActivated:
            if(triggerPress == "PUSH"){
                this->

            }
            break;
        
        case State::SideStepRightActivated:
            if(triggerPress == "PUSH"){
                this->

            }
            break;

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
                this->currentState = State::StairsUp;
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
            break;

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
            break;

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
            break;

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
            break;

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
            break;

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
            break;
        
        case State::SofaSitSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SofaSitActivated;
            }
            else if(joystickPress == "DOUBLE PRESS"){
                this->currentState = State::SofaSit;
            }
            break;

        case State::SofaSitActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SofaStandUp;
            }
            break;

        case State::SofaStandUp:
            if(joystickPress == "PUSH"){
                this->currentState = State::SofaStandUpSelected;
            }
            else if(joystickPress == "DOUBLE PRESS"){
                this->currentState = State::Sofa;
            }
            else if(joystickPress == "LEFT"){
                this->currentState = State::SofaSit;
            }
            else if(joystickPress == "DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            break;

        case State::SofaStandUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SofaStandUpActivated;
            }
            else if(joystickPress == "DOUBLE PRESS"){
                this->currentState = State::SofaStandUp;
            }
            break;

        case State::SofaStandUpActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::1Walk;
            }
            break;

        case State::SlopeUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SlopeUpActivated;
            }
            else if(joystickPress == "DOUBLE PRESS"){
                this->currentState = State::SlopeUp;
            }
            break;

        case State::SlopeUpActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            break;

        case State::SlopeDownSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SlopeDownActivated;
            }
            else if(joystickPress == "DOUBLE PRESS"){
                this->currentState = State::SlopeDown;
            }
            break;

        case State::SlopeDownActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            break;

        case State::StairsUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StairsUpActivated;
            }
            else if(joystickPress == "DOUBLE PRESS"){
                this->currentState = State::StairsUp;
            }
            break;

        case State::StairsUpActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }

        case State::StairsDownSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StairsDownActivated;
            }
            else if(joystickPress == "DOUBLE PRESS"){
                this->currentState = State::StairsDown;
            }
            break;

        case State::StairsDownActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            break;

     

        default:
            break;
    }
}





// Return the SD addresses of the image that should be drawn in the current state
int * StateMachine::getScreenImage(){
    static int currentSdAddresses[2] = {0, 0};
    switch (this->currentState)
    {
        case State::HomeSit:
            currentSdAddresses[0] = HomeSit1_Hi;
            currentSdAddresses[1] = HomeSit1_Lo;
            break;
        case State::StandUp:
            currentSdAddresses[0] = StandUp1_Hi 
            currentSdAddresses[1] = StandUp1_Lo             
            break;
        case State::StandUpSelected:
            currentSdAddresses[0] = StandUpSelected1_Hi 
            currentSdAddresses[1] = StandUpSelected1_Lo
            break;
        case State::StandUpActivated:
            currentSdAddresses[0] = StandUpActivated1_Hi
            currentSdAddresses[1] = StandUpActivated1_Lo
            break;
        case State::TurnOffStart:
            currentSdAddresses[0] = TurnOffStart1_Hi 
            currentSdAddresses[1] = TurnOffStart1_Lo 
            break;
        case State::HomeStandStart:
            currentSdAddresses[0] = HomeStandStart1_Hi
            currentSdAddresses[1] = HomeStandStart1_Lo  
            break;
        case State::Sit:
            currentSdAddresses[0] = Sit1_Hi
            currentSdAddresses[1] = Sit1_Lo   
            break;
        case State::SitSelected:
            currentSdAddresses[0] = SitSelected1_Hi
            currentSdAddresses[1] = SitSelected1_Lo
            break;
        case State::SitActivated:
            currentSdAddresses[0] = SitActivated1_Hi
            currentSdAddresses[1] = SitActivated1_Lo   
            break;
        case State::HomeStand:
            currentSdAddresses[0] = HomeStand1_Hi
            currentSdAddresses[1] = HomeStand1_Lo
            break;
        case State::TurnOff:
            currentSdAddresses[0] = TurnOff1_Hi
            currentSdAddresses[1] = TurnOff1_Lo 
            break;
        case State::Stairs:
            currentSdAddresses[0] = Stairs1_Hi
            currentSdAddresses[1] = Stairs1_Lo    
            break;
        case State::StairsUp:
            currentSdAddresses[0] = StairsUp1_Hi
            currentSdAddresses[1] = StairsUp1_Lo
            break;
        case State::StairsUpSelected:
            currentSdAddresses[0] = StairsUpSelected1_Hi
            currentSdAddresses[1] = StairsUpSelected1_Lo 
            break;
        case State::StairsUpActivated:
            currentSdAddresses[0] = StairsUpActivated1_Hi
            currentSdAddresses[1] = StairsUpActivated1_Lo
            break;
        case State::StairWalk:
            currentSdAddresses[0] = StairsWalk1_Hi 
            currentSdAddresses[1] = StairsWalk1_Lo  
            break;
        case State::StairWalkSelected:
            currentSdAddresses[0] = StairsWalkSelected1_Hi
            currentSdAddresses[1] = StairsWalkSelected1_Lo 
            break;
        case State::StairWalkActivated:
            currentSdAddresses[0] = StairsWalkActivated1_Hi
            currentSdAddresses[1] = StarisWalkActivated1_Lo
            break;
        case State::StairsDown:
            currentSdAddresses[0] = StairsDown1_Hi
            currentSdAddresses[1] = StairsDown1_Lo
            break;
        case State::StairsDownSelected:
            currentSdAddresses[0] = StairsDownSelected1_Hi
            currentSdAddresses[1] = StairsDownSelected1_Lo 
            break;
        case State::StairsDownActivated:
            currentSdAddresses[0] = StairsDownACtivated1_Hi
            currentSdAddresses[1] = StairsDownActivated1_Lo
            break;
        case State::Walk:
            currentSdAddresses[0] = Walk1_Hi
            currentSdAddresses[1] = Walk1_Lo  
            break;
        case State::WalkSmall:
            currentSdAddresses[0] = WalkSmall1_Hi 
            currentSdAddresses[1] = WalkSmall1_Lo   
            break;
        case State::WalkNormal:
            currentSdAddresses[0] = WalkNormal1_Hi
            currentSdAddresses[1] = WalkNormal1_Lo  
            break;
        case State::WalkLarge:
            currentSdAddresses[0] = WalkLarge1_Hi
            currentSdAddresses[1] = WalkLarge1_Lo  
            break;
        case State::WalkNormalSelected:
            currentSdAddresses[0] = WalkNormalSelected1_Hi
            currentSdAddresses[1] = WalkNormalSelected1_Lo 
            break;
        case State::WalkNormalActivated:
            currentSdAddresses[0] = WalkNormalActivated1_Hi
            currentSdAddresses[1] = WalkNormalActivated1_Lo


        default:
            Serial.println("Can't draw this state");
            currentSdAddresses[0] = 0;
            currentSdAddresses[1] = 0;
            break;
    }
    return currentSdAddresses;
}
#include "StateMachine.h"
#include "SD_sector_addresses.h"

// Constructor
StateMachine::StateMachine()
{
    this->currentState = State::HomeSit;
    this->rememberStateWIB = State::Walk;
    this->rememberStateSit = State::Sit;
    this->rememberStateObstacle = State::Sofa;
    this->rememberStateObstacleWIB = State::Slope;
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
                this->currentState = State::HomeStandStart;
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
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::HomeSit;
            }
            break;
        case State::StandUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StandUpActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::StandUp;
            }
            break;
        case State::HomeStandStartSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeStandStartActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::HomeStandStart;
            }
            break;
        case State::TurnOffStartSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::TurnOffStartActivated;
            }
            else if(rockerState == "UP"){ //Double press
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
                this->rememberStateSit = currentState;
                this->currentState = rememberStateWIB;
            
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
                this->rememberStateSit = currentState;
                this->currentState = rememberStateWIB;
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
                this->rememberStateSit = currentState;
                this->currentState = rememberStateWIB;
            }
            break;

        //Selected
        case State::SitSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SitActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::Sit;
            }
            break;
        case State::HomeStandSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeStandActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::HomeStand;
            }
            break;
        case State::TurnOffSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::TurnOffActivated;
            }
            else if(rockerState == "UP"){ //Double press
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
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateObstacle;
             
            }
            else if(joystickState == "DOWN"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateSit;
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
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateSit;
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
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateSit;
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
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::Walk;
            }
            else if(joystickState =="UP"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateObstacle;
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
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::Walk;
            }
            else if(joystickState =="UP"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateSit;
            }
            break;
        case State::WalkLarge:
            if(rockerState =="DOWN"){
                this->currentState = State::WalkNormal;
            }
            else if(joystickState == "PUSH"){
                this->currentState = State::WalkLargeSelected;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::Walk;
            }
            else if(joystickState =="UP"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateObstacle;
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
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SingleStep;
            }
            else if(joystickState =="UP"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateObstacle;
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
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SingleStep;
            }
            else if(joystickState =="UP"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateObstacle;
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
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SingleStep;
            }
            else if(joystickState =="UP"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateObstacle;
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
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SideStep;
            }
            else if(joystickState =="UP"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateObstacle;
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
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SideStep;
            }
            else if(joystickState =="UP"){
                this->rememberStateWIB = currentState;
                this->currentState = rememberStateObstacle;
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
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::WalkSmall;
            }
            break;
        case State::WalkNormalSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkNormalActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::WalkNormal;
            }
            break;
        case State::WalkLargeSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkLargeActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::WalkLarge;
            }
            break;
        case State::SingleStepSmallSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepSmallActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SingleStepSmall;
            }
            break;
        case State::SingleStepNormalSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepNormalActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SingleStepNormal;
            }
            break;
        case State::SingleStepLargeSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepLargeActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SingleStepLarge;
            }
            break;
        case State::SideStepLeftSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStepLeftActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SideStepLeft;
            }
        break;
        case State::SideStepRightSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStepRightActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SideStepRight;
            }
            break;

        //Activated
        case State::WalkSmallActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::Walk;
            }
            break;
        case State::WalkNormalActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::Walk;

            }
            break;
        case State::WalkLargeActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::Walk;

            }
            break;
        case State::SingleStepSmallActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStep;

            }
            break;
        case State::SingleStepNormalActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStep;

            }
            break;
        case State::SingleStepBigActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStep;
            }
            break;
        case State::SideStepLeftActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStep;
            }
            break;
        case State::SideStepRightActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStep;
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
            else if(rockerState == "UP"){ //Double press
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
            else if(rockerState == "UP"){ //Double press
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
            else if(rockerState == "UP"){ //Double press
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
            else if(rockerState == "UP"){ //Double press
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
        case State::RoughTerrain:
            if(joystickState == "PUSH"){
                this->currentState = State::RoughTerrainSelected;
            }
            else if(rockerState == "UP"){ //Double Press
                this->currentState = State::RoughTerrain;
            }
            else if(joystickState == "DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            break;
        case State::TiltedPath:
            if(joystickState == "PUSH"){
                this->currentState = State::TiltedPathSelected;
            }
            else if(rockerState == "UP"){ //Double Press
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = rememberStateWIB;
            }
            break;      
        case State::StairsUp:
            if(joystickState == "PUSH"){
                this->currentState = State::StairsUpSelected;
            }
            else if(rockerState == "UP"){ //Double press
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
            else if(rockerState == "UP"){ //Double press
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

            //Selected and activated submenus
            //Sofa
        case State::SofaSitSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SofaSitActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SofaSit;
            }
            break;
        case State::SofaSitActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SofaStandUp;
            }
            break;
        case State::SofaStandUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SofaStandUpActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SofaStandUp;
            }
            break;
        case State::SofaStandUpActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkObstacle;
                this->rememberStateObstacleWIB = State::Slope;
            }
            break;


        //Slope
        case State::SlopeUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SlopeUpActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SlopeUp;
            }
            break;
        case State::SlopeUpActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::SlopeDown;
                this->currentState = State::WalkObstacle;
            }
            break;
        case State::SlopeDownSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SlopeDownActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::SlopeDown;
            }
            break;
        case State::SlopeDownActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::RoughTerrain;    
                this->currentState = State::WalkObstacle;
            break;

        //Rough Terrain
        case State::RoughTerrainSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::RoughTerrainActivated;
            }
            else if(rockerState == "UP"){
                this->currentState = State::RoughTerrain;
            }
            break;
        case State::RoughTerrainActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::TiltedPath;    
                this->currentState = State::WalkObstacle;
            }
            break;

        //Tilted Path
        case State::TiltedPathSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::TiltedPathActivated;
            }
            else if(rockerState == "UP"){
                this->currentState = State::TiltedPath;
            }
            break;
        case State::TiltedPathActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::Stairs;    
                this->currentState = State::WalkObstacle;
            }
            break;

        //Stairs
        case State::StairsUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StairsUpActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::StairsUp;
            }
            break;

        case State::StairsUpActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::StairsDown;
                this->currentState = State::WalkObstacle;
            }
            break;
        case State::StairsDownSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StairsDownActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::StairsDown;
            }
            break;

        case State::StairsDownActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = Sofa;
                this->currentState = State::WalkObstacle;
            }
            break;

     
        //Walk in between obstacles
        case State::WalkObstacle;
            if(joystickState == "PUSH"){
                this->currentState = State::WalkObstacleSelected;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = rememberStateObstacleWIB;
            }
            break;
        case State::WalkObstacleSelected;
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkObstacleActivated;
            }
            else if(rockerState == "UP"){ //Double press
                this->currentState = State::WalkObstacle;
            }
            break;
        case State::WalkObstacleActivated;
            if(triggerPress == "PUSH"){
                this->currentState = rememberStateObstacleWIB;
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
        //Start menu
        case State::HomeSit:
            currentSdAddresses[0] = HomeSit_Hi;
            currentSdAddresses[1] = HomeSit_Lo;
            break;
        case State::HomeSitSelected:
            currentSdAddresses[0] = HomeSitSelected_Hi;
            currentSdAddresses[1] = HomeSitSelected_Lo;
        case State::HomeSitActivated:
            currentSdAddresses[0] = HomeSitActivated_Hi;
            currentSdAddresses[1] = HomeSitActivated_Lo;
        case State::StandUp:
            currentSdAddresses[0] = StandUp_Hi 
            currentSdAddresses[1] = StandUp_Lo             
            break;
        case State::StandUpSelected:
            currentSdAddresses[0] = StandUpSelected_Hi 
            currentSdAddresses[1] = StandUpSelected_Lo
            break;
        case State::StandUpActivated:
            currentSdAddresses[0] = StandUpActivated_Hi
            currentSdAddresses[1] = StandUpActivated_Lo
            break;
        case State::HomeStandStart:
            currentSdAddresses[0] = HomeStandStart_Hi
            currentSdAddresses[1] = HomeStandStart_Lo  
            break;
        case State::HomeStandStartSelected:
            currentSdAddresses[0] = HomeStandStartSelected_Hi
            currentSdAddresses[1] = HomeStandStartSelected_Lo  
            break;
        case State::HomeStandStartActivated:
            currentSdAddresses[0] = HomeStandStartActivated_Hi
            currentSdAddresses[1] = HomeStandStartActivated_Lo  
            break;
        case State::TurnOffStart:
            currentSdAddresses[0] = TurnOffStart_Hi 
            currentSdAddresses[1] = TurnOffStart_Lo 
            break;
        case State::TurnOffStartSelected:
            currentSdAddresses[0] = TurnOffStartSelected_Hi 
            currentSdAddresses[1] = TurnOffStartSelected_Lo 
            break;
        case State::TurnOffStartActivated:
            currentSdAddresses[0] = TurnOffStartActivated_Hi 
            currentSdAddresses[1] = TurnOffStartActivated_Lo 
            break;


        //Sit menu
        case State::Sit:
            currentSdAddresses[0] = Sit_Hi
            currentSdAddresses[1] = Sit_Lo   
            break;
        case State::SitSelected:
            currentSdAddresses[0] = SitSelected_Hi
            currentSdAddresses[1] = SitSelected_Lo
            break;
        case State::SitActivated:
            currentSdAddresses[0] = SitActivated_Hi
            currentSdAddresses[1] = SitActivated_Lo   
            break;
        case State::HomeStand:
            currentSdAddresses[0] = HomeStand_Hi
            currentSdAddresses[1] = HomeStand_Lo
            break;
        case State::HomeStandSelected:
            currentSdAddresses[0] = HomeStandSelected_Hi
            currentSdAddresses[1] = HomeStandSelected_Lo
            break;
        case State::HomeStandActivated:
            currentSdAddresses[0] = HomeStandActivated_Hi
            currentSdAddresses[1] = HomeStandActivated_Lo
            break;
        case State::TurnOff:
            currentSdAddresses[0] = TurnOff_Hi
            currentSdAddresses[1] = TurnOff_Lo 
            break;
        case State::TurnOffSelected:
            currentSdAddresses[0] = TurnOffSelected_Hi
            currentSdAddresses[1] = TurnOffSelected_Lo 
            break;
        case State::TurnOffActivated:
            currentSdAddresses[0] = TurnOffActivated_Hi
            currentSdAddresses[1] = TurnOffActivated_Lo 
            break;

        //Obstacle menu
        case State::Sofa:
            currentSdAddresses[0] = Sofa_Hi
            currentSdAddresses[1] = Sofa_Lo    
            break;
        case State::SofaSit:
            currentSdAddresses[0] = SofaSit_Hi
            currentSdAddresses[1] = SofaSit_Lo    
            break;
        case State::SofaSitSelected:
            currentSdAddresses[0] = SofaSitSelected_Hi
            currentSdAddresses[1] = SofaSitSelected_Lo    
            break;
        case State::SofaSitActivated:
            currentSdAddresses[0] = SofaSitActivated_Hi
            currentSdAddresses[1] = SofaSitActivated_Lo    
            break;
        case State::SofaStandUp:  
            currentSdAddresses[0] = SofaStandup_Hi
            currentSdAddresses[1] = SofaStandUp_Lo    
            break;
        case State::SofaStandUpSelected:
            currentSdAddresses[0] = SofaStandUpSelected_Hi
            currentSdAddresses[1] = SofaStandUpSelected_Lo    
            break;
        case State::SofaSitActivated:
            currentSdAddresses[0] = SofaStandUpActivated_Hi
            currentSdAddresses[1] = SofaStandUp_Lo    
            break;

        case State::Slope:
            currentSdAddresses[0] = Slope_Hi
            currentSdAddresses[1] = Slope_Lo    
            break;
        case State::SlopeUp:
            currentSdAddresses[0] = SlopeUp_Hi
            currentSdAddresses[1] = SlopeUp_Lo    
            break;
        case State::SlopeUpSelected:
            currentSdAddresses[0] = SlopeUpSelected_Hi
            currentSdAddresses[1] = SlopeUpSelected_Lo    
            break;
        case State::SlopeUpActivated:
            currentSdAddresses[0] = SlopeUpActivated_Hi
            currentSdAddresses[1] = SlopeUpActivated_Lo    
            break;
        case State::SlopeDown:
            currentSdAddresses[0] = SlopeDown_Hi
            currentSdAddresses[1] = SlopeDown_Lo    
            break;
        case State::SlopeDownSelected:
            currentSdAddresses[0] = SlopeDownSelected_Hi
            currentSdAddresses[1] = SlopeDownSelected_Lo    
            break;
        case State::SlopeDown:
            currentSdAddresses[0] = SlopeDownSelected_Hi
            currentSdAddresses[1] = SlopeDownSelected_Lo    
            break;

        case State::RoughTerrain:
            currentSdAddresses[0] = RoughTerrain_Hi
            currentSdAddresses[1] = RoughTerrain_Lo    
            break;    
        case State::RoughTerrainSelected:
            currentSdAddresses[0] = RoughTerrainSelected_Hi
            currentSdAddresses[1] = RoughTerrainSelected_Lo    
            break;    
        case State::RoughTerrainActivated:
            currentSdAddresses[0] = RoughTerrainActivated_Hi
            currentSdAddresses[1] = RoughTerrainActivated_Lo    
            break;  

        case State::TiltedPath:
            currentSdAddresses[0] = TiltedPath_Hi
            currentSdAddresses[1] = TiltedPath_Lo    
            break;  
        case State::TiltedPathSelected:
            currentSdAddresses[0] = TiltedPathSelected_Hi
            currentSdAddresses[1] = TiltedPathSelected_Lo    
            break;  
        case State::TiltedPathActivated:
            currentSdAddresses[0] = TiltedPathActivated_Hi
            currentSdAddresses[1] = TiltedPathActivated_Lo    
            break;  
          
        case State::Stairs:
            currentSdAddresses[0] = Stairs_Hi
            currentSdAddresses[1] = Stairs_Lo    
            break;
        case State::StairsUp:
            currentSdAddresses[0] = StairsUp_Hi
            currentSdAddresses[1] = StairsUp_Lo
            break;
        case State::StairsUpSelected:
            currentSdAddresses[0] = StairsUpSelected_Hi
            currentSdAddresses[1] = StairsUpSelected_Lo 
            break;
        case State::StairsUpActivated:
            currentSdAddresses[0] = StairsUpActivated_Hi
            currentSdAddresses[1] = StairsUpActivated_Lo
            break;
        case State::StairsDown:
            currentSdAddresses[0] = StairsDown_Hi
            currentSdAddresses[1] = StairsDown_Lo
            break;
        case State::StairsDownSelected:
            currentSdAddresses[0] = StairsDownSelected_Hi
            currentSdAddresses[1] = StairsDownSelected_Lo 
            break;
        case State::StairsDownActivated:
            currentSdAddresses[0] = StairsDownACtivated_Hi
            currentSdAddresses[1] = StairsDownActivated_Lo
            break;
        
        case State::WalkObstacle:
            currentSdAddresses[0] = WalkObstacle_Hi 
            currentSdAddresses[1] = WalkObstacle_Lo  
            break;
        case State::WalkObstacleSelected:
            currentSdAddresses[0] = WalkObstacleSelected_Hi
            currentSdAddresses[1] = WalkObstacleSelected_Lo 
            break;
        case State::WalkObstacleActivated:
            currentSdAddresses[0] = WalkObstacleActivated_Hi
            currentSdAddresses[1] = WalkObstacleActivated_Lo 
            break;

        //WIB
        case State::Walk:
            currentSdAddresses[0] = Walk_Hi
            currentSdAddresses[1] = Walk_Lo  
            break;
        case State::WalkSmall:
            currentSdAddresses[0] = WalkSmall_Hi 
            currentSdAddresses[1] = WalkSmall_Lo   
            break;
        case State::WalkNormal:
            currentSdAddresses[0] = WalkNormal_Hi
            currentSdAddresses[1] = WalkNormal_Lo  
            break;
        case State::WalkLarge:
            currentSdAddresses[0] = WalkLarge_Hi
            currentSdAddresses[1] = WalkLarge_Lo  
            break;
        case State::WalkNormalSelected:
            currentSdAddresses[0] = WalkNormalSelected_Hi
            currentSdAddresses[1] = WalkNormalSelected_Lo 
            break;
        case State::WalkNormalActivated:
            currentSdAddresses[0] = WalkNormalActivated_Hi
            currentSdAddresses[1] = WalkNormalActivated_Lo
            break;
        case State::WalkSmallSelected:
            currentSdAddresses[0] = WalkSmallSelected_Hi
            currentSdAddresses[1] = WalkSmallSelected_Lo 
            break;
        case State::WalkSmallActivated:
            currentSdAddresses[0] = WalkSmallActivated_Hi
            currentSdAddresses[1] = WalkSmallActivated_Lo
            break;
        case State::WalkLargeSelected:
            currentSdAddresses[0] = WalkLargeSelected_Hi
            currentSdAddresses[1] = WalkLargeSelected_Lo 
            break;
        case State::WalkLargeActivated:
            currentSdAddresses[0] = WalkLargeActivated_Hi
            currentSdAddresses[1] = WalkLargeActivated_Lo
            break;

        case State::SingleStep:
            currentSdAddresses[0] = SingleStep_Hi
            currentSdAddresses[1] = SingleStep_Lo  
            break;
        case State::SingleStepSmall:
            currentSdAddresses[0] = SingleStepSmall_Hi
            currentSdAddresses[1] = SingleStep_Lo  
            break;
        case State::SingleStepNormal:
            currentSdAddresses[0] = SingleStepNormal_Hi
            currentSdAddresses[1] = SingleStepNormal_Lo  
            break;
        case State::SingleStepLarge:
            currentSdAddresses[0] = SingleStepLarge_Hi
            currentSdAddresses[1] = SingleStepLarge_Lo  
            break;
        case State::SingleStepSmallSelected:
            currentSdAddresses[0] = SingleStepSmallSelected_Hi
            currentSdAddresses[1] = SingleStepSelected_Lo  
            break;
        case State::SingleStepNormalSelected:
            currentSdAddresses[0] = SingleStepNormalSelected_Hi
            currentSdAddresses[1] = SingleStepNormalSelected_Lo  
            break;
        case State::SingleStepLargeSelected:
            currentSdAddresses[0] = SingleStepLargeSelected_Hi
            currentSdAddresses[1] = SingleStepLargeSelected_Lo  
            break;
        case State::SingleStepSmallActivated:
            currentSdAddresses[0] = SingleStepSmallActivated_Hi
            currentSdAddresses[1] = SingleStepActivated_Lo  
            break;
        case State::SingleStepNormalActivated:
            currentSdAddresses[0] = SingleStepNormalActivated_Hi
            currentSdAddresses[1] = SingleStepNormalActivated_Lo  
            break;
        case State::SingleStepLargeActivated:
            currentSdAddresses[0] = SingleStepLargeActivated_Hi
            currentSdAddresses[1] = SingleStepLargeActivated_Lo  
            break;

        case State::SideStep:
            currentSdAddresses[0] = SideStep_Hi
            currentSdAddresses[1] = SideStep_Lo  
            break;
        case State::SideStepLeft:
            currentSdAddresses[0] = SideStepLeft_Hi
            currentSdAddresses[1] = SideStepLeft_Lo  
            break;
        case State::SideStepRight:
            currentSdAddresses[0] = SideStepRight_Hi
            currentSdAddresses[1] = SideStepRight_Lo  
            break;
        case State::SideStepLeftSelected:
            currentSdAddresses[0] = SideStepLeftSelected_Hi
            currentSdAddresses[1] = SideStepLeftSelected_Lo  
            break;
        case State::SideStepRightSelected:
            currentSdAddresses[0] = SideStepRightSelected_Hi
            currentSdAddresses[1] = SideStepRightSelected_Lo  
            break;
        case State::SideStepLeftActivated:
            currentSdAddresses[0] = SideStepLeftActivated_Hi
            currentSdAddresses[1] = SideStepLeftActivated_Lo  
            break;
        case State::SideStepRightActivated:
            currentSdAddresses[0] = SideStepRightActivated_Hi
            currentSdAddresses[1] = SideStepRightActivated_Lo  
            break;


        default:
            Serial.println("Can't draw this state");
            currentSdAddresses[0] = 0;
            currentSdAddresses[1] = 0;
            break;
    }
    return currentSdAddresses;
}
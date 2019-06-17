#include "StateMachine.h"

// Constructor
StateMachine::StateMachine()
{
    this->currentState = State::HomeSit;
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
            else if(joystickPress == "PUSH"){
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
            else if(joystickPress == "PUSH"){
                this->currentState = State::StandUpSelected;
            }
            break;
        case State::HomeStandStart:
            if(joystickState == "RIGHT"){
                this->currentState = State::TurnOffStart;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::StandUp;
            }
            else if(joystickPress == "PUSH"){
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
            else if(joystickPress == "PUSH"){
                this->currentState = State::TurnOffStartSelected;
            }
            break;

        //Selected
        case State::HomeSitSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeSitActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::HomeSit;
            }
            break;
        case State::StandUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StandUpActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::StandUp;
            }
            break;
        case State::HomeStandStartSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeStandStartActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::HomeStandStart;
            }
            break;
        case State::TurnOffStartSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::TurnOffStartActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::TurnOffStart;
            }
            break;

        //Activated
        case State::HomeSitActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::StandUp; //Automatically
            }
            break;
        case State::StandUpActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::Walk; //Automatically
            }
            break;
        case State::HomeStandStartActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::Walk; //Automatically
            }
            break;
        case State::TurnOffStartActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeSit; //Automatically
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
            else if(joystickPress == "PUSH"){
                this->currentState = State::SitSelected;
            }
            else if(joystickState == "UP"){
                this->currentState = State::Walk;
            
            }
            break;
        case State::HomeStand:
            if(joystickState == "RIGHT"){
                this->currentState = State::TurnOff;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Sit;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::HomeStandSelected;
            }
            else if(joystickState == "UP"){
                this->currentState = State::Walk;
            }
            break;
        case State::TurnOff:
            if(joystickState == "RIGHT"){
                this->currentState = State::Sit;
            }
            else if(joystickState =="LEFT"){
                this->currentState = State::HomeStand;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::TurnOffSelected;
            }
            else if(joystickState == "UP"){
                this->currentState = State::Walk;
            }
            break;

        //Selected
        case State::SitSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SitActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::Sit;
            }
            break;
        case State::HomeStandSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeStandActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::HomeStand;
            }
            break;
        case State::TurnOffSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::TurnOffActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::TurnOff;
            }
            break;

        //Activated
        case State::SitActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::StandUp; //Automatically
            }
            break;
        case State::HomeStandActivated:
            if(triggerPress = "PUSH"){
                this->currentState = State::Walk; //Automatically
            }
            break;
        case State::TurnOffActivated:
            if(triggerPress = "PUSH"){
                this->currentState = State::HomeSit; //Automatically
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
            else if(joystickPress == "PUSH"){
                this->currentState = State::WalkNormal;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
             
            }
            else if(joystickState == "DOWN"){
                this->currentState = State::Sit;
            }
            break;
        case State::SingleStep:
            if(joystickState == "RIGHT"){
                this->currentState = State::SideStep;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Walk;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SingleStepNormal;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->currentState = State::Sit;
            }
            break;
        case State::SideStep:
            if(joystickState == "RIGHT"){
                this->currentState = State::Walk;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SingleStep;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SideStepLeft;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->currentState = State::Sit;
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
            else if(joystickState =="RIGHT"){
                this->currentState = State::WalkLarge;
            }
            else if(joystickState =="LEFT"){
                this->currentState = State::WalkSmall;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::WalkNormalSelected;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::Walk;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->currentState = State::Sit;
            }
            break;
        case State::WalkSmall:
            if(rockerState =="UP"){
                this->currentState = State::WalkNormal;
            }
            else if (joystickState == "RIGHT"){
                this->currentState = State::WalkNormal;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::WalkSmallSelected;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::Walk;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->currentState = State::Sit;
            }
            break;
        case State::WalkLarge:
            if(rockerState =="DOWN"){
                this->currentState = State::WalkNormal;
            }
            else if (joystickState == "LEFT"){
                this->currentState = State::WalkNormal;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::WalkLargeSelected;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::Walk;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->currentState = State::Sit;
            }
            break;
        case State::SingleStepNormal:
            if(rockerState == "DOWN"){
                this->currentState = State::SingleStepSmall;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SingleStepSmall;
            }
            else if(rockerState =="UP"){
                this->currentState = State::SingleStepLarge;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SingleStepLarge;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SingleStepNormalSelected;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::SingleStep;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->currentState = State::Sit;
            }
            break;
        case State::SingleStepSmall:
            if(rockerState =="UP"){
                this->currentState = State::SingleStepNormal;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SingleStepNormal;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SingleStepSmallSelected;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::SingleStep;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->currentState = State::Sit;
            }
            break;
        case State::SingleStepLarge:
            if(rockerState =="DOWN"){
                this->currentState = State::SingleStepNormal;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SingleStepNormal;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SingleStepLargeSelected;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::SingleStep;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->currentState = State::Sit;
            }
            break;
        case State::SideStepLeft:
            if (joystickState == "LEFT"){
                this->currentState = State::SideStepRight;
            }
            else if (joystickState == "RIGHT"){
                this->currentState = State::SideStepRight;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SideStepLeftSelected;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::SideStep;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->currentState = State::Sit;
            }
            break;
        case State::SideStepRight:
            if (joystickState == "LEFT"){
                this->currentState = State::SideStepLeft;
            }
            else if (joystickState == "RIGHT"){
                this->currentState = State::SideStepLeft;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SideStepRightSelected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SideStep;
            }
            else if(joystickState =="UP"){
                this->currentState = rememberStateObstacle;
            }
            else if(joystickState == "DOWN"){
                this->currentState = State::Sit;
            }
            break;
        
        //Selected
        case State::WalkSmallSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkSmallActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::WalkSmall;
            }
            break;
        case State::WalkNormalSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkNormalActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::WalkNormal;
            }
            break;
        case State::WalkLargeSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkLargeActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::WalkLarge;
            }
            break;
        case State::SingleStepSmallSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepSmallActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SingleStepSmall;
            }
            break;
        case State::SingleStepNormalSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepNormalActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SingleStepNormal;
            }
            break;
        case State::SingleStepLargeSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepLargeActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SingleStepLarge;
            }
            break;
        case State::SideStepLeftSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStepLeftActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SideStepLeft;
            }
            break;
        case State::SideStepRightSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStepRightActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::SideStepRight;
            }
            break;

        //Activated
        case State::WalkSmallActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::Walk; //Automatically
            }
            break;
        case State::WalkNormalActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::Walk; //Automatically

            }
            break;
        case State::WalkLargeActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::Walk; //Automatically

            }
            break;
        case State::SingleStepSmallActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStep; //Automatically

            }
            break;
        case State::SingleStepNormalActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStep; //Automatically

            }
            break;
        case State::SingleStepLargeActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStep; //Automatically
            }
            break;
        case State::SideStepLeftActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStep; //Automatically
            }
            break;
        case State::SideStepRightActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStep; //Automatically
            }
            break;

        //Obstacle menu
        //Scroll
        case State::Sofa:
            if(joystickState == "RIGHT"){
                this->currentState = State::RoughTerrain;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Slope;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SofaSit;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            break;
        case State::Slope:
              if(joystickState == "RIGHT"){
                this->currentState = State::Sofa;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::TiltedPath;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SlopeUp;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            break; 
        case State::RoughTerrain:
              if(joystickState == "RIGHT"){
                this->currentState = State::Stairs;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Sofa;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::RoughTerrainSelected;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            break; 
        case State::TiltedPath:
              if(joystickState == "RIGHT"){
                this->currentState = State::Slope;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Stairs;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::TiltedPathSelected;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            break; 
        case State::Stairs:
              if(joystickState == "RIGHT"){
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::RoughTerrain;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::StairsUp;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            break;

        //Submenu obstacles
        case State::SofaSit:
            if(joystickPress == "PUSH"){
                this->currentState = State::SofaSitSelected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::Sofa;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SofaStandUp;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SofaStandUp;
            }
            break;
        case State::SofaStandUp:
            if(joystickPress == "PUSH"){
                this->currentState = State::SofaStandUpSelected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::Sofa;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SofaSit;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SofaSit;
            }
            break;
        case State::SlopeUp:
            if(joystickPress == "PUSH"){
                this->currentState = State::SlopeUpSelected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::Slope;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SlopeDown;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SlopeDownFinal;
            }
            break;
        case State::SlopeDown:
            if(joystickPress == "PUSH"){
                this->currentState = State::SlopeDownSelected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::Slope;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SlopeDownFinal;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SlopeUp;
            }
            break;
        case State::SlopeDownFinal:
            if(joystickPress == "PUSH"){
                this->currentState = State::SlopeDownFinalSelected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::Slope;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SlopeUp;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SlopeDown;
            }
            break; 
        case State::StairsUp:
            if(joystickPress == "PUSH"){
                this->currentState = State::StairsUpSelected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::Stairs;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::StairsDown;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::StairsDownFinal;
            }
            break;
        case State::StairsDown:
            if(joystickPress == "PUSH"){
                this->currentState = State::StairsDownSelected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::Stairs;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::StairsDownFinal;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::StairsUp;
            }
            break;
        case State::StairsDownFinal:
            if(joystickPress == "PUSH"){
                this->currentState = State::StairsDownFinalSelected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::Stairs;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::StairsUp;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::StairsDown;
            }
            break;

            //Selected and activated submenus

            //Sofa
        case State::SofaSitSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SofaSitActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SofaSit;
            }
            break;
        case State::SofaSitActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SofaStandUp; //Automatically
            }
            break;
        case State::SofaStandUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SofaStandUpActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SofaStandUp;
            }
            break;
        case State::SofaStandUpActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkObstacle; //Automatically
                this->rememberStateObstacleWIB = State::RoughTerrain;
            }
            break;


        //Slope
        case State::SlopeUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SlopeUpActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SlopeUp;
            }
            break;
        case State::SlopeUpActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::SlopeDown; //Automatically
                this->currentState = State::WalkObstacle;
            }
            break;
        case State::SlopeDownSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SlopeDownActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SlopeDown;
            }
            break;
        case State::SlopeDownActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::Sofa; //Automatically
                this->currentState = State::WalkObstacle;
            }
            break;
        case State::SlopeDownFinalSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SlopeDownFinalActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SlopeDownFinal;
            }
            break;
        case State::SlopeDownFinalActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::Sofa; //Automatically
                this->currentState = State::WalkObstacle;
            }
            break;

        //Rough Terrain
        case State::RoughTerrainSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::RoughTerrainActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::RoughTerrain; 
            }
            break;
        case State::RoughTerrainActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::Stairs;//Automatically
                this->currentState = State::WalkObstacle;
            }
            break;

        //Tilted Path
        case State::TiltedPathSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::TiltedPathActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::TiltedPath; 
            }
            break;
        case State::TiltedPathActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::Slope;    
                this->currentState = State::WalkObstacle; //Automatically
            }
            break;

        //Stairs
        case State::StairsUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StairsUpActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::StairsUp;
            }
            break;

        case State::StairsUpActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::StairsDown;
                this->currentState = State::WalkObstacle; //Automatically
            }
            break;
        case State::StairsDownSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StairsDownActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::StairsDown;
            }
            break;

        case State::StairsDownActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::TiltedPath;
                this->currentState = State::WalkObstacle; //Automatically
            }
            break;
        case State::StairsDownFinalSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StairsDownFinalActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::StairsDownFinal;
            }
            break;

        case State::StairsDownFinalActivated:
            if(triggerPress == "PUSH"){
                this->rememberStateObstacleWIB = State::TiltedPath;
                this->currentState = State::WalkObstacle; //Automatically
            }
            break;

     
        //Walk in between obstacles
        case State::WalkObstacle:
            if(joystickPress == "PUSH"){
                this->currentState = State::WalkObstacleNormal;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SingleStepObstacle;
            }
            break;
        case State::SingleStepObstacle:
            if(joystickPress == "PUSH"){
                this->currentState = State::SingleStepObstacleNormal;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = rememberStateObstacleWIB;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::WalkObstacle;
            }
            break;

        //Choose step size
        case State::WalkObstacleNormal:
            if(rockerState == "DOWN"){
                this->currentState = State::WalkObstacleSmall;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::WalkObstacleSmall;
            }
            else if(rockerState =="UP"){
                this->currentState = State::WalkObstacleLarge;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::WalkObstacleLarge;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::WalkObstacleNormalSelected;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::WalkObstacle;
            }
            break;
        case State::WalkObstacleSmall:
            if(rockerState =="UP"){
                this->currentState = State::WalkObstacleNormal;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::WalkObstacleNormal;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::WalkObstacleSmallSelected;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::WalkObstacle;
            }
            break;
        case State::WalkObstacleLarge:
            if(rockerState =="DOWN"){
                this->currentState = State::WalkObstacleNormal;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::WalkObstacleNormal;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::WalkObstacleLargeSelected;
            }
            else if(joystickState == "DOUBLE"){
                this->currentState = State::WalkObstacle;
            }
            break;
        case State::SingleStepObstacleNormal:
            if(rockerState == "DOWN"){
                this->currentState = State::SingleStepObstacleSmall;
            }
            else if(rockerState =="UP"){
                this->currentState = State::SingleStepObstacleLarge;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SingleStepObstacleSmall;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SingleStepObstacleLarge;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SingleStepObstacleNormalSelected;
            }
            else if(joystickState == "DOUBLE"){
                this->currentState = State::SingleStepObstacle;
            }
            break;
        case State::SingleStepObstacleSmall:
            if(rockerState =="UP"){
                this->currentState = State::SingleStepObstacleNormal;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SingleStepObstacleNormal;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SingleStepObstacleSmallSelected;
            }
            else if(joystickState == "DOUBLE"){
                this->currentState = State::SingleStepObstacle;
            }
            break;
        case State::SingleStepObstacleLarge:
            if(rockerState =="DOWN"){
                this->currentState = State::SingleStepObstacleNormal;
            }
            else if (joystickState == "LEFT"){
                this->currentState = State::SingleStepObstacleNormal;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SingleStepObstacleLargeSelected;
            }
            else if(joystickState == "DOUBLE"){
                this->currentState = State::SingleStepObstacle;
            }
            break;
        
        
        //Selected
        case State::WalkObstacleSmallSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkObstacleSmallActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::WalkObstacleSmall;
            }
            break;
        case State::WalkObstacleNormalSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkObstacleNormalActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::WalkObstacleNormal;
            }
            break;
        case State::WalkObstacleLargeSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkObstacleLargeActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::WalkObstacleLarge;
            }
            break;
        case State::SingleStepObstacleSmallSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepObstacleSmallActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SingleStepObstacleSmall;
            }
            break;
        case State::SingleStepObstacleNormalSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepObstacleNormalActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::SingleStepObstacleNormal;
            }
            break;
        case State::SingleStepObstacleLargeSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepObstacleLargeActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::SingleStepObstacleLarge;
            }
            break;

        //Activated
        case State::WalkObstacleSmallActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepObstacle; //Automatically
            }
            break;
        case State::WalkObstacleNormalActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepObstacle; //Automatically

            }
            break;
        case State::WalkObstacleLargeActivated:
            if(triggerPress == "PUSH"){
                this->currentState = State::SingleStepObstacle; //Automatically

            }
            break;
        case State::SingleStepObstacleSmallActivated:
            if(triggerPress == "PUSH"){
                this->currentState = rememberStateObstacleWIB; //Automatically

            }
            break;
        case State::SingleStepObstacleNormalActivated:
            if(triggerPress == "PUSH"){
                this->currentState = rememberStateObstacleWIB; //Automatically

            }
            break;
        case State::SingleStepObstacleLargeActivated:
            if(triggerPress == "PUSH"){
                this->currentState = rememberStateObstacleWIB; //Automatically
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
        //Start menu
        case State::HomeSit:
            currentSdAddresses[0] = HomeSit_Hi;
            currentSdAddresses[1] = HomeSit_Lo;
            break;
        case State::HomeSitSelected:
            currentSdAddresses[0] = HomeSitSelected_Hi;
            currentSdAddresses[1] = HomeSitSelected_Lo;
            break;
        case State::HomeSitActivated:
            currentSdAddresses[0] = HomeSitActivated_Hi;
            currentSdAddresses[1] = HomeSitActivated_Lo;
            break;
        case State::StandUp:
            currentSdAddresses[0] = StandUp_Hi;
            currentSdAddresses[1] = StandUp_Lo;           
            break;
        case State::StandUpSelected:
            currentSdAddresses[0] = StandUpSelected_Hi;
            currentSdAddresses[1] = StandUpSelected_Lo;
            break;
        case State::StandUpActivated:
            currentSdAddresses[0] = StandUpActivated_Hi;
            currentSdAddresses[1] = StandUpActivated_Lo;
            break;
        case State::HomeStandStart:
            currentSdAddresses[0] = HomeStandStart_Hi;
            currentSdAddresses[1] = HomeStandStart_Lo; 
            break;
        case State::HomeStandStartSelected:
            currentSdAddresses[0] = HomeStandStartSelected_Hi;
            currentSdAddresses[1] = HomeStandStartSelected_Lo;  
            break;
        case State::HomeStandStartActivated:
            currentSdAddresses[0] = HomeStandStartActivated_Hi;
            currentSdAddresses[1] = HomeStandStartActivated_Lo;  
            break;
        case State::TurnOffStart:
            currentSdAddresses[0] = TurnOffStart_Hi; 
            currentSdAddresses[1] = TurnOffStart_Lo; 
            break;
        case State::TurnOffStartSelected:
            currentSdAddresses[0] = TurnOffStartSelected_Hi; 
            currentSdAddresses[1] = TurnOffStartSelected_Lo; 
            break;
        case State::TurnOffStartActivated:
            currentSdAddresses[0] = TurnOffStartActivated_Hi; 
            currentSdAddresses[1] = TurnOffStartActivated_Lo; 
            break;


        //Sit menu
        case State::Sit:
            currentSdAddresses[0] = Sit_Hi;
            currentSdAddresses[1] = Sit_Lo;   
            break;
        case State::SitSelected:
            currentSdAddresses[0] = SitSelected_Hi;
            currentSdAddresses[1] = SitSelected_Lo;
            break;
        case State::SitActivated:
            currentSdAddresses[0] = SitActivated_Hi;
            currentSdAddresses[1] = SitActivated_Lo;   
            break;
        case State::HomeStand:
            currentSdAddresses[0] = HomeStand_Hi;
            currentSdAddresses[1] = HomeStand_Lo;
            break;
        case State::HomeStandSelected:
            currentSdAddresses[0] = HomeStandSelected_Hi;
            currentSdAddresses[1] = HomeStandSelected_Lo;
            break;
        case State::HomeStandActivated:
            currentSdAddresses[0] = HomeStandActivated_Hi;
            currentSdAddresses[1] = HomeStandActivated_Lo;
            break;
        case State::TurnOff:
            currentSdAddresses[0] = TurnOff_Hi;
            currentSdAddresses[1] = TurnOff_Lo; 
            break;
        case State::TurnOffSelected:
            currentSdAddresses[0] = TurnOffSelected_Hi;
            currentSdAddresses[1] = TurnOffSelected_Lo;
            break;
        case State::TurnOffActivated:
            currentSdAddresses[0] = TurnOffActivated_Hi;
            currentSdAddresses[1] = TurnOffActivated_Lo;
            break;

        //Obstacle menu
        case State::Sofa:
            currentSdAddresses[0] = Sofa_Hi;
            currentSdAddresses[1] = Sofa_Lo;    
            break;
        case State::SofaSit:
            currentSdAddresses[0] = SofaSit_Hi;
            currentSdAddresses[1] = SofaSit_Lo;    
            break;
        case State::SofaSitSelected:
            currentSdAddresses[0] = SofaSitSelected_Hi;
            currentSdAddresses[1] = SofaSitSelected_Lo;    
            break;
        case State::SofaSitActivated:
            currentSdAddresses[0] = SofaSitActivated_Hi;
            currentSdAddresses[1] = SofaSitActivated_Lo;   
            break;
        case State::SofaStandUp:  
            currentSdAddresses[0] = SofaStandUp_Hi;
            currentSdAddresses[1] = SofaStandUp_Lo;    
            break;
        case State::SofaStandUpSelected:
            currentSdAddresses[0] = SofaStandUpSelected_Hi;
            currentSdAddresses[1] = SofaStandUpSelected_Lo;   
            break;
        case State::SofaStandUpActivated:
            currentSdAddresses[0] = SofaStandUpActivated_Hi;
            currentSdAddresses[1] = SofaStandUpActivated_Lo;   
            break;

        case State::Slope:
            currentSdAddresses[0] = Slope_Hi;
            currentSdAddresses[1] = Slope_Lo;    
            break;
        case State::SlopeUp:
            currentSdAddresses[0] = SlopeUp_Hi;
            currentSdAddresses[1] = SlopeUp_Lo;    
            break;
        case State::SlopeUpSelected:
            currentSdAddresses[0] = SlopeUpSelected_Hi;
            currentSdAddresses[1] = SlopeUpSelected_Lo;    
            break;
        case State::SlopeUpActivated:
            currentSdAddresses[0] = SlopeUpActivated_Hi;
            currentSdAddresses[1] = SlopeUpActivated_Lo;    
            break;
        case State::SlopeDown:
            currentSdAddresses[0] = SlopeDown_Hi;
            currentSdAddresses[1] = SlopeDown_Lo;    
            break;
        case State::SlopeDownSelected:
            currentSdAddresses[0] = SlopeDownSelected_Hi;
            currentSdAddresses[1] = SlopeDownSelected_Lo;    
            break;
        case State::SlopeDownActivated:
            currentSdAddresses[0] = SlopeDownActivated_Hi;
            currentSdAddresses[1] = SlopeDownActivated_Lo;   
            break;
        case State::SlopeDownFinal:
            currentSdAddresses[0] = SlopeDownFinal_Hi;
            currentSdAddresses[1] = SlopeDownFinal_Lo;    
            break;
        case State::SlopeDownFinalSelected:
            currentSdAddresses[0] = SlopeDownFinalSelected_Hi;
            currentSdAddresses[1] = SlopeDownFinalSelected_Lo;    
            break;
        case State::SlopeDownFinalActivated:
            currentSdAddresses[0] = SlopeDownFinalActivated_Hi;
            currentSdAddresses[1] = SlopeDownFinalActivated_Lo;   
            break;

        case State::RoughTerrain:
            currentSdAddresses[0] = RoughTerrain_Hi;
            currentSdAddresses[1] = RoughTerrain_Lo;    
            break;    
        case State::RoughTerrainSelected:
            currentSdAddresses[0] = RoughTerrainSelected_Hi;
            currentSdAddresses[1] = RoughTerrainSelected_Lo;   
            break;    
        case State::RoughTerrainActivated:
            currentSdAddresses[0] = RoughTerrainActivated_Hi;
            currentSdAddresses[1] = RoughTerrainActivated_Lo;    
            break;  

        case State::TiltedPath:
            currentSdAddresses[0] = TiltedPath_Hi;
            currentSdAddresses[1] = TiltedPath_Lo;    
            break;  
        case State::TiltedPathSelected:
            currentSdAddresses[0] = TiltedPathSelected_Hi;
            currentSdAddresses[1] = TiltedPathSelected_Lo;   
            break;  
        case State::TiltedPathActivated:
            currentSdAddresses[0] = TiltedPathActivated_Hi;
            currentSdAddresses[1] = TiltedPathActivated_Lo;   
            break;  
          
        case State::Stairs:
            currentSdAddresses[0] = Stairs_Hi;
            currentSdAddresses[1] = Stairs_Lo;    
            break;
        case State::StairsUp:
            currentSdAddresses[0] = StairsUp_Hi;
            currentSdAddresses[1] = StairsUp_Lo;
            break;
        case State::StairsUpSelected:
            currentSdAddresses[0] = StairsUpSelected_Hi;
            currentSdAddresses[1] = StairsUpSelected_Lo; 
            break;
        case State::StairsUpActivated:
            currentSdAddresses[0] = StairsUpActivated_Hi;
            currentSdAddresses[1] = StairsUpActivated_Lo;
            break;
        case State::StairsDown:
            currentSdAddresses[0] = StairsDown_Hi;
            currentSdAddresses[1] = StairsDown_Lo;
            break;
        case State::StairsDownSelected:
            currentSdAddresses[0] = StairsDownSelected_Hi;
            currentSdAddresses[1] = StairsDownSelected_Lo; 
            break;
        case State::StairsDownActivated:
            currentSdAddresses[0] = StairsDownActivated_Hi;
            currentSdAddresses[1] = StairsDownActivated_Lo;
            break;
        case State::StairsDownFinal:
            currentSdAddresses[0] = StairsDownFinal_Hi;
            currentSdAddresses[1] = StairsDownFinal_Lo;
            break;
        case State::StairsDownFinalSelected:
            currentSdAddresses[0] = StairsDownFinalSelected_Hi;
            currentSdAddresses[1] = StairsDownFinalSelected_Lo; 
            break;
        case State::StairsDownFinalActivated:
            currentSdAddresses[0] = StairsDownFinalActivated_Hi;
            currentSdAddresses[1] = StairsDownFinalActivated_Lo;
            break;
        
        case State::WalkObstacle:
            currentSdAddresses[0] = WalkObstacle_Hi; 
            currentSdAddresses[1] = WalkObstacle_Lo;  
            break;
        case State::WalkObstacleSmall:
            currentSdAddresses[0] = WalkObstacleSmall_Hi; 
            currentSdAddresses[1] = WalkObstacleSmall_Lo;  
            break;
        case State::WalkObstacleNormal:
            currentSdAddresses[0] = WalkObstacleNormal_Hi; 
            currentSdAddresses[1] = WalkObstacleNormal_Lo;  
            break;
        case State::WalkObstacleLarge:
            currentSdAddresses[0] = WalkObstacleLarge_Hi; 
            currentSdAddresses[1] = WalkObstacleLarge_Lo;  
            break;
        case State::WalkObstacleNormalSelected:
            currentSdAddresses[0] = WalkObstacleNormalSelected_Hi;
            currentSdAddresses[1] = WalkObstacleNormalSelected_Lo; 
            break;
        case State::WalkObstacleSmallSelected:
            currentSdAddresses[0] = WalkObstacleSmallSelected_Hi;
            currentSdAddresses[1] = WalkObstacleSmallSelected_Lo; 
            break;
        case State::WalkObstacleLargeSelected:
            currentSdAddresses[0] = WalkObstacleLargeSelected_Hi;
            currentSdAddresses[1] = WalkObstacleLargeSelected_Lo; 
            break;
        case State::WalkObstacleNormalActivated:
            currentSdAddresses[0] = WalkObstacleNormalActivated_Hi;
            currentSdAddresses[1] = WalkObstacleNormalActivated_Lo; 
            break;
        case State::WalkObstacleSmallActivated:
            currentSdAddresses[0] = WalkObstacleSmallActivated_Hi;
            currentSdAddresses[1] = WalkObstacleSmallActivated_Lo; 
            break;
        case State::WalkObstacleLargeActivated:
            currentSdAddresses[0] = WalkObstacleLargeActivated_Hi;
            currentSdAddresses[1] = WalkObstacleLargeActivated_Lo; 
            break;

        case State::SingleStepObstacle:
            currentSdAddresses[0] = SingleStepObstacle_Hi; 
            currentSdAddresses[1] = SingleStepObstacle_Lo;  
            break;
        case State::SingleStepObstacleNormal:
            currentSdAddresses[0] = SingleStepObstacleNormal_Hi; 
            currentSdAddresses[1] = SingleStepObstacleNormal_Lo;  
            break;
        case State::SingleStepObstacleSmall:
            currentSdAddresses[0] = SingleStepObstacleSmall_Hi; 
            currentSdAddresses[1] = SingleStepObstacleSmall_Lo;  
            break;
        case State::SingleStepObstacleLarge:
            currentSdAddresses[0] = SingleStepObstacleLarge_Hi; 
            currentSdAddresses[1] = SingleStepObstacleLarge_Lo;  
            break;
        case State::SingleStepObstacleNormalSelected:
            currentSdAddresses[0] = SingleStepObstacleNormalSelected_Hi;
            currentSdAddresses[1] = SingleStepObstacleNormalSelected_Lo; 
            break;
        case State::SingleStepObstacleSmallSelected:
            currentSdAddresses[0] = SingleStepObstacleSmallSelected_Hi;
            currentSdAddresses[1] = SingleStepObstacleSmallSelected_Lo; 
            break;
        case State::SingleStepObstacleLargeSelected:
            currentSdAddresses[0] = SingleStepObstacleLargeSelected_Hi;
            currentSdAddresses[1] = SingleStepObstacleLargeSelected_Lo; 
            break;
        case State::SingleStepObstacleNormalActivated:
            currentSdAddresses[0] = SingleStepObstacleNormalActivated_Hi;
            currentSdAddresses[1] = SingleStepObstacleNormalActivated_Lo; 
            break;
        case State::SingleStepObstacleSmallActivated:
            currentSdAddresses[0] = SingleStepObstacleSmallActivated_Hi;
            currentSdAddresses[1] = SingleStepObstacleSmallActivated_Lo; 
            break;
        case State::SingleStepObstacleLargeActivated:
            currentSdAddresses[0] = SingleStepObstacleLargeActivated_Hi;
            currentSdAddresses[1] = SingleStepObstacleLargeActivated_Lo; 
            break;
    

        //WIB
        case State::Walk:
            currentSdAddresses[0] = Walk_Hi;
            currentSdAddresses[1] = Walk_Lo; 
            break;
        case State::WalkSmall:
            currentSdAddresses[0] = WalkSmall_Hi; 
            currentSdAddresses[1] = WalkSmall_Lo;   
            break;
        case State::WalkNormal:
            currentSdAddresses[0] = WalkNormal_Hi;
            currentSdAddresses[1] = WalkNormal_Lo;  
            break;
        case State::WalkLarge:
            currentSdAddresses[0] = WalkLarge_Hi;
            currentSdAddresses[1] = WalkLarge_Lo;  
            break;
        case State::WalkNormalSelected:
            currentSdAddresses[0] = WalkNormalSelected_Hi;
            currentSdAddresses[1] = WalkNormalSelected_Lo;
            break;
        case State::WalkNormalActivated:
            currentSdAddresses[0] = WalkNormalActivated_Hi;
            currentSdAddresses[1] = WalkNormalActivated_Lo;
            break;
        case State::WalkSmallSelected:
            currentSdAddresses[0] = WalkSmallSelected_Hi;
            currentSdAddresses[1] = WalkSmallSelected_Lo; 
            break;
        case State::WalkSmallActivated:
            currentSdAddresses[0] = WalkSmallActivated_Hi;
            currentSdAddresses[1] = WalkSmallActivated_Lo;
            break;
        case State::WalkLargeSelected:
            currentSdAddresses[0] = WalkLargeSelected_Hi;
            currentSdAddresses[1] = WalkLargeSelected_Lo; 
            break;
        case State::WalkLargeActivated:
            currentSdAddresses[0] = WalkLargeActivated_Hi;
            currentSdAddresses[1] = WalkLargeActivated_Lo;
            break;

        case State::SingleStep:
            currentSdAddresses[0] = SingleStep_Hi;
            currentSdAddresses[1] = SingleStep_Lo; 
            break;
        case State::SingleStepSmall:
            currentSdAddresses[0] = SingleStepSmall_Hi;
            currentSdAddresses[1] = SingleStepSmall_Lo;  
            break;
        case State::SingleStepNormal:
            currentSdAddresses[0] = SingleStepNormal_Hi;
            currentSdAddresses[1] = SingleStepNormal_Lo;  
            break;
        case State::SingleStepLarge:
            currentSdAddresses[0] = SingleStepLarge_Hi;
            currentSdAddresses[1] = SingleStepLarge_Lo; 
            break;
        case State::SingleStepSmallSelected:
            currentSdAddresses[0] = SingleStepSmallSelected_Hi;
            currentSdAddresses[1] = SingleStepSmallSelected_Lo;  
            break;
        case State::SingleStepNormalSelected:
            currentSdAddresses[0] = SingleStepNormalSelected_Hi;
            currentSdAddresses[1] = SingleStepNormalSelected_Lo;  
            break;
        case State::SingleStepLargeSelected:
            currentSdAddresses[0] = SingleStepLargeSelected_Hi;
            currentSdAddresses[1] = SingleStepLargeSelected_Lo;  
            break;
        case State::SingleStepSmallActivated:
            currentSdAddresses[0] = SingleStepSmallActivated_Hi;
            currentSdAddresses[1] = SingleStepSmallActivated_Lo;  
            break;
        case State::SingleStepNormalActivated:
            currentSdAddresses[0] = SingleStepNormalActivated_Hi;
            currentSdAddresses[1] = SingleStepNormalActivated_Lo;  
            break;
        case State::SingleStepLargeActivated:
            currentSdAddresses[0] = SingleStepLargeActivated_Hi;
            currentSdAddresses[1] = SingleStepLargeActivated_Lo;  
            break;

        case State::SideStep:
            currentSdAddresses[0] = SideStep_Hi;
            currentSdAddresses[1] = SideStep_Lo;  
            break;
        case State::SideStepLeft:
            currentSdAddresses[0] = SideStepLeft_Hi;
            currentSdAddresses[1] = SideStepLeft_Lo;  
            break;
        case State::SideStepRight:
            currentSdAddresses[0] = SideStepRight_Hi;
            currentSdAddresses[1] = SideStepRight_Lo;  
            break;
        case State::SideStepLeftSelected:
            currentSdAddresses[0] = SideStepLeftSelected_Hi;
            currentSdAddresses[1] = SideStepLeftSelected_Lo;  
            break;
        case State::SideStepRightSelected:
            currentSdAddresses[0] = SideStepRightSelected_Hi;
            currentSdAddresses[1] = SideStepRightSelected_Lo;  
            break;
        case State::SideStepLeftActivated:
            currentSdAddresses[0] = SideStepLeftActivated_Hi;
            currentSdAddresses[1] = SideStepLeftActivated_Lo;  
            break;
        case State::SideStepRightActivated:
            currentSdAddresses[0] = SideStepRightActivated_Hi;
            currentSdAddresses[1] = SideStepRightActivated_Lo; 
            break;
        default:
            Serial.println("Can't draw this state");
            currentSdAddresses[0] = 0;
            currentSdAddresses[1] = 0;
            break;
    }
    return currentSdAddresses;
}
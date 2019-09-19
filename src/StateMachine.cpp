#include <StateMachine.h>

// Constructor
StateMachine::StateMachine()
{
    this->currentState = State::HomeSitStart;
    this->rememberStateObstacle = State::Sofa;
    this->rememberStateObstacleWIB = State::TiltedPath;
    stateToGaitMapping[State::HomeSitStartActivated] = "home_sit";
    stateToGaitMapping[State::StandUpActivated] = "gait_stand";
    stateToGaitMapping[State::HomeStandStartActivated] = "home_stand";

    stateToGaitMapping[State::WalkNormalActivated] = "gait_walk";
    stateToGaitMapping[State::WalkSmallActivated] = "gait_walk_small";
    stateToGaitMapping[State::SingleStepNormalActivated] = "gait_single_step_normal"; 
    stateToGaitMapping[State::SingleStepSmallActivated] = "gait_single_step_small";
    
    stateToGaitMapping[State::SitActivated] = "gait_sit";
    stateToGaitMapping[State::HomeSitActivated] = "home_sit";
    stateToGaitMapping[State::HomeStandActivated] = "home_stand";

    stateToGaitMapping[State::WalkObstacleNormalActivated] = "gait_walk";
    stateToGaitMapping[State::WalkObstacleSmallActivated] = "gait_walk_small";
    stateToGaitMapping[State::SingleStepObstacleNormalActivated] = "gait_single_step_normal";
    stateToGaitMapping[State::SingleStepObstacleSmallActivated] = "gait_single_step_small";

    stateToGaitMapping[State::SofaSitActivated] = "gait_sofa_sit";
    stateToGaitMapping[State::SofaStandUpActivated] = "gait_sofa_stand";

    stateToGaitMapping[State::StairsUpActivated] = "gait_stairs_up";
    stateToGaitMapping[State::StairsDownActivated] = "gait_stairs_down";

    stateToGaitMapping[State::SideStepLeftNormalActivated] = "gait_side_step_left";
    stateToGaitMapping[State::SideStepRightNormalActivated] = "gait_side_step_right";
    stateToGaitMapping[State::SideStepLeftSmallActivated] = "gait_side_step_left_small";
    stateToGaitMapping[State::SideStepRightSmallActivated] = "gait_side_step_right_small";

    stateToGaitMapping[State::TiltedPathStartHomeToMin5Activated] = "gait_set_ankle_from_2_5_to_min5";
    stateToGaitMapping[State::FirstStartStepActivated] = "gait_tilted_path_first_starting_step";
    stateToGaitMapping[State::SecondStartStepActivated] = "gait_tilted_path_second_starting_step";
    stateToGaitMapping[State::HomeStandToMin10Activated] = "gait_set_ankle_from_min5_to_min10";
    stateToGaitMapping[State::TiltedPathMiddleStepActivated] = "gait_tilted_path_middle_step";
    stateToGaitMapping[State::HomeStandToMin5Activated] = "gait_set_ankle_from_min10_to_min5";
    stateToGaitMapping[State::FirstEndStepActivated] = "gait_tilted_path_first_ending_step";
    stateToGaitMapping[State::SecondEndStepActivated] = "gait_tilted_path_second_ending_step";
    stateToGaitMapping[State::HomeForWalk25Activated] = "gait_set_ankle_from_min5_to_2_5";
}

State StateMachine::getCurrentState(){
    return this->currentState;
}

std::string StateMachine::getGaitNameOfState(State state){
  if(stateToGaitMapping.count(state) > 0){
    return stateToGaitMapping[state];
  }
  return "";
}

// Updates the current state based on the button inputs
void StateMachine::updateState(String joystickState, String joystickPress, String rockerState, String triggerPress){
    switch (this->currentState)
    {
        //Start menu
        //Scroll
        case State::HomeSitStart:
            if(joystickState == "RIGHT"){
                this->currentState = State::StandUp;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::TurnOffStart;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::HomeSitStartSelected;
            }
            break;
        case State::StandUp:
            if(joystickState == "RIGHT"){
                this->currentState = State::HomeStandStart;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::HomeSitStart;
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
                this->currentState = State::HomeSitStart;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::HomeStandStart;
            }
            break;

        //Selected
        case State::HomeSitStartSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeSitStartActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::HomeSitStart;
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
    

        //Activated
        case State::HomeSitStartActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::StandUp; //Automatically
            }
            break;
        case State::StandUpActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::Walk; //Automatically
            }
            break;
        case State::HomeStandStartActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::Walk; //Automatically
            }
            break;
        
        
        //Sit menu
        //Scroll
        case State::Sit:
            if(joystickState == "RIGHT"){
                this->currentState = State::HomeSit;
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

        case State::HomeSit:
            if(joystickState == "RIGHT"){
                this->currentState = State::HomeStand;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Sit;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::HomeSitSelected;
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
                this->currentState = State::HomeSit;
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
        case State::HomeSitSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeSitActivated;
            }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::HomeSit;
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
    

        //Activated
        case State::SitActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::StandUp; //Automatically
            }
            break;
        case State::HomeSitActivated:
            if(triggerPress = "EXIT_GAIT"){
                this->currentState = State::StandUp; //Automatically
            }
            break;
        case State::HomeStandActivated:
            if(triggerPress = "EXIT_GAIT"){
                this->currentState = State::Walk; //Automatically
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
    //        else if(joystickPress == "PUSH"){
    //            this->currentState = State::WalkLargeSelected;
    //        }
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
    //        else if(joystickPress == "PUSH"){
    //            this->currentState = State::SingleStepLargeSelected;
    //        }
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
                this->currentState = State::SideStepLeftNormal;
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
                this->currentState = State::SideStepRightNormal;
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

        case State::SideStepLeftNormal:
            if (joystickState == "LEFT"){
                this->currentState = State::SideStepLeftSmall;
            }
            else if (joystickState == "RIGHT"){
                this->currentState = State::SideStepLeftSmall;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SideStepLeftNormalSelected;
           }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::SideStepLeft;
            }
            break;

        case State::SideStepLeftSmall:
            if (joystickState == "LEFT"){
                this->currentState = State::SideStepLeftNormal;
            }
            else if (joystickState == "RIGHT"){
                this->currentState = State::SideStepLeftNormal;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SideStepLeftSmallSelected;
           }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::SideStepLeft;
            }
            break;

        case State::SideStepRightNormal:
            if (joystickState == "LEFT"){
                this->currentState = State::SideStepRightSmall;
            }
            else if (joystickState == "RIGHT"){
                this->currentState = State::SideStepRightSmall;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SideStepRightNormalSelected;
           }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::SideStepRight;
            }
            break;

        case State::SideStepRightSmall:
            if (joystickState == "LEFT"){
                this->currentState = State::SideStepRightNormal;
            }
            else if (joystickState == "RIGHT"){
                this->currentState = State::SideStepRightNormal;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SideStepRightSmallSelected;
           }
            else if(joystickPress == "DOUBLE"){
                this->currentState = State::SideStepRight;
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
        // case State::WalkLargeSelected:
        //     if(triggerPress == "PUSH"){
        //         this->currentState = State::WalkLargeActivated;
        //     }
        //     else if(joystickPress == "DOUBLE"){ 
        //         this->currentState = State::WalkLarge;
        //     }
        //     break;
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
        // case State::SingleStepLargeSelected:
        //     if(triggerPress == "PUSH"){
        //         this->currentState = State::SingleStepLargeActivated;
        //     }
        //     else if(joystickPress == "DOUBLE"){ 
        //         this->currentState = State::SingleStepLarge;
        //     }
        //     break;
        case State::SideStepLeftNormalSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStepLeftNormalActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SideStepLeftNormal;
            }
            break;

        case State::SideStepLeftSmallSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStepLeftSmallActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SideStepLeftSmall;
            }
            break;

        case State::SideStepRightNormalSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStepRightNormalActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SideStepRightNormal;
            }
            break;

        case State::SideStepRightSmallSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SideStepRightSmallActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SideStepRightSmall;
            }
            break;


        //Activated
        case State::WalkSmallActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::Walk; //Automatically
            }
            break;
        case State::WalkNormalActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::Walk; //Automatically
            }
            break;
        // case State::WalkLargeActivated:
        //     if(triggerPress == "EXIT_GAIT"){
        //         this->currentState = State::Walk; //Automatically
        //     }
        //     break;
        case State::SingleStepSmallActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::SingleStep; //Automatically
            }
            break;
        case State::SingleStepNormalActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::SingleStep; //Automatically
            }
            break;
        // case State::SingleStepLargeActivated:
        //     if(triggerPress == "EXIT_GAIT"){
        //         this->currentState = State::SingleStep; //Automatically
        //     }
        //     break;
        case State::SideStepLeftNormalActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::SideStep; //Automatically
            }
            break;
        case State::SideStepLeftSmallActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::SideStep; //Automatically
            }
            break;    
        case State::SideStepRightSmallActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::SideStep; //Automatically
            }
            break;
        case State::SideStepRightNormalActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::SideStep; //Automatically
            }
            break;

        //Obstacle menu
        //Scroll
        case State::Sofa:
            if(joystickState == "RIGHT"){
                this->currentState = State::Stairs;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::TiltedPath;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::SofaSit;
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
                this->currentState = State::Sofa;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::StairsUp;
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            break;
        
        case State::TiltedPath:
              if(joystickState == "RIGHT"){
                this->currentState = State::Sofa;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::Stairs;
            }
            else if(joystickPress == "PUSH"){
                this->currentState = State::TiltedPathStartHomeToMin5;             
            }
            else if(joystickState =="DOWN"){
                this->rememberStateObstacle = currentState;
                this->currentState = State::Walk;
            }
            break; 
        

        //Submenu obstacles
        //Sofa
        case State::SofaSit:
            if(joystickPress == "PUSH"){
                this->currentState = State::SofaSitSelected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::Sofa;
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
            else if(joystickState == "RIGHT"){
                this->currentState = State::SofaSit;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SofaSit;
            }
            break;
        
        case State::SofaSitSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::SofaSitActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::SofaSit;
            }
            break;
        
        case State::SofaSitActivated:
            if(triggerPress == "EXIT_GAIT"){
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
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::WalkObstacle; //Automatically
                this->rememberStateObstacleWIB = State::Stairs;
            }
            break;
       
        
            
        
        //Stairs
        case State::StairsUp:
            if(joystickPress == "PUSH"){
                this->currentState = State::StairsUpSelected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::Stairs;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::StairsDown;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::StairsDown;             // old: this->currentState = State::StairsDownFinal;
            }
            break;

        case State::StairsDown:
            if(joystickPress == "PUSH"){
                this->currentState = State::StairsDownSelected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::Stairs;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::StairsUp;               // old: this->currentState = State::StairsDownFinal;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::StairsUp;
            }
            break;
            
        case State::StairsUpSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::StairsUpActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::StairsUp;
            }
            break;

        case State::StairsUpActivated:
            if(triggerPress == "EXIT_GAIT"){
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
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::WalkObstacle; //Automatically
                this->rememberStateObstacleWIB = State::TiltedPath;
            }
            break;
        // case State::StairsDownFinalSelected:
        //     if(triggerPress == "PUSH"){
        //         this->currentState = State::StairsDownFinalActivated;
        //     }
        //     else if(joystickPress == "DOUBLE"){
        //         this->currentState = State::StairsDownFinal;
        //     }
        //     break;
        // case State::StairsDownFinalActivated:
        //     if(triggerPress == "EXIT_GAIT"){
        //         this->rememberStateObstacleWIB = State::TiltedPath;
        //         this->currentState = State::WalkObstacle; //Automatically
        //     }
        //     break;

        

        // case State::StairsDownFinal:
        //     if(joystickPress == "PUSH"){
        //         this->currentState = State::StairsDownFinalSelected;
        //     }
        //     else if(joystickPress == "DOUBLE"){ 
        //         this->currentState = State::Stairs;
        //     }
        //     else if(joystickState == "RIGHT"){
        //         this->currentState = State::StairsUp;
        //     }
        //     else if(joystickState == "LEFT"){
        //         this->currentState = State::StairsDown;
        //     }
        //     break;

            //Selected and activated submenus

     //Tilted Path    
        case State::TiltedPathStartHomeToMin5:                     // first home ankles to -5 before going on the tilted path
            if(joystickPress == "PUSH"){
                this->currentState = State::TiltedPathStartHomeToMin5Selected;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::HomeForWalk25;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::FirstStartStep;
            }
            break;

        case State::TiltedPathStartHomeToMin5Selected:                  // we want the first gait to be selected & activated, to others only need to be triggered
            if(triggerPress == "PUSH"){
                this->currentState = State::TiltedPathStartHomeToMin5Activated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::TiltedPathStartHomeToMin5;
            }
            break;
        
        case State::TiltedPathStartHomeToMin5Activated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::FirstStartStep; //Automatically
            }
            break;    


        case State::FirstStartStep:                             // first step on the tilted path
            if(triggerPress == "PUSH"){
                this->currentState = State::FirstStartStepActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::TiltedPathStartHomeToMin5;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SecondStartStep;
            }
            break;
            
        case State::FirstStartStepActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::SecondStartStep; //Automatically
            }
            break; 
        
       
            
        case State::SecondStartStep:                        // second step on tilted path, after this gait we will stand on the middle part
            if(triggerPress == "PUSH"){
                this->currentState = State::SecondStartStepActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::FirstStartStep;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::HomeStandToMin10;
            }
            break;
            
        case State::SecondStartStepActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::HomeStandToMin10; //Automatically
            }
            break; 
            

        case State::HomeStandToMin10:                       // before doing side steps on the middle part we have to home to an ankle position -10
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeStandToMin10Activated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SecondStartStep;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::TiltedPathMiddleStep;
            }
            break;
            
        case State::HomeStandToMin10Activated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::TiltedPathMiddleStep; //Automatically
            }
            break; 
            

        case State::TiltedPathMiddleStep:                   // after activating a side step for the middle part you can do this action again, when you are at the end you have to push the joystick to the right. 
            if(triggerPress == "PUSH"){
                this->currentState = State::TiltedPathMiddleStepActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::HomeStandToMin10;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::HomeStandToMin5;
            }
            break;

        case State::TiltedPathMiddleStepActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::TiltedPathMiddleStep; //Automatically
            }
            break; 

        case State::HomeStandToMin5:                    // before going off the tilted path we have to home ankles to -5
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeStandToMin5Activated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::TiltedPathMiddleStep;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::FirstEndStep;
            }
            break;

        case State::HomeStandToMin5Activated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::FirstEndStep; //Automatically
            }
            break; 

        case State::FirstEndStep:                           // first step for the end of the tilted path
            if(triggerPress == "PUSH"){
                this->currentState = State::FirstEndStepActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::HomeStandToMin5;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::SecondEndStep;
            }
            break; 

        case State::FirstEndStepActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::SecondEndStep; //Automatically
            }
            break; 

        case State::SecondEndStep:                          // second step for the end of the tilted path
            if(triggerPress == "PUSH"){
                this->currentState = State::SecondEndStepActivated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::FirstEndStep;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::HomeForWalk25;
            }
            break;    

        case State::SecondEndStepActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::HomeForWalk25; //Automatically
            }
            break; 

        case State::HomeForWalk25:                          // We are now finished with the tilted path, but before we can walk we have to set ankles back to 2.5 for walking -> home.
            if(triggerPress == "PUSH"){
                this->currentState = State::HomeForWalk25Activated;
            }
            else if(joystickPress == "DOUBLE"){ 
                this->currentState = State::TiltedPath;
            }
            else if(joystickState == "LEFT"){
                this->currentState = State::SecondEndStep;
            }
            else if(joystickState == "RIGHT"){
                this->currentState = State::TiltedPathStartHomeToMin5;
            }
            break;

        case State::HomeForWalk25Activated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::WalkObstacle; //Automatically
                this->rememberStateObstacleWIB = State::Sofa;
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
    //        else if(joystickPress == "PUSH"){
    //            this->currentState = State::WalkObstacleLargeSelected;
    //        }
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
    //        else if(joystickPress == "PUSH"){
    //            this->currentState = State::SingleStepObstacleLargeSelected;
    //        }
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
        // case State::WalkObstacleLargeSelected:
        //     if(triggerPress == "PUSH"){
        //         this->currentState = State::WalkObstacleLargeActivated;
        //     }
        //     else if(joystickPress == "DOUBLE"){ 
        //         this->currentState = State::WalkObstacleLarge;
        //     }
        //     break;
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
        // case State::SingleStepObstacleLargeSelected:
        //     if(triggerPress == "PUSH"){
        //         this->currentState = State::SingleStepObstacleLargeActivated;
        //     }
        //     else if(joystickPress == "DOUBLE"){
        //         this->currentState = State::SingleStepObstacleLarge;
        //     }
        //     break;

        //Activated
        case State::WalkObstacleSmallActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::SingleStepObstacle; //Automatically
            }
            break;
        case State::WalkObstacleNormalActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = State::SingleStepObstacle; //Automatically
            }
            break;
        // case State::WalkObstacleLargeActivated:
        //     if(triggerPress == "EXIT_GAIT"){
        //         this->currentState = State::SingleStepObstacle; //Automatically
        //     }
        //     break;
        case State::SingleStepObstacleSmallActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = rememberStateObstacleWIB; //Automatically
            }
            break;
        case State::SingleStepObstacleNormalActivated:
            if(triggerPress == "EXIT_GAIT"){
                this->currentState = rememberStateObstacleWIB; //Automatically
            }
            break;
        // case State::SingleStepObstacleLargeActivated:
        //     if(triggerPress == "EXIT_GAIT"){
        //         this->currentState = rememberStateObstacleWIB; //Automatically
        //     }
        //     break;

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
        case State::HomeSitStart:
            currentSdAddresses[0] = HomeSitStart_Hi;
            currentSdAddresses[1] = HomeSitStart_Lo;
            break;
        case State::HomeSitStartSelected:
            currentSdAddresses[0] = HomeSitStartSelected_Hi;
            currentSdAddresses[1] = HomeSitStartSelected_Lo;
            break;
        case State::HomeSitStartActivated:
            currentSdAddresses[0] = HomeSitStartActivated_Hi;
            currentSdAddresses[1] = HomeSitStartActivated_Lo;
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


        case State::TiltedPath:
            currentSdAddresses[0] = TiltedPath_Hi;
            currentSdAddresses[1] = TiltedPath_Lo;    
            break;  
        case State::TiltedPathStartHomeToMin5:
            currentSdAddresses[0] = TiltedPathStartHomeToMin5_Hi;
            currentSdAddresses[1] = TiltedPathStartHomeToMin5_Lo;    
            break; 
        case State::TiltedPathStartHomeToMin5Selected:
            currentSdAddresses[0] = TiltedPathStartHomeToMin5Selected_Hi;
            currentSdAddresses[1] = TiltedPathStartHomeToMin5Selected_Lo;    
            break;    
        case State::TiltedPathStartHomeToMin5Activated:
            currentSdAddresses[0] = TiltedPathStartHomeToMin5Activated_Hi;
            currentSdAddresses[1] = TiltedPathStartHomeToMin5Activated_Lo;    
            break;    
        case State::FirstStartStep:
            currentSdAddresses[0] = FirstStartStep_Hi;
            currentSdAddresses[1] = FirstStartStep_Lo;    
            break;
        case State::FirstStartStepActivated:
            currentSdAddresses[0] = FirstStartStepActivated_Hi;
            currentSdAddresses[1] = FirstStartStepActivated_Lo;    
            break;   
        case State::SecondStartStep:
            currentSdAddresses[0] = SecondStartStep_Hi;
            currentSdAddresses[1] = SecondStartStep_Lo;    
            break; 
        case State::SecondStartStepActivated:
            currentSdAddresses[0] = SecondStartStepActivated_Hi;
            currentSdAddresses[1] = SecondStartStepActivated_Lo;    
            break;       
        case State::HomeStandToMin10:
            currentSdAddresses[0] = HomeStandToMin10_Hi;
            currentSdAddresses[1] = HomeStandToMin10_Lo;    
            break; 
        case State::HomeStandToMin10Activated:
            currentSdAddresses[0] = HomeStandToMin10Activated_Hi;
            currentSdAddresses[1] = HomeStandToMin10Activated_Lo;    
            break;     
        case State::TiltedPathMiddleStep:
            currentSdAddresses[0] = TiltedPathMiddleStep_Hi;
            currentSdAddresses[1] = TiltedPathMiddleStep_Lo;    
            break; 
        case State::TiltedPathMiddleStepActivated:
            currentSdAddresses[0] = TiltedPathMiddleStepActivated_Hi;
            currentSdAddresses[1] = TiltedPathMiddleStepActivated_Lo;    
            break;
        case State::HomeStandToMin5:
            currentSdAddresses[0] = HomeStandToMin5_Hi;
            currentSdAddresses[1] = HomeStandToMin5_Lo;    
            break; 
        case State::HomeStandToMin5Activated:
            currentSdAddresses[0] = HomeStandToMin5Activated_Hi;
            currentSdAddresses[1] = HomeStandToMin5Activated_Lo;    
            break;
        case State::FirstEndStep:
            currentSdAddresses[0] = FirstEndStep_Hi;
            currentSdAddresses[1] = FirstEndStep_Lo;    
            break; 
        case State::FirstEndStepActivated:
            currentSdAddresses[0] = FirstEndStepActivated_Hi;
            currentSdAddresses[1] = FirstEndStepActivated_Lo;    
            break;
        case State::SecondEndStep:
            currentSdAddresses[0] = SecondEndStep_Hi;
            currentSdAddresses[1] = SecondEndStep_Lo;    
            break; 
        case State::SecondEndStepActivated:
            currentSdAddresses[0] = SecondEndStepActivated_Hi;
            currentSdAddresses[1] = SecondEndStepActivated_Lo;    
            break;    
        case State::HomeForWalk25:
            currentSdAddresses[0] = HomeForWalk25_Hi;
            currentSdAddresses[1] = HomeForWalk25_Lo;    
            break; 
        case State::HomeForWalk25Activated:
            currentSdAddresses[0] = HomeForWalk25Activated_Hi;
            currentSdAddresses[1] = HomeForWalk25Activated_Lo;    
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
        // case State::StairsDownFinal:
        //     currentSdAddresses[0] = StairsDownFinal_Hi;
        //     currentSdAddresses[1] = StairsDownFinal_Lo;
        //     break;
        // case State::StairsDownFinalSelected:
        //     currentSdAddresses[0] = StairsDownFinalSelected_Hi;
        //     currentSdAddresses[1] = StairsDownFinalSelected_Lo; 
        //     break;
        // case State::StairsDownFinalActivated:
        //     currentSdAddresses[0] = StairsDownFinalActivated_Hi;
        //     currentSdAddresses[1] = StairsDownFinalActivated_Lo;
        //     break;



//WIB
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
        case State::WalkObstacleNormalActivated:
            currentSdAddresses[0] = WalkObstacleNormalActivated_Hi;
            currentSdAddresses[1] = WalkObstacleNormalActivated_Lo; 
            break;
        case State::WalkObstacleSmallActivated:
            currentSdAddresses[0] = WalkObstacleSmallActivated_Hi;
            currentSdAddresses[1] = WalkObstacleSmallActivated_Lo; 
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
        case State::SingleStepObstacleNormalActivated:
            currentSdAddresses[0] = SingleStepObstacleNormalActivated_Hi;
            currentSdAddresses[1] = SingleStepObstacleNormalActivated_Lo; 
            break;
        case State::SingleStepObstacleSmallActivated:
            currentSdAddresses[0] = SingleStepObstacleSmallActivated_Hi;
            currentSdAddresses[1] = SingleStepObstacleSmallActivated_Lo; 
            break;
    

        //Walk Menu
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
        case State::SingleStepSmallActivated:
            currentSdAddresses[0] = SingleStepSmallActivated_Hi;
            currentSdAddresses[1] = SingleStepSmallActivated_Lo;  
            break;
        case State::SingleStepNormalActivated:
            currentSdAddresses[0] = SingleStepNormalActivated_Hi;
            currentSdAddresses[1] = SingleStepNormalActivated_Lo;  
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
        case State::SideStepLeftSmall:
            currentSdAddresses[0] = SideStepLeftSmall_Hi;
            currentSdAddresses[1] = SideStepLeftSmall_Lo;  
            break;
        case State::SideStepLeftSmallSelected:
            currentSdAddresses[0] = SideStepLeftSmallSelected_Hi;
            currentSdAddresses[1] = SideStepLeftSmallSelected_Lo;  
            break;
        case State::SideStepLeftSmallActivated:
            currentSdAddresses[0] = SideStepLeftSmallActivated_Hi;
            currentSdAddresses[1] = SideStepLeftSmallActivated_Lo;  
            break;   
        case State::SideStepLeftNormal:
            currentSdAddresses[0] = SideStepLeftNormal_Hi;
            currentSdAddresses[1] = SideStepLeftNormal_Lo;  
            break;
        case State::SideStepLeftNormalSelected:
            currentSdAddresses[0] = SideStepLeftNormalSelected_Hi;
            currentSdAddresses[1] = SideStepLeftNormalSelected_Lo; 
            break;
        case State::SideStepLeftNormalActivated:
            currentSdAddresses[0] = SideStepLeftNormalActivated_Hi;
            currentSdAddresses[1] = SideStepLeftNormalActivated_Lo;
            break;
        case State::SideStepRightSmall:
            currentSdAddresses[0] = SideStepRightSmall_Hi;
            currentSdAddresses[1] = SideStepRightSmall_Lo;  
            break;
        case State::SideStepRightSmallSelected:
            currentSdAddresses[0] = SideStepRightSmallSelected_Hi;
            currentSdAddresses[1] = SideStepRightSmallSelected_Lo;  
            break;
        case State::SideStepRightSmallActivated:
            currentSdAddresses[0] = SideStepRightSmallActivated_Hi;
            currentSdAddresses[1] = SideStepRightSmallActivated_Lo;  
            break;   
        case State::SideStepRightNormal:
            currentSdAddresses[0] = SideStepRightNormal_Hi;
            currentSdAddresses[1] = SideStepRightNormal_Lo;  
            break;
        case State::SideStepRightNormalSelected:
            currentSdAddresses[0] = SideStepRightNormalSelected_Hi;
            currentSdAddresses[1] = SideStepRightNormalSelected_Lo;  
            break;
        case State::SideStepRightNormalActivated:
            currentSdAddresses[0] = SideStepRightSmallActivated_Hi;
            currentSdAddresses[1] = SideStepRightSmallActivated_Lo;  
            break;  
        default:
            Serial.println("Can't draw this state");
            currentSdAddresses[0] = 0;
            currentSdAddresses[1] = 0;
            break;
    }
    return currentSdAddresses;
}

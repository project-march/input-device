#include "StateMachine.h"
#include "SD_sector_addresses.h"

// Constructor
StateMachine::StateMachine()
{
    this->currentState = State::ScrollSlopeUp;

    // Fill scroll states
    this->scrollStates.push_back(State::ScrollSofa);
    this->scrollStates.push_back(State::ScrollCups);
    this->scrollStates.push_back(State::ScrollSlopeUp);
    this->scrollStates.push_back(State::ScrollStairsUp);
    this->scrollStates.push_back(State::ScrollSit);

    this->currentScrollState = this->scrollStates.begin();
}

// Updates the current state based on the button inputs
void StateMachine::updateState(String joystickState, String joystickPress, String rockerState, String triggerPress){
    switch (this->currentState)
    {
        case State::ScrollSofa:
            // first check if go outside scroll mode, else update scroll state
            this->updateScrollState(joystickState);
            break;
        case State::ScrollCups:
            // first check if go outside scroll mode, else update scroll state
            this->updateScrollState(joystickState);
            break;
        case State::ScrollSlopeUp:
            // first check if go outside scroll mode, else update scroll state
            this->updateScrollState(joystickState);
            break;
        case State::ScrollStairsUp:
            // first check if go outside scroll mode, else update scroll state
            this->updateScrollState(joystickState);
            break;
        case State::ScrollSit:
            // first check if go outside scroll mode, else update scroll state
            this->updateScrollState(joystickState);
            break;
        case State::Walk:
            if(joystickPress == "PUSH"){
                this->currentState = State::WalkSelected;
            }
        case State::WalkSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkActivated;
            }
            break;
        case State::WalkActivated:
            if(triggerPress == "PUSH"){
                this->currentState = *this->currentScrollState;
            }
            break;
        default:
            break;
    }
}

void StateMachine::updateScrollState(String joystickState){
    if (joystickState == "UP"){
        this->currentState = State::Walk;
    }
    else if(joystickState == "LEFT"){
        if(this->currentScrollState == this->scrollStates.begin()){
            this->currentScrollState = this->scrollStates.end();
        }
        else{
            this->currentScrollState--;
        }
        this->currentState = *this->currentScrollState;
    }
    else if(joystickState == "RIGHT"){
        if(this->currentScrollState == this->scrollStates.end()){
            this->currentScrollState = this->scrollStates.begin();
        }
        else{
            this->currentScrollState++;
        }
        this->currentState = *this->currentScrollState;
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
        default:
            currentSdAddresses[0] = BStepS_Hi;
            currentSdAddresses[1] = BStepS_Lo;
            break;
    }
    return currentSdAddresses;
}
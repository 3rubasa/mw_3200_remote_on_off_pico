
#include "ssihandlerstate.h"

SSIHandlerState::SSIHandlerState(std::shared_ptr<IState> state) :
    m_state(state) 
{

}

std::string SSIHandlerState::ProcessRequest() {
    if (m_state->GetState()) {
        return "{\"state\": \"on\"}";
    } else {
        return "{\"state\": \"off\"}";
    }
}
#pragma once

#include "include/interfaces.h"
#include "interfaces.h"
#include <memory>

class GetStateHandler : public mw_tools::servers::ISSIHandler {
public:
    GetStateHandler(std::shared_ptr<IState> state);

    virtual std::string ProcessRequest();
private:
    std::shared_ptr<IState> m_state;
};
/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

#include "creds.h"

#include "state.h"
#include "getstatehandler.h"
#include "setstatehandler.h"

#include "include/core.h"
#include "include/wifi.h"
#include "include/interfaces.h"
#include "include/ssiserver.h"
#include "include/postserver.h"

#define CONTROL_PIN 0

int main() {
  mw_tools::core::Init();

  mw_tools::wifi::Connect(WIFI_SSID, WIFI_PASSWORD, 30000);
  printf("WIFI Connected! \n");

  std::shared_ptr<IState> state = std::shared_ptr<IState>(new State{false, CONTROL_PIN});
  std::shared_ptr<mw_tools::servers::ISSIHandler> getStateHandler 
      = std::shared_ptr<mw_tools::servers::ISSIHandler>(new GetStateHandler{state});

  std::shared_ptr<mw_tools::servers::ISSIServer> ssiServer 
      = std::shared_ptr<mw_tools::servers::ISSIServer>(new mw_tools::servers::SSIServer());
  ssiServer->RegisterHandler("state", getStateHandler);
  ssiServer->Start();

  std::shared_ptr<mw_tools::servers::IPostHandler> setStateHandler 
      = std::shared_ptr<mw_tools::servers::IPostHandler>(new SetStateHandler{state});

  std::shared_ptr<mw_tools::servers::IPostServer> postServer 
      = std::shared_ptr<mw_tools::servers::IPostServer>(new mw_tools::servers::PostServer());
  postServer->RegisterHandler("/state", setStateHandler);
  postServer->Start();

  while (true) {
    sleep_ms(1000);
  }

  return 0;
}
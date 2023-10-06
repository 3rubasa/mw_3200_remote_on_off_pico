/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
// #include <iostream>
// #include <sstream>
// #include <memory>

// //#include "hardware/gpio.h"
// // #include "hardware/adc.h"
//#include "pico/cyw43_arch.h"

// // #include "lwip/apps/httpd.h"
// // #include "lwipopts.h"

#include "creds.h"

// // #include "lwip/apps/httpd.h"
// // #include "lwip/def.h"
// // #include "lwip/mem.h"

// #include <stdio.h>
// #include <string.h>

#include "state.h"
#include "ssihandlerstate.h"

#include "include/core.h"
#include "include/wifi.h"
#include "include/interfaces.h"
#include "include/ssiserver.h"

// #define DEBUG_printf printf

// static bool g_state = false;

// #define CONTROL_PIN 0

int main() {
  mw_tools::core::Init();

  sleep_ms(5000);

  mw_tools::wifi::Connect(WIFI_SSID, WIFI_PASSWORD, 30000);
  printf("WIFI Connected! \n");
    
    // // gpio_init(CONTROL_PIN);
    // // gpio_set_dir(CONTROL_PIN, GPIO_OUT);
    // // gpio_put(CONTROL_PIN, 0);

  std::shared_ptr<IState> state = std::shared_ptr<IState>(new State{false});
  std::shared_ptr<ISSIHandler> stateHandler = std::shared_ptr<ISSIHandler>(new SSIHandlerState{state});

  std::shared_ptr<ISSIServer> ssiServer = std::shared_ptr<ISSIServer>(new SSIServer());
  ssiServer->RegisterHandler("state", stateHandler);
  ssiServer->Start();
    // // Initialise web server
    

    // //ssi_init(&g_state); 
    // //printf("SSI Handler initialised\n");

  while (true) {
    sleep_ms(1000);
  }

    return 0;
}

// err_t
// httpd_post_begin(void *connection, const char *uri, const char *http_request,
//                  u16_t http_request_len, int content_len, char *response_uri,
//                  u16_t response_uri_len, u8_t *post_auto_wnd)
// {
//   LWIP_UNUSED_ARG(connection);
//   LWIP_UNUSED_ARG(http_request);
//   LWIP_UNUSED_ARG(http_request_len);
//   LWIP_UNUSED_ARG(content_len);
//   LWIP_UNUSED_ARG(post_auto_wnd);
//   printf("httpd_post_begin:\n");
//   if (memcmp(uri, "/on", 4) == 0) {
//     printf("ON\n");
//     gpio_put(CONTROL_PIN, 1);
//     cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
//     g_state = true;
//     snprintf(response_uri, response_uri_len, "/loginfail.html");
//     return ERR_OK;
//   } 
//   else if(memcmp(uri, "/off", 5) == 0) {
//     printf("OFF\n");
//     gpio_put(CONTROL_PIN, 0);
//     cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
//     g_state = false;
//     snprintf(response_uri, response_uri_len, "/loginfail.html");
//     return ERR_OK;
//   } else {
//     printf("UNKNOWN COMMAND: ");
//     printf(uri);
//     printf("\n");
//     return ERR_VAL;
//   }
// }

// err_t
// httpd_post_receive_data(void *connection, struct pbuf *p)
// {
//     printf("httpd_post_receive_data\n");
//     return ERR_OK;
// }

// void
// httpd_post_finished(void *connection, char *response_uri, u16_t response_uri_len)
// {
//   printf("httpd_post_finished\n");
//   snprintf(response_uri, response_uri_len, "/result.html");
// }
//
// Created by lucas on 12/27/18.
//

#ifndef INC_3X7DIGITDISPLAY_WEBSERVER_H
#define INC_3X7DIGITDISPLAY_WEBSERVER_H

#include <ESP8266WebServer.h>
#include "State.h"
#include "WifiConfig.h"
#include "StorageManager.h"
/**
 * Defines the callbacks for the webserver
 */



/**
 * The ESP8266WebServer register callbacks of type func<void(void)>
 * so the WebServer.cpp registers these callbacks.
 * @param s
 * @param config
 */
void registerWebserver(State *state, WifiConfig *wifiConfig);

void handleIncomingClients();

#endif //INC_3X7DIGITDISPLAY_WEBSERVER_H

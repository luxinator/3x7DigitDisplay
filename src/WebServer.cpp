//
// Created by lucas on 12/30/18.
//

#include "WebServer.h"
#include "State.h"
#include "WifiConfig.h"
#include "StorageManager.h"

State *local_state;

WifiConfig *local_wifiConfig;

ESP8266WebServer server(80);

StorageManager *local_store;

void serverHome() {
  String webString = "";
  webString = webString
      + "<!DOCTYPE html>"
      + "<html><body>"
      + " <form action=\"/\" method=\"post\">\n"
      + "  <div>\n"
      + "   <label>TimeCorrection</label>\n"
      + R"( <input name="TimeCorrection" type="number" min="-12" max="12" value=")"
      + String(local_state->time_correction) + "\">\n "
      + "  </div>\n "
      + "  <div>\n"
      + "   <label>Time Displayed on</label>\n"
      + R"( <input name="TimeDispl" type="number" "min="0" max="10" value=")"
      + String(local_state->TimeDispl) + "\">\n "
      + "  </div>\n "
      + "  <div>\n"
      + "   <label>Seconds Displayed on</label>\n"
      + R"( <input name="SecsDispl" type="number" min="0" max="10" value=")"
      + String(local_state->SecsDispl) + "\">\n"
      + "  </div>\n"
      + "  <div>\n"
      + "   <label>Date Displayed on</label>\n"
      + R"( <input name="DateDispl" type="number" min="0" max="10" value=")"
      + String(local_state->DateDispl) + "\">\n"
      + "  </div>\n "
      + "  <div>\n"
      + "   <label>Year Displayed on</label>\n"
      + R"( <input name="YearDispl" type="number" min="0" max="10" value=")"
      + String(local_state->YearDispl) + "\">\n"
      + "  </div>\n "
      + "  <div>\n"
      + "   <label>Display Brightness</label>\n"
      + R"( <input name="brightnes" type="number" min="0" max="16" value=")"
      + String(local_state->brightnes) + "\">\n"
      + "  </div>\n "
      + R"(<button type="submit">Submit</button>)"
      + " </form>"
      + "</body></html>";

  server.send(200, "text/html", webString);
}

void handlePost() {
  Serial.println("Received a post!");

  if (server.hasArg("TimeDispl"))
    local_state->TimeDispl = (uint8_t) server.arg("TimeDispl").toInt();

  if (server.hasArg("SecsDispl"))
    local_state->SecsDispl = (uint8_t) server.arg("SecsDispl").toInt();

  if (server.hasArg("DateDispl"))
    local_state->DateDispl = (uint8_t) server.arg("DateDispl").toInt();

  if (server.hasArg("YearDispl"))
    local_state->YearDispl = (uint8_t) server.arg("YearDispl").toInt();

  if (server.hasArg("brightnes"))
    local_state->brightnes = (uint8_t) server.arg("brightnes").toInt();

  if (server.hasArg("TimeCorrection"))
    local_state->time_correction = (int8_t) server.arg("TimeCorrection").toInt();

  Serial.printf("ClockState:"
                "\n TimeDispl: %d"
                "\n SecsDispl: %d"
                "\n DateDispl: %d"
                "\n YearDispl: %d"
                "\n brightnes: %d"
                "\n time_correction: %d\n",
                local_state->TimeDispl,
                local_state->SecsDispl,
                local_state->DateDispl,
                local_state->YearDispl,
                local_state->brightnes,
                local_state->time_correction);

  serverHome();
}

void registerWebserver(State *s, WifiConfig *config, StorageManager *storageManager) {

  local_state = s;
  local_wifiConfig = config;
  local_store = storageManager;

  server.on("/", HTTP_GET, serverHome);
  server.on("/", HTTP_POST, handlePost);

  server.begin();
  Serial.println("HTTP server started");
}

void handleIncomingClients() {
  server.handleClient();
}

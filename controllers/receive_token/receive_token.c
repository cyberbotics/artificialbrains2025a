/*
 * Copyright 1996-2026 Cyberbotics Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Description: Sample e-puck controller that receives a secret token from
 *              the embedding web page (index.html) through the Webots
 *              streaming WebSocket and prints it on stdout.
 */

#include <stdio.h>
#include <string.h>

#include <webots/plugins/robot_window/robot_wwi.h>
#include <webots/robot.h>

int main(int argc, char **argv) {
  wb_robot_init();
  const int time_step = (int)wb_robot_get_basic_time_step();

  printf("Token receiver controller started, waiting for token...\n");
  fflush(stdout);

  while (wb_robot_step(time_step) != -1) {
    const char *message;
    while ((message = wb_robot_wwi_receive_text())) {
      if (strncmp(message, "token:", 6) == 0)
        printf("Received secret token: %s\n", message + 6);
      else
        printf("Received message: %s\n", message);
      fflush(stdout);
    }
  }

  wb_robot_cleanup();
  return 0;
}

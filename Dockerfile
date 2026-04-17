FROM cyberbotics/webots.cloud:R2025a-ubuntu22.04
ARG PROJECT_PATH
RUN mkdir -p $PROJECT_PATH
COPY . $PROJECT_PATH
RUN cd $PROJECT_PATH/plugins/robot_windows/custom_robot_window && make clean && make
RUN cd $PROJECT_PATH/controllers/receive_token && make clean && make

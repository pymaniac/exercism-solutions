#pragma once

#include <string>
#include <vector>

namespace speedywagon {

struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};

int uv_light_heuristic(std::vector<int>* data_array);
bool connection_check(const pillar_men_sensor* const sensor);
int activity_counter(pillar_men_sensor sensor_array[], int capacity);
bool alarm_control(const pillar_men_sensor *pdata);
bool uv_alarm(pillar_men_sensor *pdata);
}  // namespace speedywagon

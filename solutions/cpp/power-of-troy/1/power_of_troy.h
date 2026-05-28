#pragma once

#include <string>
#include <memory>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

struct human {
    human() {}
    std::unique_ptr<struct artifact> possession{nullptr};
    std::shared_ptr<struct power> own_power{nullptr};
    std::shared_ptr<struct power> influenced_by{nullptr};
};

    void give_new_artifact(struct human& h, const std::string &name);
    void exchange_artifacts(std::unique_ptr<struct artifact> &a1, std::unique_ptr<struct artifact> &a2);
    void manifest_power(struct human &h, const std::string &effect);
    void use_power(const struct human &caster, struct human &target);
    int power_intensity(const struct human &h);
}  // namespace troy

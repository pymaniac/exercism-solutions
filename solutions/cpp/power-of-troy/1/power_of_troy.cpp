#include "power_of_troy.h"

namespace troy {
        void give_new_artifact(struct human& h, const std::string &name) {
            h.possession = std::make_unique<struct artifact>(name);
        }

        void exchange_artifacts(std::unique_ptr<struct artifact> &a1, std::unique_ptr<struct artifact> &a2) {
            a1.swap(a2);
        }

        void manifest_power(struct human &h, const std::string &effect) {
            h.own_power = std::make_shared<struct power>(effect);
        }

        void use_power(const struct human &caster, struct human &target) {
            target.influenced_by = caster.own_power;
        }

        int power_intensity(const struct human &h) {
            return h.own_power.use_count();
        }
}  // namespace troy

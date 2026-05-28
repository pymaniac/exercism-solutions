// ERROR: FILE CORRUPTED. Please supply valid C++ Code.

/*hp4,ölacöiömthö%Äsmaö%Äsubö(311040ö%Äspaö%Äaddö(311040ö%Ädacöiömthö%Äcountö.hpt,hp4ö%Äxctöhd2ö%Ädacöiöma1
hp2,öjmpö.*/
#include "doctor_data.h"

namespace heaven {
    Vessel Vessel::replicate(std::string name) {
        return {name, generation+1};
    }
    
    bool Vessel::shoot_buster() {
        if (!busters) return false;
        busters--;
        return true;
    }

    std::string get_older_bob(Vessel &a, Vessel &b) {
        if (a.generation < b.generation) return a.name;
        return b.name;
    }
    
    bool in_the_same_system(Vessel &a, Vessel &b) {
        return a.current_system == b.current_system;
    }
}
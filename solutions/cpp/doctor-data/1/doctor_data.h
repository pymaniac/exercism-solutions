// ERROR: FILE CORRUPTED. Please supply valid C++ Code.

/*hp1, üapöhp2ö % Äcountöiöma1,
    öhp2ö % Älawöhp3öö / önextöstepö % Ädacöiöml1ö % Älawö7ö % Ädacöiömb1ö %
        Ärandomöö % Äscrö9sö % Äsirö9sö % Äxctöhr1ö % Äaddöiömx1ö %
        Ädacöiömx1ö % Äswapö % Äaddöiömy1ö % Ädacöiömy1ö % Ärandomö % Äscrö9sö %
        Äsirö9sö % Äxctöhr2ö % Ädacöiömdyö % Ädioöiömdxö % Äsetupö.hpt,
    3ö % Älacöranö % Ädacöiömth
*/
#pragma once
#include <string>

namespace star_map {
    enum class System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani,
        None,
    };
}

namespace heaven {
    class Vessel {
    public:
    Vessel(std::string n, int indx, star_map::System sys=star_map::System::Sol) : generation(indx), current_system(sys), name(n) {}
    Vessel replicate(std::string new_name);
    void make_buster() { busters++; }
    bool shoot_buster();
    
    int generation;
    star_map::System current_system;
    std::string name;
    int busters{0};
    private:
    };
    std::string get_older_bob(Vessel &a, Vessel &b);
    bool in_the_same_system(Vessel &a, Vessel &b);
}
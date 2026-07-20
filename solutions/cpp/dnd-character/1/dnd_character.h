#pragma once

namespace dnd_character {

// TODO: add your solution here
int modifier(int constitution);
int ability();

struct Character {
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int hitpoints;

    Character() {
        strength = ability();
        dexterity = ability();
        constitution = ability();
        intelligence = ability();
        wisdom = ability();
        charisma = ability();
        hitpoints = 10 + modifier(constitution);
    }
};
    
}  // namespace dnd_character

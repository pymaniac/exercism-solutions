#include "zebra_puzzle.h"

#include <string>
#include <cstddef>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>

namespace zebra_puzzle {

#define NATION_LIST \
    X(Norwegian) \
    X(Spaniard) \
    X(Ukrainian) \
    X(Japanese) \
    X(Englishman)
        
enum class color : uint8_t {
    YELLOW, BLUE, IVORY, GREEN, RED
};

enum class nations : uint8_t {
#define X(name) name,
    NATION_LIST
#undef X
};
        
enum class pet : uint8_t {
    DOG, SNAIL, FOX, HORSE, ZEBRA
};

enum class beverage : uint8_t {
    COFFEE, TEA, MILK, OJ, WATER
};

enum class hobby : uint8_t {
    DANCING, PAINTING, READING, FOOTBALL, CHESS
};


static std::string nation_tostring(nations n) {
    switch(n) {
#define X(name) case nations::name: return #name;
        NATION_LIST
#undef X
        default: return "UNKNOWN nation";
    }
}

static int find_indx(int *arr, int val) {
    for(int i = 0; i < 5; i++) {
        if (arr[i] == val) return i;
    }
    std::cout << "not found" << std::endl;
    return 0;
}
    
bool check_nation_colors(int *nationality, int *colors) {
    if (colors[1] != (int)color::BLUE) return false;

    if (find_indx(nationality, (int)nations::Englishman) != find_indx(colors, (int)color::RED)) return false;

    int n = find_indx(nationality, (int)nations::Norwegian);
    int b = find_indx(colors, (int)color::BLUE);
    if ((n+1) != b) return false;
    
    int g = find_indx(colors, (int)color::GREEN);
    int i = find_indx(colors, (int)color::IVORY);
    return (g == i+1);
}

static bool check_ncp(int *nationality, [[maybe_unused]] int *colors, int *pets) {
    if (find_indx(nationality, (int)nations::Spaniard) != find_indx(pets, (int)pet::DOG))
        return false;
    return true;
}

static bool check_ncpd(int *nationality, int *colors, [[maybe_unused]] int *pets, int *drinks) {
    if (drinks[2] != (int)beverage::MILK) return false;
    if (find_indx(colors, (int)color::GREEN) != find_indx(drinks, (int)beverage::COFFEE))
        return false;
    if (find_indx(nationality, (int)nations::Ukrainian) != find_indx(drinks, (int)beverage::TEA))
        return false;
    return true;
}

static bool check_ncpdh(int *nationality, int *colors, int *pets, int *drinks, int *hobbies) {
    int p_indx = find_indx(hobbies, (int)hobby::PAINTING);
    if (find_indx(pets, (int)pet::SNAIL) != find_indx(hobbies, (int)hobby::DANCING))
        return false;
    if (find_indx(colors, (int)color::YELLOW) != p_indx)
        return false;
    int r = find_indx(hobbies, (int)hobby::READING);
    int f = find_indx(pets, (int)pet::FOX);
    int d = std::abs(r -f);
    if (d != 1) return false;
    int h = find_indx(pets, (int)pet::HORSE);
    d = std::abs(p_indx - h);
    if (d != 1) 
        return false;

    if (find_indx(hobbies, (int)hobby::FOOTBALL) != find_indx(drinks, (int)beverage::OJ))
        return false;
    if (find_indx(hobbies, (int)hobby::CHESS) != find_indx(nationality, (int)nations::Japanese))
        return false;

    return true;    
}
    
Solution solve() {
    int nationality[] = {0, 1, 2, 3, 4};
    int colors[] = {0, 1, 2, 3, 4};
    int pets[] = {0, 1, 2, 3, 4};
    int drinks[] = {0, 1, 2, 3, 4};
    int hobbies[] = {0, 1, 2, 3, 4};
    
    nationality[0] = (int)nations::Norwegian;
    colors[1] = (int)color::BLUE;
    drinks[2] = (int)beverage::MILK;
    
    Solution ans;
    do {
        if (nationality[0] !=  (int)nations::Norwegian) continue;
        do {
            if (!check_nation_colors(nationality, colors)) continue;
            do {
                if (!check_ncp(nationality, colors, pets)) continue;
                do {
                    if (!check_ncpd(nationality, colors, pets, drinks)) continue;
                    do {
                        if (!check_ncpdh(nationality, colors, pets, drinks, hobbies)) continue;
                        int i = find_indx(drinks, (int)beverage::WATER);
                        std::cout << i << std::endl;
                        ans.drinksWater = nation_tostring(static_cast<nations>(nationality[i]));                        
                        i = find_indx(pets, (int)pet::ZEBRA);
                        ans.ownsZebra = nation_tostring(static_cast<nations>(nationality[i]));
                    } while (std::next_permutation(hobbies, hobbies+5));
                } while (std::next_permutation(drinks, drinks+5));
            } while (std::next_permutation(pets, pets+5));
        } while (std::next_permutation(colors, colors + 5)); 
    } while (std::next_permutation(nationality, nationality + 5));
    
    return ans;
}
    
}  // namespace zebra_puzzle

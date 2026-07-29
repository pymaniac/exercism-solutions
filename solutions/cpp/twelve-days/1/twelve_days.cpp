#include "twelve_days.h"

#include <vector>

namespace twelve_days {

// TODO: add your solution here
std::string recite(size_t st, size_t end) {
    const std::string starting = "On the xxxyyy day of Christmas my true love gave to me: ";
    
    const std::vector<std::string> verses = {
        "Partridge in a Pear Tree.",
        "Turtle Doves",
        "French Hens",
        "Calling Birds",
        "Gold Rings",
        "Geese-a-Laying",
        "Swans-a-Swimming",
        "Maids-a-Milking",
        "Ladies Dancing",
            "Lords-a-Leaping",
            "Pipers Piping",
            "Drummers Drumming",            
    };

    const std::vector<std::string> conv = {"a", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve"};
    const std::vector<std::string> convist = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"};

    auto generate_string = [&](size_t i) -> std::string {
        constexpr std::string_view target = "xxxyyy";
        std::string text = starting;
        const std::string replacement = convist[i-1];

        static size_t pos = text.find(target);
        text.replace(pos, target.length(), replacement);

        int start_indx = i-1;
        while(i != 0) {
            text += conv[i-1] + " " + verses[i-1];
            if (i > 1 && start_indx)
                text += ", ";
            if (--i == 1 && start_indx)
                text += "and ";
        }

        return text;
    };

    std::string ans;
    for(size_t i = st; i <= end; i++) {
        ans += generate_string(i);
        ans += "\n\n";
    }
    ans.pop_back();
    return ans;
}

}  // namespace twelve_days

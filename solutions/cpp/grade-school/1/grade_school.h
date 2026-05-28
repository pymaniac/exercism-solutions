#pragma once

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

namespace grade_school {

// TODO: add your solution here
    class school {
    public:
        school() {};
        std::map<int, std::vector<std::string>> roster() const {
            return school_roster;
        }
        bool add(const std::string &ns, int grade) {
            auto students = school_roster[grade];
            if (std::find(students.begin(), students.end(), ns) != students.end()) return false;
            school_roster[grade].push_back(ns);
            std::sort(school_roster[grade].begin(), school_roster[grade].end());
            return true;
        }
        const std::vector<std::string> grade(int grade) const {
            try {
                 return school_roster.at(grade);       
            }
            catch(const std::out_of_range& ex)
            {
                std::cout << "1) out_of_range::what(): " << ex.what() << '\n';
                return {};
            }
        }
    
    private:
        std::map<int, std::vector<std::string>> school_roster;
    };

}  // namespace grade_school

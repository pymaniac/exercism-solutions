#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> ans(student_scores.size());
    std::transform(student_scores.begin(), student_scores.end(), ans.begin(), [](double &n) {return static_cast<int>(n);});
    return ans;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    return std::accumulate(student_scores.begin(), student_scores.end(), 0, [](int current_count, int score) {return current_count + (score <= 40 ? 1 : 0);});
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    int add_on = std::round((highest_score - 40)/4);
    return {41, 40+add_on+1, 40+2*add_on+1, 40+3*add_on+1};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    int n = student_scores.size();
    std::vector<std::string> ans;
    for(int i = 0; i < n; i++) 
        ans.push_back(std::to_string(i+1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
    return ans;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    const auto it = std::find(student_scores.begin(), student_scores.end(), 100);
    if (it == student_scores.end()) return "";
    return student_names[std::distance(student_scores.begin(), it)];
}

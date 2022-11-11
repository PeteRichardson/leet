#include "StrongPasswordChecker.hxx"
#include <iostream>

auto count_adds_needed(const std::string& password) -> int {
   // First, get it to the right size.
    // Ignore replacements, because they don't change size.
    auto l = password.size();
    auto adds_needed = 0;
    if (l < 6) {
        adds_needed = 6 - l;
    } else if (l > 20) {
        adds_needed = 20 - l;
    };
    assert (adds_needed <= 6);
    assert (adds_needed >= -30);
    return adds_needed;
}

auto count_categories_needed(const std::string& password) -> int {
   // count lowercase, uppercase & digits
    auto lowercase = 0;
    auto uppercase = 0;
    auto digits = 0;
    auto existing_required_categories = 0;
    for (char c : password) {
        if      (isupper(c)) uppercase++;
        else if (islower(c)) lowercase++;
        else if (isdigit(c)) digits++;
    }
    if (uppercase > 0) existing_required_categories++;
    if (lowercase > 0) existing_required_categories++;
    if (digits > 0) existing_required_categories++;

    auto result = 3 - existing_required_categories;

    return result;
}

auto count_repeating_char_fixups_needed(const std::string &password) {
   auto result = 0;
   auto current_char_count = 1;
   auto n = 0;
   char previous_char = ' '; // this char will not appear in the password string
   for (char c : password) {
        if (c == previous_char) {
            current_char_count++;
            //std::cout << n << ". ccc = " << current_char_count << ", c='" << c << "' - SAME CHAR\n";
        } else {
            //std::cout << n << ". ccc = " << current_char_count << ", c='" << c << "' - NEW CHAR\n";
            result += int(current_char_count / 3);
            current_char_count = 1;
        }
        previous_char = c;
   }
    result += int(current_char_count / 3);
   return result;
}


int Solution::strongPasswordChecker(std::string password) {

    std::cout << "# Checking \"" << password << "\"\n";
    auto adds_needed = count_adds_needed(password);
    auto categories_needed = count_categories_needed(password);
    auto repeating_char_fixups_needed = count_repeating_char_fixups_needed(password);
    std::cout << "adds=" << adds_needed << ", fixups=" << repeating_char_fixups_needed << ", cats=" << categories_needed << "\n";
    
    if (adds_needed >= 3)
        return adds_needed;

    int result = abs(adds_needed);  // we need to make at least this many length changes
    // if we have enough adds, then we can ignore any missing categories
    // and fixups because they can be handled by adding what's needed
    auto max = categories_needed > repeating_char_fixups_needed ? categories_needed : repeating_char_fixups_needed;
    if (adds_needed >= 0) {
        if (adds_needed < max)
            result += max - adds_needed;
    } 
    else if (adds_needed <= 0) {
        if (repeating_char_fixups_needed <= categories_needed) {
            result += categories_needed - repeating_char_fixups_needed;
        // } else if ()
        // result += repeating_char_fixups_needed - abs(adds_needed);
        } else
            result += repeating_char_fixups_needed;
    }

    return result;
}
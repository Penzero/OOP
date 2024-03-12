#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>
#include <string>

// Function to read the distribution of letters from a file and store it into an array
void read_distribution(float distribution[]) {
    std::ifstream file("distribution.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening distribution file." << std::endl;
        return;
    }

    for (int i = 0; i < 26; ++i) {
        file >> distribution[i];
    }

    file.close();
}

// Function to compute the normalized frequency of each character in a text
std::vector<float> compute_normalized_frequency(const std::string& text) {
    std::vector<int> frequency(26, 0);
    std::vector<float> normalized_frequency(26, 0.0);

    int total_letters = 0;
    for (char ch : text) {
        if (std::isalpha(ch)) {
            ch = std::tolower(ch);
            frequency[ch - 'a']++;
            total_letters++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        normalized_frequency[i] = static_cast<float>(frequency[i]) / total_letters;
    }

    return normalized_frequency;
}

// Function to compute the Chi-square distance between two histograms
float compute_CHI_square_distance(std::vector<float>& hist1, std::vector<float>& hist2) {
    float chi_square = 0.0;
    for (int i = 0; i < 26; ++i) {
        if (hist2[i] != 0) {
            float diff = hist1[i] - hist2[i];
            chi_square += (diff * diff) / hist2[i];
        }
    }
    return chi_square;
}

// Function to decrypt Caesar's cipher using frequency analysis
std::string break_caesar_cipher(const std::string& encrypted_text, const float distribution[]) {
    float min_chi_square = std::numeric_limits<float>::max();
    int best_shift = 0;
    std::string decrypted_text;
    std::vector<float> encrypted_hist = compute_normalized_frequency(encrypted_text);
    std::vector<float> distribution_vec(distribution, distribution + 26);

    for (int shift = 0; shift < 26; ++shift) {
        std::string decrypted;
        for (char ch : encrypted_text) {
            if (std::isalpha(ch)) {
                char decrypted_ch = std::tolower(ch);
                int decrypted_index = (decrypted_ch - 'a' - shift + 26) % 26;
                decrypted_ch = 'a' + decrypted_index;
                decrypted.push_back(decrypted_ch);
            } else {
                decrypted.push_back(ch);
            }
        }

        std::vector<float> decrypted_hist = compute_normalized_frequency(decrypted);
        float chi_square = compute_CHI_square_distance(decrypted_hist, distribution_vec);

        if (chi_square < min_chi_square) {
            min_chi_square = chi_square;
            best_shift = shift;
            decrypted_text = decrypted;
        }
    }

    std::cout <<std::endl << "Best Shift: " << best_shift << ", Chi-Square Distance: " << min_chi_square << std::endl;
    return decrypted_text;
}


// Function to print the decrypted text
void print_decrypted_text(const std::string& decrypted_text) {
    std::cout << "Decrypted Text: " << decrypted_text << std::endl;
}

// Function to print the menu
void print_menu() {
    std::cout << "Caesar's Cipher Breaker Application" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "1. Decrypt Caesar's Cipher" << std::endl;
    std::cout << "2. Exit" << std::endl;
}

int main() {
    const std::string distribution_file = "distribution.txt";

    // Read distribution from file
    float distribution[26];
    read_distribution(distribution);

    std::string encrypted_text;
    std::cout << "Enter the encrypted text: ";
    std::cin.ignore(); // Ignores the newline left in the input buffer
    std::getline(std::cin, encrypted_text); // Reads the entire line, including spaces

    int choice;
    do {
        print_menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string decrypted_text = break_caesar_cipher(encrypted_text, distribution);
                print_decrypted_text(decrypted_text);
                char yes;
                std::cout << "Do you want to continue? (y/n): ";
                std::cin >> yes;
                if (yes == 'n') {
                    choice = 2;
                }
                break;
            }
            case 2: {
                std::cout << "Exiting program." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    } while (choice != 2);

    return 0;
}

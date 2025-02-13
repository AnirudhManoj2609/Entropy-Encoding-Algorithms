#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class Huffmann{

private:
    std::string sequence;
    std::vector<char> unique_chars;
    std::unordered_map<char,int> occurrence_map;
    std::unordered_map<char,std::string> binary_sequence;

public:
    Huffmann(const std::string& input) : sequence(input){}

    void find_unique_chars(){
        for(char ch : sequence){
            if(occurrence_map[ch] == 0){
                unique_chars.push_back(ch);
            }
            occurrence_map[ch]++;
        }
    }

    void sort_by_order(){
        
        std::sort(unique_chars.begin(),unique_chars.end(),[this](char a, char b){
            if(occurrence_map[a] != occurrence_map[b]) 
                return occurrence_map[a] > occurrence_map[b]; 
            return sequence.find(a) < sequence.find(b);
        });

        std::cout << "Unique characters sorted by frequency (descending): ";
        for (char ch : unique_chars) {
            std::cout << ch << " ";
        }
        std::cout << std::endl;
    }
    void joining(){
        int start{},add{},index{},len = unique_chars.size();
        for(char ch : unique_chars){
            
            binary_sequence[unique_chars[index]] = std::to_string(add);
            add = add + (index < len - 2)*std::pow(10,index + 1) + (index >= len - 2);
            index += 1;
        }
    }
    void display_occurrences(){

        std::cout << "Character frequencies:\n";
        for(char ch : unique_chars) {
            std::cout << ch << ": " << occurrence_map[ch] << "\n";
        }
    }
    int getUniqueChars(){
        return unique_chars.size();
    }

    void display_code(){
        std::cout << "Code:\n";
        int len = sequence.size();
        for(size_t i{};i < len;++i){
            std::cout << binary_sequence[sequence[i]];
        }
        std::cout << std::endl;
    }
};

int main(){
    std::string sequence;
    std::cout << "Enter the sequence to be encoded: ";
    std::cin >> sequence;

    Huffmann encoder(sequence);
    encoder.find_unique_chars();
    encoder.sort_by_order();
    encoder.display_occurrences();
    encoder.joining();
    encoder.display_code();
}
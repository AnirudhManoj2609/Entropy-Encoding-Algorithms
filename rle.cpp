#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class RLE{

private:
    std::string sequence;
    std::vector<char> set_chars;
    std::vector<int> occurence;

public:
    RLE(const std::string& input) : sequence(input){}

    void find_unique_chars(){
        int len{(int)sequence.size()};
        int flag = 1,index{};
        for(size_t i{};i < len;++i){
            if(flag == 0 && set_chars[index] != sequence[i]){
                flag = 1;
                index += 1;
            }
            if(flag){
                set_chars.push_back(sequence[i]);
                flag = 0;
                occurence.push_back(1);
                continue;
            }
            occurence[index]++;
            
        }
    }

    
    void display_occurrences(){

        std::cout << "Character frequencies:\n";
        int len = set_chars.size();
        for(size_t index{};index < len;++index){
            std::cout << set_chars[index] << ": " << occurence[index] << "\n";
        }
    }
    int getUniqueChars(){
        return set_chars.size();
    }

    void display_code(){
        std::cout << "Code:\n";
        int len = set_chars.size();
        for(size_t i{};i < len;++i){
            std::cout << set_chars[i] << occurence[i];
        }
        std::cout << std::endl;
    }
};

int main(){
    std::string sequence;
    std::cout << "Enter the sequence to be encoded: ";
    std::cin >> sequence;

    RLE encoder(sequence);
    encoder.find_unique_chars();
    encoder.display_occurrences();
    encoder.display_code();
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Shannon{

private:
    std::string sequence;
    std::vector<char> unique_chars;
    std::unordered_map<char,int> occurrence_map;
    std::unordered_map<char,std::string> binary_sequence;

public:
    Shannon(const std::string& input) : sequence(input){}

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
    void cutting(int size,std::string sequence,int first,int last){
         if (first >= last) return; 

        int len = 0, index = first;
        while (index <= last) {
            binary_sequence[unique_chars[index]] += sequence;
            index++;
        }

        index = first;
        while (first != last) {
            if (len >= size / 2) {
                cutting(len, "0", first, index - 1);
                len = occurrence_map[unique_chars[index]];
                cutting(len, "1", index, last);
                break;
            }
            len += occurrence_map[unique_chars[index]];
            index++;
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

    Shannon encoder(sequence);
    encoder.find_unique_chars();
    encoder.sort_by_order();
    encoder.display_occurrences();
    encoder.cutting(sequence.size(),"",0,encoder.getUniqueChars() - 1);
    encoder.display_code();
}
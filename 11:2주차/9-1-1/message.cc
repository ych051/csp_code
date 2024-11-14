#include "message.h"

void MessageBook::AddMessage(int number, const std::string& message){
    messages_[number] = message;
}
        
void MessageBook::DeleteMessage(int number){
    messages_.erase(number);
}

std::vector<int> MessageBook::GetNumbers(){
    std::vector<int> numbers;
    for (const auto& entry : messages_) {
        numbers.push_back(entry.first);
    }
    return numbers;
}
const std::string& MessageBook::GetMessage(int number){
    static const std::string empty_string = "";
    auto it = messages_.find(number);
    if (it != messages_.end()) {
        return it->second;
    }
    return empty_string;
}
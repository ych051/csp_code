#include "reply_admin.h"
#include <iostream>
#include <string>

ReplyAdmin::ReplyAdmin(){
    chats = new std::string[NUM_OF_CHAT];
    num_chats=0;

}

ReplyAdmin::~ReplyAdmin(){
    delete[] chats;
}

int ReplyAdmin::getChatCount(){
    return num_chats;
}

bool ReplyAdmin::addChat(std::string _chat){
    if (num_chats >= NUM_OF_CHAT){
        return false;
    }
    
    chats[num_chats]=_chat;
    num_chats++;
    return true;
}

bool ReplyAdmin::removeChat(int _index){
    if (_index < 0 || _index >= num_chats){
        return false;
    }
    for (int i = _index; i < num_chats - 1;i++){
        chats[i] = chats[i + 1];
    }
    num_chats--;
    return true;
}

bool ReplyAdmin::removeChat(int* indices, int _count){
    bool removed = false;
    for (int i = _count - 1; i >= 0; i--){
        if (removeChat(indices[i])){
            removed = true;
        }
    }
    return removed;
}

bool ReplyAdmin::removeChat(int _start, int _end){
    if (_start < 0 || _end >= NUM_OF_CHAT || _start > _end){
        return false;
    }
    bool removed = false;
    for (int i = _end; i >= _start; i--){
        if (removeChat(i)){
            removed = true;
        }
    }
    return removed;
}

void ReplyAdmin::printChats(){
    for (int i = 0; i < num_chats; i++) {
        std::cout << i << ": " << chats[i] << std::endl;
    }
}
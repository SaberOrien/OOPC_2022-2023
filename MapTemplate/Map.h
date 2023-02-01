#pragma once
#include "KeyDoesNotExistException.h"

template<class Key, class Value> class Map
{
private:
    struct node
    {
    public:
        node* next;
        Key key;
        Value val;

        node(const Key givenKey){
            next = nullptr;
            key = givenKey;
        }
        ~node(){
            delete next;
        }
    };

    node* head;

    node* checkIfKeyExists(const Key givenKey) const{
        node* temp = head;
        while(temp){
            if(givenKey == temp->key){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

public:
    Map(){
        head = nullptr;
    }

    Map(const Map& m){
        node *source, **destination;
        head = NULL;
        source = m.head;
        destination = &head;

        while(source){
            *destination = new node(*source);
            source = source->next;
            destination = &((*destination)->next);
        }
    }

    Map& operator=(const Map& m){
        if(&m == this){
            return *this;
        }

        Map temp(m);
        node* newHead = head;
        head = temp.head;
        temp.head = newHead;

        return *this;
    }

    ~Map(){
        delete head;
    }

    void add(const Key& givenKey, const Value& givenValue){
        node* newNode = checkIfKeyExists(givenKey);

        if(!newNode){
            newNode = new node(givenKey);
            newNode->next = head;
            head = newNode;
            head->val = givenValue;
        }
        else{
            newNode->val = givenValue;
        }
    }

    Value* find(const Key& givenKey){
        node* temp = checkIfKeyExists(givenKey);
        if(!temp){
            throw keyDoesNotExistException(givenKey);
        }

        return &temp->val;
    }

    friend std::ostream& operator<<(std::ostream& o, const Map& m){
        node* current = m.head;
        while(current){
            o << "Key: " << current->key << "\n\t";
            o << "Value: " << current->val << "\n";
            current = current->next;
        }
        return o;
    }
};

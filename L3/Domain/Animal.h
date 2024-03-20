//
// Created by adria on 19.03.2024.
//

#ifndef GABI_EXEMPLU_ANIMAL_H
#define GABI_EXEMPLU_ANIMAL_H

#include <string>
#include <iostream>
#include "Identifiable.h"

class Animal: public Identifiable {
private:
    double size;
    std::string name;
public:
    Animal(): Identifiable{0},
    size{0.0}
    {
        std::cout<<"implicit constructor\n";
    }
    Animal(int _id_animal,double _size,const std::string& _name):
            Identifiable{_id_animal},
            size{_size},
            name{_name}
    {
        std::cout<<"explicit constructor\n";
    }
    Animal(const Animal& other):
            Identifiable{other.id},
            size{other.size},
            name{other.name}
    {
        std::cout<<"copy constructor\n";
    }

    Animal& operator = (const Animal& other){
        std::cout<<"smooth operator\n";
        this->id = other.id;
        this->size = other.size;
        this->name = other.name;
        return *this;
    }

    double get_size() const{
        return this->size;
    }
    const std::string& get_name() const{
        return this->name;
    }

    void set_name(const std::string& name){
        this->name = name;
    }

    bool operator == (const Animal& other) const{
        return this->id == other.id;
    }

    friend std::istream& operator>>(std::istream& is,Animal& a){
        is>>a.id>>a.size>>a.name;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Animal& a ){
        os<<a.id<<", "<<a.size<<", "<<a.name;
        return os;
    }

    ~Animal(){
        std::cout<<"destructor\n";
    }
};


#endif //GABI_EXEMPLU_ANIMAL_H

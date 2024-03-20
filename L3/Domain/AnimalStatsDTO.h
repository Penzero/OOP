//
// Created by adria on 19.03.2024.
//

#ifndef GABI_EXEMPLU_ANIMALSTATSDTO_H
#define GABI_EXEMPLU_ANIMALSTATSDTO_H


#include <string>
#include <utility>
#include <iostream>

class AnimalStatsDTO {
private:
    std::string name;
    double average_size;
public:
    AnimalStatsDTO(std::string  _name,double _average_size):
        name{std::move(_name)},
        average_size{_average_size}
        {}
        [[nodiscard]] double get_size() const{
        return this->average_size;
    }
        friend std::ostream& operator<<(std::ostream& os,const AnimalStatsDTO& stats)
        {
            os<<stats.name<<" cu greutatea "<<stats.average_size;
            return os;
        }
};


#endif //GABI_EXEMPLU_ANIMALSTATSDTO_H

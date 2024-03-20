#include <vector>
#include <algorithm>
template <typename TElem>
class Repo {
private:
    std::vector<TElem> elems;
public:
    Repo();
    int size() const;
    void add_element(const TElem& elem);
    void update_element(const TElem& elem);
    void remove_element(int id_elem);
    const std::vector<TElem>& get_all() const;
    ~Repo();
};

template<typename TElem>
const std::vector<TElem> &Repo<TElem>::get_all() const {
    return this->elems;
}

template<typename TElem>
void Repo<TElem>::remove_element(int id_elem) {
    auto it =std::find_if(this->elems.begin(),this->elems.end(),[&id_elem](const auto& x){
        return id_elem == x.get_id();
    });
    if (it == this->elems.end()){
        throw std::exception{};
    }
    this->elems.erase(it);
}

template<typename TElem>
void Repo<TElem>::update_element(const TElem &elem) {
    auto it =std::find(this->elems.begin(),this->elems.end(),elem);
    if (it == this->elems.end()){
        throw std::exception{};
    }
    *it = elem;
}

template<typename TElem>
void Repo<TElem>::add_element(const TElem &elem) {
    auto it =std::find(this->elems.begin(),this->elems.end(),elem);
    if (it != this->elems.end()){
        throw std::exception{};
    }
    this->elems.push_back(elem);
}

template<typename TElem>
int Repo<TElem>::size() const {
    return this->elems.size();
}

template<typename TElem>
Repo<TElem>::~Repo() {

}

template<typename TElem>
Repo<TElem>::Repo() {

}


#ifndef GABI_EXEMPLU_IDENTIFIABLE_H
#define GABI_EXEMPLU_IDENTIFIABLE_H


class Identifiable {
protected:
    int id;
public:
    explicit Identifiable(int _id):
    id{_id}
    {}
    int get_id() const;

};


#endif //GABI_EXEMPLU_IDENTIFIABLE_H

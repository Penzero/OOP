#include "../Domain/Animal.h"
#include "../persistency/Repo.h"
#include "../Domain/AnimalStatsDTO.h"

class AnimalService {
private:
    Repo<Animal>& repo;
public:
    explicit AnimalService(Repo<Animal>& _repo):repo{_repo}{}
    const std::vector<AnimalStatsDTO> get_top_7_heaviest_names_on_average();
    ~AnimalService()= default;
};


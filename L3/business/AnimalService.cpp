#include "AnimalService.h"
#include <unordered_map>
#include <utility>
const std::vector<AnimalStatsDTO> AnimalService::get_top_7_heaviest_names_on_average() {
    std::unordered_map<std::string,std::pair<double,int>> stat;
    auto all = this->repo.get_all();
    std::for_each(all.begin(),all.end(),[&stat](
            const auto& x
            ){
        if (stat.find(x.get_name())==stat.end()){
            stat[x.get_name()]=std::pair<double,int>{x.get_size(),0};
        }
        stat[x.get_name()].first+=x.get_size();
        stat[x.get_name()].second++;
    });

    return std::vector<AnimalStatsDTO>();
}

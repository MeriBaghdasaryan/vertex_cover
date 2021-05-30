#ifndef VERTEX_COVER_HPP
#define VERTEX_COVER_HPP

bool removable(std::vector<int> , std::vector<int>);
int max_removable(std::vector<std::vector<int> > , std::vector<int>);
std::vector<int> procedure_1(std::vector<std::vector<int>> , std::vector<int>);
std::vector<int> procedure_2(std::vector<std::vector<int>> , std::vector<int> , int);
int cover_size(std::vector<int>);

#endif 

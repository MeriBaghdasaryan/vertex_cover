#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "vertex_cover.hpp"

int main()
{
    std::ifstream infile ("graph.txt");
    std::ofstream outfile ("covers.txt");
    std::cout << "Vertex Cover Algorithm." << std::endl;
    int n, i, j, k, p, q, r, s, min, edge, counter = 0;
    infile>>n;
    std::vector<std::vector<int> > graph;
    for(i = 0; i < n; i++)
    {
        std::vector<int> row;
        for(j=0; j<n; j++)
        {
            infile>>edge;
            row.push_back(edge);
        }
        graph.push_back(row);
    }
    std::vector<std::vector<int> > neighbors;
    for(i = 0; i < graph.size(); i++)
    {
        std::vector<int> neighbor;
        for(j = 0; j < graph[i].size(); j++)
        {
            if(graph[i][j] == 1) 
            {
                neighbor.push_back(j);
            }

        }
        
        neighbors.push_back(neighbor);
    }
    std::cout << "Graph has n = " << n << " vertices." << std::endl;
    bool found = false;
    std::cout << "Finding Vertex Covers..." << std::endl;
    min = n + 1;
    std::vector<std::vector<int> > covers;
    std::vector<int> allcover;
    for(i = 0; i < graph.size(); i++)
    {
        allcover.push_back(1);
    }

    for(i = 0; i < allcover.size(); i++)
    {
        if(found)
        {
            break;
        }
        counter++;
        std::cout << counter << ". ";
        outfile << counter << ". ";
        std::vector<int> cover = allcover;
        cover[i] = 0;
        cover = procedure_1(neighbors,cover);
        s = cover_size(cover);
        if(s < min)
        {
            min = s;
        }
        if(s <= k)
        {
            outfile << "Vertex Cover ("<< s <<"): ";
            for(j = 0; j < cover.size(); j++)
            {
                if(cover[j] == 1)
                {
                    outfile << j + 1 << " ";
                }
            }
            outfile << std::endl;
            std::cout << "Vertex Cover Size: "<< s << std::endl;
            covers.push_back(cover);
            found = true;
            break;
        }
        for(j = 0; j < n - k; j++)
        { 
            cover = procedure_2(neighbors,cover,j);
        }
        s = cover_size(cover);
        if(s < min)
        {
            min = s;
        }
        outfile << "Vertex Cover ("<< s <<"): ";
        for(j = 0; j < cover.size(); j++)
        {
            if(cover[j] == 1)
            {
                outfile << j + 1 << " ";
            }
        }
        outfile << std::endl;
        std::cout << "Vertex Cover Size: "<< s << std::endl;
        covers.push_back(cover);
        if(s <= k)
        { 
            found = true;
            break;
        }
    }
    for(p = 0; p < covers.size(); p++)
    {
        if(found) 
        {
            break;
        }
        for(q = p + 1; q < covers.size(); q++)
        {
            if(found)
            {
                break;
            }
            counter++;
            std::cout << counter << ". ";
            outfile << counter << ". ";
            std::vector<int> cover = allcover;
            for(r = 0; r < cover.size(); r++)
            {
                if(covers[p][r] == 0 && covers[q][r] == 0)
                {
                    cover[r] = 0;
                }
            }
            cover = procedure_1(neighbors,cover);
            s = cover_size(cover);
            if(s < min)
            {
                min = s;
            }
            if(s <= k)
            {
                outfile << "Vertex Cover ("<< s <<"): ";
                for(j = 0; j < cover.size(); j++) 
                {
                    if(cover[j] == 1) 
                    {
                        outfile << j + 1 << " ";
                    }
                }   
                outfile << std::endl;
                std::cout << "Vertex Cover Size: " << s << std::endl;
                found = true;
                break;
            }   
            for(j = 0; j < k; j++)
            {
                cover = procedure_2(neighbors,cover,j);
            }
            s = cover_size(cover);
            if(s < min)
            {
                min = s;
            }

            outfile << "Vertex Cover ("<< s <<"): ";
            for(j = 0; j < cover.size(); j++) 
            {    
                if(cover[j] == 1) 
                {
                    outfile << j + 1 << " ";
                }
            }
            outfile << std::endl;
            std::cout << "Vertex Cover Size: " << s << std::endl;

                break; 
        }
    }
            std::cout << "Minimum Vertex Cover size found is " << min << "." << std::endl;
            std::cout << "See cover.txt for results." << std::endl;
    
    return 0;
}


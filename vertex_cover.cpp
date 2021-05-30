#include <vector>

bool removable(std::vector<int> neighbor,std::vector<int> cover)
{
    bool check = true;
    for(int i = 0; i < neighbor.size(); i++)
    {    
        if(cover[neighbor[i]] == 0)
        {
            check = false;
            break;
        }
    }
    return check;
}


int max_removable(std::vector<std::vector<int> > neighbors, std::vector<int> cover)
{
    int r = -1, max = -1;
    for(int i = 0; i < cover.size(); i++)
    {
        if(cover[i] == 1 && removable(neighbors[i],cover) == true)
        {
            std::vector<int> temp_cover = cover;
            temp_cover[i] = 0;
            int sum = 0;
            for(int j = 0; j < temp_cover.size(); j++)
            {
                if(temp_cover[j] == 1 && removable(neighbors[j], temp_cover) == true)
                {
                    sum++;
                }
            }
            if(sum > max)
            {
                max = sum;
                r = i;
            }
        }
    }
    return r;
}


std::vector<int> procedure_1(std::vector<std::vector<int> > neighbors, std::vector<int> cover)
{
    std::vector<int> temp_cover = cover;
    int r = 0;
    while(r != -1)
    {
        r = max_removable(neighbors,temp_cover);
        if(r != -1)
        {
            temp_cover[r] = 0;
        }
    }
    return temp_cover;
}


std::vector<int> procedure_2(std::vector<std::vector<int>> neighbors, std::vector<int> cover, int k)
{
    int count = 0;
    std::vector<int> temp_cover = cover;
    int i = 0;
    for(int i = 0; i < temp_cover.size(); i++)
    {
        if(temp_cover[i] == 1)
        {
            int sum = 0, index;
            for(int j = 0; j < neighbors[i].size(); j++)
            if(temp_cover[neighbors[i][j]] == 0)
            {
                index = j;
                sum++;
            }
            if(sum == 1 && cover[neighbors[i][index]] == 0)
            {
                temp_cover[neighbors[i][index]] = 1;
                temp_cover[i] = 0;
                temp_cover = procedure_1(neighbors,temp_cover);
                count++;
            }
            if(count > k)
            {
                break;
            }
        }
    }
    return temp_cover;
}


int cover_size(std::vector<int> cover)
{
    int count = 0;
    for(int i = 0; i < cover.size(); i++)
        if(cover[i] == 1) count++;
            return count;
        
}


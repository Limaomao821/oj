#include<cstdio>
#include<cstdlib>
#include<deque>
#include<vector>
using namespace std;

// typedef struct{
//     char landscape;
//     char tagged;
// }block;

static int m, n;

// void findAndTag(char** grid, int m_current, int n_current){
//     *(*(grid+m_current)+n_current) = 2;
    
//     char landscape;

//     //could go up
//     if(m_current>0){
//         landscape = *(*(grid+m_current-1)+n_current);
//         if(landscape == 1){
//             findAndTag(grid, m_current-1, n_current);
//         }
//     }

//     //could go down
//     if(m_current<m-1){
//         landscape = *(*(grid+m_current+1)+n_current);
//         if(landscape == 1){
//             findAndTag(grid, m_current+1, n_current);
//         }
//     }

//     //could go left
//     if(n_current>0){
//         landscape = *(*(grid+m_current)+n_current-1);
//         if(landscape == 1){
//             findAndTag(grid, m_current, n_current-1);
//         }
//     }

//     //could go right
//     if(n_current<n-1){
//         landscape = *(*(grid+m_current)+n_current+1);
//         if(landscape == 1){
//             findAndTag(grid, m_current, n_current+1);
//         }
//     }
// } 


int main(void){
    scanf("%d%d", &m, &n);

    // char** grid = (char**)malloc(m*sizeof(char*));
    vector< vector<char> > grid;
    grid.resize(m);
    
    int m_temp=0, n_temp=0;
    for(m_temp=0;m_temp<m;++m_temp){
        // *(grid+m_temp) = (char*)malloc(n*sizeof(char));
        for(n_temp=0;n_temp<n;++n_temp){
            int temp;
            scanf("%d", &temp);
            // if(temp) grid[m_temp][n_temp] = 1;
            // else grid[m_temp][n_temp] = 0;
            
            grid[m_temp].push_back(temp);
            
            // grid[m_temp][n_temp]=temp;
        }
    }

    int island_num=0;
    deque< pair<short, short> > wait;
    for(m_temp=0;m_temp<m;++m_temp){
        for(n_temp=0;n_temp<n;++n_temp){
            char landscape = grid[m_temp][n_temp];
            if(landscape==1){
                ++island_num;
                grid[m_temp][n_temp] = 2;
                wait.push_back(make_pair(m_temp, n_temp));
                while(!wait.empty()){
                    pair<short, short> temp = wait.front();
                    wait.pop_front();

                    char temp_landscape;
                    //could go up
                    if(temp.first>0){
                        temp_landscape = grid[temp.first-1][temp.second];
                        if(temp_landscape==1){
                            grid[temp.first-1][temp.second] = 2;
                            wait.push_back(make_pair(temp.first-1, temp.second));
                        }
                    }

                    //could go down
                    if(temp.first<m-1){
                        temp_landscape = grid[temp.first+1][temp.second];
                        if(temp_landscape==1){
                            grid[temp.first+1][temp.second] = 2;
                            wait.push_back(make_pair(temp.first+1, temp.second));
                        }
                    }

                    //could go left
                    if(temp.second>0){
                        temp_landscape = grid[temp.first][temp.second-1];
                        if(temp_landscape==1){
                            grid[temp.first][temp.second-1] = 2;
                            wait.push_back(make_pair(temp.first, temp.second-1));
                        }
                    }

                    //could go right
                    if(temp.second<n-1){
                        temp_landscape = grid[temp.first][temp.second+1];
                        if(temp_landscape==1){
                            grid[temp.first][temp.second+1] = 2;
                            wait.push_back(make_pair(temp.first, temp.second+1));
                        }
                    }
                }
            }
        }
    }
    printf("%d", island_num);

    // for(m_temp=0;m_temp<m;++m_temp){
    //     for(n_temp=0;n_temp<n;++n_temp){
    //         printf("(%d, %d) ", (*(grid+m_temp)+n_temp)->landscape, (*(grid+m_temp)+n_temp)->tagged);
    //     }
    //     printf("\n");
    // }
    return 0;
}
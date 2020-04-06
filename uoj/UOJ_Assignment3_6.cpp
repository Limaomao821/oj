#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
    vector<short> m_pos;
    vector<short> b_pos;

    char input;
    int pos=0;
    while(scanf("%c", &input)){
        if(input=='\n'){
            break;
        }else if(input=='M'){
            m_pos.push_back(pos);
        }else{
            b_pos.push_back(pos);
        }
        ++pos;
    }

    short jump_len = 0;
    scanf("%hd", &jump_len);

    int can_be_eaten=0;
    int b_len = b_pos.size();
    int m_len = m_pos.size();
    int b_ptr=0, m_ptr=0;
    for(b_ptr=0; b_ptr<b_len;){
        if(b_ptr >= b_len || m_ptr >= m_len){
            break;
        }

        if( abs(b_pos[b_ptr] - m_pos[m_ptr]) <= jump_len){
            ++can_be_eaten;
            ++m_ptr;
            ++b_ptr;
        }else{
            while( (abs(b_pos[b_ptr] - m_pos[m_ptr]) > jump_len) && b_ptr<b_len && m_ptr<m_len){
                if(b_pos[b_ptr] > m_pos[m_ptr]) ++m_ptr;
                else ++b_ptr;
            }

            if(b_ptr >= b_len || m_ptr >= m_len){
                break;
            }

            if( abs(b_pos[b_ptr] - m_pos[m_ptr]) <= jump_len){
                ++can_be_eaten;
                ++m_ptr;
                ++b_ptr;
            }
        }
    }

    printf("%hd", can_be_eaten);
    return 0;
}
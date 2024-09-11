#include "./myHeaders/myHeaders.h"

void Box(){
    gotoXY(0,0);
    for(int i=0;i<Window_width+2;i++){
        std::cout<<"#";
    }
    std::cout<<std::endl;
    for(int i=0;i<Window_height;i++){
        for(int j=0;j<Window_width;j++){
            if(j==0){
                std::cout<<"#";
            }
            if(i==current_y && j==current_x){
                std::cout<<"O"; //snake's head
            }
            else if(i==fruit_y && j==fruit_x){
                std::cout<<"1"; //fruit denoted with score the snake will get once collected
            }
            else{
                bool tail=false;
                for(int k=0;k<tail_len;k++){
                    if(tail_x[k]==j && tail_y[k]==i){
                        std::cout<<"0";
                        tail=true;
                    }
                }
                if(tail==false){
                    std::cout<<" ";
                }
            }
            if(j==Window_width-1){
                std::cout<<"#";
            }
        }
        std::cout<<std::endl;
    }
    for(int i=0;i<Window_width+2;i++){
        std::cout<<"#";
    }
    std::cout<<std::endl;
    std::cout<<"Fruits Collected: "<<score<<std::endl;
}
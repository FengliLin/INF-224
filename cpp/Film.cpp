//
//  Film.cpp
//  INF224_TP
//
//  Created by Fengli LIN on 04/12/2018.
//  Copyright © 2018 Fengli LIN. All rights reserved.
//

#include "Film.hpp"

Film::Film(const std::string n,const std::string p, const int *d, const int len):Video(n,p){
    tableOfDuree = new int[len];
    nbOfChaptre = len;
    for (int i=0;i<len;++i){
        *(tableOfDuree+i) = *(d +i);
    }
}

Film::Film(const Film& f) : Video(f){
    nbOfChaptre = f.getNbOfChaptre();
    if(f.tableOfDuree){
        tableOfDuree = new int[nbOfChaptre];
        for (int i=0;i<nbOfChaptre;++i){
            *(tableOfDuree+i) = *(f.getTableOfDuree() +i);
        }
    }
    else tableOfDuree = nullptr;
    
}

Film& Film::operator=(const Film & f){
    Video::operator=(f);
    nbOfChaptre = f.getNbOfChaptre();
    //delete tableOfDuree;
    if(f.tableOfDuree){
        tableOfDuree = new int[nbOfChaptre];
        for (int i=0;i<nbOfChaptre;++i){
            *(tableOfDuree+i) = *(f.getTableOfDuree() +i);
        }
    }
    else tableOfDuree = nullptr;
    return *this;
}

void Film:: setDurees(const int *d, const int len) {
    if(len <=0){
        std::cerr<<"the length is non positive!";
    }
    tableOfDuree = new int[len];
    nbOfChaptre = len;
    for (int i=0;i<len;++i){
        *(tableOfDuree+i) = *(d +i);
    }
}

void Film:: showValues(std::ostream & s)  const {
    Multimedia::showValues(s);
    s << ";   Total number of chapters:" << nbOfChaptre ;
    for (int i=0;i<nbOfChaptre;++i){
        s << ";   Num of chapter: " << i << ", duration of this chapter: " << tableOfDuree[i];
    }
}

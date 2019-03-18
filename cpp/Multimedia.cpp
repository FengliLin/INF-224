//
//  Multimedia.cpp
//  INF224_TP
//
//  Created by Fengli LIN on 27/11/2018.
//  Copyright © 2018 Fengli LIN. All rights reserved.
//

#include "Multimedia.hpp"
using namespace std;

Multimedia::Multimedia(){
    nom = "";
    nomDuFichier = "";
};

Multimedia::Multimedia(const Multimedia& m){
    nom = m.getNom();
    nomDuFichier = m.getNomDuFichier();
}

Multimedia &Multimedia:: operator=(const Multimedia& m){
    nom = m.getNom();
    nomDuFichier = m.getNomDuFichier();
    return *this;
}

void Multimedia::showValues(ostream & s) const{
    if(nom.size()==0){
        s << " File name is empty!" ;
    }
    else{
        s << " File name:" << nom ;
    }
    if(nomDuFichier.size()==0){
        s << " File path is empty!" ;
    }
    else {
        s << "；File path: " << nomDuFichier ;
    }
};

//
//  Groupe.cpp
//  INF224_TP
//
//  Created by Fengli LIN on 18/12/2018.
//  Copyright © 2018 Fengli LIN. All rights reserved.
//

#include "Groupe.hpp"
using namespace std;

void Group::showContents(std::ostream & s) const{
    if(groupNom.size()==0){
        s << " Nom is empty!" ;
    }
    else{
        s << " Group Nom:" << groupNom << "|---->";
    }
    for (auto & it : *this) {
        it->showValues(s);
        s << " |----> ";
    }
};


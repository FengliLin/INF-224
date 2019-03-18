//
//  Film.hpp
//  INF224_TP
//
//  Created by Fengli LIN on 04/12/2018.
//  Copyright © 2018 Fengli LIN. All rights reserved.
//

#ifndef Film_hpp
#define Film_hpp

#include <stdio.h>

#include "Video.hpp"


class Film: public Video{
private:
    int *tableOfDuree = nullptr;
    int nbOfChaptre = 0;
public:
    //Constructor functions
    Film(){};
    
    Film(const std::string n,const std::string p):Video(n,p){};
    
    Film(const std::string n,const std::string p, const int *d, const int len);
    
    Film(const Film&);
    
    Film& operator= (const Film&);
    
    virtual ~Film(){ delete tableOfDuree; tableOfDuree=nullptr; std:: cout<<"release film:"<< getNom()<< std::endl;};
    
    //member functions
    void setDurees(const int *d, const int len);
    
    const int * getTableOfDuree()const{return tableOfDuree;};
    
    int getNbOfChaptre()const{ return nbOfChaptre;};
    
    void showValues(std::ostream & s)  const override;

    
    
};

#endif /* Film_hpp */

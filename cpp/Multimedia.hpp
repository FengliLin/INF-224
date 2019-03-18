//
//  Multimedia.hpp
//  INF224_TP
//
//  Created by Fengli LIN on 27/11/2018.
//  Copyright © 2018 Fengli LIN. All rights reserved.
//

#ifndef Multimedia_hpp
#define Multimedia_hpp

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <map>


class Multimedia{
private:
    std::string nom = "";
    std::string nomDuFichier = "";
    
public:
    //Constructor functions
    Multimedia();
    Multimedia(const Multimedia&);
    Multimedia(const std::string n1, const std::string n2):nom(n1),nomDuFichier(n2){};
    virtual ~Multimedia(){};
    
    Multimedia& operator=(const Multimedia&);
    
    //member functions
    std::string getNom() const{return nom;};
    std::string getNomDuFichier() const{return nomDuFichier;};
    void setNom(const std::string n){nom = n;};
    void setNomDuFichier(const std::string n){nomDuFichier=n;};
    virtual void showValues(std::ostream & s) const;
    virtual void jouerMedia(std::ostream & s) const = 0;
};

#endif /* Multimedia_hpp */

//
//  Groupe.hpp
//  INF224_TP
//
//  Created by Fengli LIN on 18/12/2018.
//  Copyright © 2018 Fengli LIN. All rights reserved.
//

#ifndef Groupe_hpp
#define Groupe_hpp

#include <list>
#include <ostream>
#include "Multimedia.hpp"
#include "Video.hpp"
#include "Photo.hpp"
#include "Film.hpp"

using MultimediaPtr = std::shared_ptr<Multimedia>;

class Group: public std::list<MultimediaPtr>{
private:
    std::string groupNom ="";
    
public:
    //Constructor functions
    Group():std::list<MultimediaPtr>(){}
    Group(const std::string n):groupNom(n){}
    virtual ~Group(){}
    
    //member functions
    std::string getGroupNom() const{ return groupNom;}
    void showContents(std::ostream & s) const;
};
#endif /* Groupe_hpp */

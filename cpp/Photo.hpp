//
//  photo.hpp
//  INF224_TP
//
//  Created by Fengli LIN on 03/12/2018.
//  Copyright © 2018 Fengli LIN. All rights reserved.
//

#ifndef photo_hpp
#define photo_hpp

#include "Multimedia.hpp"

class Photo: public Multimedia{
private:
    double length = 0.0;
    double width = 0.0;
public:
    //Constructor functions
    Photo():Multimedia(){ length = 0.0; width = 0.0;}
    
    Photo(std::string n, std::string p):Multimedia(n,p){}
    
    Photo(std::string n, std::string p, double l, double w):Multimedia(n,p){ length = l; width = w;}
    
    Photo(const Photo& p):Multimedia(p){ length = p.getLength(); width = p.getWidth();}
    
    Photo& operator=(const Photo& p){
        Multimedia::operator=(p);
        length = p.getLength();
        width = p.getWidth();
        return *this;
    }
    
    virtual ~Photo(){};
    
    //member functions
    double getLength() const{return length;}
    
    double getWidth() const{return width;}
    
    void setLength(double l){length =l;}
    
    void setWidth(double w){width =w;}
    
    void showValues(std::ostream & s)  const override{
    Multimedia::showValues(s);
        s << "；Length: " << length  << "；Width: " << width ;
    };
    
    void jouerMedia(std::ostream & s) const override{
        if(getNomDuFichier().size()==0){
            s << "The file path does not exist!";
            return;
        }
        std::string path;
        path = "imagej "+ getNomDuFichier() + " &";
        // For MacOS system, using "open" command to open a file
        //path = "open "+ getNomDuFichier() + " &";
        system(path.c_str());
    }
};


#endif /* photo_hpp */

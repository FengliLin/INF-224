//
//  Video.hpp
//  INF224_TP
//
//  Created by Fengli LIN on 27/11/2018.
//  Copyright © 2018 Fengli LIN. All rights reserved.
//

#ifndef Video_hpp
#define Video_hpp

#include "Multimedia.hpp"

class Video: public Multimedia{
private:
    int duree = 0;
public:
    //Constructor functions
    Video():Multimedia(){duree = 0;}
    
    Video(const std::string n,const std::string p):Multimedia(n,p){}
    
    Video(const std::string n,const std::string p,const int d):Multimedia(n,p){ duree = d;}
    
    Video(const Video& v):Multimedia(v){ duree = v.getDuree();}
    
    Video& operator=(const Video& v){
        Multimedia::operator=(v);
        duree = v.getDuree();
        return *this;
    }
    
    virtual ~Video(){};
    
    //member functions
    int getDuree() const{return duree;}
    
    virtual void setDuree(const int d){duree =d;}
    
    void showValues(std::ostream & s)  const override{
        Multimedia::showValues(s);
        s << "；Duree: " << duree ;
    };
    
    void jouerMedia(std::ostream & s) const override{
        if(getNomDuFichier().size()==0){
            s << "The file path does not exist!";\
            return;
        }
        std::string path;
        path = "mpv "+ getNomDuFichier() + " &";
        // For MacOS system, using "open" command to open a file
        //path = "open "+ getNomDuFichier() + " &";
        system(path.c_str());
    }
};

#endif /* Video_hpp */





//
//  Database.hpp
//  INF224_TP
//
//  Created by Fengli LIN on 04/01/2019.
//  Copyright © 2019 Fengli LIN. All rights reserved.
//

#ifndef Database_hpp
#define Database_hpp

#include "Photo.hpp"
#include "Film.hpp"
#include "Groupe.hpp"

using MultimediaPtr = std::shared_ptr<Multimedia>;
using GroupPtr = std::shared_ptr<Group>;
using PhotoPtr = std::shared_ptr<Photo>;
using VideoPtr = std::shared_ptr<Video>;
using FilmPtr = std::shared_ptr<Film>;
using MultimediaMap = std :: map < std::string , MultimediaPtr >;
using GroupMap = std :: map < std::string , GroupPtr >;

class Database : public Photo,Film,Group{
private:
    MultimediaMap tabOfMedia ;
    GroupMap tabOfGroup ;
public:
    //Constructor functions
    Database(){}
    virtual ~Database(){}
    
    //member functions
    PhotoPtr addPhoto(const std::string name,const std::string path,const double length,const double width);
    
    VideoPtr addVideo(const std::string name,const std::string path,const int duration);
    
    FilmPtr addFilm(const std::string name,const std::string path, const int *durations, const int len);
    
    GroupPtr addGroup(const std::string name);
    
    void findMedia(const std::string key,std::ostream & s);
    
    void findGroup(const std::string key,std::ostream & s);
    
    void playMedia(const std::string key,std::ostream & s);
    
    void deleteMedia(const std::string key,std::ostream & s);
    
    void deleteGroup(const std::string key,std::ostream & s);
    
};
#endif /* Database_hpp */

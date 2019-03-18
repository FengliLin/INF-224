//
//  Database.cpp
//  INF224_TP
//
//  Created by Fengli LIN on 04/01/2019.
//  Copyright © 2019 Fengli LIN. All rights reserved.
//

#include "Database.hpp"


PhotoPtr Database::addPhoto(const std::string name,const std::string path,const double length,const double width){
    PhotoPtr tmp (new Photo(name,path,length,width));
    tabOfMedia.insert( MultimediaMap :: value_type(tmp->getNom(), tmp));
    return tmp;
}

VideoPtr Database::addVideo(const std::string name,const std::string path,const int duration){
    VideoPtr tmp (new Video(name,path,duration));
    tabOfMedia.insert( MultimediaMap :: value_type(tmp->getNom(), tmp));
    return tmp;
}

FilmPtr Database::addFilm(const std::string name,const std::string path, const int *durations, const int len){
    FilmPtr tmp (new Film(name,path,durations,len));
    tabOfMedia.insert( MultimediaMap :: value_type(tmp->getNom(), tmp));
    return tmp;
}
GroupPtr Database::addGroup(const std::string name){
    GroupPtr tmp (new Group(name));
    tabOfGroup.insert( GroupMap :: value_type(tmp->getGroupNom(), tmp));
    return tmp;
}

void Database::findMedia(const std::string key,std::ostream & s){
    MultimediaMap::iterator it= tabOfMedia.find(key);
    if(it == tabOfMedia.end()){
        s << "The file doesn't exist!";
    }
    else{
        it->second->showValues(s);
    }
}

void Database::findGroup(const std::string key,std::ostream & s){
    GroupMap::iterator it= tabOfGroup.find(key);
    if(it == tabOfGroup.end()){
        s << "The group doesn't exist!";
    }
    else{
        it->second->showContents(s);
    }
}

void Database::playMedia(const std::string key, std::ostream & s){
    MultimediaMap::iterator it= tabOfMedia.find(key);
    if(it == tabOfMedia.end()){
        s << "The file doesn't exist!";
    }
    else{
        it->second->jouerMedia(s);
    }
}

void Database::deleteMedia(const std::string key, std::ostream & s){
    MultimediaMap::iterator it= tabOfMedia.find(key);
    if(it == tabOfMedia.end()){
        s << "The file doesn't exist!";
    }
    else{
        //remove the media from all groups
        for (GroupMap::iterator itg = tabOfGroup.begin();itg == tabOfGroup.end();++itg){
            for(Group::iterator tmp_it = itg->second->begin(); tmp_it == itg->second->end();++tmp_it){
                if((tmp_it->get())->getNom()==key){
                    itg->second->erase(tmp_it);
                }
            }
        }
        //remove the media from the database
        tabOfMedia.erase(it);
    }
}

void Database::deleteGroup(const std::string key,std::ostream & s){
    GroupMap::iterator it= tabOfGroup.find(key);
    if(it == tabOfGroup.end()){
        s << "The group doesn't exist!";
    }
    else{
        tabOfGroup.erase(it);
    }
}

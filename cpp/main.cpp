//
// main.cpp
// Created on 21/10/2018
// valgrimd ./myprog

#include <iostream>
#include "Multimedia.hpp"
#include "Video.hpp"
#include "Photo.hpp"
#include "Film.hpp"
#include "Groupe.hpp"
#include "Database.hpp"
using namespace std;
using MultimediaPtr = std::shared_ptr<Multimedia>;
using GroupPtr = std::shared_ptr<Group>;
using PhotoPtr = std::shared_ptr<Photo>;
using VideoPtr = std::shared_ptr<Video>;
using FilmPtr = std::shared_ptr<Film>;
using DBPtr = std::shared_ptr<Database>;
using MultimediaMap = std :: map < std::string , MultimediaPtr >;
using GroupMap = std :: map < std::string , GroupPtr >;

void printMedias(Multimedia ** tab, unsigned int count) {
    for (unsigned int k = 0; k < count; ++k) {
        tab[k]->showValues(cout);
        tab[k]->jouerMedia(cout);
    }
}

int main(int argc, const char* argv[])
{
    int len = 5;
    int*durees = new int[5];
    for(int i=0;i<len;++i){
        durees[i]=i;
    }
    
    cout << endl << "-----------test class Photo------------" << endl;
    Photo test("IMG_3894.JPG","./Media/Monkey.jpeg",2,3);
    test.showValues(cout);
    test.jouerMedia(cout);
    
    
    cout << endl << "-----------test class Film------------" << endl;
    Film *film1 = new Film("f1","./Media/01.mkv",durees,len);
    
    film1->showValues(cout);
    int td[3]={4,5,6};
    Film *film2 = new Film(*film1);
    *film2 = *film1;
    film2->showValues(cout);
    delete film1;
    film1 = nullptr;
    
    film2->showValues(cout);
    delete film2;
    film2 = nullptr;
    
    Film *test2 = new Film("IMG_3894.JPG","./Media/Monkey.jpeg",td,3);
    test2->showValues(cout);

    test2->setDurees(durees, len);
    

    Film *test3 = new Film( *test2);
    test3->showValues(cout);
    cout << endl << "-----------test smart pointer------------" << endl;
    
    FilmPtr t1(new Film("01","./Media/01.mkv",durees,len));
    cout << t1.use_count()<<endl;
    
    Group *testGroup = new Group("Family");
    testGroup->push_back(t1);
    cout << t1.use_count()<<endl;
    
    testGroup->showContents(cout);

    Group *testGroup2 = new Group("Work");
    testGroup2->push_back(t1);
    cout << t1.use_count()<<endl;
    t1.reset();
    cout << t1.use_count()<<endl;
    delete testGroup;
    
    testGroup2->showContents(cout);
    delete testGroup2;
    
    cout<< "all groups are deleted"<<endl;
    
    
    cout << endl << "-----------test class Database------------" << endl;
    DBPtr testDatabase (new Database());
    PhotoPtr p1 = testDatabase->addPhoto("p1","./Media/Monkey.jpeg",2,3);
    VideoPtr v2 = testDatabase->addVideo("v2","./Media/01.mkv",2);
    FilmPtr f1 = testDatabase->addFilm("f1","./Media/01.mkv",durees,len);
    GroupPtr g1 = testDatabase->addGroup("Family");
    g1->push_back(p1);
    cout<<f1.use_count()<<endl;

    g1->push_back(f1);
    cout<<f1.use_count()<<endl;

    GroupPtr g2 = testDatabase->addGroup("Work");
    g2->push_back(f1);
    cout<<f1.use_count()<<endl;
    testDatabase->findMedia("p1",cout);
    testDatabase->playMedia("v2",cout);
    return 0;
}



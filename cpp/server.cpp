//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Database.hpp"
#include <list>
using namespace std;
using namespace cppu;
using DBPtr = std::shared_ptr<Database>;

const int PORT = 3331;

class MyBase: public Database{
public:
  /* Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
   * Ca doit etre une methode de la classe qui gere les données, afin qu'elle
   * puisse y accéder.
   *
   * Arguments:
   * - 'request' contient la requête
   * - 'response' sert à indiquer la réponse qui sera renvoyée au client
   * - si la fonction renvoie false la connexion est close.
   *
   * Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
   * un thread par client).
   *
   * Pour eviter les problemes de concurrence on peut créer un verrou en creant
   * une variable Lock **dans la pile** qui doit etre en mode WRITE (2e argument = true)
   * si la fonction modifie les donnees.
   */
    bool processRequest(TCPConnection& cnx, const string& request, string& response)
    {
        cerr << "\nRequest: '" << request << "'" << endl;

    // 1) pour decouper la requête:
    // on peut par exemple utiliser stringstream et getline()
        istringstream iss(request);
        ostringstream answer;
        list<string> myRequestSplited;
        do{
            string sub;
            iss >> sub;
          
            if(sub.compare("")!=0){
                myRequestSplited.push_back(sub);
            }
        } while (iss);
    
    // 2) faire le traitement:
    // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
    // - sinon juste: TCPLock lock(cnx);
        auto it=myRequestSplited.begin();
      
        if(it->compare("end")==0)return false;//"end"
        if(it->compare("play")==0){ //play "name"
            it++;
            this->playMedia(*it,answer);
        }
        else if(it->compare("findM")==0){//findM "name"
            cerr<<"findM actived"<<endl;
            it++;
            this->findMedia(*it,answer);
        }
        else if(it->compare("findG")==0){//findG "name"
            cerr<<"findG actived"<<endl;
            it++;
            this->findGroup(*it,answer);
        }

    // 3) retourner la reponse au client:
    // - pour l'instant ca retourne juste OK suivi de la requête
    // - pour retourner quelque chose de plus utile on peut appeler la methode print()
    //   des objets ou des groupes en lui passant en argument un stringstream
    // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
    //   ils servent à délimiter les messages entre le serveur et le client
    
    response = answer.str();
    cerr << "response: " << response << endl;
    
    // renvoyer false si on veut clore la connexion avec le client
    return true;
  }
};


int main(int argc, char* argv[])
{
  // cree le TCPServer
  shared_ptr<TCPServer> server(new TCPServer());
  
  // cree l'objet qui gère les données
  shared_ptr<MyBase> base(new MyBase());
  PhotoPtr monkey = base->addPhoto("Monkey","./Media/Monkey.jpeg",800,600);
  PhotoPtr bamboo = base->addPhoto("Bamboo","./Media/Bamboo.jpeg",1000,667);
  VideoPtr reflet = base->addVideo("Reflet","./Media/01.mkv",95);
  GroupPtr plant = base->addGroup("Plant");
  GroupPtr animal =base->addGroup("Animal");
  plant->push_back(bamboo);
  animal->push_back(monkey);
  animal->push_back(reflet);

  // le serveur appelera cette méthode chaque fois qu'il y a une requête
  server->setCallback(*base, &MyBase::processRequest);
  
  // lance la boucle infinie du serveur
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);
  
  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }
  
  return 0;
}


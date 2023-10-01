#include<iostream>
#include<string.h>
#include<vector>
#include<time.h>
using namespace std;

class Jucator
{
    string nume;
    char sex;
    int varsta;
    string armaPreferata;
    int kills;

public:
    Jucator(string, char, int, int, string);
    Jucator(const Jucator& obj);

    Jucator& operator = (const Jucator& obj);
    friend ostream& operator << (ostream& out, const Jucator& obj);
    friend istream& operator >> (istream& in, Jucator& obj);

    string getNume() {return this->nume;}
    int getKills() {return this->kills;}
    void setKills(){this->kills ++;}

    ~Jucator(){};
};

Jucator :: Jucator(string nume = "cineva", char sex = 'M', int varsta = 18, int kills = 0, string armaPreferata = "ceva")
{
    this->nume = nume;
    this->sex = sex;
    this->varsta = varsta;
    this->kills = kills;
    this->armaPreferata = armaPreferata;

}

Jucator :: Jucator(const Jucator& obj)
{
    this->nume = obj.nume;
    this->sex = obj.sex;
    this->varsta = obj.varsta;
    this->kills = obj.kills;
    this->armaPreferata = obj.armaPreferata;
}

Jucator& Jucator :: operator = (const Jucator& obj)
{
    if(this != &obj){
        this->nume = obj.nume;
        this->sex = obj.sex;
        this->varsta = obj.varsta;
        this->kills = obj.kills;
        this->armaPreferata = obj.armaPreferata;
    }
    return *this;
}

ostream& operator << (ostream& out, const Jucator& obj)
{
    out<<"Nume: "<<obj.nume<<endl;
    out<<"Sex: "<<obj.sex<<endl;
    out<<"Varsta: "<<obj.varsta<<endl;
    out<<"Kills: "<<obj.kills<<endl;
    out<<"Arma preferata: "<<obj.armaPreferata<<endl;
    return out;
}

istream& operator >> (istream& in, Jucator& obj)
{
    cout<<"Nume: "; in>>obj.nume;
    cout<<"Sex: "; in>>obj.sex;
    cout<<"Varsta: "; in>>obj.varsta;
    cout<<"Arma preferata: "; in>>obj.armaPreferata;
}

class BattleRoyale
{
protected:
    vector<Jucator> p;
    int numarJucatori;
    int durata;
    string numeArena;
public:
    BattleRoyale();
    BattleRoyale(vector<Jucator>);
    BattleRoyale(vector<Jucator>, int, int, string);
    BattleRoyale(BattleRoyale&);

    BattleRoyale& operator = (BattleRoyale&);
    virtual istream& citire(istream& in) = 0;
    virtual ostream& afisare(ostream& out) const = 0;
    virtual void start() = 0;

    ~BattleRoyale(){};
};

BattleRoyale :: BattleRoyale()
{
    this->p = {};
    this->numarJucatori = 0;
    this->durata = 0;
    this->numeArena = "ceva";
}

BattleRoyale :: BattleRoyale(vector<Jucator> p, int numarJucatori, int durata, string numeArena)
{
    this->p = p;
    this->numarJucatori = numarJucatori;
    this->durata = durata;
    this->numeArena = numeArena;
}

BattleRoyale :: BattleRoyale (BattleRoyale& obj)
{
    this->p = obj.p;
    this->numarJucatori = obj.numarJucatori;
    this->durata = obj.durata;
    this->numeArena = obj.numeArena;
}

BattleRoyale& BattleRoyale :: operator = (BattleRoyale& obj)
{
    if(this != &obj){
        this->p = obj.p;
        this->numarJucatori = obj.numarJucatori;
        this->durata = obj.durata;
        this->numeArena = obj.numeArena;
    }
    return *this;
}

class BattleRoyaleSolo : virtual public BattleRoyale
{
protected:
    vector<Jucator> clasament;
public:
    BattleRoyaleSolo();
    BattleRoyaleSolo(vector<Jucator>);
    BattleRoyaleSolo(vector<Jucator>, int, int, string, vector<Jucator>);
    BattleRoyaleSolo(BattleRoyaleSolo&);

    BattleRoyaleSolo& operator = (BattleRoyaleSolo&);
    istream& citire(istream&);
    ostream& afisare(ostream&) const;
    friend istream& operator >> (istream&, BattleRoyaleSolo&);
    friend ostream& operator << (ostream&, const BattleRoyaleSolo&);

    void setClasament(Jucator& obj){this->clasament.push_back(obj);}
    vector<Jucator> getP(){return this->p;}

    virtual void start()
{
        system("CLS");
        cout<<"BATTLE ROYALE SOLO"<<endl<<endl;
        system("PAUSE");
        if(this->p.size() == 0)
            return;
        while(this->p.size() != 1){
            cout<<endl;
            event();
            system("PAUSE");
        }
        system("CLS");
        cout<<"THE GAME IS OVER"<<endl<<"THE WINNER IS "<<this->p[0].getNume()<<"!"<<endl<<endl;
        setClasament(this->p[0]);

        for(int i=0; i<this->clasament.size(); i++)
            cout<<i+1<<"."<<endl<<clasament[clasament.size() - i - 1]<<endl;

}

    void event()
{
        srand(time(NULL));
        int k = rand() % 10;
        int x = 0, y = 0;
            while(x == y){
                x = rand() % p.size();
                y = rand() % p.size();
            }
        switch(k){
            case 0:{
                cout<<this->p[x].getNume()<<" il omoara pe "<<this->p[y].getNume()<<" cu sabia."<<endl<<endl;
                break;
            }
            case 1:{
                cout<<this->p[x].getNume()<<" il omoara pe "<<this->p[y].getNume()<<" cu pistolul."<<endl<<endl;
                break;
            }
            case 2:{
                cout<<this->p[x].getNume()<<" arunca o grenada si il omoara pe "<<this->p[y].getNume()<<endl<<endl;
                break;
            }
            case 3:{
                cout<<this->p[x].getNume()<<" il omoara pe "<<this->p[y].getNume()<<" cu ak-ul."<<endl<<endl;
                break;
            }
            case 4:{
                cout<<this->p[x].getNume()<<" il prinde pe "<<this->p[y].getNume()<<" pe la spate si il omoara."<<endl<<endl;
                break;
            }
            case 5:{
                cout<<this->p[x].getNume()<<" il omoara pe "<<this->p[y].getNume()<<" cu arcul."<<endl<<endl;
                break;
            }
            case 6:{
                cout<<this->p[x].getNume()<<" il omoara pe "<<this->p[y].getNume()<<" cu pumnii."<<endl<<endl;
                break;
            }
            case 7:{
                cout<<this->p[x].getNume()<<" il omoara pe "<<this->p[y].getNume()<<" de la distanta cu sniper-ul."<<endl<<endl;
                break;
            }
            case 8:{
                cout<<this->p[x].getNume()<<" il omoara pe "<<this->p[y].getNume()<<" cu toporul."<<endl<<endl;
                break;
            }
            case 9:{
                cout<<this->p[x].getNume()<<" il omoara pe "<<this->p[y].getNume()<<" cu cutitul."<<endl<<endl;
                break;
            }
        }
        this->p[x].setKills();
            this->setClasament(this->p[y]);
            this->p.erase(this->p.begin() + y);
}

    virtual ~BattleRoyaleSolo(){};
};

BattleRoyaleSolo :: BattleRoyaleSolo() : BattleRoyale()
{
    this->clasament = {};
}

BattleRoyaleSolo :: BattleRoyaleSolo(vector<Jucator> p) : BattleRoyale()
{
    this->p = p;
    this->clasament = {};
}


BattleRoyaleSolo :: BattleRoyaleSolo(vector<Jucator> p, int nrJucatori, int durata, string numeArena, vector<Jucator> clasament) :
BattleRoyale(p, nrJucatori, durata, numeArena)
{
    this->clasament = clasament;
}

BattleRoyaleSolo :: BattleRoyaleSolo(BattleRoyaleSolo& obj) : BattleRoyale(obj)
{
    this->clasament = obj.clasament;
}

BattleRoyaleSolo& BattleRoyaleSolo :: operator = (BattleRoyaleSolo& obj)
{
    if(this != &obj){
        BattleRoyale :: operator = (obj);
        this->clasament = obj.clasament;
    }
    return *this;
}

ostream& BattleRoyaleSolo :: afisare(ostream& out) const
{
    out<<"Numar jucatori: "<<this->numarJucatori<<endl;
    out<<"Durata: "<<this->durata<<endl;
    out<<"Clasament:"<<endl<<endl;
    for(int i=0; i<this->clasament.size(); i++)
        out<<i+1<<". "<<this->clasament[this->clasament.size()-i-1]<<endl;
    return out;
}

ostream& operator << (ostream& out, const BattleRoyaleSolo& obj)
{
    return obj.afisare(out);
}

istream& BattleRoyaleSolo :: citire(istream& in)
{
    cout<<"Numar jucatori: "; in>>this->numarJucatori;
    cout<<"Durata: "; in>>this->durata;
    cout<<"Jucatori: "<<endl;
    for(int i=0; i<this->numarJucatori; i++){
        Jucator obj;
        in>>obj;
        p.push_back(obj);
    }
    return in;
}

istream& operator >> (istream& in, BattleRoyaleSolo& obj)
{
    return obj.citire(in);
}

class BattleRoyaleTeams : virtual public BattleRoyale
{
protected:
    vector<vector<Jucator>> e;
public:
    BattleRoyaleTeams();
    BattleRoyaleTeams(vector<vector<Jucator>>);
    BattleRoyaleTeams(vector<Jucator>, int, int, string, vector<vector<Jucator>>);
    BattleRoyaleTeams(BattleRoyaleTeams&);

    BattleRoyaleTeams& operator = (BattleRoyaleTeams&);
    istream& citire(istream&);
    ostream& afisare(ostream&) const;
    friend istream& operator >> (istream&, BattleRoyaleTeams&);
    friend ostream& operator << (ostream&, const BattleRoyaleTeams&);

    virtual void start()
{
        system("CLS");
        cout<<"BATTLE ROYALE TEAMS"<<endl<<endl;
        system("PAUSE");
        if(this->e.size() == 0)
            return;
        while(this->e.size() != 1){
            cout<<endl;
            event();
            system("PAUSE");
        }
        system("CLS");
        cout<<"THE GAME IS OVER"<<endl<<"THE WINNING TEAM IS "<<endl;
        for(int i=0; i<this->e[0].size(); i++)
            cout<<this->e[0][i]<<endl<<endl;
}
    void event()
{
        srand(time(NULL));
        int k = rand() % 10;
        int x=0, y=0, x2=0, y2=0;
        while(x == x2){
            x = rand() % e.size();
            y = rand() % e[x].size();
            x2 = rand() % e.size();
            y2 = rand() % e[x2].size();
        }
        switch(k){
            case 0:{
                cout<<this->e[x][y].getNume()<<" il omoara pe "<<this->e[x2][y2].getNume()<<" cu sabia."<<endl<<endl;
                break;
            }
            case 1:{
                cout<<this->e[x][y].getNume()<<" il omoara pe "<<this->e[x2][y2].getNume()<<" cu pistolul."<<endl<<endl;
                break;
            }
            case 2:{
                cout<<this->e[x][y].getNume()<<" arunca o grenada si il omoara pe "<<this->e[x2][y2].getNume()<<endl<<endl;
                break;
            }
            case 3:{
                cout<<this->e[x][y].getNume()<<" il omoara pe "<<this->e[x2][y2].getNume()<<" cu ak-ul."<<endl<<endl;
                break;
            }
            case 4:{
                cout<<this->e[x][y].getNume()<<" il prinde pe "<<this->e[x2][y2].getNume()<<" pe la spate si il omoara."<<endl<<endl;
                break;
            }
            case 5:{
                cout<<this->e[x][y].getNume()<<" il omoara pe "<<this->e[x2][y2].getNume()<<" cu arcul."<<endl<<endl;
                break;
            }
            case 6:{
                cout<<this->e[x][y].getNume()<<" il omoara pe "<<this->e[x2][y2].getNume()<<" cu pumnii."<<endl<<endl;
                break;
            }
            case 7:{
                cout<<this->e[x][y].getNume()<<" il omoara pe "<<this->e[x2][y2].getNume()<<" de la distanta cu sniper-ul."<<endl<<endl;
                break;
            }
            case 8:{
                cout<<this->e[x][y].getNume()<<" il omoara pe "<<this->e[x2][y2].getNume()<<" cu toporul."<<endl<<endl;
                break;
            }
            case 9:{
                cout<<this->e[x][y].getNume()<<" il omoara pe "<<this->e[x2][y2].getNume()<<" cu cutitul."<<endl<<endl;
                break;
            }
        }
        this->e[x][y].setKills();
        this->e[x2].erase(this->e[x2].begin() + y2);
        if(this->e[x2].size() == 0)
            this->e.erase(this->e.begin() + x2);
    }


    virtual ~BattleRoyaleTeams(){};
};

BattleRoyaleTeams :: BattleRoyaleTeams() : BattleRoyale()
{
    this->e = {};
}

BattleRoyaleTeams :: BattleRoyaleTeams(vector<vector<Jucator>> e) : BattleRoyale()
{
    this->e = e;
}

BattleRoyaleTeams :: BattleRoyaleTeams(vector<Jucator> p, int nrJucatori, int durata, string numeArena, vector<vector<Jucator>> e) :
BattleRoyale(p, nrJucatori, durata, numeArena)
{
    this->e = e;
}

BattleRoyaleTeams :: BattleRoyaleTeams(BattleRoyaleTeams& obj) : BattleRoyale(obj)
{
    this->e = obj.e;
}

BattleRoyaleTeams& BattleRoyaleTeams :: operator = (BattleRoyaleTeams& obj)
{
    if(this != &obj){
        BattleRoyale :: operator = (obj);
        this->e = obj.e;
    }
    return *this;
}

ostream& BattleRoyaleTeams :: afisare(ostream& out) const
{
    out<<"Numar jucatori: "<<this->numarJucatori<<endl;
    out<<"Numar echipe: "<<this->e.size()<<endl;
    out<<"Durata: "<<this->durata<<endl;
    return out;
}

ostream& operator << (ostream& out, const BattleRoyaleTeams& obj)
{
    return obj.afisare(out);
}

istream& BattleRoyaleTeams :: citire(istream& in)
{
    cout<<"Numar jucatori: "; in>>this->numarJucatori;
    cout<<"Durata: "; in>>this->durata;
    cout<<"Jucatori: "<<endl;
    for(int i=0; i<this->numarJucatori; i++){
        Jucator obj;
        in>>obj;
        p.push_back(obj);
    }
    return in;
}

istream& operator >> (istream& in, BattleRoyaleTeams& obj)
{
    return obj.citire(in);
}

class BattleRoyaleMixt : public BattleRoyaleSolo, public BattleRoyaleTeams
{
    vector<Jucator> clasamentFinala;
public:
    BattleRoyaleMixt();
    BattleRoyaleMixt(vector<vector<Jucator>> e);
    BattleRoyaleMixt(vector<Jucator>, int, int, string, vector<Jucator>, vector<vector<Jucator>>, vector<Jucator>);
    BattleRoyaleMixt(BattleRoyaleMixt&);

    BattleRoyaleMixt& operator = (BattleRoyaleMixt&);
    istream& citire(istream&);
    ostream& afisare(ostream&) const;
    friend istream& operator >> (istream&, BattleRoyaleMixt&);
    friend ostream& operator << (ostream&, const BattleRoyaleMixt&);

    void start()
{
        system("CLS");
        cout<<"BATTLE ROYALE MIXT"<<endl<<endl;
        system("PAUSE");
        if(this->e.size() == 0)
            return;
        while(this->e.size() != 1){
            cout<<endl;
            event();
            system("PAUSE");
        }
        system("CLS");
        cout<<"THE FIRST PART IS OVER"<<endl<<"THE FINALISTS ARE: "<<endl;
        for(int i=0; i<this->e[0].size(); i++){
            cout<<this->e[0][i]<<endl<<endl;
            this->p.push_back(e[0][i]);
        }
        system("PAUSE");

        system("CLS");
        cout<<"BATTLE ROYALE MIXT - FINALA"<<endl<<endl;
        system("PAUSE");
        if(this->p.size() == 0)
            return;
        while(this->p.size() != 1){
            cout<<endl;
            event2();
            system("PAUSE");
        }
        system("CLS");
        cout<<"THE GAME IS OVER"<<endl<<"THE WINNER IS "<<this->p[0].getNume()<<"!"<<endl<<endl;
        setClasament(this->p[0]);

        for(int i=0; i<this->clasament.size(); i++)
            cout<<i+1<<"."<<endl<<clasament[clasament.size() - i - 1]<<endl;

    }

    void event(){BattleRoyaleTeams :: event();}
    void event2(){BattleRoyaleSolo :: event();}

    ~BattleRoyaleMixt(){};
};

BattleRoyaleMixt :: BattleRoyaleMixt() : BattleRoyaleSolo(), BattleRoyaleTeams()
{
    this->clasamentFinala = {};
}

BattleRoyaleMixt :: BattleRoyaleMixt(vector<vector<Jucator>> e) : BattleRoyaleSolo(), BattleRoyaleTeams()
{
    this->e = e;
    this->clasamentFinala = {};
}

BattleRoyaleMixt :: BattleRoyaleMixt(vector<Jucator> p, int nrJucatori, int durata, string numeArena, vector<Jucator> clasament, vector<vector<Jucator>> e, vector<Jucator> clasamentFinala) :
BattleRoyaleSolo(p, nrJucatori, durata, numeArena, clasament), BattleRoyaleTeams(p, nrJucatori, durata, numeArena, e)
{
    this->clasamentFinala = clasamentFinala;
}

BattleRoyaleMixt :: BattleRoyaleMixt(BattleRoyaleMixt& obj) : BattleRoyaleSolo(obj), BattleRoyaleTeams(obj)
{
    this->clasamentFinala = obj.clasamentFinala;
}

BattleRoyaleMixt& BattleRoyaleMixt :: operator = (BattleRoyaleMixt& obj)
{
    if(this != &obj){
        BattleRoyaleSolo :: operator = (obj);
        BattleRoyaleTeams :: operator = (obj);
        this->clasamentFinala = obj.clasamentFinala;
    }
    return *this;
}

ostream& BattleRoyaleMixt :: afisare(ostream& out) const
{
    BattleRoyaleSolo :: afisare(out);
    out<<"Numar echipe: "<<this->e.size()<<endl;
    return out;
}

ostream& operator << (ostream& out, const BattleRoyaleMixt& obj)
{
    return obj.afisare(out);
}

istream& BattleRoyaleMixt :: citire(istream& in)
{
    BattleRoyaleSolo :: citire(in);
    return in;
}

istream& operator >> (istream& in, BattleRoyaleMixt& obj)
{
    return obj.citire(in);
}

class Meniu
{
    vector<Jucator> p;
    vector<vector<Jucator>> e;
public:
    Meniu(){};
    void menuStart();
    void addJucator(vector<Jucator>& p, int x);
    void modifyJucator(vector<Jucator>& p, int x);
    void deleteJucator(vector<Jucator>& p, int x);
    void showJucator(vector<Jucator>& p, int x);
    void addTeam(int x);
    void modifyTeam(int x);
    void deleteTeam(int x);
    void showTeams(int x);
    void startBattleRoyaleSolo();
    void startBattleRoyaleTeams();
    void startBattleRoyaleMixt();
};

void Meniu :: menuStart()
{
    system("CLS");
    cout<<"BATTLE ROYALE"<<endl<<endl;
    int k;
    cout<<"Pick your gamemode"<<endl<<endl;
    cout<<"1. Battle Royale Solo"<<endl;
    cout<<"2. Battle Royale Teams"<<endl;
    cout<<"3. Battle Royale Mixt"<<endl;
    cin>>k;
    switch(k){
        case 1:{
            startBattleRoyaleSolo();
            break;
        }
        case 2:{
            startBattleRoyaleTeams();
            break;
        }
        case 3:{
            startBattleRoyaleMixt();
            break;
        }
    }
}

void Meniu :: startBattleRoyaleSolo()
{
    system("CLS");
    int k;
    cout<<"BATTLE ROYALE SOLO"<<endl<<endl;
    cout<<"1. Add Player"<<endl;
    cout<<"2. Modify Player"<<endl;
    cout<<"3. Delete Player"<<endl;
    cout<<"4. Show Player"<<endl;
    cout<<"5. Start Battle Royale"<<endl;
    cout<<"0. Stop"<<endl;
    cin>>k;
    switch(k){
        case 1:
            addJucator(p, 1);
            break;
        case 2:
            modifyJucator(p, 1);
            break;
        case 3:
            deleteJucator(p, 1);
            break;
        case 4:
            showJucator(p, 1);
            break;
        case 5:
            BattleRoyale* a = new BattleRoyaleSolo(p);
            a->start();
            break;
    }

}

void Meniu :: addJucator(vector<Jucator>& p, int x)
{
    system("CLS");
    Jucator obj;
    cin>>obj;
    p.push_back(obj);
    system("CLS");
    switch(x){
        case 1:
            startBattleRoyaleSolo();
            break;
        case 2:
            startBattleRoyaleTeams();
            break;
        case 3:
            startBattleRoyaleMixt();
           break;
    }

}

void Meniu :: modifyJucator(vector<Jucator>& p, int x)
{
    system("CLS");
    for(int i=0; i<p.size(); i++)
        cout<<p[i]<<endl;
    int j;
    cout<<"Insert the index of the player you want to modify(starts at 0)"<<endl;
    cin>>j;
    if(j < 0 || j >=p.size()){
        system("CLS");
        cout<<"Invalid index!"<<endl;
        int k;
        cout<<"1. Incearca din nou"<<endl;
        cout<<"2. Inapoi la meniu"<<endl;
        cin>>k;
        system("CLS");
        if(k == 1) modifyJucator(p, x);
        else switch(x){
        case 1:
            startBattleRoyaleSolo();
            break;
        case 2:
            startBattleRoyaleTeams();
            break;
        case 3:
            startBattleRoyaleMixt();
           break;
    }
    }
    else{
        Jucator obj;
        cin>>obj;
        p[j] = obj;
        system("CLS");
        switch(x){
        case 1:
            startBattleRoyaleSolo();
            break;
        case 2:
            startBattleRoyaleTeams();
            break;
        case 3:
            startBattleRoyaleMixt();
           break;
    }
        }
}



void Meniu :: deleteJucator(vector<Jucator>& p, int x)
{
    system("CLS");
    for(int i=0; i<p.size(); i++)
        cout<<p[i]<<endl;
    int j;
    cout<<"Insert the index of the player you want to delete(starts at 0)"<<endl;
    cin>>j;
    if(j < 0 || j >=p.size()){
        system("CLS");
        cout<<"Invalid index!"<<endl;
        int k;
        cout<<"1. Incearca din nou"<<endl;
        cout<<"2. Inapoi la meniu"<<endl;
        cin>>k;
        system("CLS");
        if(k == 1) deleteJucator(p, x);
        else switch(x){
        case 1:
            startBattleRoyaleSolo();
            break;
        case 2:
            startBattleRoyaleTeams();
            break;
        case 3:
            startBattleRoyaleMixt();
           break;
    }
    }
    else{
        p.erase(p.begin() + j);
        system("CLS");
        switch(x){
        case 1:
            startBattleRoyaleSolo();
            break;
        case 2:
            startBattleRoyaleTeams();
            break;
        case 3:
            startBattleRoyaleMixt();
           break;
    }
        }
}

void Meniu :: showJucator(vector<Jucator>& p, int x)
{
    system("CLS");
    for(int i=0; i<p.size(); i++)
        cout<<p[i]<<endl;
    system("PAUSE");
    system("CLS");
    switch(x){
        case 1:
            startBattleRoyaleSolo();
            break;
        case 2:
            startBattleRoyaleTeams();
            break;
        case 3:
            startBattleRoyaleMixt();
           break;
    }
}

void Meniu :: startBattleRoyaleTeams()
{
    system("CLS");
    int k;
    cout<<"BATTLE ROYALE TEAMS"<<endl<<endl;
    cout<<"1. Add Team"<<endl;
    cout<<"2. Modify Team"<<endl;
    cout<<"3. Delete Team"<<endl;
    cout<<"4. Show Teams"<<endl;
    cout<<"5. Start Battle Royale"<<endl;
    cout<<"0. Stop"<<endl;
    cin>>k;
    switch(k){
        case 1:
            addTeam(2);
            break;
        case 2:
            modifyTeam(2);
            break;
        case 3:
            deleteTeam(2);
            break;
        case 4:
            showTeams(2);
            break;
        case 5:
            BattleRoyale* b = new BattleRoyaleTeams(e);
            b->start();
            break;
    }
}

void Meniu :: addTeam(int x)
{
    system("CLS");
    int k;
    cout<<"How many players do you want your team to have?"<<endl;
    cin>>k;
    vector<Jucator> aux;
    for(int i=0; i<k; i++){
        Jucator obj;
        cin>>obj;
        cout<<endl;
        aux.push_back(obj);
    }
    e.push_back(aux);
    if(x == 2)
        startBattleRoyaleTeams();
    else startBattleRoyaleMixt();
}

void Meniu :: modifyTeam(int x)
{
    system("CLS");
    for(int i=0; i<e.size(); i++){
        cout<<"Echipa "<<i+1<<endl<<endl;
        for(int j=0; j<e[i].size(); j++)
            cout<<e[i][j]<<endl;
    }
    cout<<"Insert the index of the team you want to modify"<<endl;
    int k;
    cin>>k;
    cout<<"Echipa "<<k<<endl;
    for(int j=0; j<e[k-1].size(); j++)
            cout<<e[k-1][j]<<endl;
    cout<<"1. Add Player"<<endl;
    cout<<"2. Modify Player"<<endl;
    cout<<"3. Delete Player"<<endl;
    cout<<"4. Show Player"<<endl;
    cout<<"5. Back"<<endl;
    cout<<"0. Stop"<<endl;
    int m;
    cin>>m;
    switch(m){
        case 1:
            addJucator(e[k-1], x);
            break;
        case 2:
            modifyJucator(e[k-1], x);
            break;
        case 3:
            deleteJucator(e[k-1], x);
            break;
        case 4:
            showJucator(e[k-1], x);
            break;
        case 5:
            if(x == 2)
                startBattleRoyaleTeams();
            else startBattleRoyaleMixt();
            break;
    }
}

void Meniu :: deleteTeam(int x)
{
    for(int i=0; i<e.size(); i++){
        cout<<"Echipa "<<i+1<<endl<<endl;
        for(int j=0; j<e[i].size(); j++)
            cout<<e[i][j]<<endl;
    }
    cout<<"Insert the index of the team you want to delete"<<endl;
    int k;
    cin>>k;
    e.erase(e.begin() + k - 1);
    if(x == 2)
        startBattleRoyaleTeams();
    else startBattleRoyaleMixt();
}

void Meniu :: showTeams(int x)
{
    system("CLS");
    for(int i=0; i<e.size(); i++){
        cout<<"Echipa "<<i+1<<endl<<endl;
        for(int j=0; j<e[i].size(); j++)
            cout<<e[i][j]<<endl;
    }
    system("PAUSE");
    if(x == 2)
        startBattleRoyaleTeams();
    else startBattleRoyaleMixt();
}

void Meniu :: startBattleRoyaleMixt()
{
    system("CLS");
    int k;
    cout<<"BATTLE ROYALE MIXT"<<endl<<endl;
    cout<<"1. Add Team"<<endl;
    cout<<"2. Modify Team"<<endl;
    cout<<"3. Delete Team"<<endl;
    cout<<"4. Show Teams"<<endl;
    cout<<"5. Start Battle Royale"<<endl;
    cout<<"0. Stop"<<endl;
    cin>>k;
    switch(k){
        case 1:
            addTeam(3);
            break;
        case 2:
            modifyTeam(3);
            break;
        case 3:
            deleteTeam(3);
            break;
        case 4:
            showTeams(3);
            break;
        case 5:
            BattleRoyale* c = new BattleRoyaleMixt(e);
            c->start();
            break;
    }
}

int main()
{
    Meniu a;
    a.menuStart();
    return 0;
}

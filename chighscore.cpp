#include "chighscore.h"



cHighscore::cHighscore()
{
    for(int i=0;i<10;i++)
    {
        punkty_[i]=0;
    }
    font.loadFromFile("Resources/font.otf");

    for(int i=0;i<10;i++)
    {
        wyniki_[i].setFont(font);
        wyniki_[i].setCharacterSize(30);
        wyniki_[i].setPosition(50.f,200.f+(40.f*(static_cast<float>(i))));
    }

}

 void cHighscore::draw(RenderWindow&okno)
{
    for(int i=0;i<10;i++)
    {
        okno.draw(wyniki_[i]);
    }
}

void cHighscore::read()
{
    string linia;
    fstream plik;
    plik.open("Resources/Highscore.txt",ios::in);

    int x=0;
    while(!plik.eof())
    {
        getline(plik,nicki_[x],',');
        getline(plik,linia);
        punkty_[x]=atoi(linia.c_str());
        if(x==9)
            break;
        x++;
    }
    plik.close();

    for(int i=0;i<10;i++)
    {
        linia=to_string(i+1)+"."+" "+nicki_[i]+" ";

        for(unsigned int j=60-static_cast<unsigned int>(linia.length()*1.5)-to_string(punkty_[i]).length();j>0;j--)
        {
            linia=linia+"-";
        }
        linia=linia+to_string(punkty_[i]);
        wyniki_[i].setString(linia);
    }
}

void cHighscore::update(int punkt, string nick)
{
    string linia;

    fstream plik;
    plik.open("Resources/Highscore.txt",ios::in);

    int x=0;
    while(!plik.eof())
    {
        getline(plik,nicki_[x],',');
        getline(plik,linia);
        punkty_[x]=atoi(linia.c_str());
        if(x==9)
            break;
        x++;
    }
    plik.close();

    for(int i=9;i>0;i--)
    {
        if(punkt>punkty_[i]&&punkt<punkty_[i-1])
        {
            for(int j=8;j>0;j--)
            {
                nicki_[j+1]=nicki_[j];
                punkty_[j+1]=punkty_[j];
                if(j+1==i)
                    break;
            }
            punkty_[i]=punkt;
            nicki_[i]=nick;
        }
        if(punkt>punkty_[0])
        {
            for(int j=8;j>=0;j--)
            {
                nicki_[j+1]=nicki_[j];
                punkty_[j+1]=punkty_[j];
            }
            punkty_[0]=punkt;
            nicki_[0]=nick;
        }
    }
    plik.open("Resources/Highscore.txt",ios::out|ios::trunc);
    for(int i=0;i<10;i++)
    {
        plik<<nicki_[i]<<","<<punkty_[i]<<endl;
    }
    plik.close();

    for(int i=0;i<10;i++)
    {
        linia=to_string(i+1)+"."+" "+nicki_[i]+" ";

        for(unsigned int j=60-static_cast<unsigned int>(linia.length()*1.5)-to_string(punkty_[i]).length();j>0;j--)
        {
            linia=linia+"-";
        }
        linia=linia+to_string(punkty_[i]);
        wyniki_[i].setString(linia);
    }

}

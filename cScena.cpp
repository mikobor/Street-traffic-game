#include "cScena.h"

void cScena::initOkno()
{
    this->okno=new RenderWindow(VideoMode(800,800,32),"Street Traffic Game");
}

cScena::cScena()
{
    this->initOkno();
    this->okno->setFramerateLimit(60);
    font.loadFromFile("Resources/font.otf");
    nick_.setFont(font);
    nick_.setFillColor(Color::White);
    nick_.setCharacterSize(40);
    startpage_tex.loadFromFile("Resources/startpage.jpg");
    this->menu_tex.loadFromFile("Resources/menu1.png");
    this->nick_tex.loadFromFile("Resources/podaj_nick.png");
    this->map_tex.loadFromFile("Resources/mapa.png");
    this->highscore_tex.loadFromFile("Resources/highscore.png");
    background.setTexture(startpage_tex);
    soundtrack_buff.loadFromFile("Resources/soundtrack_taxi.wav");
    soundtrack.setBuffer(soundtrack_buff);
}

cScena::~cScena()
{
    delete okno;
    delete gracz;
    delete przeszkoda;
    for(auto el:pasy)
        delete el;
    for(auto el:palmy)
        delete el;
    delete moneta;
}

void cScena::zdarzeniaUpdate()
{
    while(this->okno->pollEvent(zdarzenie))
    {
        if(menuSt)
        {
                if (zdarzenie.type == Event::Closed)
                    this->okno->close();

                if (zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Up)
                    menu.up();

                if (zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Down)
                    menu.down();

                if (zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Return)
                {
                    switch(menu.getWybrany())
                    {
                    case 1:
                        menuSt=false;
                        highscoreSt=true;
                        break;
                    case 2:
                        this->okno->close();
                        break;
                    case 0:
                        menuSt=false;
                        gameSt=true;
                        this->gracz=new cGracz(360,605);
                        this->przeszkoda=new cPrzeszkoda(-550);
                        this->pasy.clear();
                        this->pasy.push_back(new cPas(-200));
                        this->pasy.push_back(new cPas(0));
                        this->pasy.push_back(new cPas(200));
                        this->pasy.push_back(new cPas(400));
                        this->pasy.push_back(new cPas(600));
                        this->palmy.clear();
                        this->palmy.push_back(new cPalma(0));
                        this->palmy.push_back(new cPalma(300));
                        this->palmy.push_back(new cPalma(600));
                        this->moneta=new cMoneta;
                        soundtrack.play();
                        soundtrack.setLoop(true);
                        new string (nick);
                        break;
                    default:
                        break;
                    }
                }
        } else if(gameSt)
        {
                if (zdarzenie.type == Event::Closed)
                    this->okno->close();

                if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)
                   this->okno->close();

        } else if(highscoreSt)
          {
                if (zdarzenie.type == Event::Closed)
                    this->okno->close();

                if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)
                {
                    highscoreSt=false;
                    menuSt=true;
                }
        }
        else if(nickSt)
        {
            if (zdarzenie.type == Event::Closed)
                this->okno->close();

            if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)
               this->okno->close();

            if (zdarzenie.type == Event::TextEntered)
            {
                if (zdarzenie.text.unicode <= 126&&zdarzenie.text.unicode>=33)
                {
                    nick+=static_cast<char>(zdarzenie.text.unicode);
                    nick_.setPosition(400-static_cast<float>((nick.length()*8)),450);
                    nick_.setString(nick);
                }
                else if(zdarzenie.text.unicode==8)
                    nick=nick.substr(0,nick.length()-1);
            }
            if(zdarzenie.type==Event::KeyPressed && zdarzenie.key.code==Keyboard::Return)
            {

                highscore.update(this->gracz->getScore()/6,nick);
                nickSt=false;
                highscoreSt=true;
            }
        }
    }
}

void cScena::update()
{
    if(licznik<180)
    {
        licznik++;
    } else
    {
        if(menuSt)
        {
            this->zdarzeniaUpdate();
            if(background.getTexture()!=&menu_tex)
                background.setTexture(menu_tex);
        }
        else if(highscoreSt)
        {
            this->zdarzeniaUpdate();
            if(background.getTexture()!=&highscore_tex)
                background.setTexture(highscore_tex);
            highscore.read();

        }
        else if(gameSt)
        {
            this->zdarzeniaUpdate();
            if(background.getTexture()!=&map_tex)
                background.setTexture(map_tex);
            for (auto& itr: palmy)
                itr->update(*gracz);

            for (auto& itr: pasy)
                itr->update(*gracz);

            this->przeszkoda->update(*gracz);
            this->moneta->update(*przeszkoda,*gracz);
            this->gracz->update();
            if(this->gracz->getHp()<=0)
            {
                gameSt=false;
                nickSt=true;
            }
        }
        else if(nickSt)
        {
            this->zdarzeniaUpdate();
            background.setTexture(nick_tex);
        }
        if(!gameSt)
            soundtrack.stop();
    }
}

void cScena::render()
{
    this->okno->clear();

    this->okno->draw(background);

    if(menuSt&&licznik>=180)
    {
        menu.draw(*okno);
    } else if(gameSt)
    {
        if(this->gracz->getHp()>0)
        {
        for(auto& itr:pasy)
            this->okno->draw(*itr);

        for(auto& itr:palmy)
            this->okno->draw(*itr);
        this->okno->draw(*przeszkoda);
        this->okno->draw(*moneta);
        this->okno->draw(*gracz);
        }
    } else if(highscoreSt)
    {
        highscore.draw(*okno);
    }
    else if(nickSt)
    {
        this->okno->draw(nick_);
    }

    this->okno->display();

}

void cScena::run()
{
    while(this->okno->isOpen())
    {
        this->update();
        this->render();

    }
}

bool cScena::oknoisOpen()
{
    return this->okno->isOpen();
}

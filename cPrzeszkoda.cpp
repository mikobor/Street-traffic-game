#include "cPrzeszkoda.h"


cPrzeszkoda::cPrzeszkoda( float t_y )
{
    taxi_tex.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/taxi.png");
    auto_tex.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/auto2.png");
    pickup_tex.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/pickup.png");
    trach_buffer.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/Trach.wav");
    trach.setBuffer(trach_buffer);
    auto1_.setPosition(100, t_y);
    auto2_.setPosition(300, t_y);
    auto3_.setPosition(500, t_y);
    auto1_.setScale(0.5,0.35f);
    auto2_.setScale(0.5,0.35f);
    auto3_.setScale(0.5,0.35f);
}

void cPrzeszkoda::draw(RenderTarget & target, RenderStates states) const
{
    target.draw(this->auto1_,states);
    target.draw(this->auto2_,states);
    target.draw(this->auto3_,states);
}

void cPrzeszkoda::update(cGracz &gracz)
{

    this->przeszkoda_vel=this->przeszkoda_vel+0.002f;
    if(gracz.getHp()<=0)
        this->przeszkoda_vel=0;

    if(this->auto1_.getPosition().y>800||this->auto2_.getPosition().y>800||this->auto3_.getPosition().y>800)
    {
        this->losowosc=rand()%120;
        switch(losowosc%6)
        {
        case 1:
            this->auto1_.setTexture(auto_tex);
            this->auto2_.setTexture(pickup_tex);
            this->auto3_.setTexture(taxi_tex);
            break;
        case 2:
            this->auto1_.setTexture(taxi_tex);
            this->auto2_.setTexture(auto_tex);
            this->auto3_.setTexture(pickup_tex);
            break;
        case 3:
            this->auto1_.setTexture(pickup_tex);
            this->auto2_.setTexture(taxi_tex);
            this->auto3_.setTexture(auto_tex);
            break;
        case 4:
            this->auto1_.setTexture(auto_tex);
            this->auto2_.setTexture(taxi_tex);
            this->auto3_.setTexture(pickup_tex);
            break;
        case 5:
            this->auto1_.setTexture(taxi_tex);
            this->auto2_.setTexture(pickup_tex);
            this->auto3_.setTexture(auto_tex);
            break;
        case 0:
            this->auto1_.setTexture(pickup_tex);
            this->auto2_.setTexture(auto_tex);
            this->auto3_.setTexture(taxi_tex);
            break;

        }
        this->auto1_.setPosition(120,-550);
        this->auto2_.setPosition(320,-550);
        this->auto3_.setPosition(520,-550);

        losowosc=rand()%120;
    }

       switch(losowosc%6)
        {
        case 1:
            this->auto1_.move(this->przeszkoda_velocity_);
            break;
        case 2:
            this->auto2_.move(this->przeszkoda_velocity_);
            break;
        case 3:
            this->auto3_.move(this->przeszkoda_velocity_);
            break;
        case 4:
            this->auto1_.move(this->przeszkoda_velocity_);
            this->auto2_.move(this->przeszkoda_velocity_);
            break;
        case 5:
            this->auto1_.move(this->przeszkoda_velocity_);
            this->auto3_.move(this->przeszkoda_velocity_);
            break;
        case 0:
            this->auto2_.move(this->przeszkoda_velocity_);
            this->auto3_.move(this->przeszkoda_velocity_);
            break;
       }

       if(gracz.getGlobalBounds().intersects(this->auto1_.getGlobalBounds()))
       {
           this->destroyed_=true;
       }
       if(gracz.getGlobalBounds().intersects(this->auto2_.getGlobalBounds()))
       {
           this->destroyed_=true;
       }
       if(gracz.getGlobalBounds().intersects(this->auto3_.getGlobalBounds()))
       {
           this->destroyed_=true;
       }

       if(destroyed_==true)
       {
           trach.play();
           this->auto1_.setPosition(120,800);
           this->auto2_.setPosition(320,800);
           this->auto3_.setPosition(520,800);
           destroyed_=false;
           gracz.setHp(gracz.getHp()-1);
       }
}

FloatRect cPrzeszkoda::getGlobalBounds1()
{
    return this->auto1_.getGlobalBounds();
}

FloatRect cPrzeszkoda::getGlobalBounds2()
{
    return this->auto2_.getGlobalBounds();
}

FloatRect cPrzeszkoda::getGlobalBounds3()
{
    return this->auto3_.getGlobalBounds();
}

#include "cPrzeszkoda.h"


cPrzeszkoda::cPrzeszkoda( float t_y )
{
    taxi_tex.loadFromFile("Resources/taxi.png");
    auto_tex.loadFromFile("Resources/auto2.png");
    pickup_tex.loadFromFile("Resources/pickup.png");
    trach_buffer.loadFromFile("Resources/Trach.wav");
    trach.setBuffer(trach_buffer);
    auto1_.setPosition(120, t_y);
    auto2_.setPosition(325, t_y);
    auto3_.setPosition(520, t_y);
    auto1_.setScale(0.5,0.35f);
    auto2_.setScale(0.5,0.35f);
    auto3_.setScale(0.5,0.35f);
    auto1_.setTexture(taxi_tex);
    auto2_.setTexture(pickup_tex);
    auto3_.setTexture(auto_tex);
}

void cPrzeszkoda::draw(RenderTarget & target, RenderStates states) const
{
    target.draw(this->auto1_,states);
    target.draw(this->auto2_,states);
    target.draw(this->auto3_,states);
}

void cPrzeszkoda::update(cGracz &gracz)
{

    przeszkoda_vel=przeszkoda_vel+0.0008f;
    przeszkoda_velocity_={0,przeszkoda_vel};
    if(gracz.getHp()<=0)
        this->przeszkoda_vel=0;

    if(this->auto1_.getPosition().y>900||this->auto2_.getPosition().y>900||this->auto3_.getPosition().y>900)
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
        this->auto2_.setPosition(325,-550);
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
           this->auto1_.setPosition(120,900);
           this->auto2_.setPosition(320,900);
           this->auto3_.setPosition(520,900);
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

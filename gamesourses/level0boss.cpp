#include "gameheaders/managerdep.h"
void ManagerDep::GenerateLevel0Boss()
{
    auto tmp=this->enemymanager.bosses.find(32);
    if(tmp!=this->enemymanager.bosses.end())
    {
        int Existcount=Count-tmp->second.tmpcount;
        qreal maxhp=tmp->second.maxhp;
        qreal curhp=tmp->second.hp;
        if(curhp>0.8*maxhp)
        {
            if(Count>=tmp->second.tmpcount+100)//缓冲时间
            {
                this->hero->isAbsorbingProps=false;
                if(Existcount%100==0&&Existcount%500!=0)
                {
                    this->enemymanager.SetOneEnemyRandomMode(&tmp->second,100.0*Width/1920,700.0*Width/1920,100.0*Width/1920,300.0*Width/1920,8.0);
                    this->barragemanager.AddOneCircle(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),35,tr("wooden"),tr("ball"),0,0.2);
                    this->barragemanager.AddOneCircle(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),35,tr("wooden"),tr("ball"),0,0.15);
                    this->barragemanager.AddOneCircle(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),35,tr("wooden"),tr("ball"),0,0.1);
                }
                if(Existcount%500==0)
                {
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI/2,tr("rock"),tr("ball"),7,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI/2,tr("rock"),tr("ball"),6,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI/2,tr("rock"),tr("ball"),5,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI/2,tr("rock"),tr("ball"),4,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI/2,tr("rock"),tr("ball"),3,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI/2,tr("rock"),tr("ball"),2,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI/2,tr("rock"),tr("ball"),1,0);
                }
                if(tmp->second.stagelefttime<=0)//超出时间限制
                {
                    tmp->second.setHp(0.8*maxhp);
                }
                tmp->second.stagelefttime=30.0-(Existcount-100)*0.015;
            }
            else
            {
                tmp->second.setHp(maxhp);//无敌
                this->hero->isAbsorbingProps=true;
            }
        }
        else if(curhp>0.5*maxhp)
        {
            if(tmp->second.stage==1)
            {
                tmp->second.stage=2,tmp->second.tmpcount=Count,tmp->second.stagelefttime=45,this->bulletmanager.DestoryAllEnemyBullets();
                qreal distance=qSqrt((tmp->second.X-470.0*Width/1920)*(tmp->second.X-470.0*Width/1920)+(tmp->second.Y-235.0*Width/1920)*(tmp->second.Y-235.0*Width/1920));
                this->enemymanager.SetOneEnemyMoveMode(&tmp->second,470.0*Width/1920,235.0*Width/1920,8.0,distance!=0.0?-64.0/(2.0*distance*1920/Width):0);
            }
            if(Count>=tmp->second.tmpcount+100)//缓冲时间
            {
                this->hero->isAbsorbingProps=false;
                int extra=int((0.8*maxhp-curhp)/(0.3*maxhp)*5);
                if(Existcount%(20-extra*2)==0)
                {
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),6,M_PI*5.0/6,tr("purple"),tr("ball"),5,0);
                }
                if(Existcount%50==0)
                {
                    this->barragemanager.AddOneRandomRain(&tmp->second,tr("x"),-40*Width/1920,8+extra,0,tr("blue"),tr("ball"),2,2,0,0);
                    this->barragemanager.AddOneRandomRain(&tmp->second,tr("x"),1194*Width/1920,8+extra,M_PI,tr("blue"),tr("ball"),2,2,0,0);
                }
                if(tmp->second.stagelefttime<=0)//超出时间限制
                {
                    tmp->second.setHp(0.5*maxhp);
                }
                tmp->second.stagelefttime=45.0-(Existcount-100)*0.015;
            }
            else
            {
                tmp->second.setHp(0.8*maxhp);//无敌
                this->hero->isAbsorbingProps=true;
            }
        }
        else if(curhp>0.3*maxhp)
        {
            if(tmp->second.stage==2)
            {
                tmp->second.stage=3,tmp->second.tmpcount=Count,tmp->second.stagelefttime=30,this->bulletmanager.DestoryAllEnemyBullets();
                qreal distance=qSqrt((tmp->second.X-470.0*Width/1920)*(tmp->second.X-470.0*Width/1920)+(tmp->second.Y-235.0*Width/1920)*(tmp->second.Y-235.0*Width/1920));
                this->enemymanager.SetOneEnemyMoveMode(&tmp->second,470.0*Width/1920,235.0*Width/1920,8.0,distance!=0.0?-64.0/(2.0*distance*1920/Width):0);
            }
            if(Count>=tmp->second.tmpcount+100)//缓冲时间
            {
                this->hero->isAbsorbingProps=false;
                if(Existcount%80==0&&Existcount%400!=0)
                {
                    this->enemymanager.SetOneEnemyRandomMode(&tmp->second,100.0*Width/1920,700.0*Width/1920,100.0*Width/1920,300.0*Width/1920,8.0);
                    this->barragemanager.AddOneCircle(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),39,tr("wooden"),tr("ball"),0,0.2);
                    this->barragemanager.AddOneCircle(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),39,tr("wooden"),tr("ball"),0,0.15);
                    this->barragemanager.AddOneCircle(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),39,tr("wooden"),tr("ball"),0,0.1);
                }
                if(Existcount%400==0)
                {
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),7,M_PI/2,tr("rock"),tr("ball"),7,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),6,M_PI/2,tr("rock"),tr("ball"),6,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),7,M_PI/2,tr("rock"),tr("ball"),5,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),6,M_PI/2,tr("rock"),tr("ball"),4,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),7,M_PI/2,tr("rock"),tr("ball"),3,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),6,M_PI/2,tr("rock"),tr("ball"),2,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),7,M_PI/2,tr("rock"),tr("ball"),1,0);
                }
                if(tmp->second.stagelefttime<=0)//超出时间限制
                {
                    tmp->second.setHp(0.3*maxhp);
                }
                tmp->second.stagelefttime=30.0-(Existcount-100)*0.015;
            }
            else
            {
                tmp->second.setHp(0.5*maxhp);//无敌
                this->hero->isAbsorbingProps=true;
            }
        }
        else
        {
            if(tmp->second.stage==3)
            {
                tmp->second.stage=4,tmp->second.tmpcount=Count,tmp->second.stagelefttime=45,this->bulletmanager.DestoryAllEnemyBullets();
                qreal distance=qSqrt((tmp->second.X-470.0*Width/1920)*(tmp->second.X-470.0*Width/1920)+(tmp->second.Y-235.0*Width/1920)*(tmp->second.Y-235.0*Width/1920));
                this->enemymanager.SetOneEnemyMoveMode(&tmp->second,470.0*Width/1920,235.0*Width/1920,8.0,distance!=0.0?-64.0/(2.0*distance*1920/Width):0);
            }
            if(Count>=tmp->second.tmpcount+100)//缓冲时间
            {
                this->hero->isAbsorbingProps=false;
                if(Existcount%40==0)
                {
                    this->barragemanager.AddOneLine(&tmp->second,qreal(((Existcount-100)/40)%10+0.5)*1194.0/10*Width/1920,1510*Width/1920,-M_PI/2,tr("red"),tr("ball"),25.0*Width/1920,5,8,0);
                    this->barragemanager.AddOneLine(&tmp->second,qreal(-((Existcount-100)/40)%10+9.5)*1194.0/10*Width/1920,1510*Width/1920,-M_PI/2,tr("blue"),tr("ball"),25.0*Width/1920,5,8,0);
                    this->barragemanager.AddOneRandomCircle(&tmp->second,qreal(((Existcount-100)/40)%10+0.5)*1194.0/10*Width/1920,1410*Width/1920,5,tr("red"),tr("ball"),5,2,0,0);
                    this->barragemanager.AddOneRandomCircle(&tmp->second,qreal(-((Existcount-100)/40)%10+9.5)*1194.0/10*Width/1920,1410*Width/1920,5,tr("blue"),tr("ball"),5,2,0,0);
                }
                if(Existcount%360==0)
                {
                    this->enemymanager.SetOneEnemyRandomMode(&tmp->second,100.0*Width/1920,700.0*Width/1920,100.0*Width/1920,300.0*Width/1920,8.0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),1,M_PI/2,tr("purple"),tr("ball"),4.0,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),1,M_PI/2,tr("purple"),tr("ball"),3.5,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),1,M_PI/2,tr("purple"),tr("ball"),3.0,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),1,M_PI/2,tr("purple"),tr("ball"),2.5,0);
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),1,M_PI/2,tr("purple"),tr("ball"),2.0,0);
                }
                if(tmp->second.stagelefttime<=0)//超出时间限制
                {
                    tmp->second.setHp(0*maxhp);
                }
                tmp->second.stagelefttime=45.0-(Existcount-100)*0.015;
            }
            else
            {
                tmp->second.setHp(0.3*maxhp);//无敌
                this->hero->isAbsorbingProps=true;
            }
        }
    }
}

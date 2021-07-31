/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Score.h
 * Author: jyroj
 *
 * Created on July 26, 2021, 1:29 AM
 */

#ifndef SCORE_H
#define SCORE_H

class score {
protected:
    float grammar, spell, length, content;
public:
    score();
};
class PassFail: public score {
private:
    float minPass, totScore;
public:
    PassFail();
    void display();
};

#endif /* SCORE_H */


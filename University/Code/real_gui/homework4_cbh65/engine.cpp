// Assignment I3: Due June 25
// Written by: Cole Hurst (cbh65)
// GUI Summer session 1, Dr. Dan Tamir
// mainMenu.h

#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int TIC = 0;

int main(){

    int status = 0;
    int boatXX = 2047;
    int boatXY = 2047;
    int boatYX = -1;
    int boatYY = -1;
    int movement = 0;




    while(TICS != 0)
    {
        if (boatXX < 0 && boatXY < 0){

            if (boatXX > 0 && boatXY > 0){

                if (boatXX > 1024 && boatXY > 1024){
                    if (boatXX > 1536 && boatXY > 1536){
                        if(boatXX > 1792 && boatXY > 1792){

                        status = 4;
                        return;
                        }
                    status = 3;
                    return;
                    }
                status = 2;
                return;
                }
            status = 1;
            return;
            }
        status = 0;
        return;
        }

        if (status == 0){
            cout << "boat Y is invisible" << endl;}
        else if (status == 1){
            cout << "boat Y is in region A" << endl;}
        else if (status == 2){
            cout << "boat Y is in region B" << endl;}
        else if (status == 3){
            cout << "boat Y is in region C" << endl;}
        else if (status == 4){
            cout << "boat Y is in region D" << endl;}
        else{
            cout << "coordinate error" << endl;}

        movement = rand() % 10 + 1;


        //1 is invisible
        if (movement == 1){
            boatYX = -1;
            boatYY = -1;
        }
        //2 is north
        else if(movement == 2){
            boatYY--;
        }
        //3 is north east
        else if(movement == 3){
            boatYX--;
            boatYY--;
        }
        //4 is east
        else if (movement == 4){

            boatYY--;
        }
        //5 is south east
        else if (movement == 5){
            boatYX--;
            boatYY++;
        }
        //6 is south
        else if (movement == 6){
            boatYY++;
        }
        //7 is south west
        else if (movement == 7){
            boatYX++;
            boatY++;
        }
        //8 is west
        else if (movement == 8){
            boatYX++;
        }
        //9 is north west
        else if (movement == 9){
            boatYX++;
            boatYY--;
        }
        //10 is stay
        else if (movement == 10){
            boatYX = boatXX;
            boatYY = boatYY;
        }



        TICS--;


    }


}

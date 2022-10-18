#include "mbed.h"
#include <string>
DigitalOut myled(LED1);

const float delay_super_short = 0.2;
const float delay_short = 0.5;
const float delay_long = 1;

void dot(){
        myled = 1; // LED is ON
        wait(delay_short); // 200 ms
        myled = 0; // LED is OFF
        wait(delay_super_short); //

}

void dash(){
        myled = 1; // LED is ON
        wait(delay_long); // 200 ms
        myled = 0; // LED is OFF
        wait(delay_super_short); // 1 sec

}

void beep(string morseAlphabet){
    for(unsigned i = 0; i<morseAlphabet.length(); i++){
        if(morseAlphabet[i] == '-'){
            dot();
        }else{
            dash();
        }

    }
}
int main() {  
    while(1) {
        char latinAlphabet[30] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',' };
        string morseAlphabet[30] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", "--..--" };
        string latinPhrase = "JakubSikola";

        while(1) {
            for(unsigned i = 0; i<latinPhrase.length(); i++){
                for(int counter = 0; counter < 30; counter++){
                    if(latinPhrase.at(i) == latinAlphabet[counter]){
                        beep(morseAlphabet[counter]);
                        break;
                    }
                }
            }
        }
    }
}

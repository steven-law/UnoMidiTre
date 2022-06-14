#include <MIDI.h>

#include <MIDI.h>

//some basic code for the CB55 drum machine
//currently, you must use the trigger conditioner (TRIG IN 1),
//as this code outputs gate signals instead of actual trigs
//for everything but accent

//should be easy enough to convert them all to triggers if needed, just
//take a look at the accent code

MIDI_CREATE_DEFAULT_INSTANCE();

const int Out1Pin = 2;     //define pins for 12 instrument gates and accent trig
const int Out2Pin = 3;
const int Out3Pin = 4;
const int Out4Pin = 5;
const int Out5Pin = 6;
const int Out6Pin = 7;
const int Out7Pin = 8;
const int Out8Pin = 9;
const int Out9Pin = 10;
const int Out10Pin = 11;
const int Out11Pin = 12;
const int Out12Pin = 13;


void handleNoteOn(byte channel, byte pitch, byte velocity)
{
    //a series of if/elses to parse incoming MIDI data and turn on gates
    //MIDI notes for the four voices correspond to GM drums
  if(pitch == 36){
    digitalWrite(Out1Pin, HIGH);
  }else if(pitch == 37){
    digitalWrite(Out2Pin, HIGH);
  }else if(pitch == 38){
    digitalWrite(Out3Pin, HIGH);
  }else if(pitch == 39){
    digitalWrite(Out4Pin, HIGH);
  }else if(pitch == 40){
    digitalWrite(Out5Pin, HIGH);
  }else if(pitch == 41){
    digitalWrite(Out6Pin, HIGH);
  }else if(pitch == 42){
    digitalWrite(Out7Pin, HIGH);
  }else if(pitch == 43){
    digitalWrite(Out8Pin, HIGH);
  }else if(pitch == 44){
    digitalWrite(Out9Pin, HIGH);
  }else if(pitch == 45){
    digitalWrite(Out10Pin, HIGH);
  }else if(pitch == 46){
    digitalWrite(Out11Pin, HIGH);
  }else if(pitch == 47){
    digitalWrite(Out12Pin, HIGH);
  }

}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
    //turn off gate signals at note off
  if(pitch == 36){
    digitalWrite(Out1Pin, LOW);
  }else if(pitch == 37){
    digitalWrite(Out2Pin, LOW);
  }else if(pitch == 38){
    digitalWrite(Out3Pin, LOW);
  }else if(pitch == 39){
    digitalWrite(Out4Pin, LOW);
  }else if(pitch == 40){
    digitalWrite(Out5Pin, LOW);
  }else if(pitch == 41){
    digitalWrite(Out6Pin, LOW);
  }else if(pitch == 42){
    digitalWrite(Out7Pin, LOW);
  }else if(pitch == 43){
    digitalWrite(Out8Pin, LOW);
  }else if(pitch == 44){
    digitalWrite(Out9Pin, LOW);
  }else if(pitch == 45){
    digitalWrite(Out10Pin, LOW);
  }else if(pitch == 46){
    digitalWrite(Out11Pin, LOW);
  }else if(pitch == 47){
    digitalWrite(Out12Pin, LOW);
  }

}

// -----------------------------------------------------------------------------

void setup()
{
    // Connect the handleNoteOn function to the MIDI library,
    // so it is called upon reception of a NoteOn.
  MIDI.setHandleNoteOn(handleNoteOn);

    // Do the same for NoteOffs
  MIDI.setHandleNoteOff(handleNoteOff);

    // Initiate MIDI communications, listen to all channels
  MIDI.begin(10); //currently set to listen only on channel 10
  //MIDI.begin(MIDI_CHANNEL_OMNI); //for omni

  pinMode(Out1Pin, OUTPUT);   //set pin modes to output
  pinMode(Out2Pin, OUTPUT);
  pinMode(Out3Pin, OUTPUT);
  pinMode(Out4Pin, OUTPUT);
  pinMode(Out5Pin, OUTPUT);
  pinMode(Out6Pin, OUTPUT);
  pinMode(Out7Pin, OUTPUT);
  pinMode(Out8Pin, OUTPUT);
  pinMode(Out9Pin, OUTPUT);
  pinMode(Out10Pin, OUTPUT);
  pinMode(Out11Pin, OUTPUT);
  pinMode(Out12Pin, OUTPUT);
  
}

void loop()
{
  MIDI.read();  //listens for incoming MIDI

}

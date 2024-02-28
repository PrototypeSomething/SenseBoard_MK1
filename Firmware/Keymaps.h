#define numberOfMuxes 5  // defining number of muxes and channels per mux
#define muxChannels 16

int mux;  // declaring some integers
int muxChannel;

/*
  ,-----_-----_-----_-----_-----_-----_-----_-----_-----_-----_-----_-----_-----.
  | esc | f1  | f2  | f3  | f4  | f5  | f6  | f7  | f8  | f9  | f10 | f11 | f12 |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------------.
  |  ~  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | 10  |  0  |  -  |    <----    |
  +-------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------+-----.
  |  tab  |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |     \     | del |
  +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+----+-----------+-----|
  |  caps  |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |     enter      | pgu |
  +---------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+---------+-----|
  |  shift  |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |     shift     |  ↑  | pgd |
  +---------+-----+-------+-------------------------------------+-----+-----+-----+-----+-----+-----+
  | ctrl  |  win  |  alt  |                space                |altgr| fn  |menu |  ←  |  ↓  |  →  |
  \-------+-------+-------+-------------------------------------+-----+-----+-----+-----+-----+-----/
*/

const int keymaps[numberOfMuxes][muxChannels] = {  // declaring keymaps in a 2D array, sorted in Miltiplexer and then channel on the multiplexer, The commented out keymaps is for another library and hence not used here
  { KC_LGUI, KC_LCTRL, KC_LSHIFT, KC_CAPSLOCK, KC_TAB, KC_GRAVE, KC_ESCAPE, KC_F1, KC_1, KC_Q, KC_A, KC_Z, KC_LALT, KC_X, KC_S, KC_W },
  { KC_2, KC_F2, KC_F3, KC_3, KC_E, KC_D, KC_C, KC_V, KC_F, KC_R, KC_4, KC_F4, KC_F5, KC_5, KC_T, KC_G },
  { KC_SPACE, KC_B, KC_N, KC_H, KC_Y, KC_6, KC_F6, KC_F7, KC_7, KC_U, KC_J, KC_M, KC_K, KC_I, KC_8, KC_F8 },
  { KC_F9, KC_9, KC_O, KC_L, KC_COMMA, KC_DOT, KC_RALT, KC_MENU, KC_SCOLON, KC_P, KC_0, KC_F10, KC_F11, KC_MINUS, KC_LBRACKET, KC_QUOTE },
  { KC_ENTER, KC_SLASH, KC_RCTRL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RSHIFT, KC_UP, KC_RBRACKET, KC_PLUS, KC_F12, KC_BSPACE, KC_BSLASH, KC_PSCREEN, KC_DELETE, KC_DELETE }

  /*{KEY_LEFT_GUI, KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_CAPS_LOCK, KEY_TAB, 0x7e, KEY_ESC, KEY_F1, '1', 'q', 'a', 'z', KEY_LEFT_ALT, 'x', 's', 'w'},      //}
  {'2', KEY_F2, KEY_F3, '3', 'e', 'd', 'c', 'v', 'f', 'r', '4', KEY_F4, KEY_F5, '5', 't', 'g'},                                                         //}
  {' ', 'b', 'n', 'h', 'y', '6', KEY_F6, KEY_F7, '7', 'u', 'j', 'm', 'k', 'i', '8', KEY_F8},                                                            //}  Used for another library (BLE52_Mouse_and_Keyboard.h)
  {KEY_F9, '9', 'o', 'l', ',', '.'},                                                                                                                    //}
  {KEY_RETURN}*/                                                                                                                                        //}
};

int switchValues[5][16][2] = {  // min and max values for each switch, this is updated by the switchCalibration function
  { { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 } },
  { { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 } },
  { { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 } },
  { { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 } },
  { { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 }, { 300, 450 } }
};


#include "SwitchReader.h"  //Putting this as the end to have have access to everything in this document in SwitchReader.h

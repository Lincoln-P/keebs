// configure the global tapping term
#define TAPPING_TERM 190

// enable rapid switch from tap to hold, disables double tap hold auto-repeat
#define QUICK_TAP_TERM 0

// enable permissive hold, activates mod behaviour if a nested key press is noted
// used per key to aviod fat-fingered combos when doing stuff
#define PERMISSIVE_HOLD_PER_KEY

// define auto shift functionality
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define NO_AUTO_SHIFT_TAB // used for caps lock instead
#define NO_AUTO_SHIFT_ALPHA // bad for typing like a human
#define AUTO_SHIFT_ENTER

// retro tapping and retro shifting
#define RETRO_TAPPING

// default RGB settings
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 64
#define RGB_MATRIX_DEFAULT_SAT 239
#define RGB_MATRIX_DEFAULT_VAL 109

// update rotary resolution
#define ENCODER_RESOLUTION 2

// update rgb ordering 
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB
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

// default RGB settings
#undef RGB_MATRIX_DEFAULT_MODE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#undef RGB_MATRIX_DEFAULT_HUE
#define RGB_MATRIX_DEFAULT_HUE 64
#undef RGB_MATRIX_DEFAULT_SAT
#define RGB_MATRIX_DEFAULT_SAT 239
#undef RGB_MATRIX_DEFAULT_VAL
#define RGB_MATRIX_DEFAULT_VAL 109

// update rotary resolution
#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 2

// update rgb ordering 
#undef WS2812_BYTE_ORDER
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       6
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      5
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64
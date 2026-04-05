/**
 * cf01_driver.cpp — CWClockfaceDriver adapter for cw-cf-0x01 (Super Mario)
 * v3 bridge: wraps the v2 CF01::Clockface class in the function-pointer API.
 */

#include "Clockface01.h"        // v2 class, namespace CF01
#include <CWClockfaceDriver.h>     // v3 driver API

static CF01::Clockface* s_face = nullptr;

static void cf01_setup(Adafruit_GFX* display, CWDateTime* dateTime) {
    if (!s_face) s_face = new CF01::Clockface(display);
    s_face->setup(dateTime);
}

static void cf01_update() {
    if (s_face) s_face->update();
}

static void cf01_teardown() {
    // Instance kept alive for fast re-activation.
}

CWClockfaceDriver cf_mario = {
    .name     = "Super Mario",
    .index    = 0,
    .setup    = cf01_setup,
    .update   = cf01_update,
    .teardown = cf01_teardown,
};

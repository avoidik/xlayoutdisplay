#ifndef XLAYOUTDISPLAYS_EDID_H
#define XLAYOUTDISPLAYS_EDID_H

#include <memory>
#include "Mode.h"

#define EDID_MIN_LENGTH 128
#define EDID_BYTE_MAX_CM_HORIZ 0x15
#define EDID_BYTE_MAX_CM_VERT 0x16

class Edid {
public:
    Edid() = default;

    // throws invalid_argument when length > EDID_MIN_LENGTH
    Edid(const unsigned char *edid, size_t length, const char *name);

    virtual ~Edid();

    virtual const int maxCmHoriz() const;

    virtual const int maxCmVert() const;

    virtual const long dpiForMode(const ModeP &mode) const;

private:
    unsigned char *edid = nullptr;
};

#endif //XLAYOUTDISPLAYS_EDID_H

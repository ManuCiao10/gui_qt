#ifndef HWID_H
#define HWID_H

class Hardware_HWID {
public:
    static const char *generate_hwid();
};

inline const char *Hardware_HWID::generate_hwid()
{
    return "12345678";
}


#endif // HWID_H

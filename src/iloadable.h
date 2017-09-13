#ifndef ORCHARD_ILOADABLE_H
#define ORCHARD_ILOADABLE_H

class Resources;

class ILoadable
{
    public:
        virtual ~ILoadable() = default;
        virtual void load(Resources &resources) = 0;
};

#endif //ORCHARD_ILOADABLE_H

#ifndef ILOADABLE_H_
#define ILOADABLE_H_

class Resources;

class ILoadable
{
    public:
        virtual ~ILoadable() {}
        virtual void load(Resources& resources) = 0;
};

#endif // ILOADABLE_H_


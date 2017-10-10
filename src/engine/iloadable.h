#ifndef ORCHARD_ILOADABLE_H
#define ORCHARD_ILOADABLE_H

class Resources;

/**
 * @brief The ILoadable abstract base class must be used like a Java interface. "Loadable" objects'
 * implementations of the load() method will "tell" the Resources object how to load its components.
 */
class ILoadable
{
    public:
        virtual ~ILoadable() = default;
        /// @brief Tells the Resources object how to load the implementing object's components. This
        /// method should be overloaded, but not called directly in client code.
        virtual void load(Resources &resources) = 0;
};

#endif //ORCHARD_ILOADABLE_H

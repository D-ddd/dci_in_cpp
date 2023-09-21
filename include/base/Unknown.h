#ifndef H84CEB6A8_6AA0_4BE4_AFAE_6C5518270D43
#define H84CEB6A8_6AA0_4BE4_AFAE_6C5518270D43

#include "base/interface_def.h"
#include "base/Role.h"

namespace dci {

    UNKNOWN_INTERFACE(Unknown, 0xFFFFFFFE)
    {
        virtual void* castTo(const InterfaceId iid) const = 0;
    };

    template <typename TO>
    TO* unknown_cast(const Unknown* from)
    {
        return from == 0 ? 0 : (TO*)from->castTo(TO::E_IID);
    }

}

#define BEGIN_INTERFACE_TABLE() \
    virtual void* castTo(const InterfaceId iid) const \
    { switch(iid) {


#define END_INTERFACE_TABLE() \
    case 0xFFFFFFFF:          \
    default: return 0; }}


#define __HAS_INTERFACE(iface) \
    case iface::E_IID: \
      return const_cast<iface*>(static_cast<const iface*>(this));


#endif /* H84CEB6A8_6AA0_4BE4_AFAE_6C5518270D43 */
